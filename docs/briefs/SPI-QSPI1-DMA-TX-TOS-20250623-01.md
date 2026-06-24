# IMPLEMENTATION_BRIEF

> 分析 Agent 填写；执行 Agent（Codex / Cursor Agent）**只改「改动清单」**，不改清单外内容。

## 元信息

| 字段 | 值 |
|------|-----|
| **ID** | `SPI-QSPI1-DMA-TX-TOS-20250623-01` |
| **目标** | QSPI1 Level2 DMA 异步 + Polling：`SRC_QSPI1TX` 路由到 DMA Ch3，TX DMA 能启动；改动范围最小（仅 TX SRC，不扩 RX / Polling 补丁） |
| **项目** | `Applications/SipAddon/tc234Autosar` |
| **分支 / 基线** | `最小模块` |
| **状态** | `done`（2025-06-23 上板验证通过） |

## 根因（已确认）

- TC234 上 `SRC_QSPI1TX.TOS=0` 时服务请求送给 **CPU0**，不触发 **DMA Ch3**
- Infineon `Spi_lHwEnableQspiTxIntr()` 原实现只置 **SRE (0x400)**，未置 **TOS=1 (0x800)** 与 **SRPN=TxDmaChannel**
- **补充根因（验证后）**：`Spi_lHwSetQspiTxIntr()` 内 `Spi_lHwRouteQspiSrcToDma()` 会清 **RX SRE**；只恢复 TX SRE 时 `SRC_QSPI1RX≈0x01070802`（SRE=0, SRR=1），RX DMA 完不成，Polling 永远 `PENDING`
- 现象：`Spi_AsyncTransmit` 返回 OK，但 `g_SpiSeqResult=SPI_SEQ_PENDING`，`SRC_QSPI1TX.SRR=1`，`DMA_CHCSR003=0`，示波器无波形
- 修改前 `SRC_QSPI1TX` 约 `0x210F0400`（TOS=0）；目标约 `0x....0C03`（TOS=1, SRPN=3, SRE=1）
- QSPI1 固定映射：**TX=DMA Ch3，RX=DMA Ch2**（GenData 不可改通道号）

## 实施结果（已验证）

**文件**：`Applications/SipAddon/tc234Autosar/MCAL/spi_infineon_tricore/ssc/src/Spi.c`

| 项 | 内容 |
|----|------|
| 新增宏 | `SPI_SRC_QSPI_TOS_DMA_MSK`、`SPI_SRC_QSPI_ROUTE_CLEARMASK`、`SPI_SRC_QSPI_SRPN_MSK` |
| 新增函数 | `Spi_lHwRouteQspiSrcToDma()` — 写 TX+RX 的 TOS/SRPN（会清 SRE） |
| 调用点 | `Spi_lHwEnableQspiTxIntr`、`Spi_lHwSetQspiTxIntr`、`Spi_lHwEnableQspiRxIntr`、`Spi_lHwInitIntr(_SV)` |
| **关键补丁** | `Spi_lHwSetQspiTxIntr()`：Route 后恢复 **TX SRE + RX SRE**（与 `EnableQspiRxIntr` 相同 MODIFY） |

**验证通过**：

- `SRC_QSPI1TX` ≈ `0x20100C03`
- `SRC_QSPI1RX` ≈ `0x....0C02`（SRE=1）
- `g_SpiSeqResult` = OK，`g_SpiSendCount` 递增
- 示波器 P11.6 / P11.9 有波形

**待收敛（可选）**：原清单 [2][5] 建议拆成仅 TX 的 `Spi_lHwRouteQspiTxSrcToDma`，避免 Route 误伤 RX；当前方案已可用。

## 背景约束

- 参考：`agent.md`、`AGENTS.md`
- 仅改：`MCAL/spi_infineon_tricore/ssc/src/Spi.c`（及 brief 列出的 `StartApplication.c` 调试符号）
- **不改** GenData、DaVinci 配置、DMA 通道号
- 匹配现有宏：`SPI_SFR_RUNTIME_MODIFY32`、`SPI_SRC_QSPI_TX_*`
- `Spi.c` 在仓库中为本地 MCAL 副本（非 git 跟踪），改前建议自行备份

## 改动清单

### [1] 文件：`Applications/SipAddon/tc234Autosar/MCAL/spi_infineon_tricore/ssc/src/Spi.c`

- **位置**：宏定义区（约 `SPI_SRC_QSPI_TX_SETMASK5` 附近）
- **操作**：新增

```c
#define SPI_SRC_QSPI_TOS_DMA_MSK             (0x00000800U)
#define SPI_SRC_QSPI_ROUTE_CLEARMASK         (0x00000FFFU)
#define SPI_SRC_QSPI_SRPN_MSK                (0x000000FFU)
```

- **验收**：编译通过

---

### [2] 文件：同上 `Spi.c`

- **函数**：新增 `Spi_lHwRouteQspiTxSrcToDma(uint32 Module)`（仅 **TX**，不写 RX SRC）
- **操作**：
  1. 从 `Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.TxDmaChannel` 取通道号（复用现有 `#if SPI_SAFETY_ENABLE` 分支模式，与 `Spi_lHwInitDmaIntr` 一致）
  2. `TxRouteMask = (TxDmaChannel & 0xFF) | 0x800`
  3. 用 `SPI_SFR_RUNTIME_MODIFY32` 写 `MODULE_SRC.QSPI.QSPI[Module].TX.U`，`CLEARMASK=SPI_SRC_QSPI_ROUTE_CLEARMASK`，`SETMASK=TxRouteMask | (原寄存器 SRE 位 0x400 若需保留)`
  4. **不要**写 `MODULE_SRC.QSPI.QSPI[Module].RX.U`
- **声明**：在 `#if (SPI_LEVEL_DELIVERED != 0U)` 的 inline 声明区增加函数原型
- **验收**：QSPI1 调用后 `SRC_QSPI1TX` 低 12 位含 TOS=1、SRPN=3

---

### [3] 文件：同上 `Spi.c`

- **函数**：`Spi_lHwEnableQspiTxIntr`
- **操作**：在现有两次 `SPI_SFR_RUNTIME_MODIFY32`（SETMASK1/SETMASK2）**之前**调用 `Spi_lHwRouteQspiTxSrcToDma(Module)`
- **验收**：每次 TX 使能前 TOS/SRPN 正确

---

### [4] 文件：同上 `Spi.c`

- **函数**：`Spi_lHwSetQspiTxIntr`
- **操作**：
  1. 在 SETR（SETMASK5）**之前**调用 Route
  2. 恢复 TX **SRE**（SETMASK1 + SETMASK2）
  3. **必须**恢复 RX **SRE**（SETMASK1 + SETMASK3 on RX）— 实测验证项，原 brief 禁止项已推翻
- **验收**：SETR 前 TX/RX 均为 TOS=1 且 SRE=1

---

### [5] 文件：同上 `Spi.c`（清理，若当前代码存在则删除）

- **操作**：删除 / 撤回以下「分析阶段误加」内容（若存在）：
  - `Spi_lHwRouteQspiSrcToDma`（同时写 TX+RX 的版本）
  - 在 `Spi_lHwInitIntr` / `Spi_lHwInitIntr_SV` / `Spi_lHwEnableQspiRxIntr` 中对 Route 的调用
  - `Spi_lHwClearDmaChSrcPending` 及 MainFunction 内对其的调用
  - MainFunction 里 USRF+HTRE 的兜底分支
  - `DmaStartTransferRuntime` 里仅为 Polling 增加的 `DMAENABLECHINTRTRIGGER(Rx)`（若仅为 RX Polling 补丁而加）
  - 调试变量 `g_SpiDbgSrcDmaCh2/3`（若与 StartApplication 重复定义冲突）
- **验收**：`grep Spi_lHwRouteQspiSrcToDma` 无结果；仅保留 `Spi_lHwRouteQspiTxSrcToDma`

---

### [6] 文件：`Applications/SipAddon/tc234Autosar/Appl/Source/StartApplication.c`

- **操作**：调试符号**只声明不定义**（若 Spi.c 中有定义）：

```c
extern volatile uint32 g_SpiDbgSrcQspi1Tx;
extern volatile uint32 g_SpiDbgSrcQspi1Rx;
extern volatile uint32 g_SpiDbgSrcDmaCh2;  /* 仅当 Spi.c 有定义 */
extern volatile uint32 g_SpiDbgSrcDmaCh3;
```

- **约束**：同一符号不得在 `Spi.o` 与 `StartApplication.o` 重复定义（避免 `ltc E108`）
- **验收**：链接无 multiple definition

## 明确不做

- 不改 `SRC_QSPI1RX` / RX Route（除非后续单独 brief）
- 不改 `Spi_MainFunction_Handling` 完成检测逻辑
- 不改 DaVinci / `Spi_Cfg.h` / `Spi_PBCfg.c`
- 不切换 DMA 通道号
- 不把 `Spi_SyncTransmit` 路径改回（应用层保持现有 Async 测试即可）

## 验证步骤

1. **编译** Eclipse 工程 `tc234Autosar`，无 link error
2. **运行** 现有 `StartApplication_SPI_TestCyclic`（Polling）
3. **寄存器**（传输发起后）：
   - `SRC_QSPI1TX` ≈ `0x....0C03`（TOS=1, SRPN=3, SRE=1）
   - `DMA_DADR003` = `0xF0001D64`（QSPI1 DATAENTRY0）
4. **变量**（改善即可，不强制一次成功）：
   - `g_SpiDbgAfterSetQspiTxIntrCnt >= 1`
   - `g_SpiSeqResult` 由 `1(PENDING)` 向 `0(OK)` 变化
5. **示波器**：P11.6 SCLK / P11.9 MOSI 有波形（最终目标）

## 回滚

- 删除 [1]–[4] 新增宏与 `Spi_lHwRouteQspiTxSrcToDma`，恢复 `Spi_lHwEnableQspiTxIntr` / `Spi_lHwSetQspiTxIntr` 为供应商原始仅 SRE 版本
- 或从本地备份还原整个 `Spi.c`

## 执行 Agent 指令（复制到新会话第一条消息）

```text
执行施工单：docs/briefs/SPI-QSPI1-DMA-TX-TOS-20250623-01.md

规则：
- 严格按「改动清单 [1]–[6]」修改，不要重新分析、不要扩大范围
- 不要修改「明确不做」中的内容
- 改完后列出 diff 摘要，并说明每条清单是否完成
- 遵循 agent.md；改 MCAL 后若 graphify 可用则运行 graphify update .
```
