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
 *              File: Xcp_Lcfg.c
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

    
#define XCP_LCFG_SOURCE
    
#include "Xcp.h"

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

#if ( XCP_DAQ == STD_ON )
# define XCP_START_SEC_VAR_NOCACHE_NOINIT_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

XCP_LOCAL VAR(uint8, XCP_VAR_NOINIT_NOCACHE) Xcp_SendQueue_Core0[XCP_NUMBER_OF_CHANNELS][256UL];

# define XCP_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"
#endif

#define XCP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#if( XCP_DAQ == STD_ON )
CONSTP2VAR(uint8, XCP_CONST, XCP_VAR_NOINIT) Xcp_SendQueueRef[XCP_NUMBER_OF_CORES] =
{
  &Xcp_SendQueue_Core0[0][0]
};

CONST(uint32, XCP_CONST) Xcp_SendQueueSize[XCP_NUMBER_OF_CORES] =
{
  sizeof(Xcp_SendQueue_Core0[0])
};

CONST(Xcp_ECcIDType, XCP_CONST) Xcp_ECcIdMapping[XCP_MAX_EVENT] = 
{
  {
    0U, 
    0U
  }, 
  {
    0U, 
    0U
  }, 
  {
    0U, 
    0U
  }, 
  {
    0U, 
    0U
  }
};
#endif

/* PRQA S 1334 EOF */ /* MD_Xcp_1334 */
CONST(Xcp_TlApiType, XCP_CONST) Xcp_TlApi[1] = 
{
  {
    CanXcp_Send /*  ApplXcpSend  */ , 
    CanXcp_SendFlush /*  ApplXcpSendFlush  */ , 
    CanXcp_TLService /*  ApplXcpTLService  */ 
  }
};

/* Events */
 
/* Flash programming */

#define XCP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

