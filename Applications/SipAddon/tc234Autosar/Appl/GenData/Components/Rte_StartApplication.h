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
 *          File:  Rte_StartApplication.h
 *        Config:  TsiStandard.dpa
 *   ECU-Project:  MyECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700982 for Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *
 *   Description:  Application header file for SW-C <StartApplication>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_STARTAPPLICATION_H
# define _RTE_STARTAPPLICATION_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_StartApplication_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpRxCtrl_DeSignal_Rx16bit_Cyclic_a691adb3 (32768U)
#  define Rte_InitValue_PpRxData_DeSignal_Rx15bit_OnWrite_a1df81ad (25U)
#  define Rte_InitValue_PpTxCtrl_DeSignal_Tx32bit_OnWrite_b2cd4fc2 (31U)
#  define Rte_InitValue_PpTxData_DeSignal_Tx24bit_Cyclic_85bf3e37 (0U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint16, RTE_VAR_NOINIT) Rte_Irv_StartApplication_IrvOccuranceCounterDid; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_StartApplication_PpRxCtrl_DeSignal_Rx16bit_Cyclic_a691adb3(P2VAR(uint16, AUTOMATIC, RTE_STARTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_StartApplication_PpRxData_DeSignal_Rx15bit_OnWrite_a1df81ad(P2VAR(uint16, AUTOMATIC, RTE_STARTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_StartApplication_PpTxCtrl_DeSignal_Tx32bit_OnWrite_b2cd4fc2(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_StartApplication_PpTxData_DeSignal_Tx24bit_Cyclic_85bf3e37(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_StartApplication_PpNvmDataPort_ReadBlock(dtRef_VOID DstPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_StartApplication_PpNvmDataPort_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_StartApplication_UR_USR_CHNL_3c6d4e43_GetCurrentComMode(P2VAR(ComM_ModeType, AUTOMATIC, RTE_STARTAPPLICATION_APPL_VAR) ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_StartApplication_UR_USR_CHNL_3c6d4e43_RequestComMode(ComM_ModeType ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_PpRxCtrl_DeSignal_Rx16bit_Cyclic_a691adb3 Rte_Read_StartApplication_PpRxCtrl_DeSignal_Rx16bit_Cyclic_a691adb3
#  define Rte_Read_PpRxData_DeSignal_Rx15bit_OnWrite_a1df81ad Rte_Read_StartApplication_PpRxData_DeSignal_Rx15bit_OnWrite_a1df81ad


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpTxCtrl_DeSignal_Tx32bit_OnWrite_b2cd4fc2 Rte_Write_StartApplication_PpTxCtrl_DeSignal_Tx32bit_OnWrite_b2cd4fc2
#  define Rte_Write_PpTxData_DeSignal_Tx24bit_Cyclic_85bf3e37 Rte_Write_StartApplication_PpTxData_DeSignal_Tx24bit_Cyclic_85bf3e37


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ECUM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_ECUM_APPL_CODE) EcuM_SelectShutdownTarget(EcuM_StateType targetState, EcuM_ModeType resetSleepMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_ECUM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_EcuM_ShutdownTarget_SelectShutdownTarget EcuM_SelectShutdownTarget
#  define Rte_Call_PpNvmDataPort_ReadBlock Rte_Call_StartApplication_PpNvmDataPort_ReadBlock
#  define Rte_Call_PpNvmDataPort_WriteBlock Rte_Call_StartApplication_PpNvmDataPort_WriteBlock
#  define Rte_Call_UR_USR_CHNL_3c6d4e43_GetCurrentComMode Rte_Call_StartApplication_UR_USR_CHNL_3c6d4e43_GetCurrentComMode
#  define Rte_Call_UR_USR_CHNL_3c6d4e43_RequestComMode Rte_Call_StartApplication_UR_USR_CHNL_3c6d4e43_RequestComMode


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_StartApplication_Cyclic250ms_IrvOccuranceCounterDid() \
  Rte_Irv_StartApplication_IrvOccuranceCounterDid
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_StartApplication_OnDataRec_RxData_IrvOccuranceCounterDid() \
  Rte_Irv_StartApplication_IrvOccuranceCounterDid
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvWrite_StartApplication_OnDataRec_RxData_IrvOccuranceCounterDid(data) \
  (Rte_Irv_StartApplication_IrvOccuranceCounterDid = (data))
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_COM_TxSigValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_NM_ActiveComMUsers; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_TxCtrlSigValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_TxDataSigValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_COM_RxSigValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_XcpPimDownload; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_XcpPimUpload; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(EnumActiveComponentType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_ActiveComponent; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_DIAG_LastRxData; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(EnumMEM_BlockStateType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_MEM_BlockState; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_MEM_DataBuffer; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_NM_ActiveChannelHasFullComRequest; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_NM_ActiveComMChannel; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(EnumNM_ApplStateType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_NM_ApplState; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_NM_BusSleepModeTimer; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StartApplication_Uptime; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_COM_TxSigValue0() \
  (&Rte_StartApplication_COM_TxSigValue0) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_NM_ActiveComMUsers() \
  (&Rte_StartApplication_NM_ActiveComMUsers) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TxCtrlSigValue() \
  (&Rte_StartApplication_TxCtrlSigValue) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TxDataSigValue() \
  (&Rte_StartApplication_TxDataSigValue) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_COM_RxSigValue0() \
  (&Rte_StartApplication_COM_RxSigValue0) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_XcpPimDownload() \
  (&Rte_StartApplication_XcpPimDownload) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_XcpPimUpload() \
  (&Rte_StartApplication_XcpPimUpload) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_ActiveComponent() \
  (&Rte_StartApplication_ActiveComponent) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DIAG_LastRxData() \
  (&Rte_StartApplication_DIAG_LastRxData) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MEM_BlockState() \
  (&Rte_StartApplication_MEM_BlockState) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MEM_DataBuffer() \
  (&Rte_StartApplication_MEM_DataBuffer) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_NM_ActiveChannelHasFullComRequest() \
  (&Rte_StartApplication_NM_ActiveChannelHasFullComRequest) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_NM_ActiveComMChannel() \
  (&Rte_StartApplication_NM_ActiveComMChannel) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_NM_ApplState() \
  (&Rte_StartApplication_NM_ApplState) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_NM_BusSleepModeTimer() \
  (&Rte_StartApplication_NM_BusSleepModeTimer) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Uptime() \
  (&Rte_StartApplication_Uptime) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define StartApplication_START_SEC_CODE
# include "StartApplication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_StartApplication_Cyclic1000ms StartApplication_Cyclic1000ms
#  define RTE_RUNNABLE_StartApplication_Cyclic10ms StartApplication_Cyclic10ms
#  define RTE_RUNNABLE_StartApplication_Cyclic1ms StartApplication_Cyclic1ms
#  define RTE_RUNNABLE_StartApplication_Cyclic250ms StartApplication_Cyclic250ms
#  define RTE_RUNNABLE_StartApplication_Init StartApplication_Init
#  define RTE_RUNNABLE_StartApplication_MEM_JobFinished StartApplication_MEM_JobFinished
#  define RTE_RUNNABLE_StartApplication_OnDataRec_RxCtrl StartApplication_OnDataRec_RxCtrl
#  define RTE_RUNNABLE_StartApplication_OnDataRec_RxData StartApplication_OnDataRec_RxData
# endif

FUNC(void, StartApplication_CODE) StartApplication_Cyclic1000ms(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, StartApplication_CODE) StartApplication_Cyclic10ms(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, StartApplication_CODE) StartApplication_Cyclic1ms(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, StartApplication_CODE) StartApplication_Cyclic250ms(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, StartApplication_CODE) StartApplication_Init(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, StartApplication_CODE) StartApplication_MEM_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, StartApplication_CODE) StartApplication_OnDataRec_RxCtrl(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, StartApplication_CODE) StartApplication_OnDataRec_RxData(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define StartApplication_STOP_SEC_CODE
# include "StartApplication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_PiEcuM_ShutdownTarget_E_NOT_OK (1U)

#  define RTE_E_PiNvmDataPort_E_NOT_OK (1U)

#  define RTE_E_PiUR_USR_CHNL_3c6d4e43_E_MODE_LIMITATION (2U)

#  define RTE_E_PiUR_USR_CHNL_3c6d4e43_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_STARTAPPLICATION_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
