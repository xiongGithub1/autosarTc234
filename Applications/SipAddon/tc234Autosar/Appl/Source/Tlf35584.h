/**********************************************************************************************************************
 * TLF35584 PMIC/SBC driver over Autosar Spi (QSPI1, 1 MHz, Mode 0, HW parity).
 **********************************************************************************************************************/

#ifndef TLF35584_H
#define TLF35584_H

#include "Std_Types.h"

#define TLF35584_CLEAR_STATUS_FLAGS       (0x3Fu)

/* Protected configuration (IEBS_wulin) */
#define TLF35584_SYSCFG0_QST_ENA          (0x01u)
#define TLF35584_SYSCFG1_ERRMON_DIS       (0x00u)
#define TLF35584_WDCFG0_INIT              (0x93u) /* WWD/FWD off, SPI WWD trig, 1 ms, err thr 9 */

/* DEVCTRL rail / tracker enables */
#define TLF35584_DEVCTRL_QT2_EN           (0x80u)
#define TLF35584_DEVCTRL_QT1_EN           (0x40u)
#define TLF35584_DEVCTRL_COMEN_EN         (0x20u)
#define TLF35584_DEVCTRL_VREFEN_EN        (0x08u)
#define TLF35584_DEVCTRL_RAIL_MASK        (0xE8u)
#define TLF35584_DEVCTRL_STATEREQ_MASK    (0x07u)

typedef enum
{
  TLF35584_SPI_CMD_READ  = 0u,
  TLF35584_SPI_CMD_WRITE = 1u
} Tlf35584_SpiCmdType;

typedef enum
{
  TLF35584_REG_PROTCFG   = 0x03u,
  TLF35584_REG_SYSCFG0   = 0x04u,
  TLF35584_REG_SYSCFG1   = 0x05u,
  TLF35584_REG_WDCFG0    = 0x06u,
  TLF35584_REG_RSYSCFG0   = 0x0Bu,
  TLF35584_REG_RSYSCFG1   = 0x0Cu,
  TLF35584_REG_RWDCFG0   = 0x0Du,
  TLF35584_REG_DEVCTRL   = 0x15u,
  TLF35584_REG_DEVCTRLN  = 0x16u,
  TLF35584_REG_SYSSF     = 0x1Du,
  TLF35584_REG_SPISF     = 0x1Fu,
  TLF35584_REG_DEVSTAT   = 0x27u
} Tlf35584_RegAddrType;

typedef enum
{
  TLF35584_UNLOCK_KEY1 = 0xABu,
  TLF35584_UNLOCK_KEY2 = 0xEFu,
  TLF35584_UNLOCK_KEY3 = 0x56u,
  TLF35584_UNLOCK_KEY4 = 0x12u,
  TLF35584_LOCK_KEY1   = 0xDFu,
  TLF35584_LOCK_KEY2   = 0x34u,
  TLF35584_LOCK_KEY3   = 0xBEu,
  TLF35584_LOCK_KEY4   = 0xCAu
} Tlf35584_ProtKeyType;

typedef enum
{
  TLF35584_STATE_NONE     = 0u,
  TLF35584_STATE_INIT     = 1u,
  TLF35584_STATE_NORMAL   = 2u,
  TLF35584_STATE_SLEEP    = 3u,
  TLF35584_STATE_STANDBY  = 4u,
  TLF35584_STATE_WAKE     = 5u
} Tlf35584_StateType;

typedef enum
{
  TLF35584_STATE_REQ_NONE    = 0u,
  TLF35584_STATE_REQ_INIT     = 1u,
  TLF35584_STATE_REQ_NORMAL   = 2u,
  TLF35584_STATE_REQ_SLEEP    = 3u,
  TLF35584_STATE_REQ_STANDBY  = 4u,
  TLF35584_STATE_REQ_WAKE     = 5u
} Tlf35584_StateReqType;

typedef enum
{
  TLF35584_INIT_IDLE = 0u,
  TLF35584_INIT_BUSY,
  TLF35584_INIT_OK,
  TLF35584_INIT_FAILED
} Tlf35584_InitStatusType;

typedef struct
{
  uint8 syssf;
  uint8 spisf;
  uint8 devstat;
  uint8 syscfg0;
  uint8 syscfg1;
  uint8 wdcfg0;
  uint8 devctrl;
} Tlf35584_DeviceType;

extern volatile Tlf35584_InitStatusType g_Tlf35584InitStatus;
extern volatile uint8 g_Tlf35584InitPhase;
extern volatile uint8 g_Tlf35584LastSpiResult;
extern volatile uint8 g_Tlf35584LastSetupRet;
extern volatile uint8 g_Tlf35584LastAsyncRet;
extern volatile uint8 g_Tlf35584LastSeqResult;
extern volatile uint16 g_Tlf35584LastTxWord;
extern volatile uint16 g_Tlf35584LastRxWord;
extern volatile uint8 g_Tlf35584LastRxParityOk;
extern volatile uint8 g_Tlf35584LastRxData;
extern volatile uint8 g_Tlf35584LastTxData;
extern volatile uint8 g_Tlf35584LastEchoMatch;
extern volatile uint32 g_Tlf35584XferCount;
extern volatile uint8 g_Tlf35584DeviceState;
extern volatile uint8 g_Tlf35584Syssf;
extern volatile uint8 g_Tlf35584Ss1Level;
extern volatile uint8 g_Tlf35584Ss2Level;
extern volatile uint8 g_Tlf35584NmiPending;

extern Tlf35584_DeviceType g_Tlf35584Device;

void Tlf35584_MainFunction(void);
void Tlf35584_NotifyNmi(void);
void Tlf35584_PortInit(void);
void Tlf35584_ReadSafeStatePins(void);

Std_ReturnType Tlf35584_Transfer(Tlf35584_SpiCmdType cmd, Tlf35584_RegAddrType regAddr, uint8 data, uint8* rxData);
Std_ReturnType Tlf35584_SetStateRequest(Tlf35584_StateReqType stateReq);
Std_ReturnType Tlf35584_EnableAllRails(void);
Tlf35584_StateType Tlf35584_GetState(void);

#endif /* TLF35584_H */

