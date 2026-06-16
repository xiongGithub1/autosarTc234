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
 *            Module: Dcm
 *           Program: MSR_Vector_SLP4
 *          Customer: Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC234LP
 *    License Scope : The usage is restricted to CBD1700982_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dcm_Lcfg.c
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



#define DCM_LCFG_SOURCE
/* ----------------------------------------------
 ~&&&   Includes
---------------------------------------------- */
                                                                                                                                                     /* PRQA S 0857, 0828 EOF */ /* MD_MSR_1.1_857, MD_MSR_1.1_828 */
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Det.h"
#include "Dcm_Int.h"
#include "PduR_Dcm.h"
#include "ComM_Dcm.h"
/* ----------------------------------------------
 ~&&&   Defines
---------------------------------------------- */
#if (DCM_DIDMGR_NVM_READ_ENABLED == STD_ON) || \
    (DCM_DIDMGR_NVM_WRITE_ENABLED == STD_ON)
# if defined(NVM_VENDOR_ID)
#  if (NVM_VENDOR_ID == 30u)
/* Only Vector NvM supports this feature up to now */
#   define Dcm_GetDcmNvMBlockId(blockId)                             (uint16)(NvM_GetDcmBlockId(blockId))                                            /* PRQA S 3453 */ /* QAC 7.0:  A function could probably be used instead of this function-like macro */ /* Macro is more efficient! */
#  endif
# endif

/* Default NvM handle offset */
# if !defined(Dcm_GetDcmNvMBlockId)
#  define Dcm_GetDcmNvMBlockId(blockId)                              (uint16)(blockId)                                                               /* PRQA S 3453 */ /* QAC 7.0:  A function could probably be used instead of this function-like macro */ /* Macro is more efficient! */
# endif
#endif
/* ----------------------------------------------
 ~&&&   Call-back function declarations
---------------------------------------------- */
#define DCM_START_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_F300_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_F300_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, DCM_VAR_NOINIT) DataLength);
/***********************************************************************************************************************
 *  Dcm_RidMgr_0100_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0100_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_0100_Stop()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0100_Stop(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_0100_RequestResults()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0100_RequestResults(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_0104_RequestResults()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0104_RequestResults(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostProcessor()
***********************************************************************************************************************/
/*! \brief         Dummy post-processor
 *  \details       This post-processor is called for diagnostic services which do not require any post processing.
 *  \param[in]     status  The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoPostProcessor(Dcm_ConfirmationStatusType status);
/***********************************************************************************************************************
 *  Dcm_ServiceNoUpdater()
***********************************************************************************************************************/
/*! \brief         Realizes a dummy paged buffer updater.
 *  \details       This function is never called.
 *  \param[in,out] pDataContext  Pointer to the data context
 *  \param[out]    ErrorCode     Negative response code
 *  \return        DCM_E_NOT_OK  Operation failed. Take the NRC from ErrorCode. Do not call again
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoUpdater(Dcm_DiagDataContextPtrType pDataContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_ServiceNoCancel()
***********************************************************************************************************************/
/*! \brief         Dummy service cancellation.
 *  \details       -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoCancel(void);
#define DCM_STOP_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Uninitialized RAM 8-Bit
---------------------------------------------- */
#define DCM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/*! DCM protocol descriptor */
DCM_LOCAL VAR(Dcm_MsgItemType, DCM_VAR_NOINIT) Dcm_CfgNetBuffer_000[50];
#define DCM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM 8-Bit
---------------------------------------------- */
#define DCM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/*! TxPduId to DCM connection map */
CONST(Dcm_NetConnRefMemType, DCM_CONST) Dcm_CfgNetTxPduInfo[2]=
{
    0u
  , 0u
};
/*! TxPduId to DCM periodic message index (connection specific zero based) */
CONST(Dcm_CfgNetPTxObjHandleMemType, DCM_CONST) Dcm_CfgNetPeriodicTxPduInfo[2]=
{
   0u
  ,1u
};
/*! Map of DCM relevant network handles */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetConnComMChannelMap[1]=
{
    0u
};
/*! Service 0x28 list of channels for the all-comm-channel parameter */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetComCtrlChannelListAll[2]=
{
   1u
  , 0u
};
/*! Look up table of DCM service identifiers */
CONST(uint8, DCM_CONST) Dcm_CfgDiagSvcIdLookUpTable[17]=
{
   16u
  ,0x10u
  ,0x11u
  ,0x14u
  ,0x19u
  ,0x22u
  ,0x23u
  ,0x27u
  ,0x28u
  ,0x2Au
  ,0x2Cu
  ,0x2Eu
  ,0x2Fu
  ,0x31u
  ,0x3Du
  ,0x3Eu
  ,0x85u
};
/*! Service 0x10 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc10SubFuncLookUpTable[4]=
{
   3u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x11 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc11SubFuncLookUpTable[2]=
{
   1u
  ,0x01u
};
/*! Service 0x19 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc19SubFuncLookUpTable[13]=
{
   12u
  ,0x01u
  ,0x02u
  ,0x03u
  ,0x04u
  ,0x06u
  ,0x07u
  ,0x08u
  ,0x09u
  ,0x0Au
  ,0x0Cu
  ,0x0Du
  ,0x14u
};
/*! Service 0x27 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc27SubFuncLookUpTable[5]=
{
   4u
  ,0x01u
  ,0x02u
  ,0x03u
  ,0x04u
};
/*! Service 0x28 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubFuncLookUpTable[5]=
{
   4u
  ,0x00u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x28 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28MessageTypeLookUpTable[4]=
{
   3u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x28 network ID lookup */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubNetIdLookUp[3]=
{
   2u
  ,0x00u
  ,0x0Fu
};
/*! Service 0x2C look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc2CSubFuncLookUpTable[4]=
{
   3u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x3E look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc3ESubFuncLookUpTable[2]=
{
   1u
  ,0x00u
};
/*! Look up table of service 0x85 */
CONST(uint8, DCM_CONST) Dcm_CfgSvc85SubFuncLookUpTable[3]=
{
   2u
  ,0x01u
  ,0x02u
};
#define DCM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM 16-Bit
---------------------------------------------- */
#define DCM_START_SEC_CONST_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/*! DID look up table  */
CONST(uint16, DCM_CONST) Dcm_CfgDidMgrDidLookUpTable[19]=
{
   18u
  ,0x0001u
  ,0x0002u
  ,0x0003u
  ,0x0004u
  ,0x0055u
  ,0x0100u
  ,0x0101u
  ,0xF180u
  ,0xF187u
  ,0xF189u
  ,0xF18Cu
  ,0xF190u
  ,0xF193u
  ,0xF201u
  ,0xF300u
  ,0xF410u
  ,0xF412u
  ,0xF413u
};
/*! RID look up table  */
CONST(uint16, DCM_CONST) Dcm_CfgRidMgrRidLookUpTable[5]=
{
   4u
  ,0x0100u
  ,0x0104u
  ,0x0203u
  ,0xF518u
};
/*! Service 0x2A timings */
CONST(Dcm_TmrTimerCntrMemType, DCM_CONST) Dcm_CfgSvc2ASchdRateTime[3]=
{
      0u
  ,   0u
  ,   0u
};
/*! Service 0x2A delay timings */
CONST(Dcm_TmrTimerCntrMemType, DCM_CONST) Dcm_CfgNetPeriodicDelayTime[3]=
{
      0u
  ,   0u
  ,   0u
};
#define DCM_STOP_SEC_CONST_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM of unspecified size
---------------------------------------------- */
#define DCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/*! DCM buffer descriptor */
CONST(Dcm_CfgNetBufferInfoType, DCM_CONST) Dcm_CfgNetBufferInfo[1]=
{
   { Dcm_CfgNetBuffer_000,  50u}
};
/*! RxPduId map */
CONST(Dcm_CfgNetRxPduInfoType, DCM_CONST) Dcm_CfgNetRxPduInfo[2]=
{
   { TRUE, 0u}
  ,{ FALSE, 0u}
};
/*! DCM periodic connection transmision PduIds */
CONST(PduIdType, DCM_CONST) Dcm_CfgNetPeriodicTxPduIds[1]=
{
   PduRConf_PduRSrcPdu_SRC_Can_PT_msg_diag_Uudt_Response_MyECU_346f2748
};
/*! DCM connection descriptor */
CONST(Dcm_CfgNetConnectionInfoType, DCM_CONST) Dcm_CfgNetConnectionInfo[1]=
{
   { 0x00E0u,  10u,PduRConf_PduRSrcPdu_SRC_Can_PT_msg_diag_Response_MyECU_346f2748, 0u,0u}
};
/*! DCM protocol descriptor */
CONST(Dcm_CfgNetProtocolInfoType, DCM_CONST) Dcm_CfgNetProtocolInfo[1]=
{
   { {    0u,   0u},4095u, 3u,TRUE,0u,DemConf_DemClient_DemClient}
};
/*! Map of all relevant for DCM network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetAllComMChannelMap[1]=
{
   ComMConf_ComMChannel_CAN_f26020e5
};
/*! Look up table of DCM relevant network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetNetworkHandleLookUpTable[2]=
{
   1u
  ,ComMConf_ComMChannel_CAN_f26020e5
};
/*! Diagnostic service execution conditions */
CONST(Dcm_CfgStatePreconditionInfoType, DCM_CONST) Dcm_CfgStatePreconditions[3]=
{
   { { 0x07u,0x07u}}
  ,{ { 0x06u,0x07u}}
  ,{ { 0x04u,0x07u}}
};
/*! Session state properties */
CONST(Dcm_CfgStateSessionInfoType, DCM_CONST) Dcm_CfgStateSessionInfo[3]=
{
   { {    5u, 500u},RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION,0x01u}
  ,{ {    5u, 500u},RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION,0x02u}
  ,{ {    5u, 500u},RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION,0x03u}
};
/*! Security Access state properties */
CONST(Dcm_CfgStateSecurityInfoType, DCM_CONST) Dcm_CfgStateSecurityInfo[2]=
{
   { 1000u, 3u,0x01u} /* SecLvl: UnlockedL1 */
  ,{ 1000u, 3u,0x02u} /* SecLvl: Level_3 */
};
/*! DID properties */
CONST(Dcm_CfgDidMgrDidInfoType, DCM_CONST) Dcm_CfgDidMgrDidInfo[18]=
{
   {    6u,   6u,   0u,   0u,0x01u, 9u} /* DID: 0x0001 */
  ,{    4u,   4u,   1u,   0u,0x03u, 8u} /* DID: 0x0002 */
  ,{    4u,   4u,   3u,   0u,0x05u, 8u} /* DID: 0x0003 */
  ,{    1u,   1u,   5u,   0u,0x02u, 5u} /* DID: 0x0004 */
  ,{    2u,   2u,   6u,   0u,0x03u, 0u} /* DID: 0x0055 */
  ,{   10u,  10u,   8u,   0u,0x03u, 0u} /* DID: 0x0100 */
  ,{    2u,   2u,  10u,   0u,0x03u, 0u} /* DID: 0x0101 */
  ,{    5u,   5u,  12u,   0u,0x03u, 5u} /* DID: 0xF180 */
  ,{    4u,   4u,  14u,   0u,0x03u, 8u} /* DID: 0xF187 */
  ,{   13u,  13u,  16u,   0u,0x03u,10u} /* DID: 0xF189 */
  ,{    4u,   4u,  18u,   0u,0x03u, 8u} /* DID: 0xF18C */
  ,{   17u,  17u,  20u,   0u,0x03u,11u} /* DID: 0xF190 */
  ,{    4u,   4u,  22u,   0u,0x03u, 8u} /* DID: 0xF193 */
  ,{    2u,   2u,  24u,   0u,0x01u, 0u} /* DID: 0xF201 */
  ,{    0u, 255u,  25u,   0u,0x11u, 7u} /* DID: 0xF300 */
  ,{    2u,   2u,  27u,   0u,0x01u, 0u} /* DID: 0xF410 */
  ,{    2u,   2u,  28u,   0u,0x01u, 0u} /* DID: 0xF412 */
  ,{    2u,   2u,  29u,   0u,0x01u, 0u} /* DID: 0xF413 */
};
/*! DID operation properties */
CONST(Dcm_CfgDidMgrOpInfoType, DCM_CONST) Dcm_CfgDidMgrOpInfo[30]=
{
   {    0u,   0u,0x05u} /* DID: 0x0001 */
  ,{    0u,   2u,0x05u} /* DID: 0x0002 */
  ,{    0u,   4u,0x01u} /* DID: 0x0002 */
  ,{    0u,   5u,0x01u} /* DID: 0x0003 */
  ,{    2u,   6u,0x0Fu} /* DID: 0x0003 */
  ,{    0u,  10u,0x01u} /* DID: 0x0004 */
  ,{    0u,  11u,0x05u} /* DID: 0x0055 */
  ,{    0u,  13u,0x01u} /* DID: 0x0055 */
  ,{    0u,  14u,0x05u} /* DID: 0x0100 */
  ,{    0u,  16u,0x01u} /* DID: 0x0100 */
  ,{    0u,  17u,0x05u} /* DID: 0x0101 */
  ,{    0u,  19u,0x01u} /* DID: 0x0101 */
  ,{    0u,  20u,0x05u} /* DID: 0xF180 */
  ,{    0u,  22u,0x01u} /* DID: 0xF180 */
  ,{    0u,  23u,0x05u} /* DID: 0xF187 */
  ,{    0u,  25u,0x01u} /* DID: 0xF187 */
  ,{    0u,  26u,0x05u} /* DID: 0xF189 */
  ,{    0u,  28u,0x01u} /* DID: 0xF189 */
  ,{    0u,  29u,0x05u} /* DID: 0xF18C */
  ,{    0u,  31u,0x01u} /* DID: 0xF18C */
  ,{    0u,  32u,0x05u} /* DID: 0xF190 */
  ,{    0u,  34u,0x01u} /* DID: 0xF190 */
  ,{    0u,  35u,0x05u} /* DID: 0xF193 */
  ,{    0u,  37u,0x01u} /* DID: 0xF193 */
  ,{    1u,  38u,0x05u} /* DID: 0xF201 */
  ,{    0u,  40u,0x03u} /* DID: 0xF300 */
  ,{    0u,  42u,0x00u} /* DID: 0xF300 */
  ,{    0u,  42u,0x05u} /* DID: 0xF410 */
  ,{    0u,  44u,0x05u} /* DID: 0xF412 */
  ,{    0u,  46u,0x05u} /* DID: 0xF413 */
};
/*! DID operation classes */
CONST(Dcm_CfgDidMgrDidOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpClassInfo[49]=
{
   {  0u}
  ,{  1u}
  ,{  2u}
  ,{  3u}
  ,{  4u}
  ,{  5u}
  ,{  6u}
  ,{  7u}
  ,{  8u}
  ,{  9u}
  ,{ 10u}
  ,{ 11u}
  ,{ 12u}
  ,{ 13u}
  ,{ 14u}
  ,{ 19u}
  ,{ 24u}
  ,{ 29u}
  ,{ 30u}
  ,{ 31u}
  ,{ 32u}
  ,{ 34u}
  ,{ 36u}
  ,{ 38u}
  ,{ 39u}
  ,{ 40u}
  ,{ 41u}
  ,{ 42u}
  ,{ 43u}
  ,{ 44u}
  ,{ 45u}
  ,{ 46u}
  ,{ 47u}
  ,{ 48u}
  ,{ 49u}
  ,{ 50u}
  ,{ 51u}
  ,{ 52u}
  ,{ 53u}
  ,{ 54u}
  ,{ 55u}
  ,{ 56u}
  ,{ 57u}
  ,{ 58u}
  ,{ 59u}
  ,{ 60u}
  ,{ 61u}
  ,{ 62u}
  ,{ 63u}
};
/*! List of signal intervals */
CONST(Dcm_CfgDidMgrSignalInfoType, DCM_CONST) Dcm_CfgDidMgrSignalInfo[12]=
{
   {    0u,   2u}
  ,{    2u,   2u}
  ,{    2u,   2u}
  ,{    2u,   2u}
  ,{    2u,   2u}
  ,{    0u,   1u}
  ,{    1u,   4u}
  ,{    0u,   0u}
  ,{    0u,   4u}
  ,{    0u,   6u}
  ,{    0u,  13u}
  ,{    0u,  17u}
};
/*! DID signal operation classes */
CONST(Dcm_CfgDidMgrSignalOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrSignalOpClassInfo[63]=
{
   { ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Example_ReadOnlyDID_DID_Data_GlobalTime_ReadData)), 2u} /* DID: 0x0001 */                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Example_ReadOnlyDID_DID_Data_GlobalTime_ConditionCheckRead)), 1u} /* DID: 0x0001 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Example_ReadWriteData_GlobalTime_ReadData)), 2u} /* DID: 0x0002 */                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Example_ReadWriteData_GlobalTime_ConditionCheckRead)), 1u} /* DID: 0x0002 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Example_ReadWriteData_GlobalTime_WriteData)), 2u} /* DID: 0x0002 */                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SampleIoControl_DID_Data_ReadData)), 2u} /* DID: 0x0003 */                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SampleIoControl_DID_Data_ReturnControlToECU)), 3u} /* DID: 0x0003 */                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SampleIoControl_DID_Data_ResetToDefault)), 3u} /* DID: 0x0003 */                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SampleIoControl_DID_Data_FreezeCurrentState)), 3u} /* DID: 0x0003 */                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SampleIoControl_DID_Data_ShortTermAdjustment)), 4u} /* DID: 0x0003 */                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Example_WriteOnlyDID_DID_DataObject_WriteData)), 2u} /* DID: 0x0004 */                            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_DID_StartApplication_ReadData)), 1u} /* DID: 0x0055 */                                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_DID_StartApplication_ConditionCheckRead)), 0u} /* DID: 0x0055 */                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_DID_StartApplication_WriteData)), 1u} /* DID: 0x0055 */                                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ReadData)), 2u} /* DID: 0x0100 */                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ReadData)), 2u} /* DID: 0x0100 */                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_NmVersion_ReadData)), 2u} /* DID: 0x0100 */                                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ReadData)), 2u} /* DID: 0x0100 */                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ReadData)), 2u} /* DID: 0x0100 */                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ConditionCheckRead)), 1u} /* DID: 0x0100 */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ConditionCheckRead)), 1u} /* DID: 0x0100 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_NmVersion_ConditionCheckRead)), 1u} /* DID: 0x0100 */                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ConditionCheckRead)), 1u} /* DID: 0x0100 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ConditionCheckRead)), 1u} /* DID: 0x0100 */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_WriteData)), 2u} /* DID: 0x0100 */                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_CanDriverVersion_WriteData)), 2u} /* DID: 0x0100 */                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_NmVersion_WriteData)), 2u} /* DID: 0x0100 */                                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_WriteData)), 2u} /* DID: 0x0100 */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_WriteData)), 2u} /* DID: 0x0100 */                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData)), 2u} /* DID: 0x0101 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ConditionCheckRead)), 1u} /* DID: 0x0101 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData)), 2u} /* DID: 0x0101 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Boot_Software_NumberOfModules_ReadData)), 2u} /* DID: 0xF180 */                                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ReadData)), 2u} /* DID: 0xF180 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Boot_Software_NumberOfModules_ConditionCheckRead)), 1u} /* DID: 0xF180 */                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ConditionCheckRead)), 1u} /* DID: 0xF180 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Boot_Software_NumberOfModules_WriteData)), 2u} /* DID: 0xF180 */                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_WriteData)), 2u} /* DID: 0xF180 */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ReadData)), 2u} /* DID: 0xF187 */                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ConditionCheckRead)), 1u} /* DID: 0xF187 */                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_WriteData)), 2u} /* DID: 0xF187 */                            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_EcuIdentification_Part_Number_ReadData)), 2u} /* DID: 0xF189 */                                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_EcuIdentification_Part_Number_ConditionCheckRead)), 1u} /* DID: 0xF189 */                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_EcuIdentification_Part_Number_WriteData)), 2u} /* DID: 0xF189 */                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SerialNumber_SerialNumber_ReadData)), 2u} /* DID: 0xF18C */                                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SerialNumber_SerialNumber_ConditionCheckRead)), 1u} /* DID: 0xF18C */                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SerialNumber_SerialNumber_WriteData)), 2u} /* DID: 0xF18C */                                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Identification_VIN_ReadData)), 2u} /* DID: 0xF190 */                                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Identification_VIN_ConditionCheckRead)), 1u} /* DID: 0xF190 */                            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Identification_VIN_WriteData)), 2u} /* DID: 0xF190 */                                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ReadData)), 2u} /* DID: 0xF193 */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ConditionCheckRead)), 1u} /* DID: 0xF193 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_WriteData)), 2u} /* DID: 0xF193 */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PeriodicDataSample_DataRecord_ReadData)), 2u} /* DID: 0xF201 */                                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PeriodicDataSample_DataRecord_ConditionCheckRead)), 1u} /* DID: 0xF201 */                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgr_F300_ReadData)), 2u} /* DID: 0xF300 */                                                                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgr_F300_ReadDataLength)), 2u} /* DID: 0xF300 */                                                                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0xF410_DID_Data_ReadData)), 2u} /* DID: 0xF410 */                                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0xF410_DID_Data_ConditionCheckRead)), 1u} /* DID: 0xF410 */                                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0xF412_DID_Data_ReadData)), 2u} /* DID: 0xF412 */                                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0xF412_DID_Data_ConditionCheckRead)), 1u} /* DID: 0xF412 */                                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0xF413_DID_Data_ReadData)), 2u} /* DID: 0xF413 */                                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0xF413_DID_Data_ConditionCheckRead)), 1u} /* DID: 0xF413 */                                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! IO control DID operation properties */
CONST(Dcm_CfgDidMgrOpInfoIoControlType, DCM_CONST) Dcm_CfgDidMgrOpInfoIoControl[1]=
{
   {    6u,   2u} /* DID: 0x0003 */
};
/*! RID properties */
CONST(Dcm_CfgRidMgrRidInfoType, DCM_CONST) Dcm_CfgRidMgrRidInfo[4]=
{
   {    0u,   1u,0x07u} /* RID: 0x0100 */
  ,{    3u,   1u,0x05u} /* RID: 0x0104 */
  ,{    5u,   1u,0x01u} /* RID: 0x0203 */
  ,{    6u,   1u,0x01u} /* RID: 0xF518 */
};
/*! RID operation properties */
CONST(Dcm_CfgRidMgrOpInfoType, DCM_CONST) Dcm_CfgRidMgrOpInfo[7]=
{
   { ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0100_Start)),   1u,   1u,   4u,   4u, 9u} /* RID: 0x0100 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0100_Stop)),   0u,   0u,   4u,   4u, 9u} /* RID: 0x0100 */                                                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0100_RequestResults)),   0u,   0u,   2u,   2u, 9u} /* RID: 0x0100 */                                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_Start)),   3u,   3u,   0u,   0u, 1u} /* RID: 0x0104 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0104_RequestResults)),   0u,   0u,   4u,   4u, 9u} /* RID: 0x0104 */                                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_CheckProgrammingPreconditions_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0x0203 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ForceBootMode_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF518 */                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! Properties of the memory map of a specific MID */
CONST(Dcm_CfgMemMgrMemMapInfoType, DCM_CONST) Dcm_CfgMemMgrMemMap[1]=
{
   { 0x00000000u,0xFFFFFFFEUL,{    1u,   1u}}
};
/*! DCM service initializers */
CONST(Dcm_DiagSvcInitFuncType, DCM_CONST) Dcm_CfgDiagSvcInitializers[5]=
{
   Dcm_Service27Init
  ,Dcm_Service2AInit
  ,Dcm_Service2CInit
  ,Dcm_Service2FInit
  ,NULL_PTR /* end marker */
};
/*! DCM service properties */
CONST(Dcm_CfgDiagServiceInfoType, DCM_CONST) Dcm_CfgDiagServiceInfo[17]=
{
   { Dcm_Service10Processor,0x01u, 1u,   1u,   2u, 0u, 0u} /* SID: 0x10 */
  ,{ Dcm_Service11Processor,0x01u, 1u,   3u,   4u, 0u, 0u} /* SID: 0x11 */
  ,{ Dcm_Service14Processor,0x00u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x14 */
  ,{ Dcm_Service19Processor,0x01u, 1u,   5u,   0u, 2u, 0u} /* SID: 0x19 */
  ,{ Dcm_Service22Processor,0x00u, 2u,   0u,   0u, 0u, 0u} /* SID: 0x22 */
  ,{ Dcm_Service23Processor,0x00u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x23 */
  ,{ Dcm_Service27Processor,0x03u, 1u,   6u,   0u, 0u, 0u} /* SID: 0x27 */
  ,{ Dcm_Service28Processor,0x01u, 1u,   7u,   0u, 0u, 0u} /* SID: 0x28 */
  ,{ Dcm_Service2AProcessor,0x00u, 1u,   8u,   0u, 0u, 0u} /* SID: 0x2A */
  ,{ Dcm_Service2CProcessor,0x01u, 1u,   9u,   0u, 0u, 0u} /* SID: 0x2C */
  ,{ Dcm_Service2EProcessor,0x00u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x2E */
  ,{ Dcm_Service2FProcessor,0x00u, 3u,  10u,   0u, 0u, 0u} /* SID: 0x2F */
  ,{ Dcm_Service31Processor,0x01u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x31 */
  ,{ Dcm_Service3DProcessor,0x00u, 4u,   0u,   0u, 0u, 0u} /* SID: 0x3D */
  ,{ Dcm_Service3EProcessor,0x01u, 1u,   0u,   0u, 0u, 0u} /* SID: 0x3E */
  ,{ Dcm_Service85Processor,0x01u, 1u,  11u,   0u, 0u, 0u} /* SID: 0x85 */
  ,{ Dcm_RepeaterDeadEnd,0x00u, 0u,   0u,   0u, 0u, 0u} /* Dcm_RepeaterDeadEnd */
};
/*! Indirection from diag service info to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgDiagSvcIdExecPrecondTable[16]=
{
      0u /* SID: 0x10 */
  ,   0u /* SID: 0x11 */
  ,   0u /* SID: 0x14 */
  ,   0u /* SID: 0x19 */
  ,   0u /* SID: 0x22 */
  ,   0u /* SID: 0x23 */
  ,   1u /* SID: 0x27 */
  ,   1u /* SID: 0x28 */
  ,   1u /* SID: 0x2A */
  ,   0u /* SID: 0x2C */
  ,   0u /* SID: 0x2E */
  ,   2u /* SID: 0x2F */
  ,   1u /* SID: 0x31 */
  ,   0u /* SID: 0x3D */
  ,   0u /* SID: 0x3E */
  ,   0u /* SID: 0x85 */
};
/*! DCM service post processors */
CONST(Dcm_DiagSvcConfirmationFuncType, DCM_CONST) Dcm_CfgDiagSvcPostProcessors[12]=
{
   Dcm_ServiceNoPostProcessor
  ,Dcm_Service10PostProcessor
  ,Dcm_Service10FastPostProcessor
  ,Dcm_Service11PostProcessor
  ,Dcm_Service11FastPostProcessor
  ,Dcm_Service19PostProcessor
  ,Dcm_Service27PostProcessor
  ,Dcm_Service28PostProcessor
  ,Dcm_Service2APostProcessor
  ,Dcm_Service2CPostProcessor
  ,Dcm_Service2FPostProcessor
  ,Dcm_Service85PostProcessor
};
/*! DCM service paged buffer updater */
CONST(Dcm_DiagSvcUpdateFuncType, DCM_CONST) Dcm_CfgDiagSvcUpdaters[3]=
{
   Dcm_ServiceNoUpdater
  ,Dcm_PagedBufferDataPadding
  ,Dcm_Service19Updater
};
/*! DCM service paged buffer canceller */
CONST(Dcm_DiagSvcCancelFuncType, DCM_CONST) Dcm_CfgDiagSvcCancellers[1]=
{
   Dcm_ServiceNoCancel
};
/*! Service 0x10 sub-service properties table  */
CONST(Dcm_CfgSvc10SubFuncInfoType, DCM_CONST) Dcm_CfgSvc10SubFuncInfo[3]=
{
   { { 50u, 500u}} /* Session ID: 0x01 */
  ,{ { 50u, 500u}} /* Session ID: 0x02 */
  ,{ { 50u, 500u}} /* Session ID: 0x03 */
};
/*! Indirection from service 0x10 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc10SubFuncExecPrecondTable[3]=
{
      0u /* Session ID: 0x01 */
  ,   0u /* Session ID: 0x02 */
  ,   0u /* Session ID: 0x03 */
};
/*! Service 0x11 sub-service properties table  */
CONST(Dcm_CfgSvc11SubFuncInfoType, DCM_CONST) Dcm_CfgSvc11SubFuncInfo[1]=
{
   { Dcm_Service11_01Processor} /* SF: 0x01 */
};
/*! Indirection from service 0x11 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc11SubFuncExecPrecondTable[1]=
{
      0u /* SF: 0x01 */
};
/*! Service 0x19 sub-service properties table  */
CONST(Dcm_CfgSvc19SubFuncInfoType, DCM_CONST) Dcm_CfgSvc19SubFuncInfo[12]=
{
   { Dcm_Service19_01Processor, 2u} /* SF: 0x01 */
  ,{ Dcm_Service19_02Processor, 2u} /* SF: 0x02 */
  ,{ Dcm_Service19_03Processor, 1u} /* SF: 0x03 */
  ,{ Dcm_Service19_04Processor, 5u} /* SF: 0x04 */
  ,{ Dcm_Service19_06Processor, 5u} /* SF: 0x06 */
  ,{ Dcm_Service19_07Processor, 3u} /* SF: 0x07 */
  ,{ Dcm_Service19_08Processor, 3u} /* SF: 0x08 */
  ,{ Dcm_Service19_09Processor, 4u} /* SF: 0x09 */
  ,{ Dcm_Service19_0AProcessor, 1u} /* SF: 0x0A */
  ,{ Dcm_Service19_0CProcessor, 1u} /* SF: 0x0C */
  ,{ Dcm_Service19_0DProcessor, 1u} /* SF: 0x0D */
  ,{ Dcm_Service19_14Processor, 1u} /* SF: 0x14 */
};
/*! Indirection from service 0x19 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc19SubFuncExecPrecondTable[12]=
{
      0u /* SF: 0x01 */
  ,   0u /* SF: 0x02 */
  ,   0u /* SF: 0x03 */
  ,   0u /* SF: 0x04 */
  ,   0u /* SF: 0x06 */
  ,   0u /* SF: 0x07 */
  ,   0u /* SF: 0x08 */
  ,   0u /* SF: 0x09 */
  ,   0u /* SF: 0x0A */
  ,   0u /* SF: 0x0C */
  ,   0u /* SF: 0x0D */
  ,   0u /* SF: 0x14 */
};
/*! Service 0x27 sub-service properties table  */
CONST(Dcm_CfgSvc27SubFuncInfoType, DCM_CONST) Dcm_CfgSvc27SubFuncInfo[4]=
{
   { Dcm_Service27SeedProcessor,   1u} /* SF: 0x01 */                                                                                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ Dcm_Service27KeyProcessor,   5u} /* SF: 0x02 */                                                                                                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ Dcm_Service27SeedProcessor,   1u} /* SF: 0x03 */                                                                                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ Dcm_Service27KeyProcessor,   3u} /* SF: 0x04 */                                                                                                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! Service 0x27 security level properties table  */
CONST(Dcm_CfgSvc27SecLevelInfoType, DCM_CONST) Dcm_CfgSvc27SecLevelInfo[2]=
{
   { ((Dcm_Svc27GetSeedFuncType)(Rte_Call_SecurityAccess_UnlockedL1_GetSeed)),Rte_Call_SecurityAccess_UnlockedL1_CompareKey,   4u, 0u} /* SecLvl: UnlockedL1 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_Svc27GetSeedFuncType)(Rte_Call_SecurityAccess_Level_3_GetSeed)),Rte_Call_SecurityAccess_Level_3_CompareKey,   2u, 0u} /* SecLvl: Level_3 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! Indirection from service 0x27 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc27SubFuncExecPrecondTable[4]=
{
      1u /* SF: 0x01 */
  ,   1u /* SF: 0x02 */
  ,   1u /* SF: 0x03 */
  ,   1u /* SF: 0x04 */
};
/*! Service 0x28 sub-service properties table  */
CONST(Dcm_CfgSvc28SubFuncInfoType, DCM_CONST) Dcm_CfgSvc28SubFuncInfo[4]=
{
   { Dcm_Service28_XXProcessor, 2u} /* SF: 0x00 */
  ,{ Dcm_Service28_XXProcessor, 2u} /* SF: 0x01 */
  ,{ Dcm_Service28_XXProcessor, 2u} /* SF: 0x02 */
  ,{ Dcm_Service28_XXProcessor, 2u} /* SF: 0x03 */
};
/*! Indirection from service 0x28 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc28SubFuncExecPrecondTable[4]=
{
      1u /* SF: 0x00 */
  ,   1u /* SF: 0x01 */
  ,   1u /* SF: 0x02 */
  ,   1u /* SF: 0x03 */
};
/*! Service 0x28 network ID to ComM channel map */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgSvc28SubNetIdMap[2]=
{
   DCM_SVC_28_NETWORK_ALL
  ,DCM_SVC_28_NETWORK_CURRENT
};
/*! Service 0x2C sub-service properties table  */
CONST(Dcm_CfgSvc2CSubFuncInfoType, DCM_CONST) Dcm_CfgSvc2CSubFuncInfo[3]=
{
   { Dcm_Service2C_01Processor, 2u} /* SF: 0x01 */
  ,{ Dcm_Service2C_02Processor, 2u} /* SF: 0x02 */
  ,{ Dcm_Service2C_03Processor, 0u} /* SF: 0x03 */
};
/*! Indirection from service 0x2C sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc2CSubFuncExecPrecondTable[3]=
{
      0u /* SF: 0x01 */
  ,   0u /* SF: 0x02 */
  ,   0u /* SF: 0x03 */
};
/*! Indirection from service 0x3E sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc3ESubFuncExecPrecondTable[1]=
{
      0u /* SF: 0x00 */
};
/*! Indirection from service 0x85 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc85SubFuncExecPrecondTable[2]=
{
      0u /* SF: 0x01 */
  ,   0u /* SF: 0x02 */
};
/*! DCM service 0x85 properties */
CONST(Dcm_CfgSvc85SubFuncInfoType, DCM_CONST) Dcm_CfgSvc85SubFuncInfo[2]=
{
   { Dem_EnableDTCSetting,RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING} /* SF: 0x01 */
  ,{ Dem_DisableDTCSetting,RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING} /* SF: 0x02 */
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Module call-out implementations
---------------------------------------------- */
#define DCM_START_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_F300_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data)
{
  return Dcm_Svc2CDefMgrRead(   0u, OpStatus, Data);
}
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_F300_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, DCM_VAR_NOINIT) DataLength)
{
  DCM_IGNORE_UNREF_PARAM(OpStatus);                                                                                                                  /* PRQA S 3112 */ /* MD_Dcm_3112 */
  return Dcm_Svc2CDefMgrReadDataLength(   0u, DataLength);
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0100_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0100_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataInIn_Option0;
  uint32 dataOutOut_InitState;
  Std_ReturnType stdReturn;

  dataInIn_Option0 = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)));                                                                          /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  stdReturn = Rte_Call_RoutineServices_SampleRoutineControl_Start(dataInIn_Option0
                                                                 , OpStatus
                                                                 , &dataOutOut_InitState
                                                                 , ErrorCode
                                                                 );                                                                                  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
  if (E_OK == stdReturn)
  {
    {
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 0u, Dcm_UtiGetHiHiByte(dataOutOut_InitState));                                                          /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 1u, Dcm_UtiGetHiLoByte(dataOutOut_InitState));                                                          /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 2u, Dcm_UtiGetLoHiByte(dataOutOut_InitState));                                                          /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 3u, Dcm_UtiGetLoLoByte(dataOutOut_InitState));                                                          /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
    }
  }
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0100_Stop()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0100_Stop(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint32 dataOutOut_StopState;
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  stdReturn = Rte_Call_RoutineServices_SampleRoutineControl_Stop(OpStatus
                                                                , &dataOutOut_StopState
                                                                , ErrorCode
                                                                );                                                                                   /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
  if (E_OK == stdReturn)
  {
    {
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 0u, Dcm_UtiGetHiHiByte(dataOutOut_StopState));                                                          /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 1u, Dcm_UtiGetHiLoByte(dataOutOut_StopState));                                                          /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 2u, Dcm_UtiGetLoHiByte(dataOutOut_StopState));                                                          /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 3u, Dcm_UtiGetLoLoByte(dataOutOut_StopState));                                                          /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
    }
  }
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0100_RequestResults()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0100_RequestResults(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint16 dataOutOut_Result;
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  stdReturn = Rte_Call_RoutineServices_SampleRoutineControl_RequestResults(OpStatus
                                                                          , &dataOutOut_Result
                                                                          , ErrorCode
                                                                          );                                                                         /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
  if (E_OK == stdReturn)
  {
    {
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 0u, Dcm_UtiGetHiByte(dataOutOut_Result));                                                               /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 1u, Dcm_UtiGetLoByte(dataOutOut_Result));                                                               /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
    }
  }
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0104_RequestResults()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0104_RequestResults(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint32 dataOutOut_Result;
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  stdReturn = Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_RequestResults(OpStatus
                                                                                    , &dataOutOut_Result
                                                                                    , ErrorCode
                                                                                    );                                                               /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
  if (E_OK == stdReturn)
  {
    {
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 0u, Dcm_UtiGetHiHiByte(dataOutOut_Result));                                                             /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 1u, Dcm_UtiGetHiLoByte(dataOutOut_Result));                                                             /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 2u, Dcm_UtiGetLoHiByte(dataOutOut_Result));                                                             /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
      Dcm_DiagSetResDataAsU8Rel(pMsgContext, 3u, Dcm_UtiGetLoLoByte(dataOutOut_Result));                                                             /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
    }
  }
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostProcessor()
***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoPostProcessor() */
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoPostProcessor(Dcm_ConfirmationStatusType status)
{
  DCM_IGNORE_UNREF_PARAM(status);                                                                                                                    /* PRQA S 3112 */ /* MD_Dcm_3112 */
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoUpdater()
***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoUpdater() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoUpdater(Dcm_DiagDataContextPtrType pDataContext, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  DCM_IGNORE_UNREF_PARAM(pDataContext);                                                                                                              /* PRQA S 3112 */ /* MD_Dcm_3112 */
  DCM_IGNORE_UNREF_PARAM(ErrorCode);                                                                                                                 /* PRQA S 3112 */ /* MD_Dcm_3112 */
  return E_NOT_OK;
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoCancel()
***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoCancel() */
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoCancel(void)
{
  /* nothing to do */
}
#define DCM_STOP_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ********************************************************************************************************************
 * END OF FILE: Dcm_Lcfg.c
 * ******************************************************************************************************************** */

