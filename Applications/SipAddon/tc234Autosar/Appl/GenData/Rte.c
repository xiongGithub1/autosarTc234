/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte.c
 *        Config:  TsiStandard.dpa
 *   ECU-Project:  MyECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700982 for Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *
 *   Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0781, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_Rte_0781, MD_MSR_1.1_857 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_AppCom.h"
#include "Rte_BswM.h"
#include "Rte_ComM.h"
#include "Rte_Det.h"
#include "Rte_EcuM.h"
#include "Rte_Os_OsCore_Core0_swc.h"
#include "Rte_StartApplication.h"
#include "SchM_BswM.h"
#include "SchM_Can.h"
#include "SchM_CanIf.h"
#include "SchM_CanSM.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_Det.h"
#include "SchM_Dio.h"
#include "SchM_EcuM.h"
#include "SchM_Mcu.h"
#include "SchM_PduR.h"
#include "SchM_Port.h"

#include "Rte_Hook.h"

#include "Com.h"
#if defined(IL_ASRCOM_VERSION)
# define RTE_USE_COM_TXSIGNAL_RDACCESS
#endif

#include "Rte_Cbk.h"

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif


/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(BswM_ESH_RunRequest, RTE_VAR_NOINIT) Rte_BswM_Provide_BswMRteModeRequestPort_requestedMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Per-Instance Memory
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(uint32, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_COM_TxSigValue0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_NM_ActiveComMUsers; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_TxCtrlSigValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_TxDataSigValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_COM_RxSigValue0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_XcpPimDownload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_XcpPimUpload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(EnumActiveComponentType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_ActiveComponent; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_DIAG_LastRxData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(EnumMEM_BlockStateType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_MEM_BlockState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_MEM_DataBuffer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_NM_ActiveChannelHasFullComRequest; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_NM_ActiveComMChannel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(EnumNM_ApplStateType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_NM_ApplState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_NM_BusSleepModeTimer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_Uptime; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Buffer for inter-runnable variables
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(uint16, RTE_VAR_NOINIT) Rte_Irv_StartApplication_IrvOccuranceCounterDid; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/

VAR(BswM_ESH_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode; /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined OS_US2TICKS_SystemTimer
# define RTE_USEC_SystemTimer OS_US2TICKS_SystemTimer
#else
# define RTE_USEC_SystemTimer(val) ((TickType)RTE_CONST_USEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer
# define RTE_MSEC_SystemTimer OS_MS2TICKS_SystemTimer
#else
# define RTE_MSEC_SystemTimer(val) ((TickType)RTE_CONST_MSEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer
# define RTE_SEC_SystemTimer OS_SEC2TICKS_SystemTimer
#else
# define RTE_SEC_SystemTimer(val)  ((TickType)RTE_CONST_SEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#define RTE_CONST_MSEC_SystemTimer_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer_1 (1UL)
#define RTE_CONST_MSEC_SystemTimer_10 (10UL)
#define RTE_CONST_MSEC_SystemTimer_100 (100UL)
#define RTE_CONST_MSEC_SystemTimer_20 (20UL)
#define RTE_CONST_MSEC_SystemTimer_250 (250UL)

#define RTE_CONST_SEC_SystemTimer_0 (0UL)
#define RTE_CONST_SEC_SystemTimer_1 (1000UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Init(void)
{
  /* activate the tasks */
  (void)ActivateTask(Default_BSW_Async_Task); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_Default_BSW_Async_Task_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_Default_BSW_Async_Task_0_20ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417 */ /* MD_Rte_Os */

}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* set default values for internal data */
  Rte_BswM_Provide_BswMRteModeRequestPort_requestedMode = 0U;

  /* initialize inter-runnable variables */
  Rte_Irv_StartApplication_IrvOccuranceCounterDid = 0U;

  /* mode management initialization part 1 */

  Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_STARTUP;

  /* activate the tasks */
  (void)ActivateTask(Default_Appl_Init_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Default_Appl_Task); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE_AppCom_RWsignal, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_StartApplication_StartApplication_Cyclic1000ms, RTE_SEC_SystemTimer(0) + (TickType)1, RTE_SEC_SystemTimer(1)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_StartApplication_StartApplication_Cyclic10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_StartApplication_StartApplication_Cyclic1ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(1)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_StartApplication_StartApplication_Cyclic250ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(250)); /* PRQA S 3417 */ /* MD_Rte_Os */

  return RTE_E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE_AppCom_RWsignal); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_StartApplication_StartApplication_Cyclic1000ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_StartApplication_StartApplication_Cyclic10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_StartApplication_StartApplication_Cyclic1ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_StartApplication_StartApplication_Cyclic250ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE2_Default_BSW_Async_Task_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_Default_BSW_Async_Task_0_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */

}

FUNC(void, RTE_CODE) Rte_InitMemory(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_BswMRteModeRequestPort_requestedMode(BswM_ESH_RunRequest data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_BswM_Provide_BswMRteModeRequestPort_requestedMode = *(&data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_StartApplication_PpTxCtrl_DeSignal_Tx32bit_OnWrite_b2cd4fc2(uint32 data) /* PRQA S 0850, 1505, 3206 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206 */
{
  data = data;

  return RTE_E_OK;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_StartApplication_PpTxData_DeSignal_Tx24bit_Cyclic_85bf3e37(uint32 data) /* PRQA S 0850, 1505, 3206 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206 */
{
  data = data;

  return RTE_E_OK;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_BswM_Provide_BswMRteModeRequestPort_requestedMode;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_StartApplication_PpRxCtrl_DeSignal_Rx16bit_Cyclic_a691adb3(P2VAR(uint16, AUTOMATIC, RTE_STARTAPPLICATION_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 32768U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_StartApplication_PpRxData_DeSignal_Rx15bit_OnWrite_a1df81ad(P2VAR(uint16, AUTOMATIC, RTE_STARTAPPLICATION_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 25U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_StartApplication_PpNvmDataPort_ReadBlock(dtRef_VOID DstPtr) /* PRQA S 0850, 1505, 3206, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 3197 */ /* MD_Rte_3197 */


  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_StartApplication_PpNvmDataPort_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 0850, 1505, 3206, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 3197 */ /* MD_Rte_3197 */


  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_StartApplication_UR_USR_CHNL_3c6d4e43_GetCurrentComMode(P2VAR(ComM_ModeType, AUTOMATIC, RTE_STARTAPPLICATION_APPL_VAR) ComMode) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = ComM_GetCurrentComMode((ComM_UserHandleType)0, ComMode);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_StartApplication_UR_USR_CHNL_3c6d4e43_RequestComMode(ComM_ModeType ComMode) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = ComM_RequestComMode((ComM_UserHandleType)0, ComMode);

  return ret;
}


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_ESH_Mode nextMode) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  BswM_ESH_Mode currentMode;
  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  currentMode = Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
  if (nextMode >= 5U)
  {
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_CallDetReportError(RTE_SWITCH_SERVICE_ID, RTE_E_DET_MODEARGUMENT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  else if (currentMode >= 5U)
  {
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_CallDetReportError(RTE_SWITCH_SERVICE_ID, RTE_E_DET_MODESTATE); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = nextMode;
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(BswM_ESH_Mode, RTE_CODE) Rte_Mode_BswM_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  return Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
}


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     Default_Appl_Init_Task
 * Priority: 45
 * Schedule: NON
 *********************************************************************************************************************/
TASK(Default_Appl_Init_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  StartApplication_Init();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Default_Appl_Task
 * Priority: 5
 * Schedule: NON
 *********************************************************************************************************************/
TASK(Default_Appl_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run_AppCom_RWsignal | Rte_Ev_Run_StartApplication_StartApplication_Cyclic1000ms | Rte_Ev_Run_StartApplication_StartApplication_Cyclic10ms | Rte_Ev_Run_StartApplication_StartApplication_Cyclic1ms | Rte_Ev_Run_StartApplication_StartApplication_Cyclic250ms | Rte_Ev_Run_StartApplication_StartApplication_OnDataRec_RxCtrl | Rte_Ev_Run_StartApplication_StartApplication_OnDataRec_RxData); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Default_Appl_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_AppCom_RWsignal | Rte_Ev_Run_StartApplication_StartApplication_Cyclic1000ms | Rte_Ev_Run_StartApplication_StartApplication_Cyclic10ms | Rte_Ev_Run_StartApplication_StartApplication_Cyclic1ms | Rte_Ev_Run_StartApplication_StartApplication_Cyclic250ms | Rte_Ev_Run_StartApplication_StartApplication_OnDataRec_RxCtrl | Rte_Ev_Run_StartApplication_StartApplication_OnDataRec_RxData)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_StartApplication_StartApplication_Cyclic1000ms) != (EventMaskType)0)
    {
      /* call runnable */
      StartApplication_Cyclic1000ms();
    }

    if ((ev & Rte_Ev_Run_StartApplication_StartApplication_Cyclic10ms) != (EventMaskType)0)
    {
      /* call runnable */
      StartApplication_Cyclic10ms();
    }

    if ((ev & Rte_Ev_Run_StartApplication_StartApplication_Cyclic1ms) != (EventMaskType)0)
    {
      /* call runnable */
      StartApplication_Cyclic1ms();
    }

    if ((ev & Rte_Ev_Run_StartApplication_StartApplication_Cyclic250ms) != (EventMaskType)0)
    {
      /* call runnable */
      StartApplication_Cyclic250ms();
    }

    if ((ev & Rte_Ev_Run_StartApplication_StartApplication_OnDataRec_RxCtrl) != (EventMaskType)0)
    {
      /* call runnable */
      StartApplication_OnDataRec_RxCtrl();
    }

    if ((ev & Rte_Ev_Run_StartApplication_StartApplication_OnDataRec_RxData) != (EventMaskType)0)
    {
      /* call runnable */
      StartApplication_OnDataRec_RxData();
    }

    if ((ev & Rte_Ev_Run_AppCom_RWsignal) != (EventMaskType)0)
    {
      /* call runnable */
      RWsignal();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Default_BSW_Async_Task
 * Priority: 30
 * Schedule: NON
 *********************************************************************************************************************/
TASK(Default_BSW_Async_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_Default_BSW_Async_Task_0_10ms | Rte_Ev_Cyclic2_Default_BSW_Async_Task_0_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Default_BSW_Async_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_Default_BSW_Async_Task_0_10ms | Rte_Ev_Cyclic2_Default_BSW_Async_Task_0_20ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_Async_Task_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      BswM_MainFunction();

      /* call schedulable entity */
      CanSM_MainFunction();

      /* call schedulable entity */
      Can_MainFunction_BusOff();

      /* call schedulable entity */
      Can_MainFunction_Mode();

      /* call schedulable entity */
      Can_MainFunction_Wakeup();
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_Async_Task_0_20ms) != (EventMaskType)0)
    {
      /* call runnable */
      ComM_MainFunction_0();
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_Async_Task_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Com_MainFunctionRx();

      /* call schedulable entity */
      Com_MainFunctionTx();

      /* call runnable */
      EcuM_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0781:  MISRA rule: 5.6
     Reason:     The name is being used as a structure/union member as well as being a label, tag or ordinary identifier.
                 The compliance to this rule is under user's control.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects leading to the violation.

   MD_Rte_3197:  MISRA rule: -
     Reason:     The variable is not written by the code in all possible code variants. Due to this, the variable is initialized.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: -
     Reason:     The parameter's are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 7.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
