/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                            All rights reserved.
 *              This software is copyright protected and proprietary to Vector Informatik GmbH.
 *              Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *              All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  SAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *              This implementation is sample code and only intended to illustrate an example of a possible BSW
 *              implementation. The implementation may not be complete and is not provided for use in production
 *              without any modifications. If this sample code is used in any way, the customer shall test
 *              this implementation as well as any of its modifications with diligent care.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: StartApplication.c
 *       Description: This StartApplication demonstrates following usecases: COM, MEM, NM, XCP
 *********************************************************************************************************************/

#define STARTAPPLICATION_SOURCE

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
//#include "Xcp.h"
//#include "Dio_Cfg.h"
#include "Dio.h"
#include "Rte_StartApplication.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>
 *********************************************************************************************************************/
volatile uint16 g_Kl15Voltage_mV = 0u;
volatile uint8 g_Kl15NmRequestActive = 0u;
volatile uint8 g_Can1EnLevel=0u;
volatile uint8 g_SS1=0u;
volatile uint8 g_SS2=0u;
volatile uint8 g_Can1NerrLevel=0u;
volatile uint8 g_Can1NstbLevel=0u;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL MACROS
**********************************************************************************************************************/
#define STARTAPPLICATION_INVALID_SIGNAL_VALUE 0xFF
#if !defined (STARTAPPLICATION_LOCAL)
# define STARTAPPLICATION_LOCAL static
#endif

#define STARTAPPLICATION_NM_COMM_CHANNEL_INVALID  0xFF
#define STARTAPPLICATION_NM_NUMBER_OF_CHANNELS    1u
#define STARTAPPLICATION_NM_COMM_MODE_MASK        0x80
#define STARTAPPLICATION_NM_COMM_CHANNEL_MASK     0x7F
#define STARTAPPLICATION_NM_MAX_COMMUSERS         1

/* Timer for Bus Sleep Mode */
#define STARTAPPLICATION_NM_DURATION_T1    20 /* T1 as multiples of cyclic runnable period 250ms */
#define STARTAPPLICATION_NM_DURATION_T2    20 /* T2 as multiples of cyclic runnable period 250ms */
#define STARTAPPLICATION_KL15_ON_THRESHOLD_MV   10000u




/**********************************************************************************************************************
  LOCAL DATA TYPES
**********************************************************************************************************************/
/* Represents all supported return codes which are transmitted by DUT via TX control signal */
typedef enum { STARTAPPLICATION_RETURN_CODE_OK = 0, STARTAPPLICATION_RETURN_CODE_ERROR = 1, STARTAPPLICATION_RETURN_CODE_UNKNOWN_COMPONENT = 2, STARTAPPLICATION_RETURN_CODE_PENDING = 3 } StartApplication_EnumCtrlReturnCodeType;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define StartApplication_START_SEC_CODE
# include "StartApplication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_SendCtrl(void);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_SendData(void);
STARTAPPLICATION_LOCAL FUNC(uint16, StartApplication_CODE) StartApplication_ReadData(void);
STARTAPPLICATION_LOCAL FUNC(uint16, StartApplication_CODE) StartApplication_ReadCtrl(void);

STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_COM_CalculateRxData(void);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_COM_CalculateTxData(void);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_COM_ReadRxData(void);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_COM_WriteTxData(void);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_MEM_Cyclic(void);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_MEM_OnDataRec_RxData(VAR(uint16, AUTOMATIC) rxDataBuffer);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_XCP_Cyclic(void);

STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_RequestComMode(uint8 channel, ComM_ModeType comMode);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_RequestComMUser(uint8 user);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_SetActiveComMUser(uint8 channel);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_GetCurrentComMode(uint8 channel, ComM_ModeType* comMode);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_OnDataRec_RxData(uint8 rxDataBuffer);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_DetermineTxCtrlSignal(void);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_HandleActiveChannel(void);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_HandleInactiveChannels(void);
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_HandleKl15Request(void);

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/
/*** FUNCTIONS FOR INTER ECU COMMUNICATION ***/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_SendCtrl(void)
{
    (void)Rte_Write_PpTxCtrl_DeSignal_Tx32bit_OnWrite_b2cd4fc2(*Rte_Pim_TxCtrlSigValue());
}

STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_SendData(void)
{
    (void)Rte_Write_PpTxData_DeSignal_Tx24bit_Cyclic_85bf3e37(*Rte_Pim_TxDataSigValue());
}

STARTAPPLICATION_LOCAL FUNC(uint16, StartApplication_CODE) StartApplication_ReadData(void)
{
    uint16 result = 0;
    (void)Rte_Read_PpRxData_DeSignal_Rx15bit_OnWrite_a1df81ad(&result);
    return result;
}

STARTAPPLICATION_LOCAL FUNC(uint16, StartApplication_CODE) StartApplication_ReadCtrl(void)
{
    uint16 result = 0;
    (void)Rte_Read_PpRxCtrl_DeSignal_Rx16bit_Cyclic_a691adb3(&result);
    return result;
}

/*** RUNNABLES **/

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApplication_Init
 * Description: Called during startup
 *
 *********************************************************************************************************************/
FUNC(void, StartApplication_CODE) StartApplication_Init(void)
{
    *Rte_Pim_ActiveComponent() = STARTAPPLICATION_ACTIVE_COMPONENT_COM_RXTX;
    *Rte_Pim_TxCtrlSigValue() = STARTAPPLICATION_RETURN_CODE_OK;
    *Rte_Pim_TxDataSigValue() = 0;
    *Rte_Pim_Uptime() = 0;

    *Rte_Pim_NM_ActiveComMChannel() = STARTAPPLICATION_NM_COMM_CHANNEL_INVALID;
    *Rte_Pim_NM_BusSleepModeTimer() = 0;
    *Rte_Pim_NM_ApplState() = NM_APPL_STATE_FULL_COMM_EXTERN;
    *Rte_Pim_NM_ActiveChannelHasFullComRequest() = FALSE;
    *Rte_Pim_NM_ActiveComMUsers() = 0;

    *Rte_Pim_MEM_DataBuffer() = 0;
    *Rte_Pim_MEM_BlockState() = MEM_STATE_UNKNOWN;

    *Rte_Pim_XcpPimDownload() = 0;
    *Rte_Pim_XcpPimUpload() = 0;

    g_Kl15Voltage_mV = 0u;
    g_Kl15NmRequestActive = 0u;


    /* Request full communication for all start application comm users */
//    (void)Rte_Call_UR_USR_CHNL_3c6d4e43_RequestComMode (COMM_FULL_COMMUNICATION);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK StartApplication_Init>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

} /* PRQA S 6050 */ /* MD_StartApplication_STCAL_6050 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApplication_Cyclic10ms
 * Description: Called every 0.01 seconds
 *
 *********************************************************************************************************************/
FUNC(void, StartApplication_CODE) StartApplication_Cyclic10ms(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApplication_Cyclic1000ms
 * Description: Called every 1.0 seconds
 *
 *********************************************************************************************************************/
FUNC(void, StartApplication_CODE) StartApplication_Cyclic1000ms(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    if(*Rte_Pim_Uptime() < 255)
    {
        (*Rte_Pim_Uptime())++;
    }
    Dio_FlipChannel(DioConf_DioChannel_DioChannel_led1);
    Dio_FlipChannel(DioConf_DioChannel_DioChannel_led2);
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApplication_Cyclic1ms
 * Description: Called every 0.001 seconds
 *
 *********************************************************************************************************************/
FUNC(void, StartApplication_CODE) StartApplication_Cyclic1ms(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    /* nothing to be done cyclically every 1 ms */
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApplication_Cyclic250ms
 * Description: Called every 0.25 seconds
 *
 *********************************************************************************************************************/

FUNC(void, StartApplication_CODE) StartApplication_Cyclic250ms(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	g_Can1EnLevel=Dio_ReadChannel(DioConf_DioChannel_DioChannel_canEn);
	g_Can1NerrLevel=Dio_ReadChannel(DioConf_DioChannel_DioChannel_canNerr);
	g_Can1NstbLevel=Dio_ReadChannel(DioConf_DioChannel_DioChannel_canNstb);
	g_SS1=Dio_ReadChannel(DioConf_DioChannel_DioChannel_SS1);
	g_SS2=Dio_ReadChannel(DioConf_DioChannel_DioChannel_SS2);
    StartApplication_NM_HandleKl15Request();
    switch(*Rte_Pim_ActiveComponent())
    {
        case STARTAPPLICATION_ACTIVE_COMPONENT_COM_RXTX:
        {
            StartApplication_COM_ReadRxData();
            StartApplication_COM_CalculateTxData();
            StartApplication_COM_WriteTxData();
            break;
        }
        case STARTAPPLICATION_ACTIVE_COMPONENT_COM_TXONLY:
        {
            StartApplication_COM_CalculateRxData();
            StartApplication_COM_CalculateTxData();
            StartApplication_COM_WriteTxData();
            break;
        }
        case STARTAPPLICATION_ACTIVE_COMPONENT_MEM:
        {
            StartApplication_MEM_Cyclic();
            break;
        }
        case STARTAPPLICATION_ACTIVE_COMPONENT_NM:
        {
//            StartApplication_NM_HandleActiveChannel();
//            StartApplication_NM_DetermineTxCtrlSignal();

            break;
        }
        case STARTAPPLICATION_ACTIVE_COMPONENT_XCP:
        {
            StartApplication_XCP_Cyclic();
            break;
        }
        default :
        {

            break;
        }

    }

//    CanNm_NetworkRequest();
//    StartApplication_NM_HandleInactiveChannels();
    if((*Rte_Pim_ActiveComponent() != STARTAPPLICATION_ACTIVE_COMPONENT_COM_RXTX)
      && (*Rte_Pim_ActiveComponent() != STARTAPPLICATION_ACTIVE_COMPONENT_COM_TXONLY))
    {
        StartApplication_SendData();
        StartApplication_SendCtrl();
    }

} /* PRQA S 6050 */ /* MD_StartApplication_STCAL_6050 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApplication_MEM_JobFinished
 * Description: Called by NvM BSW Module if a job for the StartApplication NvM block was processed
 *
 *********************************************************************************************************************/
FUNC(void, StartApplication_CODE) StartApplication_MEM_JobFinished(VAR(NvM_ServiceIdType, AUTOMATIC) ServiceId, VAR(NvM_RequestResultType, AUTOMATIC) JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    switch (ServiceId)
    {
        case NVM_WRITE_BLOCK:
            /* write job finished */
            if ( NVM_REQ_OK == JobResult)
            {
                *Rte_Pim_MEM_BlockState() = MEM_STATE_WRITE_FINISHED;
            }
            else
            {
                *Rte_Pim_MEM_BlockState() = MEM_STATE_WRITE_FAILED;
            }
            break;
        case NVM_READ_BLOCK:
            /* read job finished */
            if ( NVM_REQ_OK == JobResult)
            {
                *Rte_Pim_TxDataSigValue() = *Rte_Pim_MEM_DataBuffer();
                *Rte_Pim_MEM_BlockState() = MEM_STATE_READ_FINISHED;
            }
            else
            {
                *Rte_Pim_MEM_BlockState() = MEM_STATE_READ_FAILED;
            }
            break;
        default:
            /* nothing to do for other ServiceIDs */
            break;
    }
    if(*Rte_Pim_ActiveComponent() == STARTAPPLICATION_ACTIVE_COMPONENT_MEM)
    {
        *Rte_Pim_TxCtrlSigValue() = *Rte_Pim_MEM_BlockState();
        StartApplication_SendCtrl();
    }

}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApplication_OnDataRec_RxCtrl
 * Description: the value of the ctrl rx signal determines which usecase is active
 *
 *********************************************************************************************************************/
FUNC(void, StartApplication_CODE) StartApplication_OnDataRec_RxCtrl(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    uint8 channel;
    uint16 rxCtrlBuffer = StartApplication_ReadCtrl();
    if(*Rte_Pim_ActiveComponent() == (EnumActiveComponentType)rxCtrlBuffer)
    {
        return;
    }
    switch((EnumActiveComponentType)rxCtrlBuffer)
    {
        case STARTAPPLICATION_ACTIVE_COMPONENT_COM_RXTX:
        case STARTAPPLICATION_ACTIVE_COMPONENT_COM_TXONLY:
        {
            *Rte_Pim_ActiveComponent() = (EnumActiveComponentType)rxCtrlBuffer;
            *Rte_Pim_TxCtrlSigValue() = STARTAPPLICATION_RETURN_CODE_OK;
            break;
        }
        case STARTAPPLICATION_ACTIVE_COMPONENT_MEM:
        {
            *Rte_Pim_ActiveComponent() = (EnumActiveComponentType)rxCtrlBuffer;
            *Rte_Pim_TxDataSigValue() = 0U;
            if ( (MEM_STATE_READ_PENDING != *Rte_Pim_MEM_BlockState()) && (MEM_STATE_WRITE_PENDING != *Rte_Pim_MEM_BlockState()) )
            {
                /* activate initial read after use case activation */
                *Rte_Pim_MEM_BlockState() = MEM_STATE_WRITE_FINISHED;
            }
            *Rte_Pim_TxCtrlSigValue() = STARTAPPLICATION_RETURN_CODE_OK;
            break;
        }
        case STARTAPPLICATION_ACTIVE_COMPONENT_NM:
        {
            *Rte_Pim_ActiveComponent() = (EnumActiveComponentType)rxCtrlBuffer;
            *Rte_Pim_TxCtrlSigValue() = STARTAPPLICATION_RETURN_CODE_OK;
            break;
        }
        case STARTAPPLICATION_ACTIVE_COMPONENT_XCP:
        {
            *Rte_Pim_ActiveComponent() = (EnumActiveComponentType)rxCtrlBuffer;
            *Rte_Pim_TxCtrlSigValue() = STARTAPPLICATION_RETURN_CODE_OK;
            break;
        }
        case STARTAPPLICATION_ACTIVE_COMPONENT_INVALID:
        {
            /* Do nothing here */
            break;
        }
        case STARTAPPLICATION_ACTIVE_COMPONENT_DIAG:
        default:
        {
            *Rte_Pim_TxCtrlSigValue() = STARTAPPLICATION_RETURN_CODE_UNKNOWN_COMPONENT;
            break;
        }
    }
    /* Switch the test application state of all channels to the init state NM_APPL_STATE_FULL_COMM_EXTERN */
    for (channel=0; channel<STARTAPPLICATION_NM_NUMBER_OF_CHANNELS; channel++)
    {
        *Rte_Pim_NM_ApplState() = NM_APPL_STATE_FULL_COMM_EXTERN;
    }
    StartApplication_SendCtrl();

} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApplication_OnDataRec_RxData
 * Description: handle received data dependent on the active usecase
 *
 *********************************************************************************************************************/
FUNC(void, StartApplication_CODE) StartApplication_OnDataRec_RxData(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    uint16 rxDataBuffer = StartApplication_ReadData();
    if(rxDataBuffer == STARTAPPLICATION_INVALID_SIGNAL_VALUE)
    {
        return;
    }
    switch(*Rte_Pim_ActiveComponent())
    {
        case STARTAPPLICATION_ACTIVE_COMPONENT_MEM:
        {
            StartApplication_MEM_OnDataRec_RxData(rxDataBuffer);
            break;
        }
        case STARTAPPLICATION_ACTIVE_COMPONENT_NM:
        {
            StartApplication_NM_OnDataRec_RxData((uint8)rxDataBuffer);
            break;
        }
        default:
        {
            break;
        }
    }

} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/*** END OF RUNNABLES **/

/*** LOCAL FUNCTIONS **/

/**********************************************************************************************************************
 *
 * Local Function Entity Name: StartApplication_COM_CalculateRxData
 * Description: Calculate a substitute value for the RX signals with the same algorithm as the Tester based on the current value of the RxData signal.
 *
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_COM_CalculateRxData(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    uint16 rxData = StartApplication_ReadData();
    if( STARTAPPLICATION_INVALID_SIGNAL_VALUE != rxData )
    {
        *Rte_Pim_COM_RxSigValue0() = rxData;                                           /* Scale uint15 [0 ... 0x7fff] to uint15 [0 ... 0x7fff] */
    }

}

/**********************************************************************************************************************
 *
 * Local Function Entity Name: StartApplication_COM_CalculateTxData
 * Description: Calculate the value of the Tx signals based on the current value of the corresponding Rx signals.
 *
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_COM_CalculateTxData(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    *Rte_Pim_COM_TxSigValue0() = *Rte_Pim_COM_RxSigValue0()*0x200;                 /* Scale uint15 [0 ... 0x7fff] to uint24 [0 ... 0xffffff] */

}

/**********************************************************************************************************************
 *
 * Local Function Entity Name: StartApplication_COM_ReadRxData
 * Description: Read the current value of the RX signals from the sender/receiver ports
 *
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_COM_ReadRxData(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    uint16 rxDataBuffer = 0;
    (void)Rte_Read_PpRxData_DeSignal_Rx15bit_OnWrite_a1df81ad(&rxDataBuffer);
    if( STARTAPPLICATION_INVALID_SIGNAL_VALUE != rxDataBuffer )
    {
        *Rte_Pim_COM_RxSigValue0() = rxDataBuffer;
    }

}

/**********************************************************************************************************************
 *
 * Local Function Entity Name: StartApplication_COM_WriteTxData
 * Description: Write the current value of the TX signals from the sender/receiver ports
 *
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_COM_WriteTxData(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    (void)Rte_Write_PpTxData_DeSignal_Tx24bit_Cyclic_85bf3e37(*Rte_Pim_COM_TxSigValue0());

}

/**********************************************************************************************************************
 *
 * Local Function Entity Name: StartApplication_MEM_Cyclic
 * Description: Called by StartApplication_Cyclic250ms runnable if MEM usecase is active
 *
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_MEM_Cyclic(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    /* if no transaction is made on the block and the last transaction was not a read job */
    if ( (MEM_STATE_WRITE_FINISHED == *Rte_Pim_MEM_BlockState()) || (MEM_STATE_WRITE_FAILED == *Rte_Pim_MEM_BlockState()) )
    {
        /* signalize read pending */
        *Rte_Pim_MEM_BlockState() = MEM_STATE_READ_PENDING;
        *Rte_Pim_TxCtrlSigValue() = *Rte_Pim_MEM_BlockState();
        StartApplication_SendCtrl();
        /* start read job */
        (void)Rte_Call_PpNvmDataPort_ReadBlock(Rte_Pim_MEM_DataBuffer());
    }

}

/**********************************************************************************************************************
 *
 * Local Function Entity Name: StartApplication_MEM_OnDataRec_RxData
 * Description: Called by StartApplication_OnDataRec_RxData runnable if MEM usecase is active
 *
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_MEM_OnDataRec_RxData(VAR(uint16, AUTOMATIC) rxDataBuffer) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    /* if no transaction is made on the block and the last transaction was not a write job */
    if ( (MEM_STATE_READ_FINISHED == *Rte_Pim_MEM_BlockState()) || (MEM_STATE_READ_FAILED == *Rte_Pim_MEM_BlockState()) )
    {
        /* signalize write pending */
        *Rte_Pim_MEM_BlockState() = MEM_STATE_WRITE_PENDING;
        *Rte_Pim_TxCtrlSigValue() = *Rte_Pim_MEM_BlockState();
        StartApplication_SendCtrl();
        /* copy value to global buffer */
        *Rte_Pim_MEM_DataBuffer() = (uint8) rxDataBuffer;
        /* start write job */
        (void)Rte_Call_PpNvmDataPort_WriteBlock(Rte_Pim_MEM_DataBuffer());
    }

}

/**********************************************************************************************************************
 *
 * Local Function Entity Name: StartApplication_XCP_Cyclic
 * Description: Called by StartApplication_Cyclic250ms runnable if XCP usecase is active
 *
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_XCP_Cyclic(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    *Rte_Pim_XcpPimUpload() = *Rte_Pim_XcpPimDownload();
//    Xcp_Event(XcpConf_XcpEventChannel_XcpEventChannel_StartApplication);
}



/**********************************************************************************************************************
 *
 * Local Function Entity Name: StartApplication_NM_OnDataRec_RxData
 * Description: handle received data dependent on the active NM usecase
 *
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_OnDataRec_RxData(uint8 rxDataBuffer) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    uint8 requestedChannel;

    /* Activate the requested communication channel which is set in the remaining bits of the 8bit RxData signal and request the communication mode */
    requestedChannel = rxDataBuffer & (uint8)STARTAPPLICATION_NM_COMM_CHANNEL_MASK;

    if (requestedChannel < STARTAPPLICATION_NM_NUMBER_OF_CHANNELS)
    {
        if (*Rte_Pim_NM_ActiveComMChannel() != requestedChannel)
        {
            /* The channel under test has changed */
            *Rte_Pim_NM_ActiveComMChannel() = requestedChannel;
            /* The new channel is currently in mode FULL_COMM_EXTERN */
            *Rte_Pim_NM_ApplState() = NM_APPL_STATE_FULL_COMM_EXTERN;
            /* The channel requires one or more ComM Users */
            StartApplication_NM_SetActiveComMUser(*Rte_Pim_NM_ActiveComMChannel());
        }
        /* Get the communication mode from the highest bit of the 8bit RxData signal: 1 = FULL communication, 0 = no communication */
        *Rte_Pim_NM_ActiveChannelHasFullComRequest() = (rxDataBuffer & (uint8)STARTAPPLICATION_NM_COMM_MODE_MASK) != 0;
        StartApplication_NM_DetermineTxCtrlSignal();
    }
}

/**********************************************************************************************************************
 *
 * Local Function Entity Name: StartApplication_NM_RequestComMode
 * Description: Request the given ComM communication mode for the given channel.
 *
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_RequestComMode(uint8 channel, ComM_ModeType comMode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    Std_ReturnType retValue = E_OK;
    if (channel >= STARTAPPLICATION_NM_NUMBER_OF_CHANNELS)
    {
        return;
    }
    switch(channel)
    {
        case 0: /* CAN*/
        {
            retValue |= Rte_Call_UR_USR_CHNL_3c6d4e43_RequestComMode (comMode);
            break;
        }
        default: /* PRQA S 2018 */ /* MD_StartApplication_2018 */
        {
            retValue = E_NOT_OK;
            break;
        }
    }

} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *
 * Local Function Entity Name: StartApplication_NM_RequestComMUser
 * Description: Request the COMM_FULL_COMMUNICATION for given ComMUser.
 *
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_RequestComMUser(uint8 user) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    Std_ReturnType retValue = E_OK;
    switch(user)
    {
        case 0:
        {
            retValue |= Rte_Call_UR_USR_CHNL_3c6d4e43_RequestComMode (COMM_FULL_COMMUNICATION);
            break;
        }
        default:
        {
            retValue = E_NOT_OK;
            break;
        }
    }
} /* PRQA S 6050 */ /* MD_StartApplication_STCAL_6050 */

/**********************************************************************************************************************
 *
 * Local Function Entity Name: StartApplication_NM_GetCurrentComMode
 * Description: Get the current ComM communication mode for the given channel.
 *
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_GetCurrentComMode(uint8 channel, ComM_ModeType* comMode)
{
    Std_ReturnType retValue = E_OK;
    if (channel >= STARTAPPLICATION_NM_NUMBER_OF_CHANNELS)
    {
        return;
    }
    switch(channel)
    {
        case 0: /* CAN*/
        {
            retValue |= Rte_Call_UR_USR_CHNL_3c6d4e43_GetCurrentComMode (comMode);
            break;
        }
        default: /* PRQA S 2018 */ /* MD_StartApplication_2018 */
        {
            retValue = E_NOT_OK;
            break;
        }
    }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *
 * Local Function Entity Name: StartApplication_NM_SetActiveComMUser
 * Description: Set the active ComM Users for the given channel.
 *
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_SetActiveComMUser(uint8 channel) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    switch (channel)
    {
        case 0: /* CAN*/
        {
            *Rte_Pim_NM_ActiveComMUsers() = 1 << 0;
            break;
        }
        default:
        {
            *Rte_Pim_NM_ActiveComMUsers() = 0;
            break;
        }
    }
}

/**********************************************************************************************************************
 * StartApplication_NM_HandleActiveChannel()
 *********************************************************************************************************************/
/*! \brief       Execute the state machine for the active channel.
 *  \details     In case NoCom is requested for the active channel
 *               Otherwise calling the function has no effect.
 *  \pre         The NM usecase is active and the active channel is valid
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
*********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_HandleActiveChannel(void)
{
    if (STARTAPPLICATION_ACTIVE_COMPONENT_NM != *Rte_Pim_ActiveComponent())
    {
        return;
    }
    if ( STARTAPPLICATION_NM_COMM_CHANNEL_INVALID == *Rte_Pim_NM_ActiveComMChannel())
    {
        return;
    }
    if (FALSE != *Rte_Pim_NM_ActiveChannelHasFullComRequest())
    {
        *Rte_Pim_NM_BusSleepModeTimer() = 0;
        *Rte_Pim_NM_ApplState() = NM_APPL_STATE_FULL_COMM_EXTERN;
        StartApplication_NM_RequestComMode(*Rte_Pim_NM_ActiveComMChannel(), COMM_FULL_COMMUNICATION);
    }
    else
    {
        switch(*Rte_Pim_NM_ApplState())
        {
            case NM_APPL_STATE_FULL_COMM_EXTERN:
            {
                /* Tester has switched to no communication */
                StartApplication_NM_RequestComMode(*Rte_Pim_NM_ActiveComMChannel(), COMM_NO_COMMUNICATION);
                *Rte_Pim_NM_ApplState() = NM_APPL_STATE_NO_COMM_EXTERN;
                *Rte_Pim_NM_BusSleepModeTimer() = 0;
                break;
            }
            case NM_APPL_STATE_NO_COMM_EXTERN:
            {
                ComM_ModeType comMMode;
                StartApplication_NM_GetCurrentComMode(*Rte_Pim_NM_ActiveComMChannel(), &comMMode);
                if (0 == *Rte_Pim_NM_BusSleepModeTimer())
                {
                    /* Timer T1 is not running */
                    if (COMM_NO_COMMUNICATION == comMMode)
                    {
                        /* Bus is in NoCom --> start timer T1 */
                        *Rte_Pim_NM_BusSleepModeTimer() = STARTAPPLICATION_NM_DURATION_T1;
                    }
                }
                else
                {
                    /* Timer T1 is running */
                    if (*Rte_Pim_NM_BusSleepModeTimer() > 1)
                    {
                        (*Rte_Pim_NM_BusSleepModeTimer())--;
                        if (COMM_FULL_COMMUNICATION == comMMode)
                        {
                            /* Bus is in FullCom although it was not requested --> wakeup by bus occurred */
                            /* Stop timer T1, it will be restarted once the channel is in NoCom */
                            *Rte_Pim_NM_BusSleepModeTimer() = 0;
                        }
                    }
                    else
                    {
                        /* T1 timer has expired, request full communication, restart the T2 timer, switch to the internal full communication state */
                        StartApplication_NM_RequestComMode(*Rte_Pim_NM_ActiveComMChannel(), COMM_FULL_COMMUNICATION);
                        *Rte_Pim_NM_ApplState() = NM_APPL_STATE_FULL_COMM_INTERN;
                        *Rte_Pim_NM_BusSleepModeTimer() = STARTAPPLICATION_NM_DURATION_T2;
                    }
                }
                break;
            }
            case NM_APPL_STATE_FULL_COMM_INTERN:
            {
                if (0 != *Rte_Pim_NM_BusSleepModeTimer())
                {
                    /* Timer T2 is running */
                    if (*Rte_Pim_NM_BusSleepModeTimer() > 1)
                    {
                        (*Rte_Pim_NM_BusSleepModeTimer())--;
                        StartApplication_NM_DetermineTxCtrlSignal();
                    }
                    else
                    {
                        /* T2 timer has expired, request no communication, restart the T1 timer, send the TxCtrl signal with value 0 (=no communication) and switch to the external no communication state */
                        StartApplication_NM_RequestComMode(*Rte_Pim_NM_ActiveComMChannel(), COMM_NO_COMMUNICATION);
                        *Rte_Pim_NM_BusSleepModeTimer() = 0;
                        *Rte_Pim_NM_ApplState() = NM_APPL_STATE_NO_COMM_EXTERN;
                        StartApplication_NM_DetermineTxCtrlSignal();
                    }
                }
                break;
            }
            default:
            {
                *Rte_Pim_NM_ApplState() = NM_APPL_STATE_FULL_COMM_EXTERN; /* Set to init state */
                break;
            }
        } /* end of switch(*Rte_Pim_NM_ApplState()[channel]) */
    }
} /* PRQA S 2006, 6030, 6080 */ /* MD_MSR_14.7, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 * StartApplication_NM_HandleInactiveChannels
 *********************************************************************************************************************/
/*! \brief       Request FullCommunication for each channel unless the channel is the active channel in the NM usecase.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
*********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_HandleInactiveChannels(void)
{
    uint8 i;
    if (*Rte_Pim_ActiveComponent() == STARTAPPLICATION_ACTIVE_COMPONENT_NM)
    {
        for (i = 0; i < STARTAPPLICATION_NM_MAX_COMMUSERS; i++)
        {
            if (0 == (*Rte_Pim_NM_ActiveComMUsers() & (uint32)(1 << i)))
            {
                StartApplication_NM_RequestComMUser(i);
            }
        }
    }
    else
    {
        for (i = 0; i < STARTAPPLICATION_NM_NUMBER_OF_CHANNELS; i++)
        {
            StartApplication_NM_RequestComMode(i, COMM_FULL_COMMUNICATION);
        }
    }
}

/**********************************************************************************************************************
 * StartApplication_NM_HandleKl15Request
 *********************************************************************************************************************/
/*! \brief       Map a simulated KL15 voltage to a local ComM request.
 *  \details     KL15 > 10V  -> request FULL communication
 *               KL15 < 10V  -> release local communication request
 *               KL15 == 10V -> keep previous state
 *********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_HandleKl15Request(void)
{
    if ((g_Kl15NmRequestActive == 0u) && (g_Kl15Voltage_mV > STARTAPPLICATION_KL15_ON_THRESHOLD_MV))
    {
        *Rte_Pim_NM_ActiveComMChannel() = 0u;
        *Rte_Pim_NM_ActiveComMUsers() = (uint32)(1u << 0);
        *Rte_Pim_NM_ActiveChannelHasFullComRequest() = TRUE;
        *Rte_Pim_NM_ApplState() = NM_APPL_STATE_FULL_COMM_EXTERN;
        *Rte_Pim_NM_BusSleepModeTimer() = 0u;
        StartApplication_NM_RequestComMode(0u, COMM_FULL_COMMUNICATION);
        StartApplication_NM_DetermineTxCtrlSignal();
        g_Kl15NmRequestActive = 1u;
    }
    else if ((g_Kl15NmRequestActive != 0u) && (g_Kl15Voltage_mV < STARTAPPLICATION_KL15_ON_THRESHOLD_MV))
    {
        *Rte_Pim_NM_ActiveComMChannel() = 0u;
        *Rte_Pim_NM_ActiveChannelHasFullComRequest() = FALSE;
        *Rte_Pim_NM_ApplState() = NM_APPL_STATE_NO_COMM_EXTERN;
        *Rte_Pim_NM_BusSleepModeTimer() = 0u;
        StartApplication_NM_RequestComMode(0u, COMM_NO_COMMUNICATION);
        StartApplication_NM_DetermineTxCtrlSignal();
        g_Kl15NmRequestActive = 0u;
    }
}


/**********************************************************************************************************************
 * StartApplication_NM_DetermineTxCtrlSignal()
 *********************************************************************************************************************/
/*! \brief       Set the TxCtrl signal as follows: Bits 0..5 = channel, Bit 6 = internal NW request, Bit 7: external NW request
 *  \pre         The NM usecase is active
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
*********************************************************************************************************************/
STARTAPPLICATION_LOCAL FUNC(void, StartApplication_CODE) StartApplication_NM_DetermineTxCtrlSignal(void)
{
    *Rte_Pim_TxCtrlSigValue() = *Rte_Pim_NM_ActiveComMChannel();
    if (NM_APPL_STATE_FULL_COMM_INTERN == *Rte_Pim_NM_ApplState())
    {
        *Rte_Pim_TxCtrlSigValue() |= 0x40;
    }
    if (NM_APPL_STATE_FULL_COMM_EXTERN == *Rte_Pim_NM_ApplState())
    {
        *Rte_Pim_TxCtrlSigValue() |= 0x80;
    }
}


/*** END OF LOCAL FUNCTIONS **/


# define StartApplication_STOP_SEC_CODE
# include "StartApplication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/****************************************************************************/
/*  MISRA deviations                                                        */
/****************************************************************************/
/* Justification for module-specific MISRA deviations:

  MD_StartApplication_2018: MISRA rule: 14.1
      Reason:     Default label is provided as a defensive measure against possible future code changes and to comply with rule 15.3.
      Risk:       There is no risk.
      Prevention: Not applicable.

  MD_StartApplication_STCAL_6050:
    Reason:     Number of distinct function calls depends on the configuration.
    Risk:       There is no risk.
    Prevention: Not applicable.
*/

/**********************************************************************************************************************
  END OF FILE: StartApplication.c
**********************************************************************************************************************/
