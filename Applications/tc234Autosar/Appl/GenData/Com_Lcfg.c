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
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC234LP
 *    License Scope : The usage is restricted to CBD1700982_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Lcfg.c
 *   Generation Time: 2026-05-30 09:53:14
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


/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/
/* PRQA S 0342 EOF */ /* MD_Com_0342 */
/* PRQA S 0612 EOF */ /* MD_Com_0612 */
/* PRQA S 0639 EOF */ /* MD_MSR_1.1_639 */
/* PRQA S 0850 EOF */ /* MD_MSR_19.8 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 2006 EOF */ /* MD_MSR_14.7 */
/* PRQA S 3109 EOF */ /* MD_MSR_14.3 */
/* PRQA S 3453 EOF */ /* MD_CSL_3453 */
/* PRQA S 3458 EOF */ /* MD_MSR_19.4 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#define V_IL_ASRCOMCFG5_LCFG_SOURCE

#include "Com.h"

#include "Com_Lcfg.h"

#include "Rte_Cbk.h"

#include "SchM_Com.h"

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
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
  Com_ConstValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueUInt16Type, COM_CONST) Com_ConstValueUInt16[2] = {
  /* Index     ConstValueUInt16      Referable Keys */
  /*     0 */           0x8000U,  /* [/ActiveEcuC/Com/ComConfig/Signal_Rx16bit_Cyclic_a691adb3InitValue, /ActiveEcuC/Com/ComConfig/Signal_Rx16bit_Cyclic_a691adb3RxDataTimeoutSubstitutionValue] */
  /*     1 */           0x0019U   /* [/ActiveEcuC/Com/ComConfig/Signal_Rx15bit_OnWrite_a1df81adInitValue, /ActiveEcuC/Com/ComConfig/Signal_Rx15bit_OnWrite_a1df81adRxDataTimeoutSubstitutionValue] */
};
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_PduGrpVector
**********************************************************************************************************************/
/** 
  \var    Com_PduGrpVector
  \brief  Contains an I-PDU-Group vector for each I-PDU, mapping the I-PDU to the corresponding I-PDU-Groups.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_PduGrpVectorType, COM_CONST) Com_PduGrpVector[2] = {
  /* Index     PduGrpVector      Referable Keys */
  /*     0 */         0x02U,  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  /*     1 */         0x01U   /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle100_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/msg_RxCycle_E2eProf1C_500_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/msg_RxEvent_20_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/msg_StartAppl_Rx_MyECU_oCAN_3abd61be] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                              Description
  InitValueUsed                        TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  ApplType                             Application data type.
  BitPosition                          Little endian bit position of the signal or group signal within the I-PDU.
  RxDataTimeoutSubstitutionValueIdx    the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  RxPduInfoIdx                         the index of the 1:1 relation pointing to Com_RxPduInfo
  StartByteInPduPosition               Start Byte position of the signal or group signal within the I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[2] = {
    /* Index    InitValueUsed  ApplType                           BitPosition  RxDataTimeoutSubstitutionValueIdx  RxPduInfoIdx  StartByteInPduPosition        Referable Keys */
  { /*     0 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,         12U,                                1U,           3U,                     1U },  /* [/ActiveEcuC/Com/ComConfig/Signal_Rx15bit_OnWrite_a1df81ad, /ActiveEcuC/Com/ComConfig/msg_RxEvent_20_oCAN_3abd61be] */
  { /*     1 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,         32U,                                0U,           1U,                     4U }   /* [/ActiveEcuC/Com/ComConfig/Signal_Rx16bit_Cyclic_a691adb3, /ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[2] = {
  /* Index     RxAccessInfoInd      Referable Keys */
  /*     0 */               1U,  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be] */
  /*     1 */               0U   /* [/ActiveEcuC/Com/ComConfig/msg_RxEvent_20_oCAN_3abd61be] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxCbkFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_RxCbkFuncPtr
  \brief  Function pointer table containing configured notification and invalid notifications function pointer for signals and signal groups.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(ComRxCbkType, COM_CONST) Com_RxCbkFuncPtr[2] = {
  /* Index     RxCbkFuncPtr                                    Referable Keys */
  /*     0 */ Rte_COMCbk_Signal_Rx16bit_Cyclic_a691adb3  ,  /* [/ActiveEcuC/Com/ComConfig/Signal_Rx16bit_Cyclic_a691adb3Ack] */
  /*     1 */ Rte_COMCbk_Signal_Rx15bit_OnWrite_a1df81ad    /* [/ActiveEcuC/Com/ComConfig/Signal_Rx15bit_OnWrite_a1df81adAck] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Rx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxPduGrpInfoType, COM_CONST) Com_RxPduGrpInfo[5] = {
    /* Index    PduGrpVectorStartIdx */
  { /*     0 */                   1U },
  { /*     1 */                   1U },
  { /*     2 */                   1U },
  { /*     3 */                   1U },
  { /*     4 */                   1U }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                   Description
  RxDefPduBufferUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_RxDefPduBuffer
  RxSigInfoUsed             TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigInfo
  RxDefPduBufferEndIdx      the end index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxDefPduBufferStartIdx    the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxSigInfoEndIdx           the end index of the 0:n relation pointing to Com_RxSigInfo
  RxSigInfoStartIdx         the start index of the 0:n relation pointing to Com_RxSigInfo
  Type                      Defines whether rx Pdu is a NORMAL or TP IPdu.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[5] = {
    /* Index    RxDefPduBufferUsed  RxSigInfoUsed  RxDefPduBufferEndIdx  RxDefPduBufferStartIdx  RxSigInfoEndIdx                    RxSigInfoStartIdx                    Type                              Referable Keys */
  { /*     0 */               TRUE,         FALSE,                   1U,                     0U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle100_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Rx_fcef2243] */
  { /*     1 */               TRUE,          TRUE,                   7U,                     1U,                                1U,                                  0U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Rx_fcef2243] */
  { /*     2 */               TRUE,         FALSE,                  15U,                     7U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle_E2eProf1C_500_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Rx_fcef2243] */
  { /*     3 */               TRUE,          TRUE,                  19U,                    15U,                                2U,                                  1U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/msg_RxEvent_20_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Rx_fcef2243] */
  { /*     4 */               TRUE,         FALSE,                  27U,                    19U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO }   /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Rx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Rx_fcef2243] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element             Description
  RxAccessInfoIdx     the index of the 1:1 relation pointing to Com_RxAccessInfo
  SignalProcessing
  ValidDlc            Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[2] = {
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*     0 */              1U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be] */
  { /*     1 */              0U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U }   /* [/ActiveEcuC/Com/ComConfig/msg_RxEvent_20_oCAN_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeFalse
**********************************************************************************************************************/
/** 
  \var    Com_TxModeFalse
  \brief  Contains all relevant information for transmission mode false.
  \details
  Element       Description
  Direct        TRUE if transmission mode contains a direct part.
  TimeOffset    Initial time offset factor for cyclic transmission.
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[6] = {
    /* Index    Direct  TimeOffset  TimePeriod        Referable Keys */
  { /*     0 */  FALSE,         1U,         5U },  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  { /*     1 */  FALSE,         1U,         1U },  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  { /*     2 */  FALSE,         2U,       100U },  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be] */
  { /*     3 */  FALSE,         4U,        50U },  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  { /*     4 */   TRUE,         1U,         0U },  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  { /*     5 */  FALSE,         1U,         0U }   /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element            Description
  TxModeFalseUsed    TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxModeFalse
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[6] = {
    /* Index    TxModeFalseUsed        Referable Keys */
  { /*     0 */            TRUE },  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  { /*     1 */            TRUE },  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  { /*     2 */            TRUE },  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be] */
  { /*     3 */            TRUE },  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  { /*     4 */            TRUE },  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  { /*     5 */            TRUE }   /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element       Description
  Direct        TRUE if transmission mode contains a direct part.
  TimeOffset    Initial time offset factor for cyclic transmission.
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[6] = {
    /* Index    Direct  TimeOffset  TimePeriod        Referable Keys */
  { /*     0 */  FALSE,         1U,         5U },  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  { /*     1 */  FALSE,         1U,         1U },  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  { /*     2 */  FALSE,         2U,       100U },  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be] */
  { /*     3 */  FALSE,         4U,        50U },  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  { /*     4 */   TRUE,         1U,         0U },  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  { /*     5 */  FALSE,         1U,         0U }   /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Tx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorEndIdx      the end index of the 0:n relation pointing to Com_PduGrpVector
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxPduGrpInfoType, COM_CONST) Com_TxPduGrpInfo[6] = {
    /* Index    PduGrpVectorEndIdx                       PduGrpVectorStartIdx                      */
  { /*     0 */                                      1U,                                        0U },
  { /*     1 */                                      1U,                                        0U },
  { /*     2 */                                      1U,                                        0U },
  { /*     3 */                                      1U,                                        0U },
  { /*     4 */                                      1U,                                        0U },
  { /*     5 */ COM_NO_PDUGRPVECTORENDIDXOFTXPDUGRPINFO, COM_NO_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                   Description
  TxPduInitValueUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
  ExternalId                External ID used to call PduR_ComTransmit().
  MetaDataLength            Length of MetaData.
  TxBufferLength            the number of relations pointing to Com_TxBuffer
  TxPduInitValueEndIdx      the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx    the start index of the 0:n relation pointing to Com_TxPduInitValue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[6] = {
    /* Index    TxPduInitValueUsed  ExternalId                                                            MetaDataLength  TxBufferLength  TxPduInitValueEndIdx  TxPduInitValueStartIdx        Referable Keys */
  { /*     0 */               TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_msg_StartAppl_Tx_MyECU_346f2748,             0U,             8U,                   8U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  { /*     1 */               TRUE,              PduRConf_PduRSrcPdu_SRC_Can_PT_msg_TxCycle10_0_346f2748,             0U,             7U,                  15U,                     8U },  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  { /*     2 */               TRUE,           PduRConf_PduRSrcPdu_SRC_Can_PT_msg_TxCycle1000_10_346f2748,             0U,             2U,                  17U,                    15U },  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  { /*     3 */               TRUE, PduRConf_PduRSrcPdu_SRC_Can_PT_msg_TxCycle_E2eProf1C_500_30_346f2748,             0U,             8U,                  25U,                    17U },  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  { /*     4 */               TRUE,               PduRConf_PduRSrcPdu_SRC_Can_PT_msg_TxEvent_10_346f2748,             0U,             7U,                  32U,                    25U },  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  { /*     5 */               TRUE,               PduRConf_PduRSrcPdu_SRC_Can_msg_nm_MyECU_oCAN_3abd61be,             0U,             6U,                  38U,                    32U }   /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[38] = {
  /* Index     TxPduInitValue      Referable Keys */
  /*     0 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     1 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     2 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     3 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     4 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     5 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     6 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     7 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     8 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  /*     9 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  /*    10 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  /*    11 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  /*    12 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  /*    13 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  /*    14 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  /*    15 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be] */
  /*    16 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be] */
  /*    17 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    18 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    19 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    20 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    21 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    22 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    23 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    24 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    25 */           0x1FU,  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  /*    26 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  /*    27 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  /*    28 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  /*    29 */           0x3FU,  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  /*    30 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  /*    31 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  /*    32 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
  /*    33 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
  /*    34 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
  /*    35 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
  /*    36 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
  /*    37 */           0x00U   /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element                   Description
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxBufferEndIdx            the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[2] = {
    /* Index    BitLength  BitPosition  BusAcc                       StartByteInPduPosition  TxBufferEndIdx  TxBufferStartIdx  TxPduInfoIdx        Referable Keys */
  { /*     0 */       24U,         32U, COM_NBYTE_BUSACCOFTXSIGINFO,                     4U,            15U,              12U,           1U },  /* [/ActiveEcuC/Com/ComConfig/Signal_Tx24bit_Cyclic_85bf3e37, /ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  { /*     1 */       32U,          0U, COM_NBYTE_BUSACCOFTXSIGINFO,                     0U,            29U,              25U,           4U }   /* [/ActiveEcuC/Com/ComConfig/Signal_Tx32bit_OnWrite_b2cd4fc2, /ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_DelayTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_DelayTimeCnt
  \brief  Current counter value of minimum delay counter.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_DelayTimeCntType, COM_VAR_NOINIT) Com_DelayTimeCnt[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_GatewayProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_GatewayProcessingISRLockCounterType, COM_VAR_NOINIT) Com_GatewayProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle100_0_oCAN_3abd61be] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle_E2eProf1C_500_10_oCAN_3abd61be] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxEvent_20_oCAN_3abd61be] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Rx_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleTxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleTxPduDeferred
  \brief  Flag array used for deferred Tx confirmation handling.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_HandleTxPduDeferredType, COM_VAR_NOINIT) Com_HandleTxPduDeferred[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized = FALSE;
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCnt
  \brief  Current repetition counter value for replication of transmission requests plus one initial transmit.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RepCntType, COM_VAR_NOINIT) Com_RepCnt[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCycleCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCycleCnt
  \brief  Current counter value of repetition period for replication of transmission requests.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RepCycleCntType, COM_VAR_NOINIT) Com_RepCycleCnt[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle100_0_oCAN_3abd61be] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle_E2eProf1C_500_10_oCAN_3abd61be] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle_E2eProf1C_500_10_oCAN_3abd61be] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle_E2eProf1C_500_10_oCAN_3abd61be] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle_E2eProf1C_500_10_oCAN_3abd61be] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle_E2eProf1C_500_10_oCAN_3abd61be] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle_E2eProf1C_500_10_oCAN_3abd61be] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle_E2eProf1C_500_10_oCAN_3abd61be] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle_E2eProf1C_500_10_oCAN_3abd61be] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxEvent_20_oCAN_3abd61be] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxEvent_20_oCAN_3abd61be] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxEvent_20_oCAN_3abd61be] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxEvent_20_oCAN_3abd61be] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Rx_MyECU_oCAN_3abd61be] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Rx_MyECU_oCAN_3abd61be] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Rx_MyECU_oCAN_3abd61be] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Rx_MyECU_oCAN_3abd61be] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Rx_MyECU_oCAN_3abd61be] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Rx_MyECU_oCAN_3abd61be] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Rx_MyECU_oCAN_3abd61be] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Rx_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredFctPtrCache
**********************************************************************************************************************/
/** 
  \var    Com_RxDeferredFctPtrCache
  \brief  Cache for deferred Rx (invalid) notification.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDeferredFctPtrCacheType, COM_VAR_NOINIT) Com_RxDeferredFctPtrCache[1];
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[5];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle100_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Rx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle500_20_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Rx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxCycle_E2eProf1C_500_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Rx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_RxEvent_20_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Rx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Rx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Rx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt16
  \brief  Rx Signal and Group Signal Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferUInt16Type, COM_VAR_NOINIT) Com_RxSigBufferUInt16[2];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/Signal_Rx15bit_OnWrite_a1df81ad, /ActiveEcuC/Com/ComConfig/Signal_Rx15bit_OnWrite_a1df81ad_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Signal_Rx16bit_Cyclic_a691adb3, /ActiveEcuC/Com/ComConfig/Signal_Rx16bit_Cyclic_a691adb3_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[38];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/Signal_Tx24bit_Cyclic_85bf3e37] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/Signal_Tx24bit_Cyclic_85bf3e37] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/Signal_Tx24bit_Cyclic_85bf3e37] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/Signal_Tx32bit_OnWrite_b2cd4fc2] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/Signal_Tx32bit_OnWrite_b2cd4fc2] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/Signal_Tx32bit_OnWrite_b2cd4fc2] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/Signal_Tx32bit_OnWrite_b2cd4fc2] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_TxDeadlineMonitoringISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_WaitingForConfirmation
**********************************************************************************************************************/
/** 
  \var    Com_WaitingForConfirmation
  \brief  Flag array used for Tx error notification handling.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_WaitingForConfirmationType, COM_VAR_NOINIT) Com_WaitingForConfirmation[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/msg_StartAppl_Tx_MyECU_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle10_0_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle1000_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxCycle_E2eProf1C_500_30_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/msg_TxEvent_10_oCAN_3abd61be, /ActiveEcuC/Com/ComConfig/MyECU_oCAN_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/msg_nm_MyECU_oCAN_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/






/**********************************************************************************************************************
  END OF FILE: Com_Lcfg.c
**********************************************************************************************************************/

