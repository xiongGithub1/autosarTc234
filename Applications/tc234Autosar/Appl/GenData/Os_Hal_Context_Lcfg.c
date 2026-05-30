/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC234LP
 *    License Scope : The usage is restricted to CBD1700982_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Context_Lcfg.c
 *   Generation Time: 2026-05-30 09:53:13
 *           Project: TsiStandard - Version 1
 *          Delivery: CBD1700982_D00
 *      Tool Version: DaVinci Configurator (beta) 5.16.31 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_HAL_CONTEXT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os hal dependencies */
#include "Os_Hal_Core.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore_Core0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore_Core0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore_Core0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore_Core0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_Core0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_Core0_Isr_Level2_Dyn;

/*! HAL dynamic task context data: Default_Appl_Init_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Appl_Init_Task_Dyn;

/*! HAL dynamic task context data: Default_Appl_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Appl_Task_Dyn;

/*! HAL dynamic task context data: Default_BSW_Async_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_BSW_Async_Task_Dyn;

/*! HAL dynamic task context data: Default_BSW_Sync_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_BSW_Sync_Task_Dyn;

/*! HAL dynamic task context data: Default_Background_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Background_Task_Dyn;

/*! HAL dynamic task context data: Default_Init_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Dyn;

/*! HAL dynamic task context data: Default_RTE_Mode_switch_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_RTE_Mode_switch_Task_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore_Core0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore_Core0_Dyn;

/*! HAL exception context data: OsCore_Core0 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_Core0_ExceptionContext;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore_Core0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore_Core0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Init_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Init_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .IntStatus        = */ ((uint32)10<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL hook context configuration data: ErrorHook_OsCore_Core0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore_Core0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Error_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Error_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperStatusHook,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .IntStatus        = */ ((uint32)10<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CanIsr_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Isr_Core_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_CanIsr_0,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .IntStatus        = */ ((uint32)10<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Isr_Core_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerPfrtIsr,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .IntStatus        = */ ((uint32)10<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Default_Appl_Init_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Appl_Init_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio1_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio1_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Default_Appl_Init_Task,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Default_Appl_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Appl_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Default_Appl_Task_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Default_Appl_Task_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Default_Appl_Task,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Default_BSW_Async_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_BSW_Async_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Default_BSW_Async_Task_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Default_BSW_Async_Task_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Default_BSW_Async_Task,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Default_BSW_Sync_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_BSW_Sync_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio2_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio2_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Default_BSW_Sync_Task,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Default_Background_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Background_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio6_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio6_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Default_Background_Task,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Default_Init_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio0_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio0_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Default_Init_Task,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Default_RTE_Mode_switch_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_RTE_Mode_switch_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio4_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio4_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Default_RTE_Mode_switch_Task,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: IdleTask_OsCore_Core0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore_Core0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio7_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio7_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL kernel stack configuration data: OsCore_Core0_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore_Core0_Kernel =
{
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Kernel_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Kernel_Dyn)+1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for HAL exception context. */
CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1] =
{
  &OsCfg_Hal_Context_OsCore_Core0_ExceptionContext,
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_Lcfg.c
 *********************************************************************************************************************/
