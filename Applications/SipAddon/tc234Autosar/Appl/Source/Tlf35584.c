/**********************************************************************************************************************
 * TLF35584 driver ??IEBS_wulin init sequence on Autosar Spi L2 + Dio GPIO.
 *********************************************************************************************************************/

#include "Tlf35584.h"
#include "Tlf35584_Cfg.h"
#include "Dio.h"
#include "Spi.h"
#include "SchM_Spi.h"

#define TLF35584_SPI_POLL_LOOP_MAX        (50000u)
#define TLF35584_MODE_VERIFY_RETRIES      (10u)

typedef enum
{
  TLF35584_PHASE_PORT_INIT = 0u,
  TLF35584_PHASE_SPI_MODE,
  TLF35584_PHASE_PROTECTED_CFG,
  TLF35584_PHASE_GOTO_NORMAL,
  TLF35584_PHASE_ENABLE_RAILS,
  TLF35584_PHASE_CLEAR_STATUS,
  TLF35584_PHASE_VERIFY,
  TLF35584_PHASE_DONE
} Tlf35584_InitPhaseType;

volatile Tlf35584_InitStatusType g_Tlf35584InitStatus = TLF35584_INIT_IDLE;
volatile uint8 g_Tlf35584LastSpiResult = 0xFFu;
volatile uint8 g_Tlf35584DeviceState = 0xFFu;
volatile uint8 g_Tlf35584Syssf = 0u;
volatile uint8 g_Tlf35584Ss1Level = 0u;
volatile uint8 g_Tlf35584Ss2Level = 0u;
volatile uint8 g_Tlf35584NmiPending = 0u;

Tlf35584_DeviceType g_Tlf35584Device;

static volatile uint8 s_Tlf35584SpiModeConfigured = 0u;
static volatile Tlf35584_InitPhaseType s_Tlf35584InitPhase = TLF35584_PHASE_PORT_INIT;
static volatile uint8 s_Tlf35584VerifyRetries = 0u;

static uint16 s_Tlf35584TxWord;
static uint16 s_Tlf35584RxWord;

volatile uint8 g_Tlf35584InitPhase = 0u;
volatile uint32 g_Tlf35584XferCount = 0u;
volatile uint8 g_Tlf35584LastSetupRet = 0xFFu;
volatile uint8 g_Tlf35584LastAsyncRet = 0xFFu;
volatile uint8 g_Tlf35584LastSeqResult = 0xFFu;
volatile uint16 g_Tlf35584LastTxWord = 0u;
volatile uint16 g_Tlf35584LastRxWord = 0u;
volatile uint8 g_Tlf35584LastRxParityOk = 0u;
volatile uint8 g_Tlf35584LastRxData = 0u;
volatile uint8 g_Tlf35584LastTxData = 0u;
volatile uint8 g_Tlf35584LastEchoMatch = 0u;

/* IEBS Data_Spi + tlf35584_yh_bit: bit0 = odd parity, data at [8:1], addr at [14:9], R/W at bit15. */
static uint16 Tlf35584_ComputeOddParityBit0(uint16 data)
{
  uint8 parityAcc = (uint8)(data & 0x02u);
  uint8 bitIdx;

  for (bitIdx = 2u; bitIdx < 16u; bitIdx++)
  {
    parityAcc = (uint8)(((data >> (bitIdx - 1u)) & 0x02u) ^ parityAcc);
  }

  if (parityAcc != 0u)
  {
    return (uint16)(data | 0x0001u);
  }
  return (uint16)(data & 0xFFFEu);
}

static uint16 Tlf35584_BuildFrame(Tlf35584_SpiCmdType cmd, Tlf35584_RegAddrType regAddr, uint8 data)
{
  uint16 frame;

  if (cmd == TLF35584_SPI_CMD_WRITE)
  {
    frame = (uint16)(0x8000u |
                     (((uint16)((uint8)regAddr & 0x3Fu)) << 9) |
                     (((uint16)data & 0xFFu) << 1));
  }
  else
  {
    frame = (uint16)((((uint16)((uint8)regAddr & 0x3Fu)) << 9) |
                     (((uint16)data & 0xFFu) << 1));
  }

  return Tlf35584_ComputeOddParityBit0(frame);
}

static void Tlf35584_PollSequenceCompletion(void)
{
  uint32 pollIdx;

  for (pollIdx = 0u; pollIdx < TLF35584_SPI_POLL_LOOP_MAX; pollIdx++)
  {
    Spi_MainFunction_Handling();
    if (Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence) != SPI_SEQ_PENDING)
    {
      break;
    }
  }

#if (SPI_CANCEL_API == STD_ON)
  if (Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence) == SPI_SEQ_PENDING)
  {
    (void)Spi_Cancel(SpiConf_SpiSequence_SpiSequence);
  }
#endif
}

static Std_ReturnType Tlf35584_EnsureSpiPollingMode(void)
{
#if (SPI_LEVEL_DELIVERED == 2U)
  if (s_Tlf35584SpiModeConfigured == 0u)
  {
    if (Spi_SetAsyncMode(SPI_POLLING_MODE) != E_OK)
    {
      return E_NOT_OK;
    }
    s_Tlf35584SpiModeConfigured = 1u;
  }
#else
  s_Tlf35584SpiModeConfigured = 1u;
#endif
  return E_OK;
}

Std_ReturnType Tlf35584_Transfer(Tlf35584_SpiCmdType cmd, Tlf35584_RegAddrType regAddr, uint8 data, uint8* rxData)
{
  Std_ReturnType retVal;

  if (Tlf35584_EnsureSpiPollingMode() != E_OK)
  {
    return E_NOT_OK;
  }

  if (Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence) == SPI_SEQ_PENDING)
  {
    return E_NOT_OK;
  }

  s_Tlf35584TxWord = Tlf35584_BuildFrame(cmd, regAddr, data);
  s_Tlf35584RxWord = 0u;
  g_Tlf35584LastTxWord = s_Tlf35584TxWord;
  g_Tlf35584LastRxWord = 0u;
  g_Tlf35584LastRxParityOk = 0u;
  g_Tlf35584LastTxData = data;
  g_Tlf35584LastRxData = 0u;
  g_Tlf35584LastEchoMatch = 0u;

  retVal = Spi_SetupEB(
      SpiConf_SpiChannel_SpiChannel,
      (const Spi_DataType*)&s_Tlf35584TxWord,
      (Spi_DataType*)&s_Tlf35584RxWord,
      1u);
  g_Tlf35584LastSetupRet = (uint8)retVal;
  if (retVal != E_OK)
  {
    return E_NOT_OK;
  }

  retVal = Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence);
  g_Tlf35584LastAsyncRet = (uint8)retVal;
  if (retVal != E_OK)
  {
    return E_NOT_OK;
  }

  Tlf35584_PollSequenceCompletion();

  g_Tlf35584LastSeqResult = (uint8)Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence);
  g_Tlf35584LastRxWord = s_Tlf35584RxWord;
  if (s_Tlf35584RxWord == Tlf35584_ComputeOddParityBit0((uint16)(s_Tlf35584RxWord & 0xFFFEu)))
  {
    g_Tlf35584LastRxParityOk = 1u;
  }
  g_Tlf35584LastRxData = (uint8)((s_Tlf35584RxWord >> 1) & 0xFFu);
  if (g_Tlf35584LastRxData == data)
  {
    g_Tlf35584LastEchoMatch = 1u;
  }
  if (g_Tlf35584LastSeqResult != (uint8)SPI_SEQ_OK)
  {
    return E_NOT_OK;
  }

  if (rxData != NULL_PTR)
  {
    *rxData = (uint8)((s_Tlf35584RxWord >> 1) & 0xFFu);
  }

  g_Tlf35584XferCount++;
  return E_OK;
}

static Std_ReturnType Tlf35584_WriteReg(Tlf35584_RegAddrType regAddr, uint8 data)
{
  return Tlf35584_Transfer(TLF35584_SPI_CMD_WRITE, regAddr, data, NULL_PTR);
}

static Std_ReturnType Tlf35584_ReadReg(Tlf35584_RegAddrType regAddr, uint8* data)
{
  return Tlf35584_Transfer(TLF35584_SPI_CMD_READ, regAddr, 0u, data);
}

static Std_ReturnType Tlf35584_WriteDevCtrlPair(uint8 devCtrl, uint8 devCtrlN)
{
  if (Tlf35584_WriteReg(TLF35584_REG_DEVCTRL, devCtrl) != E_OK)
  {
    return E_NOT_OK;
  }
  return Tlf35584_WriteReg(TLF35584_REG_DEVCTRLN, devCtrlN);
}

static Std_ReturnType Tlf35584_UnlockProtectedRegs(void)
{
  if (Tlf35584_WriteReg(TLF35584_REG_PROTCFG, TLF35584_UNLOCK_KEY1) != E_OK) { return E_NOT_OK; }
  if (Tlf35584_WriteReg(TLF35584_REG_PROTCFG, TLF35584_UNLOCK_KEY2) != E_OK) { return E_NOT_OK; }
  if (Tlf35584_WriteReg(TLF35584_REG_PROTCFG, TLF35584_UNLOCK_KEY3) != E_OK) { return E_NOT_OK; }
  if (Tlf35584_WriteReg(TLF35584_REG_PROTCFG, TLF35584_UNLOCK_KEY4) != E_OK) { return E_NOT_OK; }
  return E_OK;
}

static Std_ReturnType Tlf35584_LockProtectedRegs(void)
{
  if (Tlf35584_WriteReg(TLF35584_REG_PROTCFG, TLF35584_LOCK_KEY1) != E_OK) { return E_NOT_OK; }
  if (Tlf35584_WriteReg(TLF35584_REG_PROTCFG, TLF35584_LOCK_KEY2) != E_OK) { return E_NOT_OK; }
  if (Tlf35584_WriteReg(TLF35584_REG_PROTCFG, TLF35584_LOCK_KEY3) != E_OK) { return E_NOT_OK; }
  if (Tlf35584_WriteReg(TLF35584_REG_PROTCFG, TLF35584_LOCK_KEY4) != E_OK) { return E_NOT_OK; }
  return E_OK;
}

static Std_ReturnType Tlf35584_WriteProtectedReg(Tlf35584_RegAddrType regAddr, uint8 data)
{
  if (Tlf35584_UnlockProtectedRegs() != E_OK)
  {
    return E_NOT_OK;
  }
  if (Tlf35584_WriteReg(regAddr, data) != E_OK)
  {
    return E_NOT_OK;
  }
  return Tlf35584_LockProtectedRegs();
}

void Tlf35584_PortInit(void)
{
  /* IEBS tlf35584_port_init: ERR and WDI driven high (no fault / idle WDI). */
  Dio_WriteChannel(TLF35584_DIO_ERR_PIN, STD_HIGH);
  Dio_WriteChannel(TLF35584_DIO_WDI_PIN, STD_HIGH);
  Dio_WriteChannel(TLF35584_DIO_MPS_PIN, STD_LOW);
}

void Tlf35584_ReadSafeStatePins(void)
{
  g_Tlf35584Ss1Level = (uint8)Dio_ReadChannel(TLF35584_DIO_SS1_PIN);
  g_Tlf35584Ss2Level = (uint8)Dio_ReadChannel(TLF35584_DIO_SS2_PIN);
}

void Tlf35584_NotifyNmi(void)
{
  g_Tlf35584NmiPending = 1u;
}

static Std_ReturnType Tlf35584_HandleNmi(void)
{
  if (g_Tlf35584NmiPending == 0u)
  {
    return E_OK;
  }

  (void)Tlf35584_WriteReg(TLF35584_REG_SYSSF, TLF35584_CLEAR_STATUS_FLAGS);
  (void)Tlf35584_WriteReg(TLF35584_REG_SPISF, TLF35584_CLEAR_STATUS_FLAGS);

  if (Tlf35584_SetStateRequest(TLF35584_STATE_REQ_NORMAL) == E_OK)
  {
    g_Tlf35584NmiPending = 0u;
    return E_OK;
  }

  return E_NOT_OK;
}

static Std_ReturnType Tlf35584_WaitDevCtrlIdle(void)
{
  uint8 devCtrl;
  uint32 retry;

  for (retry = 0u; retry < TLF35584_MODE_VERIFY_RETRIES; retry++)
  {
    if (Tlf35584_ReadReg(TLF35584_REG_DEVCTRL, &devCtrl) != E_OK)
    {
      return E_NOT_OK;
    }
    if ((devCtrl & TLF35584_DEVCTRL_STATEREQ_MASK) == 0u)
    {
      return E_OK;
    }
  }

  return E_NOT_OK;
}

Std_ReturnType Tlf35584_SetStateRequest(Tlf35584_StateReqType stateReq)
{
  uint8 devStat;
  uint8 devCtrl;
  uint8 txCtrl;
  uint8 txCtrlN;
  uint32 retry;

  for (retry = 0u; retry < TLF35584_MODE_VERIFY_RETRIES; retry++)
  {
    if (Tlf35584_ReadReg(TLF35584_REG_DEVSTAT, &devStat) != E_OK)
    {
      return E_NOT_OK;
    }

    if ((devStat & TLF35584_DEVCTRL_STATEREQ_MASK) == (uint8)stateReq)
    {
      return E_OK;
    }

    if (Tlf35584_ReadReg(TLF35584_REG_DEVCTRL, &devCtrl) != E_OK)
    {
      return E_NOT_OK;
    }

    if ((devCtrl & TLF35584_DEVCTRL_STATEREQ_MASK) != 0u)
    {
      continue;
    }

    txCtrl = (uint8)((devStat & TLF35584_DEVCTRL_RAIL_MASK) | (uint8)stateReq);
    txCtrlN = (uint8)((~txCtrl) & 0xEFu);

    return Tlf35584_WriteDevCtrlPair(txCtrl, txCtrlN);
  }

  return E_NOT_OK;
}

Std_ReturnType Tlf35584_EnableAllRails(void)
{
  uint8 devStat;
  uint8 txCtrl;
  uint8 txCtrlN;

  if (Tlf35584_WaitDevCtrlIdle() != E_OK)
  {
    return E_NOT_OK;
  }

  if (Tlf35584_ReadReg(TLF35584_REG_DEVSTAT, &devStat) != E_OK)
  {
    return E_NOT_OK;
  }

  txCtrl = (uint8)((devStat & TLF35584_DEVCTRL_STATEREQ_MASK) |
                   TLF35584_DEVCTRL_QT2_EN |
                   TLF35584_DEVCTRL_QT1_EN |
                   TLF35584_DEVCTRL_COMEN_EN |
                   TLF35584_DEVCTRL_VREFEN_EN);
  txCtrlN = (uint8)((~txCtrl) & 0xEFu);

  g_Tlf35584Device.devctrl = txCtrl;
  return Tlf35584_WriteDevCtrlPair(txCtrl, txCtrlN);
}

Tlf35584_StateType Tlf35584_GetState(void)
{
  uint8 regVal;

  if (Tlf35584_ReadReg(TLF35584_REG_DEVSTAT, &regVal) != E_OK)
  {
    return TLF35584_STATE_NONE;
  }

  g_Tlf35584Device.devstat = regVal;
  return (Tlf35584_StateType)(regVal & TLF35584_DEVCTRL_STATEREQ_MASK);
}

static Std_ReturnType Tlf35584_ConfigureProtectedRegs(void)
{
  if (Tlf35584_WriteProtectedReg(TLF35584_REG_SYSCFG0, TLF35584_SYSCFG0_QST_ENA) != E_OK)
  {
    return E_NOT_OK;
  }
  g_Tlf35584Device.syscfg0 = TLF35584_SYSCFG0_QST_ENA;

  if (Tlf35584_WriteProtectedReg(TLF35584_REG_SYSCFG1, TLF35584_SYSCFG1_ERRMON_DIS) != E_OK)
  {
    return E_NOT_OK;
  }
  g_Tlf35584Device.syscfg1 = TLF35584_SYSCFG1_ERRMON_DIS;

  if (Tlf35584_WriteProtectedReg(TLF35584_REG_WDCFG0, TLF35584_WDCFG0_INIT) != E_OK)
  {
    return E_NOT_OK;
  }
  g_Tlf35584Device.wdcfg0 = TLF35584_WDCFG0_INIT;

  return E_OK;
}

static void Tlf35584_ReadStatusSnapshot(void)
{
  (void)Tlf35584_ReadReg(TLF35584_REG_SYSSF, &g_Tlf35584Device.syssf);
  (void)Tlf35584_ReadReg(TLF35584_REG_SPISF, &g_Tlf35584Device.spisf);
  (void)Tlf35584_ReadReg(TLF35584_REG_DEVSTAT, &g_Tlf35584Device.devstat);
  g_Tlf35584Syssf = g_Tlf35584Device.syssf;
}

static Std_ReturnType Tlf35584_ClearAllStatusFlags(void)
{
  if (Tlf35584_WriteReg(TLF35584_REG_SYSSF, TLF35584_CLEAR_STATUS_FLAGS) != E_OK)
  {
    return E_NOT_OK;
  }
  return Tlf35584_WriteReg(TLF35584_REG_SPISF, TLF35584_CLEAR_STATUS_FLAGS);
}

static Std_ReturnType Tlf35584_RunInitPhase(void)
{
  g_Tlf35584InitPhase = (uint8)s_Tlf35584InitPhase;

  switch (s_Tlf35584InitPhase)
  {
    case TLF35584_PHASE_PORT_INIT:
      Tlf35584_PortInit();
      s_Tlf35584InitPhase = TLF35584_PHASE_SPI_MODE;
      return E_OK;

    case TLF35584_PHASE_SPI_MODE:
      g_Tlf35584LastSpiResult = (uint8)Tlf35584_EnsureSpiPollingMode();
      if (g_Tlf35584LastSpiResult != (uint8)E_OK)
      {
        return E_NOT_OK;
      }
      s_Tlf35584InitPhase = TLF35584_PHASE_PROTECTED_CFG;
      return E_OK;

    case TLF35584_PHASE_PROTECTED_CFG:
      g_Tlf35584LastSpiResult = (uint8)Tlf35584_ConfigureProtectedRegs();
      if (g_Tlf35584LastSpiResult != (uint8)E_OK)
      {
        return E_NOT_OK;
      }
      s_Tlf35584InitPhase = TLF35584_PHASE_GOTO_NORMAL;
      return E_OK;

    case TLF35584_PHASE_GOTO_NORMAL:
      g_Tlf35584LastSpiResult = (uint8)Tlf35584_SetStateRequest(TLF35584_STATE_REQ_NORMAL);
      if (g_Tlf35584LastSpiResult != (uint8)E_OK)
      {
        return E_NOT_OK;
      }
      s_Tlf35584InitPhase = TLF35584_PHASE_ENABLE_RAILS;
      return E_OK;

    case TLF35584_PHASE_ENABLE_RAILS:
      g_Tlf35584LastSpiResult = (uint8)Tlf35584_EnableAllRails();
      if (g_Tlf35584LastSpiResult != (uint8)E_OK)
      {
        return E_NOT_OK;
      }
      s_Tlf35584InitPhase = TLF35584_PHASE_CLEAR_STATUS;
      return E_OK;

    case TLF35584_PHASE_CLEAR_STATUS:
      (void)Tlf35584_ClearAllStatusFlags();
      Tlf35584_ReadStatusSnapshot();
      Dio_WriteChannel(TLF35584_DIO_MPS_PIN, STD_HIGH);
      s_Tlf35584VerifyRetries = TLF35584_MODE_VERIFY_RETRIES;
      s_Tlf35584InitPhase = TLF35584_PHASE_VERIFY;
      return E_OK;

    default:
      return E_OK;
  }
}

void Tlf35584_MainFunction(void)
{
  uint8 phaseGuard;

  if (g_Tlf35584InitStatus == TLF35584_INIT_OK)
  {
    (void)Tlf35584_HandleNmi();
    Tlf35584_ReadSafeStatePins();
    g_Tlf35584DeviceState = (uint8)Tlf35584_GetState();
    return;
  }

  if (g_Tlf35584InitStatus == TLF35584_INIT_FAILED)
  {
    return;
  }

  g_Tlf35584InitStatus = TLF35584_INIT_BUSY;

  phaseGuard = 0u;
  while ((s_Tlf35584InitPhase < TLF35584_PHASE_VERIFY) && (phaseGuard < 16u))
  {
    if (Tlf35584_RunInitPhase() != E_OK)
    {
      g_Tlf35584InitStatus = TLF35584_INIT_FAILED;
      return;
    }
    phaseGuard++;
  }

  if (s_Tlf35584InitPhase == TLF35584_PHASE_VERIFY)
  {
    g_Tlf35584InitPhase = (uint8)TLF35584_PHASE_VERIFY;
    Tlf35584_ReadSafeStatePins();
    g_Tlf35584DeviceState = (uint8)Tlf35584_GetState();
    if (g_Tlf35584DeviceState == (uint8)TLF35584_STATE_NORMAL)
    {
      g_Tlf35584InitStatus = TLF35584_INIT_OK;
      s_Tlf35584InitPhase = TLF35584_PHASE_DONE;
    }
    else if (s_Tlf35584VerifyRetries > 0u)
    {
      s_Tlf35584VerifyRetries--;
    }
    else
    {
      g_Tlf35584InitStatus = TLF35584_INIT_FAILED;
    }
  }
}


