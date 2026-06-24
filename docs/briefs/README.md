# 施工单（Implementation Brief）

分析 Agent 与执行 Agent（Codex / Cursor）分工用的文档目录。

## 流程

1. **分析会话**：调试、读寄存器、定位根因 → 生成 `docs/briefs/<ID>.md`，状态设为 `ready`
2. **执行会话**：新建 Agent，粘贴 brief 底部「执行 Agent 指令」+ `@docs/briefs/<ID>.md`
3. **验证**：按 brief「验证步骤」编译 / 上板
4. **归档**：状态改为 `done`；commit message 可带 brief ID

## 文件

| 文件 | 用途 |
|------|------|
| `IMPLEMENTATION_BRIEF.template.md` | 新任务复制此模板 |
| `SPI-QSPI1-DMA-TX-TOS-20250623-01.md` | 当前 QSPI1 TX DMA 最小改动施工单 |

## 约定

- **分析模式**：用户说「只分析 / 出施工单」→ 只写本目录下的 md，不改 MCAL
- **执行模式**：用户说「执行施工单」→ 只改 brief 清单内文件
