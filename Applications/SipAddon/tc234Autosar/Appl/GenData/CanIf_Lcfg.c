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
 *            Module: CanIf
 *           Program: MSR_Vector_SLP4
 *          Customer: Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC234LP
 *    License Scope : The usage is restricted to CBD1700982_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Lcfg.c
 *   Generation Time: 2026-06-17 20:29:11
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

#define CANIF_LCFG_SOURCE

/* PRQA S 0850 EOF */ /* MD_MSR_19.8 */
/* PRQA S 0857 EOF */ /* MD_CanIf_1.1_NumberOfMacroDefinitions */
/* PRQA S 0779 EOF */ /* MD_CanIf_5.1 */
/* PRQA S 0777 EOF */ /* MD_CanIf_5.1 */
/* PRQA S 1330, 1334 EOF */ /* MD_CanIf_16.4, MD_CanIf_16.4 */

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/ 

#include "CanIf_Cfg.h"

 /*  CanNm Header Files  */ 
#include "CanNm_Cfg.h"
#include "CanNm_Cbk.h"
 /*  PduR Header Files  */ 
#include "PduR_Cfg.h"
#include "PduR_CanIf.h"
 /*  CanSM Header Files  */ 
#include "CanSM_Cbk.h"

#define CANIF_START_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  \var  Prototypes of callback functions
**********************************************************************************************************************/

/** 
  \brief  Tx confirmation functions.
*/



/** 
  \brief  Rx indication functions.
*/





#define CANIF_STOP_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = CanSM_ControllerBusOff;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = CanSM_ControllerModeIndication;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element          Description
  CtrlStatesIdx    the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst       "First" PDU mapped to mailbox.
  PduIdLast        "Last" PDU mapped to mailbox.
  MailBoxType      Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[2] = {
    /* Index    CtrlStatesIdx                                                 PduIdFirst                           PduIdLast                           MailBoxType                    Referable Keys */
  { /*     0 */           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_e98c47e6 */,         0U  /* Unused, TxPduId 0 */,        0U  /* Unused, TxPduId 2 */, CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN00_e98c47e6_Tx] */
  { /*     1 */           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_e98c47e6 */,         1U  /* RxPduId */          ,        1U  /* RxPduId  */         , CANIF_RxBasicCANMailbox }   /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN00_e98c47e6_Rx_Std] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[3] = {
    /* Index    RxIndicationFct                                               RxIndicationLayout                                                            Referable Keys */
  { /*     0 */  { (CanIf_SimpleRxIndicationFctType)NULL_PTR }              , CanIf_SimpleRxIndicationLayout    /* PRQA S 313 */ /* MD_CanIf_11.1 */ },  /* [NULL_PTR] */
  { /*     1 */  { (CanIf_SimpleRxIndicationFctType)CanNm_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 313 */ /* MD_CanIf_11.1 */ },  /* [CanNm_RxIndication] */
  { /*     2 */  { (CanIf_SimpleRxIndicationFctType)PduR_CanIfRxIndication }, CanIf_AdvancedRxIndicationLayout  /* PRQA S 313 */ /* MD_CanIf_11.1 */ }   /* [PduR_CanIfRxIndication] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  Dlc                       Data length code.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[2] = {
    /* Index    RxPduCanId                                                                           RxPduMask                                                           UpperPduId                                              Dlc  RxIndicationFctListIdx                                      Comment                                                                     Referable Keys */
  { /*     0 */    0x0600U  /* Lower CanId of range: MyECU_5faa4e95_NMCanIDRange, 2.0- or FD-PDU */,   0x663FU  /* Upper CanId of range: MyECU_5faa4e95_NMCanIDRange */, CanNmConf_CanNmRxPdu_CAN00_CAN_17d0077e_RxPdu_2d241a48,  8U,                    1UL  /* CanNm_RxIndication */     },  /* [PDU: MyECU_5faa4e95_NMCanIDRange, Lower CanId of range: 0x600] */  /* [CanIfConf_CanIfRxPduCfg_MyECU_5faa4e95_NMCanIDRange] */
  { /*     1 */    0x0210U  /* msg_Receive_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */                   ,   0x07FFU  /* msg_Receive_oCAN00_Rx_3abd61be */                   , PduRConf_PduRSrcPdu_SRC_Can_PT_msg_Receive_0fb271d2   ,  1U,                    2UL  /* PduR_CanIfRxIndication */ }   /* [PDU: msg_Receive_oCAN00_Rx_3abd61be, CanId: 0x210]             */  /* [CanIfConf_CanIfRxPduCfg_msg_Receive_oCAN00_Rx_3abd61be] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TrcvModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TrcvModeIndicationFctType, CANIF_CONST) CanIf_TrcvModeIndicationFctPtr = CanSM_TransceiverModeIndication;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TrcvToCtrlMap
**********************************************************************************************************************/
/** 
  \var    CanIf_TrcvToCtrlMap
  \brief  Indirection table: logical transceiver index to CAN controller index.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TrcvToCtrlMapType, CANIF_CONST) CanIf_TrcvToCtrlMap[1] = {
  /* Index     TrcvToCtrlMap                                          */
  /*     0 */             0U  /* CAN controller handle ID (upper) */
};
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[2] = {
  /* Index     TxConfirmationFctList                      Referable Keys */
  /*     0 */ (CanIf_TxConfirmationFctType)NULL_PTR ,  /* [NULL_PTR] */
  /*     1 */ CanNm_TxConfirmation                     /* [CanNm_TxConfirmation] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  Dlc                         Data length code.
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[3] = {
    /* Index    CanId    UpperLayerTxPduId                                        CtrlStatesIdx                                                 Dlc  MailBoxConfigIdx                                                           TxConfirmationFctListIdx                                    Comment                                              Referable Keys */
  { /*     0 */ 0x0600U, CanNmConf_CanNmTxPdu_msg_NM_MyECU_oCAN00_TxPdu_3abd61be,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_e98c47e6 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_e98c47e6_Tx */,                      1UL  /* CanNm_TxConfirmation */ },  /* [PDU: msg_NM_MyECU_oCAN00_Tx_3abd61be]   */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/msg_NM_MyECU_oCAN00_Tx_3abd61be] */
  { /*     1 */ 0x0511U, PduRConf_PduRDestPdu_DST_Can_PT_msg_MyECU_Lamp_0fb271d2,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_e98c47e6 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_e98c47e6_Tx */,                      0UL  /* NULL_PTR */             },  /* [PDU: msg_MyECU_Lamp_oCAN00_Tx_3abd61be] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/msg_MyECU_Lamp_oCAN00_Tx_3abd61be] */
  { /*     2 */ 0x0200U, PduRConf_PduRDestPdu_DST_Can_PT_msg_Transmit_0fb271d2  ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_e98c47e6 */,  1U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_e98c47e6_Tx */,                      0UL  /* NULL_PTR */             }   /* [PDU: msg_Transmit_oCAN00_Tx_3abd61be]   */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/msg_Transmit_oCAN00_Tx_3abd61be] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_WakeUpConfig
  \brief  Wake-up source configuration
  \details
  Element                Description
  Controller             CAN controller handle ID
  WakeUpSource           Wake-up source identifier
  WakeUpTargetAddress    Logical handle ID of target (CAN controller / transceiver)
  WakeUpTargetModule     Target for wake-up source: CAN controller / transceiver
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_WakeUpConfigType, CANIF_CONST) CanIf_WakeUpConfig[1] = {
    /* Index    Controller  WakeUpSource  WakeUpTargetAddress  WakeUpTargetModule              Comment */
  { /*     0 */         0U,         32UL,                  0U, CANIF_WAKEUPREQUEST_TRCV }   /* [Only CanTrcvWakeupSource ] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element     Description
  CtrlMode    Controller mode.
  PduMode     PDU mode state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/Can/CT_CAN00_e98c47e6] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



