/*********************************************************************************************************************
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
 *       \file     Eep_30_XXspi01_Proc.h
 *       \brief    Eep Spi Low Level processing header file
 *
 *       \details  Contains state processing services, which are called by High Level implementation. Low Level
 *                 implementation accesses the underlying bus driver and processes the current job.
 *
 *********************************************************************************************************************/

#ifndef EEP_30_XXSPI01_PROC_H
# define EEP_30_XXSPI01_PROC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "Eep_30_XXspi01_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATATYPES
 *********************************************************************************************************************/

#define EEP_30_XXSPI01_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef enum{
    EEP_SPI_JOB_READ = 0,
    EEP_SPI_JOB_WRITE,
    EEP_SPI_JOB_COMPARE,
    EEP_SPI_JOB_ERASE,
    EEP_SPI_JOB_TESTCOM,
    EEP_SPI_JOB_UNLOCK,
    EEP_SPI_JOB_READINC,
    EEP_SPI_JOB_WRITEINC,
    EEP_SPI_JOB_COMPAREINC
} Eep_30_XXspi01_JobType;

#define EEP_30_XXSPI01_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define EEP_30_XXSPI01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
  Eep_30_XXspi01_InitCfgArray()
**********************************************************************************************************************/
/*!
 * \brief      Initializes configuration array at Index with passed ConfigPtr
 * \details    Initializes configuration array at Index with passed ConfigPtr. Service is called upon module initialization.
 * \param[in]  Index
 * \param[in]  ConfigPtr
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitCfgArray(uint8 Index, P2CONST(Eep_30_XXspi01_ConfigType, AUTOMATIC, EEP_30_XXSPI01_PBCFG) ConfigPtr);

/**********************************************************************************************************************
  Eep_30_XXspi01_InitComponentParameter()
**********************************************************************************************************************/
/*!
 * \brief      Initializes component parameter, flags and state machine
 * \details    Sets status to idle, job result to ok. Resets state machine and clears all internal flags.
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitComponentParameter(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_InitAsyncJob()
**********************************************************************************************************************/
/*!
 * \brief      Initializes asynchronous job.
 * \details    Initializes job parameter upon request of an asynchronous job.
 * \param[in]  EepromAddress
 * \param[out]  DesDataBufferPtr
 * \param[in]  SrcDataBufferPtr
 * \param[in]  Length
 * \param[in]  Index
 * \param[in]  JobType
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitAsyncJob(Eep_30_XXspi01_AddressType EepromAddress,
                                                       Eep_30_XXspi01_BufferPtrType DesDataBufferPtr,
                                                       Eep_30_XXspi01_ConstBufferPtrType SrcDataBufferPtr,
                                                       Eep_30_XXspi01_LengthType Length,
                                                       uint8 Index,
                                                       Eep_30_XXspi01_JobType JobType);


#if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_IsIncrementalJob()
**********************************************************************************************************************/
/*!
 * \brief      Checks if currently an incremental job is being performed.
 * \details    Checks if currently an incremental job is being performed.
 * \param[in]  CurrentJob
 * \return     TRUE: Current job is an incremental job
 *             FALSE: Current job is not an incremental job
 * \pre        Incremental feature enabled.
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(boolean, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_IsIncrementalJob(Eep_30_XXspi01_JobType CurrentJob);
#endif

#if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_SetLockLevel()
**********************************************************************************************************************/
/*!
 * \brief      Sets requested lock level in job context
 * \details    Sets requested lock level in job context. Service is called upon request of Unlock job
 * \param[in]  LockLevel
 * \pre        Unlock API is enabled via configuration
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetLockLevel(Eep_30_XXspi01_LockLevelType LockLevel);
#endif

/**********************************************************************************************************************
  Eep_30_XXspi01_SetCurrentMode()
**********************************************************************************************************************/
/*!
 * \brief      Sets current mode
 * \details    Sets current mode. Service is used in SetMode API
 * \param[in]  Mode
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetCurrentMode(MemIf_ModeType Mode);

/**********************************************************************************************************************
  Eep_30_XXspi01_SetCurrentHandling()
**********************************************************************************************************************/
/*!
 * \brief      Sets current handling
 * \details    Sets current handling. Service is used in SetHandling API
 * \param[in]  Handling
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetCurrentHandling(Eep_30_XXspi01_HandlingType Handling);


/**********************************************************************************************************************
  Eep_30_XXspi01_GetCurrentJobResult()
**********************************************************************************************************************/
/*!
 * \brief      Returns component job result to the caller
 * \details    Returns component job result to the caller (usually Ea)
 * \return     Current component job result
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC (MemIf_JobResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetCurrentJobResult(void);


/**********************************************************************************************************************
  Eep_30_XXspi01_GetCurrentStatus()
**********************************************************************************************************************/
/*!
 * \brief      Returns component status to the caller
 * \details    Returns component status to the caller (usually Ea)
 * \return     Current component status
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 * \trace DSGN-Eep22767
 */
FUNC (MemIf_StatusType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetCurrentStatus(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_CancelJob()
**********************************************************************************************************************/
/*!
 * \brief      Sets necessary flags so that cancel will be processed within next call of MainFunction
 * \details    Sets necessary flags so that cancel will be processed within next call of MainFunction. Also resets
 *             component global parameters so that user of Eep can request a new job right away.
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_CancelJob(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_MainFunctionStd()
**********************************************************************************************************************/
/*!
 * \brief      Service to handle the requested jobs and the internal management operations.
 * \details    Service to handle the requested jobs and the internal management operations.
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_MainFunctionStd(void);


/**********************************************************************************************************************
  Eep_30_XXspi01_ComEndStd()
**********************************************************************************************************************/
/*!
 * \brief      Indicates to Eep that current job of underlying bus driver is finished
 * \details    Indicates to Eep that current job of underlying bus driver is finished. Sets ProcessMainFunction flag.
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 * \trace DSGN-Eep22767
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ComEndStd(void);

# define EEP_30_XXSPI01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* EEP_30_XXSPI01_PROC_H */

/**********************************************************************************************************************
 *  END OF FILE: Eep_30_XXspi01_Proc.h
 *********************************************************************************************************************/
