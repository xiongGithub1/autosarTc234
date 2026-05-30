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
 *            Module: Cdd
 *           Program: MSR_Vector_SLP4
 *          Customer: Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC234LP
 *    License Scope : The usage is restricted to CBD1700982_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Cdd_Com_Cbk.h
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



#if !defined (CDD_COM_CBK_H)
# define CDD_COM_CBK_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "ComStack_Types.h"



/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef CDD_COM_USE_DUMMY_FUNCTIONS
#define CDD_COM_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef CDD_COM_USE_DUMMY_STATEMENT
#define CDD_COM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef CDD_COM_DUMMY_STATEMENT
#define CDD_COM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef CDD_COM_DUMMY_STATEMENT_CONST
#define CDD_COM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef CDD_COM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CDD_COM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CDD_COM_ATOMIC_VARIABLE_ACCESS
#define CDD_COM_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CDD_COM_PROCESSOR_TC234
#define CDD_COM_PROCESSOR_TC234
#endif
#ifndef CDD_COM_COMP_TASKING
#define CDD_COM_COMP_TASKING
#endif
#ifndef CDD_COM_GEN_GENERATOR_MSR
#define CDD_COM_GEN_GENERATOR_MSR
#endif
#ifndef CDD_COM_CPUTYPE_BITORDER_LSB2MSB
#define CDD_COM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef CDD_COM_CONFIGURATION_VARIANT_PRECOMPILE
#define CDD_COM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CDD_COM_CONFIGURATION_VARIANT_LINKTIME
#define CDD_COM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CDD_COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CDD_COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CDD_COM_CONFIGURATION_VARIANT
#define CDD_COM_CONFIGURATION_VARIANT CDD_COM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CDD_COM_POSTBUILD_VARIANT_SUPPORT
#define CDD_COM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define CDD_COM_COMIF  STD_OFF
#define CDD_COM_COMIF_RX  STD_OFF
#define CDD_COM_COMIF_TX  STD_OFF
#define CDD_COM_COMIF_TRIGGERTRANSMIT  STD_OFF

#define CDD_COM_PDUR_UL_COMIF  STD_ON
#define CDD_COM_PDUR_UL_COMIF_TRIGGERTRANSMIT  STD_OFF

#define CDD_COM_PDUR_UL_COMTP  STD_OFF

#define CDD_COM_PDUR_LL_COMIF  STD_OFF
#define CDD_COM_PDUR_LL_COMIF_TRIGGERTRANSMIT  STD_OFF

#define CDD_COM_PDUR_LL_COMTP  STD_OFF

#define CDD_COM_SOADUL_COMIF_RX  STD_OFF
#define CDD_COM_SOADUL_COMIF_TRIGGERTRANSMIT  STD_OFF
#define CDD_COM_SOADUL_COMIF_TXCONFIRMATION   STD_OFF

#define CDD_COM_SOADUL_COMTP_RX  STD_OFF
#define CDD_COM_SOADUL_COMTP_TX  STD_OFF





/**
 * \defgroup Cdd_ComHandleIdsPduRUpperLayerRx Handle IDs of handle space PduRUpperLayerRx.
 * \brief CddPduRUpperLayerContribution Rx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define Cdd_ComConf_CddPduRUpperLayerRxPdu_PT_GlobalTimeMaster_PP_GlobalTimeMaster_Rx_346f2748_fe6ecc87 1
#define Cdd_ComConf_CddPduRUpperLayerRxPdu_PT_msg_diag_Request_MyECU_Slave3_PP_msg_diag_Request_MyECU_Slave3_Rx_346f2748_fe6ecc87 0
/**\} */

/**
 * \defgroup Cdd_ComHandleIdsPduRUpperLayerTx Handle IDs of handle space PduRUpperLayerTx.
 * \brief CddPduRUpperLayerContribution Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define Cdd_ComConf_CddPduRUpperLayerTxPdu_PT_msg_diag_Response_MyECU_Slave3_PP_msg_diag_Response_MyECU_Slave3_Tx_346f2748_fe6ecc87 0
/**\} */

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
# define CDD_COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_19.1 */
/*lint -restore */



/** \defgroup ProvidedCddUpperLayerComIf2PduR Provided Cdd_Com communication interface to PduR
    \brief    These services have to be provided by the Cdd_Com if the CDD is an upper layer for the PduR. */
/*\{*/

/**********************************************************************************************************************
  Cdd_Com_RxIndication
**********************************************************************************************************************/
/** \brief         The function is called to indicate the complete reception of a RX I-PDU.
    \param[in]     RxPduId      id of the IF CddPduRUpperLayerRxPdu.
    \param[in]     PduInfoPtr   Payload information of the received I-PDU (pointer to data and data length).
    \return        none
    \pre           The Cdd_Com is initialized and active.
    \context       The function can be called in interrupt and on task level and should not to interrupted by another
                   Cdd_Com_RxIndication call for the same RxPduId.
    \note          The function is called by the PduR.
**********************************************************************************************************************/
FUNC(void, CDD_COM_CODE) Cdd_Com_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, CDD_COM_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
  Cdd_Com_TxConfirmation
**********************************************************************************************************************/
/** \brief         The function is called to confirm the complete transmission of a TX I-PDU.
    \param[in]     TxPduId      id of the IF CddPduRUpperLayerTxPdu.
    \return        none
    \pre           The Cdd_Com is initialized and active.
    \context       The function can be called in interrupt and on task level and should not to interrupted by another
                   Cdd_Com_TxConfirmation call for the same TxPduId.
    \note          The function is called by the PduR.
**********************************************************************************************************************/
FUNC(void, CDD_COM_CODE) Cdd_Com_TxConfirmation(PduIdType TxPduId);

#if (CDD_COM_PDUR_UL_COMIF_TRIGGERTRANSMIT == STD_ON)
/**********************************************************************************************************************
  Cdd_Com_TriggerTransmit
**********************************************************************************************************************/
/** \brief         The function is calledto request the TX I-PDU data before transmission.
    \param[in]     TxPduId      id of the IF CddPduRUpperLayerTxPdu.
    \param[in,out] PduInfoPtr   Contains a pointer to a buffer (SduDataPtr) to where the SDU
                                data shall be copied, and the available buffer size in SduLengh.
                                On return, the service will indicate the length of the copied SDU
                                data in SduLength.
    \return        E_OK         SDU has been copied and SduLength indicates the number of copied bytes.
    \return        E_NOT_OK     No data has been copied, because
                                Cdd is not initialized
                                or TxPduId is not valid
                                or PduInfoPtr is NULL_PTR
                                or SduDataPtr is NULL_PTR
                                or SduLength is too small.
    \pre           The Cdd_Com is initialized and active.
    \context       The function can be called in interrupt and on task level and should not to interrupted by another
                   Cdd_Com_TriggerTransmit call for the same TxPduId.
    \note          The function is called by the PduR.
**********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_COM_CODE) Cdd_Com_TriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, CDD_COM_APPL_DATA) PduInfoPtr);
#endif

/*\}*/




# define CDD_COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_19.1 */
/*lint -restore */

#endif  /* CDD_COM_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Cdd_Com_Cbk.h
**********************************************************************************************************************/


