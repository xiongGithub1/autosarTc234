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
 *              File: Os_Stack_Lcfg.c
 *   Generation Time: 2026-05-30 10:09:08
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

#define OS_STACK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Stack_Cfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Stack.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


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

#define OS_START_SEC_STACK_DEFAULT_APPL_TASK_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Task stack: Default_Appl_Task */
/* User: [Default_Appl_Task] */
OS_STACK_DECLARE(OsCfg_Stack_Default_Appl_Task_Dyn, OS_CFG_SIZE_DEFAULT_APPL_TASK_STACK);

#define OS_STOP_SEC_STACK_DEFAULT_APPL_TASK_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_DEFAULT_BSW_ASYNC_TASK_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Task stack: Default_BSW_Async_Task */
/* User: [Default_BSW_Async_Task] */
OS_STACK_DECLARE(OsCfg_Stack_Default_BSW_Async_Task_Dyn, OS_CFG_SIZE_DEFAULT_BSW_ASYNC_TASK_STACK);

#define OS_STOP_SEC_STACK_DEFAULT_BSW_ASYNC_TASK_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core error stack: OsCore_Core0_Error */
/* User: [ErrorHook_OsCore_Core0, OsCore_Core0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Error_Dyn, OS_CFG_SIZE_OSCORE_CORE0_ERROR_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core init stack: OsCore_Core0_Init */
/* User: [OsCore_Core0, Os_CoreInitHook_OsCore_Core0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Init_Dyn, OS_CFG_SIZE_OSCORE_CORE0_INIT_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ISR core global stack: OsCore_Core0_Isr_Core */
/* User: [CanIsr_0, CounterIsr_SystemTimer] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE_CORE0_ISR_CORE_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core kernel stack: OsCore_Core0_Kernel */
/* User: [OsCore_Core0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Kernel_Dyn, OS_CFG_SIZE_OSCORE_CORE0_KERNEL_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio0 */
/* User: [Default_Init_Task] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio0_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO0_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio1 */
/* User: [Default_Appl_Init_Task] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio1_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO1_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio2 */
/* User: [Default_BSW_Sync_Task] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio2_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO2_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio4 */
/* User: [Default_RTE_Mode_switch_Task] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio4_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO4_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio6 */
/* User: [Default_Background_Task] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio6_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO6_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio7 */
/* User: [IdleTask_OsCore_Core0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio7_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO7_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Stack configuration data: Default_Appl_Task */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Default_Appl_Task =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_Default_Appl_Task_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Default_Appl_Task_Dyn)
};

/*! Stack configuration data: Default_BSW_Async_Task */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Default_BSW_Async_Task =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_Default_BSW_Async_Task_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Default_BSW_Async_Task_Dyn)
};

/*! Stack configuration data: OsCore_Core0_Error */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Error =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Error_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Error_Dyn)
};

/*! Stack configuration data: OsCore_Core0_Init */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Init =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Init_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Init_Dyn)
};

/*! Stack configuration data: OsCore_Core0_Isr_Core */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Isr_Core =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Isr_Core_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Isr_Core_Dyn)
};

/*! Stack configuration data: OsCore_Core0_Kernel */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Kernel =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Kernel_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Kernel_Dyn)
};

/*! Stack configuration data: OsCore_Core0_Task_Prio0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio0_Dyn)
};

/*! Stack configuration data: OsCore_Core0_Task_Prio1 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio1 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio1_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio1_Dyn)
};

/*! Stack configuration data: OsCore_Core0_Task_Prio2 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio2 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio2_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio2_Dyn)
};

/*! Stack configuration data: OsCore_Core0_Task_Prio4 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio4 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio4_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio4_Dyn)
};

/*! Stack configuration data: OsCore_Core0_Task_Prio6 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio6 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio6_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio6_Dyn)
};

/*! Stack configuration data: OsCore_Core0_Task_Prio7 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio7 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio7_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_Core0_Task_Prio7_Dyn)
};


#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Stack_Lcfg.c
 *********************************************************************************************************************/
