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
 *            Module: Xcp
 *           Program: MSR_Vector_SLP4
 *          Customer: Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC234LP
 *    License Scope : The usage is restricted to CBD1700982_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanXcp_Lcfg.c
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

	

#define CANXCP_LCFG_SOURCE

#include "CanXcp_Lcfg.h"

#include "CanIf.h" /* for CanIf symbolic name value defines */

 

/* -----------------------------------------------------------------------------
    &&&~ CanXcp_PduField - 
 ----------------------------------------------------------------------------- */
#define CANXCP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

CONST(CanXcp_XcpPduType, CANXCP_PBCFG) CanXcp_PduIdField[CANXCP_NUMBER_OF_CHANNELS] =
{
  {
    XcpConf_XcpRxPdu_msg_XCP_Request_MyECU_oCAN_3abd61be, 
    XcpConf_XcpTxPdu_msg_XCP_Response_MyECU_oCAN_3abd61be, 
    CanIfConf_CanIfTxPduCfg_msg_XCP_Response_MyECU_oCAN_Tx_3abd61be
  } /*  CanXcpRxPduId CanXcpTxPduId CanIfTxPduId  */ 
}; 

/* -----------------------------------------------------------------------------
    &&&~ CanXcp_Config - 
 ----------------------------------------------------------------------------- */

CONST(CanXcp_ConfigType, CANXCP_PBCFG) CanXcp_Config = 
{
  CanXcp_PduIdField,
  NULL_PTR,
  1
};

#define CANXCP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


