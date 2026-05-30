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
 *            Module: PduR
 *           Program: MSR_Vector_SLP4
 *          Customer: Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC234LP
 *    License Scope : The usage is restricted to CBD1700982_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Cfg.h
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

#if !defined (PDUR_CFG_H)
# define PDUR_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Types.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef PDUR_USE_DUMMY_FUNCTIONS
#define PDUR_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef PDUR_USE_DUMMY_STATEMENT
#define PDUR_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef PDUR_DUMMY_STATEMENT
#define PDUR_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT_CONST
#define PDUR_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef PDUR_ATOMIC_VARIABLE_ACCESS
#define PDUR_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef PDUR_PROCESSOR_TC234
#define PDUR_PROCESSOR_TC234
#endif
#ifndef PDUR_COMP_TASKING
#define PDUR_COMP_TASKING
#endif
#ifndef PDUR_GEN_GENERATOR_MSR
#define PDUR_GEN_GENERATOR_MSR
#endif
#ifndef PDUR_CPUTYPE_BITORDER_LSB2MSB
#define PDUR_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#define PDUR_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_LINKTIME
#define PDUR_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef PDUR_CONFIGURATION_VARIANT
#define PDUR_CONFIGURATION_VARIANT PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef PDUR_POSTBUILD_VARIANT_SUPPORT
#define PDUR_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



#define PDUR_DEV_ERROR_DETECT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSafeBswChecks] || /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */
#define PDUR_DEV_ERROR_REPORT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */

#define PDUR_METADATA_SUPPORT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRMetaDataSupport] */
#define PDUR_VERSION_INFO_API STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRVersionInfoApi] */

 #define PDUR_ERROR_NOTIFICATION STD_OFF


#define PduR_PBConfigIdType uint32

#define PDUR_INVALID_VARARRAYIDX                                      ((uint16)0xFFFF) /**< Invalid VarArray element */

 /*  DET Error define list  */ 
#define PDUR_FCT_CANIFRXIND 0x01U 
#define PDUR_FCT_CANIFTX 0x09U 
#define PDUR_FCT_CANIFTXCFM 0x02U 
#define PDUR_FCT_CANNMRXIND 0x11U 
#define PDUR_FCT_CANNMTX 0x19U 
#define PDUR_FCT_CANNMTXCFM 0x12U 
#define PDUR_FCT_CANNMTT 0x13U 
#define PDUR_FCT_CANTPRXIND 0x05U 
#define PDUR_FCT_CANTPTX 0x09U 
#define PDUR_FCT_CANTPTXCFM 0x08U 
#define PDUR_FCT_CANTPSOR 0x06U 
#define PDUR_FCT_CANTPCPYRX 0x04U 
#define PDUR_FCT_CANTPCPYTX 0x07U 
#define PDUR_FCT_COMTX 0x89U 
#define PDUR_FCT_DCMTX 0x99U 
#define PDUR_FCT_DCMCTX 0x9AU 
#define PDUR_FCT_DCMCTX 0x9AU 
#define PDUR_FCT_CDD_COMTX 0xC9U 
 /*   PduR_CanIfIfRxIndication  PduR_CanIfTransmit  PduR_CanIfTxConfirmation  PduR_CanNmIfRxIndication  PduR_CanNmTransmit  PduR_CanNmTxConfirmation  PduR_CanNmTriggerTransmit  PduR_CanTpTpRxIndication  PduR_CanTpTransmit  PduR_CanTpTxConfirmation  PduR_CanTpStartOfReception  PduR_CanTpCopyRxData  PduR_CanTpCopyTxData  PduR_ComTransmit  PduR_DcmTransmit  PduR_DcmCancelTransmit  PduR_DcmCancelTransmit  PduR_Cdd_ComTransmit  */ 



/**
 * \defgroup PduRHandleIdsIfRxDest Handle IDs of handle space IfRxDest.
 * \brief Communication interface Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_RxCycle100_0_346f2748     1
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_RxCycle500_20_346f2748    2
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_RxCycle_E2eProf1C_500_10_346f2748 3
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_RxEvent_20_346f2748       4
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_StartAppl_Rx_MyECU_346f2748 5
#define PduRConf_PduRDestPdu_PduRDestPdu                              6
#define PduRConf_PduRDestPdu_PduRDestPdu_2                            0
/**\} */

/**
 * \defgroup PduRHandleIdsIfRxSrc Handle IDs of handle space IfRxSrc.
 * \brief Communication interface Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu                                5
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2                              6
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_RxCycle100_0_346f2748      0
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_RxCycle500_20_346f2748     1
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_RxCycle_E2eProf1C_500_10_346f2748 2
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_RxEvent_20_346f2748        3
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_StartAppl_Rx_MyECU_346f2748 4
/**\} */

/**
 * \defgroup PduRHandleIdsIfTpTxSrc Handle IDs of handle space IfTpTxSrc.
 * \brief Communication interface and transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1                              8
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_StartAppl_Tx_MyECU_346f2748 0
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_TxCycle10_0_346f2748       1
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_TxCycle1000_10_346f2748    2
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_TxCycle_E2eProf1C_500_30_346f2748 3
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_TxEvent_10_346f2748        4
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_diag_Response_MyECU_346f2748 5
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_diag_Uudt_Response_MyECU_346f2748 6
#define PduRConf_PduRSrcPdu_SRC_Can_msg_nm_MyECU_oCAN_3abd61be        7
/**\} */

/**
 * \defgroup PduRHandleIdsIfTxDest Handle IDs of handle space IfTxDest.
 * \brief Communication interface Tx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_StartAppl_Tx_MyECU_346f2748 1
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_TxCycle10_0_346f2748      2
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_TxCycle1000_10_346f2748   3
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_TxCycle_E2eProf1C_500_30_346f2748 4
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_TxEvent_10_346f2748       5
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_diag_Uudt_Response_MyECU_346f2748 7
#define PduRConf_PduRDestPdu_DST_Can_msg_nm_MyECU_oCAN_3abd61be       0
#define PduRConf_PduRDestPdu_PduRDestPdu_1                            6
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxDest Handle IDs of handle space TpRxDest.
 * \brief Transport protocol Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_diag_RequestGlobal_346f2748 0
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_diag_Request_MyECU_346f2748 1
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxSrc Handle IDs of handle space TpRxSrc.
 * \brief Transport protocol Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_diag_RequestGlobal_346f2748 0
#define PduRConf_PduRSrcPdu_SRC_Can_PT_msg_diag_Request_MyECU_346f2748 1
/**\} */

/**
 * \defgroup PduRHandleIdsTpTxDest Handle IDs of handle space TpTxDest.
 * \brief Transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DST_Can_PT_msg_diag_Response_MyECU_346f2748 0
/**\} */


/* User Config File Start */

/* User Config File End */


/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* PDUR_CFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Cfg.h
 *********************************************************************************************************************/

