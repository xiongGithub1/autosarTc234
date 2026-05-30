/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       \file    Eep_30_XXspi01.c
 *       \brief   Eep Spi implementation
 *
 *       \details  Eep provides API services to upper layer (Ea). Eep performs jobs on underlying EEPROM device via
 *                 SPI bus communication.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Eep_30_XXspi01.h"
#include "Eep_30_XXspi01_Cbk.h"

/* Eep Processing */
#include "Eep_30_XXspi01_Proc.h"

/**********************************************************************************************************************
 * VERSION CHECK
 *********************************************************************************************************************/

/* AUTOSAR version has to match the definitions in the static header file */
#if ( ((4u) != EEP_30_XXSPI01_AR_RELEASE_MAJOR_VERSION) || \
      ((0u) != EEP_30_XXSPI01_AR_RELEASE_MINOR_VERSION)    \
    )
# error "AUTOSAR specification version numbers of Eep_30_XXspi01.c and Eep_30_XXspi01.h are inconsistent!"
#endif

/* implementation version has to match the definitions in the static header file */
#if ( ((0x03u) != EEP_30_XXSPI01_SW_MAJOR_VERSION) || \
      ((0x00u) != EEP_30_XXSPI01_SW_MINOR_VERSION)    \
    )
# error "Software version numbers of Eep_30_XXspi01.c and Eep_30_XXspi01.h are inconsistent!"
#endif

/* generator version has to match the definitions in the generated header file */
#if ( ((2u) != EEP_30_XXSPI01_CFG_MAJOR_VERSION) || \
      ((2u) != EEP_30_XXSPI01_CFG_MINOR_VERSION)    \
    )
# error "Generator version numbers of Eep_30_XXspi01.c and Eep_30_XXspi01_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define EEP_30_XXSPI01_INST1_INDEX      0x00u
#define EEP_30_XXSPI01_INST2_INDEX      0x01u
#define EEP_30_XXSPI01_MASK_LSBIT       0x01u

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#ifndef EEP_LOCAL /* COV_EEP_COMPATIBILITY */
# define EEP_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define EEP_30_XXSPI01_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (EEP_30_XXSPI01_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_DetChkInit()
**********************************************************************************************************************/
/*!
 * \brief      Checks if module is initialized.
 * \details    Checks if module is initialized.
 * \param[in]  Index
 * \return     E_OK: Module is initialized
 *             E_NOT_OK: Module is not yet initialized
 * \pre        Development error detection is enabled.
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_DetChkInit(uint8 Index);

/**********************************************************************************************************************
  Eep_30_XXspi01_DetChkDataPointer()
**********************************************************************************************************************/
 /*!
  * \brief      Checks if the input buffer pointer related to the current job is a NULL_PTR.
  * \details    Checks DesDataBufferPtr for read class jobs and SrcDataBufferPtr for write class jobs.
  * \param[in]  DesDataBufferPtr
  * \param[in]  SrcDataBufferPtr
  * \param[in]  JobType
  * \return     E_OK: DataBufferPtr is ok
  *             E_NOT_OK: DataBufferPtr is invalid
  * \pre        Development error detection is enabled.
  * \context    TASK
  * \reentrant  TRUE
  * \synchronous TRUE
  */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_DetChkDataPointer(Eep_30_XXspi01_ConstBufferPtrType DesDataBufferPtr, Eep_30_XXspi01_ConstBufferPtrType SrcDataBufferPtr, Eep_30_XXspi01_JobType JobType);

/**********************************************************************************************************************
  Eep_30_XXspi01_DetChkAddressBoundary()
**********************************************************************************************************************/
/*!
 * \brief      Checks if EepromAddress is within range according to current job.
 * \details    Checks if EepromAddress is within range according to current job.
 * \param[in]  Index
 * \param[in]  EepromAddress
 * \param[in]  JobType
 * \return     E_OK: EepromAddress is valid
 *             E_NOT_OK: EepromAddress is invalid/out of range
 * \pre        Development error detection is enabled.
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_DetChkAddressBoundary(uint8 Index, Eep_30_XXspi01_AddressType EepromAddress, Eep_30_XXspi01_JobType JobType);

/**********************************************************************************************************************
  Eep_30_XXspi01_DetChkLength()
**********************************************************************************************************************/
/*!
 * \brief      Checks if Length parameter is within range according to current job.
 * \details    Checks if Length parameter is within range according to current job.
 * \param[in]  Index
 * \param[in]  Length
 * \param[in]  EepromAddress
 * \param[in]  JobType
 * \return     E_OK: Length is valid
 *             E_NOT_OK: Length is invalid/out of range
 * \pre        Development error detection is enabled.
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_DetChkLength(uint8 Index, Eep_30_XXspi01_LengthType Length, Eep_30_XXspi01_AddressType EepromAddress, Eep_30_XXspi01_JobType JobType);
#endif

#if (EEP_30_XXSPI01_DEV_ERROR_REPORT == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_DetGetServiceId()
**********************************************************************************************************************/
/*!
 * \brief      Maps JobType to according service id which is used for development error reporting.
 * \details    Maps JobType to according service id which is used for development error reporting.
 * \param[in]  JobType
 * \return     ServiceId
 * \pre        -
 * \config     Development error detection is enabled
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 */
EEP_LOCAL FUNC(uint8, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_DetGetServiceId(Eep_30_XXspi01_JobType JobType);
#endif

/**********************************************************************************************************************
  Eep_30_XXspi01_CheckIdle()
**********************************************************************************************************************/
/*!
 * \brief      Checks if module is currently idle.
 * \details    Checks if module is currently idle. Asynchronous jobs can only be requested if module is currently idle.
 * \return     E_OK: Module is idle
 *             E_NOT_OK: Module is busy
 * \pre        -
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_CheckIdle(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_InitStd()
**********************************************************************************************************************/
/*!
 * \brief      Performs Init service for EEP instance according to Index.
 * \details    Performs Init service for EEP instance according to Index.
 * \param[in]  Index
 * \param[in]  ConfigPtr
 * \pre        -
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 * \trace DSGN-Eep22767
 */
EEP_LOCAL FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitStd(uint8 Index, P2CONST(Eep_30_XXspi01_ConfigType, AUTOMATIC, EEP_30_XXSPI01_PBCFG) ConfigPtr);

/**********************************************************************************************************************
  Eep_30_XXspi01_SetModeStd()
**********************************************************************************************************************/
/*!
 * \brief      Performs SetMode service for EEP instance according to Index.
 * \details    Performs SetMode service for EEP instance according to Index.
 * \param[in]  Index
 * \param[in]  Mode
 * \pre        -
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 * \trace DSGN-Eep22767
 */
EEP_LOCAL FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetModeStd(uint8 Index, MemIf_ModeType Mode);

/**********************************************************************************************************************
  Eep_30_XXspi01_SetHandlingStd()
**********************************************************************************************************************/
/*!
 * \brief      Performs SetHandling service for EEP instance according to Index.
 * \details    Performs SetHandling service for EEP instance according to Index.
 * \param[in]  Index
 * \param[in]  Handling
 * \pre        -
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 * \trace DSGN-Eep22767
 */
EEP_LOCAL FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetHandlingStd(uint8 Index, Eep_30_XXspi01_HandlingType Handling);

/**********************************************************************************************************************
  Eep_30_XXspi01_CancelStd()
**********************************************************************************************************************/
/*!
 * \brief      Performs Cancel service for EEP instance according to Index.
 * \details    Performs Cancel service for EEP instance according to Index.
 * \param[in]  Index
 * \pre        -
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 * \trace DSGN-Eep22767
 */
EEP_LOCAL FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_CancelStd(uint8 Index);

/**********************************************************************************************************************
  Eep_30_XXspi01_GetJobResultStd()
**********************************************************************************************************************/
/*!
 * \brief      Performs checks and retrieves current job result of component.
 * \details    Performs checks and retrieves current job result of component.
 * \param[in]  Index
 * \pre        -
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 */
EEP_LOCAL FUNC(MemIf_JobResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetJobResultStd(uint8 Index);

#if (EEP_30_XXSPI01_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_GetVersionInfoStd()
**********************************************************************************************************************/
/*!
 * \brief      Stores version information to structure referenced by input parameter.
 * \details    Stores version information to structure referenced by input parameter.
 * \param[out]  versioninfo
 * \param[in]   Index
 * \pre        -
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 */
EEP_LOCAL FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetVersionInfoStd(P2VAR(Std_VersionInfoType, AUTOMATIC, EEP_30_XXSPI01_APPL_DATA) versioninfo, uint8 Index);
#endif

/**********************************************************************************************************************
  Eep_30_XXspi01_AsynchronousJob()
**********************************************************************************************************************/
/*!
 * \brief      Initiates job parameter according to requested asynchronous job.
 * \details    Initiates job parameter according to requested asynchronous job.
 *             Service is called upon Read (Incremental), Write (Incremental), Compare (Incremental), Erase requests.
 * \param[in]  Index
 * \param[in]  JobType
 * \param[in]  EepromAddress
 * \param[in]  DesDataBufferPtr
 * \param[in]  SrcDataBufferPtr
 * \param[in]  Length
 * \return     E_OK: Asynchronous job was successfully requested
 *             E_NOT_OK: Asynchronous job was declined
 * \pre        -
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 * \trace DSGN-Eep22767
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_AsynchronousJob(uint8 Index,
                                                    Eep_30_XXspi01_JobType JobType,
                                                    Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_BufferPtrType DesDataBufferPtr,
                                                    Eep_30_XXspi01_ConstBufferPtrType SrcDataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);

#if (EEP_30_XXSPI01_TEST_COM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_TestComStd()
**********************************************************************************************************************/
/*!
 * \brief      Initiates job parameter according to test communication job.
 * \details    Initiates job parameter according to test communication job.
 * \param[in]  Index
 * \return     E_OK: TestCom job was successfully requested
 *             E_NOT_OK: TestCom job was declined
 * \pre        -
 * \config     Test Communication API is enabled via configuration
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 * \trace DSGN-Eep22767
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_TestComStd(uint8 Index);
#endif

#if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_UnlockStd()
**********************************************************************************************************************/
/*!
 * \brief      Initiates job parameter according to unlock job.
 * \details    Initiates job parameter according to unlock job.
 * \param[in]  Index
 * \param[in]  LockLevel
 * \return     E_OK: Unlock job was successfully requested
 *             E_NOT_OK: Unlock job was declined
 * \pre        -
 * \config     Unlock Eeprom API is enabled via configuration
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 * \trace DSGN-Eep22767
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_UnlockStd(uint8 Index, Eep_30_XXspi01_LockLevelType LockLevel);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (EEP_30_XXSPI01_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_DetChkInit()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_DetChkInit(uint8 Index)
{
    Std_ReturnType retVal = E_OK;

    /* #10 Check if corresponding ConfigPtr is NULL_PTR */
    if (Eep_30_XXspi01_CfgPtr[Index] == NULL_PTR)
    {
        retVal = E_NOT_OK;
    }

    return retVal;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_DetChkDataPointer()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_DetChkDataPointer(Eep_30_XXspi01_ConstBufferPtrType DesDataBufferPtr, Eep_30_XXspi01_ConstBufferPtrType SrcDataBufferPtr, Eep_30_XXspi01_JobType JobType)
{
    Std_ReturnType retVal = E_OK;

    switch (JobType)
    {
    case EEP_SPI_JOB_READ:
    case EEP_SPI_JOB_READINC:
        /* #10 Check if DesDataBufferPtr is NULL_PTR */
        if (DesDataBufferPtr == NULL_PTR) {
            retVal = E_NOT_OK;
        }
        break;
    case EEP_SPI_JOB_WRITE:
    case EEP_SPI_JOB_WRITEINC:
    case EEP_SPI_JOB_COMPARE:
    case EEP_SPI_JOB_COMPAREINC:
        /* #20 Check if SrcDataBufferPtr is NULL_PTR */
        if (SrcDataBufferPtr == NULL_PTR) {
            retVal = E_NOT_OK;
        }
        break;
    default: /* case EEP_SPI_JOB_ERASE: */
        /* #30 Erase jobs do not contain any DataBufferPtr. Thus this is always valid */
        retVal = E_OK;
        break;

    }

    return retVal;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_DetChkAddressBoundary()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_DetChkAddressBoundary(uint8 Index, Eep_30_XXspi01_AddressType EepromAddress, Eep_30_XXspi01_JobType JobType)
{
    Std_ReturnType retVal = E_OK;

#if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
    if (Eep_30_XXspi01_IsIncrementalJob(JobType) == TRUE)
    {
        /* #10 Within incremental register jobs the EepromAddress needs to be lower than the base address, because incremental register memory is at the beginning of address space */
        if (EepromAddress >= Eep_30_XXspi01_CfgPtr[Index]->MemBaseAddress)
        {
            retVal = E_NOT_OK;
        }
        /* #20 EepromAddress has to be word aligned for incremental write jobs */
        if (JobType == EEP_SPI_JOB_WRITEINC)
        {
            /* #25 Check if EepromAddress is odd */
            if ((EepromAddress & EEP_30_XXSPI01_MASK_LSBIT) == 1u)
            {
                retVal = E_NOT_OK;
            }
        }
    }
    else
#endif
    {
        /* #30 Check if EepromAddress is within range */
        if (EepromAddress > Eep_30_XXspi01_CfgPtr[Index]->MemLastUsedAddress)
        {
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_DetChkLength()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_DetChkLength(uint8 Index, Eep_30_XXspi01_LengthType Length, Eep_30_XXspi01_AddressType EepromAddress, Eep_30_XXspi01_JobType JobType)
{
    Std_ReturnType retVal = E_OK;

    /* #10 Check if Length parameter is 0 */
    if (Length == 0)
    {
        retVal = E_NOT_OK;
    }

#if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
    if (Eep_30_XXspi01_IsIncrementalJob(JobType) == TRUE)
    {
        if ((Length + EepromAddress) > Eep_30_XXspi01_CfgPtr[Index]->MemBaseAddress)
        {
            retVal = E_NOT_OK;
        }
        /* #20 Length has to be word aligned for incremental write jobs */
        if (JobType == EEP_SPI_JOB_WRITEINC)
        {
            /* #25 Check if Length is odd */
            if ((Length & EEP_30_XXSPI01_MASK_LSBIT) == 1u)
            {
                retVal = E_NOT_OK;
            }
        }
    }
    else
#endif
    {
        /* #30 Check if Length parameter is out of range */
        if ((Length + EepromAddress) > (Eep_30_XXspi01_CfgPtr[Index]->MemLastUsedAddress + 1u))
        {
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}
#endif

#if (EEP_30_XXSPI01_DEV_ERROR_REPORT == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_DetGetServiceId()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL FUNC(uint8, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_DetGetServiceId(Eep_30_XXspi01_JobType JobType)
{
    uint8 retVal;

    /* #10 Map JobType to according ServiceId */
    switch (JobType)
    {
    case EEP_SPI_JOB_READ:
    case EEP_SPI_JOB_READINC:
        retVal = EEP_30_XXSPI01_SID_READ;
        break;
    case EEP_SPI_JOB_WRITE:
    case EEP_SPI_JOB_WRITEINC:
        retVal = EEP_30_XXSPI01_SID_WRITE;
        break;
    case EEP_SPI_JOB_COMPARE:
    case EEP_SPI_JOB_COMPAREINC:
        retVal = EEP_30_XXSPI01_SID_COMPARE;
        break;
    default: /* case EEP_SPI_JOB_ERASE: */
        retVal = EEP_30_XXSPI01_SID_ERASE;
        break;
    }

    return retVal;
}
#endif

/**********************************************************************************************************************
  Eep_30_XXspi01_CheckIdle()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_CheckIdle(void)
{
    Std_ReturnType retVal = E_NOT_OK;

    /* #10 Check if Eep is idle */
    if (Eep_30_XXspi01_GetCurrentStatus() == MEMIF_IDLE)
    {
        retVal = E_OK;
    }

    return retVal;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_InitStd()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
EEP_LOCAL FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitStd(uint8 Index, P2CONST(Eep_30_XXspi01_ConfigType, AUTOMATIC, EEP_30_XXSPI01_PBCFG) ConfigPtr)
{
    /* ----- Local Variables -----------------------------------------------------------------------------*/
    uint8 errorId = EEP_30_XXSPI01_E_NO_ERROR;

    /* ----- Development Error Checks --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_DETECT == STD_ON)

    /* ----- UNINIT CHECK --------------------------------------------------------------------------------*/
    if (ConfigPtr == NULL_PTR)
    {
        errorId = EEP_30_XXSPI01_E_PARAM_CONFIG;
    }
    else
#endif /* EEP_30_XXSPI01_DEV_ERROR_DETECT */
    {
        /* ----- Implementation ------------------------------------------------------------------------------*/
        /* #10 Initialize Eep with values referenced by ConfigPtr */
        Eep_30_XXspi01_InitCfgArray(Index, ConfigPtr); /* SBSW_EEP_03 */

        /* #20 Initialize component parameter, flags and state machine */
        Eep_30_XXspi01_InitComponentParameter();

        /* #30 Set both mode and handling to default values from configuration */
        Eep_30_XXspi01_SetCurrentMode(Eep_30_XXspi01_CfgPtr[Index]->DefaultMode);
        Eep_30_XXspi01_SetCurrentHandling(Eep_30_XXspi01_CfgPtr[Index]->DefaultHandling);
    }
    /* ----- Development Error Report --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_REPORT == STD_ON)
    if (errorId != EEP_30_XXSPI01_E_NO_ERROR)
    {
      (void)Det_ReportError(EEP_30_XXSPI01_MODULE_ID, Index, EEP_30_XXSPI01_SID_INIT, errorId);
    }
#else
    EEP_30_XXSPI01_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
#endif
}

/**********************************************************************************************************************
  Eep_30_XXspi01_SetModeStd()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetModeStd(uint8 Index, MemIf_ModeType Mode)
{
    /* ----- Local Variables -----------------------------------------------------------------------------*/
    uint8 errorId = EEP_30_XXSPI01_E_NO_ERROR;

    /* ----- Development Error Checks --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_DETECT == STD_ON)

    /* ----- UNINIT CHECK --------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_DetChkInit(Index) == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_UNINIT;
    }
    else
    /* ----- BUSY CHECK ----------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_CheckIdle() == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_BUSY;
    }
    else
#endif /* EEP_30_XXSPI01_DEV_ERROR_DETECT */
    {
        /* ----- Implementation ------------------------------------------------------------------------------*/
        /* #10 Set mode of Eep module */
        Eep_30_XXspi01_SetCurrentMode(Mode);
    }
    /* ----- Development Error Report --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_REPORT == STD_ON)
    if (errorId != EEP_30_XXSPI01_E_NO_ERROR)
    {
      (void)Det_ReportError(EEP_30_XXSPI01_MODULE_ID, Index, EEP_30_XXSPI01_SID_SET_MODE, errorId);
    }
#else
    EEP_30_XXSPI01_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
    EEP_30_XXSPI01_DUMMY_STATEMENT(Index); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
#endif

}

/**********************************************************************************************************************
  Eep_30_XXspi01_SetHandlingStd()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetHandlingStd(uint8 Index, Eep_30_XXspi01_HandlingType Handling)
{
    /* ----- Local Variables -----------------------------------------------------------------------------*/
    uint8 errorId = EEP_30_XXSPI01_E_NO_ERROR;

    /* ----- Development Error Checks --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_DETECT == STD_ON)

    /* ----- UNINIT CHECK --------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_DetChkInit(Index) == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_UNINIT;
    }
    else
    /* ----- BUSY CHECK ----------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_CheckIdle() == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_BUSY;
    }
    else
#endif /* EEP_30_XXSPI01_DEV_ERROR_DETECT */
    {
        /* ----- Implementation ------------------------------------------------------------------------------*/
        /* #10 Set handling of Eep module */
        Eep_30_XXspi01_SetCurrentHandling(Handling);
    }
    /* ----- Development Error Report --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_REPORT == STD_ON)
    if (errorId != EEP_30_XXSPI01_E_NO_ERROR)
    {
        (void)Det_ReportError(EEP_30_XXSPI01_MODULE_ID, Index, EEP_30_XXSPI01_SID_SET_HANDLING, errorId);
    }
#else
    EEP_30_XXSPI01_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
    EEP_30_XXSPI01_DUMMY_STATEMENT(Index); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
#endif
}

/**********************************************************************************************************************
  Eep_30_XXspi01_CancelStd()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
EEP_LOCAL FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_CancelStd(uint8 Index)
{
    /* ----- Local Variables -----------------------------------------------------------------------------*/
    uint8 errorId = EEP_30_XXSPI01_E_NO_ERROR;

    /* #10 Perform Development Error Checks */
#if (EEP_30_XXSPI01_DEV_ERROR_DETECT == STD_ON)

    /* ----- UNINIT CHECK --------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_DetChkInit(Index) == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_UNINIT;
    }
#endif /* EEP_30_XXSPI01_DEV_ERROR_DETECT */

    /* ----- IDLE CHECK ----------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_CheckIdle() == E_NOT_OK)
    {
        /* #20 Cancel currently running asynchronous job */
        Eep_30_XXspi01_CancelJob();
    }

    /* ----- Development Error Report --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_REPORT == STD_ON)
    if (errorId != EEP_30_XXSPI01_E_NO_ERROR)
    {
        (void)Det_ReportError(EEP_30_XXSPI01_MODULE_ID, Index, EEP_30_XXSPI01_SID_CANCEL, errorId);
    }
#else
    EEP_30_XXSPI01_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
    EEP_30_XXSPI01_DUMMY_STATEMENT(Index); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
#endif
}

/**********************************************************************************************************************
  Eep_30_XXspi01_GetJobResultStd()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL FUNC(MemIf_JobResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetJobResultStd(uint8 Index)
{
    /* ----- Local Variables -----------------------------------------------------------------------------*/
    MemIf_JobResultType retVal = MEMIF_JOB_FAILED;
    uint8 errorId = EEP_30_XXSPI01_E_NO_ERROR;

    /* ----- Development Error Checks --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_DETECT == STD_ON)

    /* ----- UNINIT CHECK --------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_DetChkInit(Index) == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_UNINIT;
    }
    else
#else
    EEP_30_XXSPI01_DUMMY_STATEMENT(Index); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
#endif /* EEP_30_XXSPI01_DEV_ERROR_DETECT */

    {
        /* ----- Implementation ------------------------------------------------------------------------------*/
        /* #10 Retrieve current job result */
        retVal = Eep_30_XXspi01_GetCurrentJobResult();
    }
    /* ----- Development Error Report --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_REPORT == STD_ON)
    if (errorId != EEP_30_XXSPI01_E_NO_ERROR)
    {
      (void)Det_ReportError(EEP_30_XXSPI01_MODULE_ID, Index, EEP_30_XXSPI01_SID_GET_JOB_RESULT, errorId);
    }
#else
    EEP_30_XXSPI01_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
#endif

    return retVal;
}

#if (EEP_30_XXSPI01_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_GetVersionInfoStd()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetVersionInfoStd(P2VAR(Std_VersionInfoType, AUTOMATIC, EEP_30_XXSPI01_APPL_DATA) versioninfo, uint8 Index)
{
    /* ----- Local Variables -----------------------------------------------------------------------------*/
    uint8 errorId = EEP_30_XXSPI01_E_NO_ERROR;

    /* ----- Development Error Checks --------------------------------------------------------------------*/
# if (EEP_30_XXSPI01_DEV_ERROR_DETECT == STD_ON)

    /* ----- VERSION POINTER CHECK ------------------------------------------------------------------------*/
    if (versioninfo == NULL_PTR)
    {
        errorId = EEP_30_XXSPI01_E_PARAM_POINTER;
    }
    else

# endif /* EA_DEV_ERROR_DETECT */
    {
        /* ----- Implementation ------------------------------------------------------------------------------*/
        /* #10 Set version information to structure referenced by versioninfo parameter */
        versioninfo->vendorID = EEP_30_XXSPI01_VENDOR_ID; /* SBSW_EEP_01 */
        versioninfo->moduleID = EEP_30_XXSPI01_MODULE_ID; /* SBSW_EEP_01 */

        versioninfo->sw_major_version = EEP_30_XXSPI01_SW_MAJOR_VERSION; /* SBSW_EEP_01 */
        versioninfo->sw_minor_version = EEP_30_XXSPI01_SW_MINOR_VERSION; /* SBSW_EEP_01 */
        versioninfo->sw_patch_version = EEP_30_XXSPI01_SW_PATCH_VERSION; /* SBSW_EEP_01 */

    }
    /* ----- Development Error Report --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_REPORT == STD_ON)
    if (errorId != EEP_30_XXSPI01_E_NO_ERROR)
    {
        (void)Det_ReportError(EEP_30_XXSPI01_MODULE_ID, Index, EEP_30_XXSPI01_SID_GET_VERSION_INFO, errorId);
    }
#else
    EEP_30_XXSPI01_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
#endif
}
#endif

/**********************************************************************************************************************
  Eep_30_XXspi01_AsynchronousJob()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_AsynchronousJob(uint8 Index,
                                                    Eep_30_XXspi01_JobType JobType,
                                                    Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_BufferPtrType DesDataBufferPtr,
                                                    Eep_30_XXspi01_ConstBufferPtrType SrcDataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* ----- Local Variables -----------------------------------------------------------------------------*/
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = EEP_30_XXSPI01_E_NO_ERROR;

    /* ----- Development Error Checks --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_DETECT == STD_ON)

    /* ----- UNINIT CHECK --------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_DetChkInit(Index) == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_UNINIT;
    }
    /* ----- BUFFER POINTER CHECK ------------------------------------------------------------------------*/
    else if (Eep_30_XXspi01_DetChkDataPointer(DesDataBufferPtr, SrcDataBufferPtr, JobType) == E_NOT_OK) /* SBSW_EEP_04 */
    {
        errorId = EEP_30_XXSPI01_E_PARAM_DATA;
    }
    /* ----- ADDRESS UPPER BOUNDARY CHECK ----------------------------------------------------------------*/
    else if (Eep_30_XXspi01_DetChkAddressBoundary(Index, EepromAddress, JobType) == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_PARAM_ADDRESS;
    }
    /* ----- LENGTH CHECK -------------------------------------------------------------------------------*/
    else if (Eep_30_XXspi01_DetChkLength(Index, Length, EepromAddress, JobType) == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_PARAM_LENGTH;
    }
    else
#endif /* EEP_30_XXSPI01_DEV_ERROR_DETECT */

    /* ----- BUSY CHECK ----------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_CheckIdle() == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_BUSY;
    }
    else
    {
        /* ----- Implementation ------------------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
        if (Eep_30_XXspi01_IsIncrementalJob(JobType) == FALSE)
#endif
        {
            /* #10 Increment EepromAddress by EEP's base address in case this is no incremental job */
            EepromAddress += Eep_30_XXspi01_CfgPtr[Index]->MemBaseAddress;
        }

        /* #20 Initialize job parameter for requested asynchronous job */
        Eep_30_XXspi01_InitAsyncJob(EepromAddress, DesDataBufferPtr, SrcDataBufferPtr, Length, Index, JobType); /* SBSW_EEP_04 */
        retVal = E_OK;
    }
    /* ----- Development Error Report --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_REPORT == STD_ON)
    if (errorId != EEP_30_XXSPI01_E_NO_ERROR)
    {
        (void)Det_ReportError(EEP_30_XXSPI01_MODULE_ID, Index, Eep_30_XXspi01_DetGetServiceId(JobType), errorId);
    }
#else
    EEP_30_XXSPI01_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
#endif

    return retVal;
} /* PRQA S 6050, 6060, 6080 */ /* MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */

#if (EEP_30_XXSPI01_TEST_COM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_TestComStd()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_TestComStd(uint8 Index)
{
    /* ----- Local Variables -----------------------------------------------------------------------------*/
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = EEP_30_XXSPI01_E_NO_ERROR;

    /* ----- Development Error Checks --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_DETECT == STD_ON)

    /* ----- UNINIT CHECK --------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_DetChkInit(Index) == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_UNINIT;
    }
    else
#endif /* EEP_30_XXSPI01_DEV_ERROR_DETECT */

    /* ----- BUSY CHECK ----------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_CheckIdle() == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_BUSY;
    }
    else
    {
        /* ----- Implementation ------------------------------------------------------------------------------*/
        /* #10 Initialize job parameter for requested TestCom job */
        Eep_30_XXspi01_InitAsyncJob(0, NULL_PTR, NULL_PTR, 0, Index, EEP_SPI_JOB_TESTCOM); /* SBSW_EEP_05 */
        retVal = E_OK;
    }
    /* ----- Development Error Report --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_REPORT == STD_ON)
    if (errorId != EEP_30_XXSPI01_E_NO_ERROR)
    {
      (void)Det_ReportError(EEP_30_XXSPI01_MODULE_ID, Index, EEP_30_XXSPI01_SID_TEST_COM, errorId);
    }
#else
    EEP_30_XXSPI01_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
#endif

    return retVal;
}
#endif

#if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_UnlockStd()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_UnlockStd(uint8 Index, Eep_30_XXspi01_LockLevelType LockLevel)
{
    /* ----- Local Variables -----------------------------------------------------------------------------*/
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = EEP_30_XXSPI01_E_NO_ERROR;

    /* ----- Development Error Checks --------------------------------------------------------------------*/
#if (EEP_30_XXSPI01_DEV_ERROR_DETECT == STD_ON)

    /* ----- UNINIT CHECK --------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_DetChkInit(Index) == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_UNINIT;
    }
    else
#endif /* EEP_30_XXSPI01_DEV_ERROR_DETECT */

    /* ----- BUSY CHECK ----------------------------------------------------------------------------------*/
    if (Eep_30_XXspi01_CheckIdle() == E_NOT_OK)
    {
        errorId = EEP_30_XXSPI01_E_BUSY;
    }
    else
    {
        /* ----- Implementation ------------------------------------------------------------------------------*/
        /* #10 Set lock level */
        Eep_30_XXspi01_SetLockLevel(LockLevel);
        /* #20 Initialize job parameter for requested Unlock job */
        Eep_30_XXspi01_InitAsyncJob(0, NULL_PTR, NULL_PTR, 1, Index, EEP_SPI_JOB_UNLOCK); /* SBSW_EEP_05 */
        retVal = E_OK;
    }
    /* ----- Development Error Report --------------------------------------------------------------------*/
    #if (EEP_30_XXSPI01_DEV_ERROR_REPORT == STD_ON)
    if (errorId != EEP_30_XXSPI01_E_NO_ERROR)
    {
      (void)Det_ReportError(EEP_30_XXSPI01_MODULE_ID, Index, EEP_30_XXSPI01_SID_SET_LOCK_LEVEL, errorId);
    }
    #else
    EEP_30_XXSPI01_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3200 */ /* MD_MSR_14.2 */
    #endif

    return retVal;
}
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  Eep_30_XXspi01_InitMemory()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitMemory(void)
{
    /* #10 Call InitMemory service for first Eep instance */
    Eep_30_XXspi01_ChipPtr[EEP_30_XXSPI01_INST1_INDEX] = &Eep_30_XXspi01_Chip; /* SBSW_EEP_02 */
    Eep_30_XXspi01_CommandBufferPtr[EEP_30_XXSPI01_INST1_INDEX] = Eep_30_XXspi01_CommandBuffer; /* SBSW_EEP_02 */
    Eep_30_XXspi01_DataBufferPtr[EEP_30_XXSPI01_INST1_INDEX] = Eep_30_XXspi01_DataBuffer; /* SBSW_EEP_02 */
}

/**********************************************************************************************************************
  Eep_30_XXspi01_Init()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Init(Eep_30_XXspi01_ConfigPtrType ConfigPtr)
{
    /* #10 Call Init service for first Eep instance */
    Eep_30_XXspi01_InitStd(EEP_30_XXSPI01_INST1_INDEX, ConfigPtr); /* SBSW_EEP_03 */
}

/**********************************************************************************************************************
  Eep_30_XXspi01_SetMode()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetMode(MemIf_ModeType Mode)
{
    /* #10 Call SetMode service for first Eep instance */
    Eep_30_XXspi01_SetModeStd(EEP_30_XXSPI01_INST1_INDEX, Mode);
}

/**********************************************************************************************************************
  Eep_30_XXspi01_SetHandling()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetHandling(Eep_30_XXspi01_HandlingType Handling)
{
    /* #10 Call SetHandling service for first Eep instance */
    Eep_30_XXspi01_SetHandlingStd(EEP_30_XXSPI01_INST1_INDEX, Handling);
}

/**********************************************************************************************************************
  Eep_30_XXspi01_Read()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Read(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_BufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous read job for first Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST1_INDEX, EEP_SPI_JOB_READ, EepromAddress, DataBufferPtr, NULL_PTR, Length); /* SBSW_EEP_04 */
}

#if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_ReadIncReg()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ReadIncReg(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_BufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous incremental read job for first Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST1_INDEX, EEP_SPI_JOB_READINC, EepromAddress, DataBufferPtr, NULL_PTR, Length); /* SBSW_EEP_04 */
}
#endif

/**********************************************************************************************************************
  Eep_30_XXspi01_Write()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Write(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous write job for first Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST1_INDEX, EEP_SPI_JOB_WRITE, EepromAddress, NULL_PTR, DataBufferPtr, Length); /* SBSW_EEP_04 */
}

#if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_WriteIncReg()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_WriteIncReg(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous incremental write job for first Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST1_INDEX, EEP_SPI_JOB_WRITEINC, EepromAddress, NULL_PTR, DataBufferPtr, Length); /* SBSW_EEP_04 */
}
#endif

/**********************************************************************************************************************
  Eep_30_XXspi01_Erase()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Erase(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous erase job for first Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST1_INDEX, EEP_SPI_JOB_ERASE, EepromAddress, NULL_PTR, NULL_PTR, Length); /* SBSW_EEP_05 */
}

/**********************************************************************************************************************
  Eep_30_XXspi01_Compare()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Compare(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous compare job for first Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST1_INDEX, EEP_SPI_JOB_COMPARE, EepromAddress, NULL_PTR, DataBufferPtr, Length); /* SBSW_EEP_04 */
}

#if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_CompareIncReg()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_CompareIncReg(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous incremental compare job for first Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST1_INDEX, EEP_SPI_JOB_COMPAREINC, EepromAddress, NULL_PTR, DataBufferPtr, Length); /* SBSW_EEP_04 */
}
#endif

#if (EEP_30_XXSPI01_TEST_COM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_TestCom()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_TestCom(void)
{
    /* #10 Request an asynchronous test com job for first Eep instance */
    return Eep_30_XXspi01_TestComStd(EEP_30_XXSPI01_INST1_INDEX);
}
#endif

#if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Unlock()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Unlock(Eep_30_XXspi01_LockLevelType LockLevel)
{
    /* #10 Request an asynchronous unlock job for first Eep instance */
    return Eep_30_XXspi01_UnlockStd(EEP_30_XXSPI01_INST1_INDEX, LockLevel);
}
#endif

/**********************************************************************************************************************
  Eep_30_XXspi01_GetStatus()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(MemIf_StatusType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetStatus(void)
{
    /* #10 Return current status for first Eep instance */
    return Eep_30_XXspi01_GetCurrentStatus();
}

/**********************************************************************************************************************
  Eep_30_XXspi01_GetJobResult()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(MemIf_JobResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetJobResult(void)
{
    /* #10 Return current job result for first Eep instance */
    return Eep_30_XXspi01_GetJobResultStd(EEP_30_XXSPI01_INST1_INDEX);
}

/**********************************************************************************************************************
  Eep_30_XXspi01_Cancel()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Cancel(void)
{
    /* #10 Cancel busy asynchronous job of first Eep instance */
    Eep_30_XXspi01_CancelStd(EEP_30_XXSPI01_INST1_INDEX);
}

#if (EEP_30_XXSPI01_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_GetVersionInfo()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetVersionInfo(Eep_30_XXspi01_VersionInfoPtrType versioninfo)
{
    /* #10 Store version information to structure referenced by versioninfo parameter */
    Eep_30_XXspi01_GetVersionInfoStd(versioninfo, EEP_30_XXSPI01_INST1_INDEX); /* SBSW_EEP_01 */
}
#endif

/**********************************************************************************************************************
  Eep_30_XXspi01_MainFunction()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_MainFunction(void)
{
    /* #10 Execute MainFunction */
    Eep_30_XXspi01_MainFunctionStd();
}

/**********************************************************************************************************************
  Eep_30_XXspi01_ComEnd()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ComEnd(void)
{
    /* #10 Execute communication end callback */
    Eep_30_XXspi01_ComEndStd();
}

/* ---------------------------- INST 2 SERVICES -------------------------------------------------------------------- */
#if (EEP_30_XXSPI01_MULTI_CHANNEL == STD_ON)

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_InitMemory()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_InitMemory(void)
{
    /* #10 Call InitMemory service for second Eep instance */
    Eep_30_XXspi01_ChipPtr[EEP_30_XXSPI01_INST2_INDEX] = &Eep_30_XXspi01_Inst2_Chip; /* SBSW_EEP_02 */
    Eep_30_XXspi01_CommandBufferPtr[EEP_30_XXSPI01_INST2_INDEX] = Eep_30_XXspi01_Inst2_CommandBuffer; /* SBSW_EEP_02 */
    Eep_30_XXspi01_DataBufferPtr[EEP_30_XXSPI01_INST2_INDEX] = Eep_30_XXspi01_Inst2_DataBuffer; /* SBSW_EEP_02 */
}

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Init()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Init(Eep_30_XXspi01_ConfigPtrType ConfigPtr)
{
    /* #10 Call Init service for second Eep instance */
    Eep_30_XXspi01_InitStd(EEP_30_XXSPI01_INST2_INDEX, ConfigPtr); /* SBSW_EEP_03 */
}

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_SetMode()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_SetMode(MemIf_ModeType Mode)
{
    /* #10 Call SetMode service for second Eep instance */
    Eep_30_XXspi01_SetModeStd(EEP_30_XXSPI01_INST2_INDEX, Mode);
}

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_SetHandling()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_SetHandling(Eep_30_XXspi01_HandlingType Handling)
{
    /* #10 Call SetHandling service for second Eep instance */
    Eep_30_XXspi01_SetHandlingStd(EEP_30_XXSPI01_INST2_INDEX, Handling);
}

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Read()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Read(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_BufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous read job for second Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST2_INDEX, EEP_SPI_JOB_READ, EepromAddress, DataBufferPtr, NULL_PTR, Length); /* SBSW_EEP_04 */
}

# if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_ReadIncReg()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_ReadIncReg(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_BufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous incremental read job for second Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST2_INDEX, EEP_SPI_JOB_READINC, EepromAddress, DataBufferPtr, NULL_PTR, Length); /* SBSW_EEP_04 */
}
# endif

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Write()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Write(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous write job for second Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST2_INDEX, EEP_SPI_JOB_WRITE, EepromAddress, NULL_PTR, DataBufferPtr, Length); /* SBSW_EEP_04 */
}

# if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_WriteIncReg()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_WriteIncReg(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous incremental write job for second Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST2_INDEX, EEP_SPI_JOB_WRITEINC, EepromAddress, NULL_PTR, DataBufferPtr, Length); /* SBSW_EEP_04 */
}
# endif

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Erase()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Erase(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous erase job for second Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST2_INDEX, EEP_SPI_JOB_ERASE, EepromAddress, NULL_PTR, NULL_PTR, Length); /* SBSW_EEP_05 */
}

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Compare()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Compare(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous compare job for second Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST2_INDEX, EEP_SPI_JOB_COMPARE, EepromAddress, NULL_PTR, DataBufferPtr, Length); /* SBSW_EEP_04 */
}

# if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_CompareIncReg()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_CompareIncReg(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length)
{
    /* #10 Request an asynchronous incremental compare job for second Eep instance */
    return Eep_30_XXspi01_AsynchronousJob(EEP_30_XXSPI01_INST2_INDEX, EEP_SPI_JOB_COMPAREINC, EepromAddress, NULL_PTR, DataBufferPtr, Length); /* SBSW_EEP_04 */
}
# endif

# if (EEP_30_XXSPI01_TEST_COM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_TestCom()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_TestCom(void)
{
    /* #10 Request an asynchronous TestCom job for second Eep instance */
    return Eep_30_XXspi01_TestComStd(EEP_30_XXSPI01_INST2_INDEX);
}
# endif

# if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Unlock()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Unlock(Eep_30_XXspi01_LockLevelType LockLevel)
{
    /* #10 Request an asynchronous unlock job for second Eep instance */
    return Eep_30_XXspi01_UnlockStd(EEP_30_XXSPI01_INST2_INDEX, LockLevel);
}
# endif

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_GetStatus()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(MemIf_StatusType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_GetStatus(void)
{
    /* #10 Return current status for second Eep instance */
    return Eep_30_XXspi01_GetCurrentStatus();
}

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_GetJobResult()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(MemIf_JobResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_GetJobResult(void)
{
    /* #10 Return current job result for second Eep instance */
    return Eep_30_XXspi01_GetJobResultStd(EEP_30_XXSPI01_INST2_INDEX);
}

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Cancel()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Cancel(void)
{
    /* #10 Cancel busy asynchronous job of second Eep instance */
    Eep_30_XXspi01_CancelStd(EEP_30_XXSPI01_INST2_INDEX);
}

# if (EEP_30_XXSPI01_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_GetVersionInfo()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_GetVersionInfo(Eep_30_XXspi01_VersionInfoPtrType versioninfo)
{
    /* #10 Store version information to structure referenced by versioninfo parameter */
    Eep_30_XXspi01_GetVersionInfoStd(versioninfo, EEP_30_XXSPI01_INST2_INDEX); /* SBSW_EEP_01 */
}
# endif

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_MainFunction()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_MainFunction(void)
{
    /* #10 Execute MainFunction */
    Eep_30_XXspi01_MainFunctionStd();
}

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_ComEnd()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_ComEnd(void)
{
    /* #10 Execute communication end callback */
    Eep_30_XXspi01_ComEndStd();
}

#endif

#define EEP_30_XXSPI01_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* START_COVERAGE_JUSTIFICATION
    \ID COV_EEP_POSTBUILD_CONFIG
    \ACCEPT TX
    \ACCEPT XF
    \REASON This condition is not necessarily both true and false within one configuration. Condition depends on PostBuild configuration
            parameter, thus it's also not possible to restrict the appearance of this condition by preprocessor switches.

    \ID COV_EEP_COMPATIBILITY
    \ACCEPT XF
    \ACCEPT TX
    \REASON [COV_MSR_COMPATIBILITY]

    \ID COV_EEP_DEFAULT
    \ACCEPT XX
    \REASON [COV_MSR_MISRA]
END_COVERAGE_JUSTIFICATION */

/* SBSW_JUSTIFICATION_BEGIN
    \ID SBSW_EEP_01
    \DESCRIPTION GetVersionInfo API writes to the object referenced by parameter versioninfo.
                 Additionally, versioninfo is checked if it's valid.
    \COUNTERMEASURE \N The caller ensures that the pointer passed to the parameters versioninfo is valid.

    \ID SBSW_EEP_02
    \DESCRIPTION Array is accessed at index corresponding to currently used EEP instance. First instance leads to array accesses with index 0.
             Second instance leads to array accesses with index 1.
    \COUNTERMEASURE \N Both the size of the array and the presence of accessing the array with index 1 is linked with the numbers of EEP modules configured.

    \ID SBSW_EEP_03
    \DESCRIPTION Constant pointer to configuration structure ConfigPtr is passed to local function.
    \COUNTERMEASURE \N The caller ensures that the configuration pointer passed to the public initialization API is valid.

    \ID SBSW_EEP_04
    \DESCRIPTION DataBufferPtr is passed to local function. This pointer is originally passed to EEP module by caller of EEP module.
    \COUNTERMEASURE \N The caller ensures that the pointer passed to the public APIs is valid.

    \ID SBSW_EEP_05
    \DESCRIPTION NULL_PTR is passed to local function as DataBufferPtr upon request of TestCom, Unlock and Erase jobs.
    \COUNTERMEASURE \N Input parameter DataBufferPtr i.e. NULL_PTR is not used in TestCom, Unlock and Erase jobs.

    \ID SBSW_EEP_06
    \DESCRIPTION NULL_PTR is passed to local function Eep_30_XXspi01_SetDataAndStartTransfer within Eep_30_XXspi01_PerformPrepareTask function.
    \COUNTERMEASURE \N For preparation the command passed to Eep_30_XXspi01_SetDataAndStartTransfer is either CMD_WREN or CMD_WRDI. In case of these commands the according
                       input parameters in Eep_30_XXspi01_SetDataAndStartTransfer function are not used. Thus it's uncritical to pass NULL_PTR as pointer parameters.

    \ID SBSW_EEP_07
    \DESCRIPTION Pointers to local objects SrcDataBufferPtr and DesDataBufferPtr are passed to function Eep_30_XXspi01_PrepareBuffer.
    \COUNTERMEASURE \N Passing reference of both buffers in function is legitimate because it's a reference of a local variable.

    \ID SBSW_EEP_08
    \DESCRIPTION Local pointers SrcDataBufferPtr and DesDataBufferPtr are passed to function Eep_30_XXspi01_SetDataAndStartTransfer.
    \COUNTERMEASURE \N SrcDataBufferPtr and DesDataBufferPtr are initialized in every case before being passed to Eep_30_XXspi01_SetDataAndStartTransfer.
                       Thus these pointers are valid at this point.

    \ID SBSW_EEP_09
    \DESCRIPTION Eep_30_XXspi01_CommandBufferPtr is an array which contains either one or two arrays of type Spi_DataType. Array is either accessed at first
                 position or within a for-loop.
    \COUNTERMEASURE \N Number of arrays in Eep_30_XXspi01_CommandBufferPtr is restricted by number of EEP modules configured. Length of each array depends
                       on CommandBufferSize, which is also the upper boundary for any array accesses.

    \ID SBSW_EEP_10
    \DESCRIPTION Pointer is passed to function. Pointer is contained in Eep_30_XXspi01_CommandBufferPtr array and indexed according to currently used EEP module instance.
    \COUNTERMEASURE \N Maximum possible instance index is directly linked to number of array elements. Thus an out of bound access is impossible.

    \ID SBSW_EEP_11
    \DESCRIPTION Pointer DesBufferPtrPtr and SrcBufferPtrPtr are passed to public SPI function.
    \COUNTERMEASURE \N The caller ensures that the pointers passed are valid.

    \ID SBSW_EEP_12
    \DESCRIPTION Object referenced by DesBufferPtrPtr or SrcBufferPtrPtr is accessed and written.
    \COUNTERMEASURE \N Reference DesBufferPtrPtr and SrcBufferPtrPtr are passed to local function. Thus caller ensures that the pointers passed are valid.

    \ID SBSW_EEP_13
    \DESCRIPTION Element of Eep_30_XXspi01_DataBufferPtr is within for loop. Element is indexed by job context's index
    \COUNTERMEASURE \N Index of Eep_30_XXspi01_DataBufferPtr element is directly linked to number of configured EEP modules. Thus it's not possible
                       to index Eep_30_XXspi01_DataBufferPtr out of bounds.
                       Size of Eep_30_XXspi01_DataBufferPtr element is page size and chunk size is at maximum the page size, which
                       corresponds to read/write size. Thus all array accesses are valid.

    \ID SBSW_EEP_14
    \DESCRIPTION Pointer to function Ea_JobEndNotification and Ea_JobErrorNotification is called.
    \COUNTERMEASURE \R It is checked whether the pointer is NULL_PTR before execution.

    \ID SBSW_EEP_15
    \DESCRIPTION ConfigPointer array Eep_30_XXspi01_CfgPtr is initialized at index with ConfigPtr parameter.
    \COUNTERMEASURE \N Index is directly linked to size of ConfigPointer array. Thus it's not possible to access this array out of bounds.

    \ID SBSW_EEP_16
    \DESCRIPTION Write access of DataBufferPtr within for loop.
    \COUNTERMEASURE \N It is ensured that DataBufferIndex + ChunkSize is at maximum length of DataBufferPtr, which are both passed by caller of EEP module.

    \ID SBSW_EEP_17
    \DESCRIPTION Function pointer from function pointer structure is called
    \COUNTERMEASURE \N  The compiler performs type check and therefore assures that valid function pointer is called.

SBSW_JUSTIFICATION_END */
/**********************************************************************************************************************
 *  END OF FILE: Eep_30_XXspi01.c
 *********************************************************************************************************************/
