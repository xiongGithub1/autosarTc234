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
 *              File: Os_Lcfg.h
 *   Generation Time: 2026-05-30 10:09:07
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

#if !defined (OS_LCFG_H)                                                             /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_Default_Appl_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Default_Appl_Init_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_APPL_INIT_TASK_CODE) Os_Task_Default_Appl_Init_Task(void);

# define OS_STOP_SEC_Default_Appl_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Default_Appl_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Default_Appl_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_APPL_TASK_CODE) Os_Task_Default_Appl_Task(void);

# define OS_STOP_SEC_Default_Appl_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Default_BSW_Async_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Default_BSW_Async_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_BSW_ASYNC_TASK_CODE) Os_Task_Default_BSW_Async_Task(void);

# define OS_STOP_SEC_Default_BSW_Async_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Default_BSW_Sync_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Default_BSW_Sync_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_BSW_SYNC_TASK_CODE) Os_Task_Default_BSW_Sync_Task(void);

# define OS_STOP_SEC_Default_BSW_Sync_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Default_Background_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Default_Background_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_BACKGROUND_TASK_CODE) Os_Task_Default_Background_Task(void);

# define OS_STOP_SEC_Default_Background_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Default_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Default_Init_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_INIT_TASK_CODE) Os_Task_Default_Init_Task(void);

# define OS_STOP_SEC_Default_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Default_RTE_Mode_switch_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Default_RTE_Mode_switch_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_RTE_MODE_SWITCH_TASK_CODE) Os_Task_Default_RTE_Mode_switch_Task(void);

# define OS_STOP_SEC_Default_RTE_Mode_switch_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CanIsr_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  CanIsr_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISR_0_CODE) Os_Isr_CanIsr_0(void);

# define OS_STOP_SEC_CanIsr_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
