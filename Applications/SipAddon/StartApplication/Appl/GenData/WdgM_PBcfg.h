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
 *            Module: WdgM
 *           Program: MSR_Vector_SLP4
 *          Customer: Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC234LP
 *    License Scope : The usage is restricted to CBD1700982_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgM_PBcfg.h
 *   Generation Time: 2026-05-30 10:09:06
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

#if !defined (WDGM_PBCFG_H)
# define WDGM_PBCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "WdgM_Cfg.h"


/**********************************************************************************************************************
 *  VERSION INFORMATION AND CHECK
 *********************************************************************************************************************/

#define WDGM_PBCFG_MAJOR_VERSION (2u) 
#define WDGM_PBCFG_MINOR_VERSION (1u) 
#define WDGM_PBCFG_PATCH_VERSION (1u) 

/* Check the version of WdgM Cfg header file */
#if ( (WDGM_CFG_TYPES_HDR_MAJOR_VERSION != (5u)) \
   || (WDGM_CFG_TYPES_HDR_MINOR_VERSION != (2u)) )
# error "Version numbers of WdgM_PBcfg.h and WdgM_Cfg.h are inconsistent!"
#endif

# define WDGM_NR_OF_CHECKPOINTS           (1u) 
# define WDGM_NR_OF_ENTITIES              (1u) 
# define WDGM_NR_OF_ALLOWED_CALLERS       (1u) 
# define WDGM_NR_OF_GLOBAL_TRANSITIONS    (0u) 
# define WDGM_NR_OF_LOCAL_TRANSITIONS     (0u) 
# define WDGM_NR_OF_WATCHDOGS_CORE0       (1u) 
# define WDGM_NR_OF_TRIGGER_MODES_CORE0   (1u) 

/* Checkpoints for supervised entity 'WdgMSupervisedEntity_StartApplication' */ 
# define WdgMConf_WdgMCheckpoint_WdgMCheckpoint_StartApplication (0u) 
 

# define WdgMConf_WdgMSupervisedEntity_WdgMSupervisedEntity_StartApplication (0u) 


#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0; 

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define WDGM_START_SEC_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* 
 * No status reporting enabled. 
 * 
 * WdgMStatusReportingMechanism is configured to WDGM_USE_NO_STATUS_REPORTING. 
 * 
 * To enable status reporting set WdgMStatusReportingMechanism to WDGM_USE_NOTIFICATIONS or WDGM_USE_MODE_SWITCH_PORTS. 
 */ 

#define WDGM_STOP_SEC_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* WDGM_PBCFG_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgM_PBcfg.h
 *********************************************************************************************************************/

