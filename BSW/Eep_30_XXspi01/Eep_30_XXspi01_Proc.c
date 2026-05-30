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
 *       \file     Eep_30_XXspi01_Proc.c
 *       \brief    Eep Spi processing source file
 *
 *       \details  Contains state processing services and access to the underlying bus driver.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Eep_30_XXspi01.h"
#include "Eep_30_XXspi01_Proc.h"
#include "SchM_Eep_30_XXspi01.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! EEPROM Instruction Set */
#define EEP_30_XXSPI01_CMD_WRSR                  (1u) /*!< Write STATUS Register */
#define EEP_30_XXSPI01_CMD_WRITE                 (2u) /*!< Write data to memory array */
#define EEP_30_XXSPI01_CMD_READ                  (3u) /*!< Read data from memory array */
#define EEP_30_XXSPI01_CMD_WRDI                  (4u) /*!< Reset the write enable latch (disable write operations) */
#define EEP_30_XXSPI01_CMD_RDSR                  (5u) /*!< Read STATUS Register */
#define EEP_30_XXSPI01_CMD_WREN                  (6u) /*!< Set the write enable latch (enable write operations) */
#define EEP_30_XXSPI01_CMD_WRINC                 (7u) /*!< Write data to incremental registers */

#define EEP_30_XXSPI01_NUMBER_OF_INSTANCES       (0x02u)

/*! Status Register Bit Masks */
#define EEP_30_XXSPI01_MASK_BUSY                 (0x01u) /*!< StatusRegister:0:0 Write-In-Process */
#define EEP_30_XXSPI01_MASK_WRITE_ENABLE         (0x02u) /*!< StatusRegister:1:1 Write Enable Latch */
#define EEP_30_XXSPI01_MASK_WRINC_OK             (0x10u) /*!< StatusRegister:4:4 Write Incremental Register Bit */

/*! Addresses and Lengths */
#define EEP_30_XXSPI01_ADDRESS_DUMMY             (0u)
#define EEP_30_XXSPI01_LENGTH_DUMMY              (0u)
#define EEP_30_XXSPI01_LENGTH_COMMAND            (1u)
#define EEP_30_XXSPI01_LENGTH_STATUSREG          (1u)
#define EEP_30_XXSPI01_LENGTH_INCREMENTAL        (2u)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#ifndef EEP_LOCAL /* COV_EEP_COMPATIBILITY */
# define EEP_LOCAL static
#endif

#if !defined (EEP_LOCAL_INLINE) /* COV_EEP_COMPATIBILITY */
# define EEP_LOCAL_INLINE LOCAL_INLINE
#endif

typedef P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) Eep_30_XXspi01_SpiDataPtrType;
typedef P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) Eep_30_XXspi01_SpiConstDataPtrType;

typedef P2VAR(Eep_30_XXspi01_SpiDataPtrType, AUTOMATIC, SPI_APPL_DATA) Eep_30_XXspi01_SpiDataPtrPtrType;
typedef P2VAR(Eep_30_XXspi01_SpiConstDataPtrType, AUTOMATIC, SPI_APPL_DATA) Eep_30_XXspi01_SpiConstDataPtrPtrType;

typedef enum
{
  EEP_30_XXSPI01_STATE_IDLE = 0,
  EEP_30_XXSPI01_STATE_PREPARE,
  EEP_30_XXSPI01_STATE_EXECUTE,
  EEP_30_XXSPI01_STATE_VERIFY
} Eep_30_XXspi01_StateType; /*!< Possible states of the state machine */

typedef struct{
    MemIf_ModeType CurrentMode;
    Eep_30_XXspi01_HandlingType CurrentHandling;
    MemIf_StatusType Status;    /*!< Current global component status which is used by Eep_GetStatusStd service */
    MemIf_JobResultType JobResult; /*!< Current global component job result which is used by Eep_GetJobResultStd service */
    Eep_30_XXspi01_StateType FsmState;    /*!< Current state machine state */
} Eep_30_XXspi01_ComponentParamType;

typedef struct
{
    boolean ProcessMainFunction;    /*!< Indicates if MainFunction needs to be processed */
    boolean CancelRequested;    /*!< Indicates if Cancel was requested. Processed in MainFunction */
    boolean JobRequested;   /*!< Indicates if new job was requested. Processed in MainFunction */
} Eep_30_XXspi01_ComponentFlagType;

typedef struct{
   uint8 Index; /*!< Instance index of currently used EEPROM device */
   uint16 NrOfQueries; /*!< Global variable for remaining number of queries */
   boolean FirstWriteAttempt; /*!< Some EEPROM devices may not reset the WEL after writing immediately, therefore two attempts are provided */
   Eep_30_XXspi01_AddressType EepromAddress; /*!< Current address the EEPROM driver is working with */
   Eep_30_XXspi01_LengthType RemainingBytes; /*!< Number of Bytes the EEPROM driver still needs to process */
   Eep_30_XXspi01_LengthType ChunkSize; /*!< Size of data package the EEPROM driver can process at a time */
   Eep_30_XXspi01_BufferPtrType DesDataBufferPtr; /*!< Reference to user buffer. Used for Read jobs only */
   Eep_30_XXspi01_ConstBufferPtrType SrcDataBufferPtr; /*!< Reference to user buffer. Used for Write and Compare jobs only */
   Eep_30_XXspi01_AddressType DataBufferIndex; /*!< Current index in user buffer */
   Eep_30_XXspi01_JobType CurrentJob; /*!< Globally stored job being processed by the EEPROM driver */
   Spi_SequenceType CurrentSequence; /*!< Latest sequence transmitted to the underlying SPI driver */
   Spi_DataType LockLevel; /*!< Protection level used in Unlock/SetLockLevel job */
} Eep_30_XXspi01_JobContextType;

typedef enum{
    EEP_NOT_OK = 0,
    EEP_NOT_FINISHED,
    EEP_INCONSISTENT,
    EEP_OK,
    EEP_BUSY
} Eep_30_XXspi01_ProcessResultType; /*!< Possible return values of state processing functions */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define EEP_30_XXSPI01_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

EEP_LOCAL VAR(Eep_30_XXspi01_JobContextType, EEP_30_XXSPI01_VAR_NO_INIT) Eep_30_XXspi01_JobContext;

#define EEP_30_XXSPI01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define EEP_30_XXSPI01_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

EEP_LOCAL VAR(Eep_30_XXspi01_ComponentParamType, EEP_30_XXSPI01_APPL_DATA) Eep_30_XXspi01_ComponentParameter =
{
    MEMIF_MODE_SLOW,                /*!< CurrentMode */
    EEP_30_XXSPI01_HANDLING_BURST,  /*!< CurrentHandling */
    MEMIF_UNINIT,                   /*!< Status */
    MEMIF_JOB_FAILED,               /*!< JobResult */
    EEP_30_XXSPI01_STATE_IDLE,      /*!< FsmState */
};

EEP_LOCAL VAR(Eep_30_XXspi01_ComponentFlagType, EEP_30_XXSPI01_APPL_DATA) Eep_30_XXspi01_ComponentFlags = /*!< Important flags to process asynchronous jobs correctly */
{
    FALSE, /*!< ProcessMainFunction */
    FALSE, /*!< CancelRequested */
    FALSE  /*!< JobRequested */
};

#define EEP_30_XXSPI01_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define EEP_30_XXSPI01_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
  Eep_30_XXspi01_ReportDemError()
**********************************************************************************************************************/
/*!
 * \brief      Reports error to DEM according to current job
 * \details    Reports error to DEM according to current job. Service is called upon failed job end
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 * \trace DSGN-Eep22772
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ReportDemError(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_ResetFsm()
**********************************************************************************************************************/
/*!
 * \brief      Resets state machine to IDLE state
 * \details    Resets state machine to IDLE state
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC (void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ResetFsm(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_ResetMainFunctionFlag()
**********************************************************************************************************************/
/*!
 * \brief      Resets ProcessMainFunction flag to false
 * \details    Resets ProcessMainFunction flag to false
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC (void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ResetMainFunctionFlag(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_ResetCancelFlag()
**********************************************************************************************************************/
/*!
 * \brief      Resets CancelRequested flag to false
 * \details    Resets CancelRequested flag to false
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC (void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ResetCancelFlag(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_StartJob()
**********************************************************************************************************************/
/*!
 * \brief      Initializes component parameters for current job
 * \details    Initializes current mode and current handling according to default values in configuration
 * \param[in]  Instance index
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_StartJob(uint8 Index);

/**********************************************************************************************************************
  Eep_30_XXspi01_InitJobContext()
**********************************************************************************************************************/
/*!
 * \brief      Initializes low level implementation's job context
 * \details    Initializes low level's job context which is used to perform current job. Service is called upon each job request
 * \param[in]  Index
 * \param[out]  DesDataBufferPtr
 * \param[in]  SrcDataBufferPtr
 * \param[in]  Length
 * \param[in]  EepromAddress
 * \param[in]  JobType
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitJobContext(uint8 Index,
                                                              Eep_30_XXspi01_BufferPtrType DesDataBufferPtr,
                                                              Eep_30_XXspi01_ConstBufferPtrType SrcDataBufferPtr,
                                                              Eep_30_XXspi01_LengthType Length,
                                                              Eep_30_XXspi01_AddressType EepromAddress,
                                                              Eep_30_XXspi01_JobType JobType);

/**********************************************************************************************************************
  Eep_30_XXspi01_InitiateFirstState()
**********************************************************************************************************************/
/*!
 * \brief      Initiates first task/state with regard to the requested job
 * \details    Initiates first task/state with regard to the requested job
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitiateFirstState(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_PerformPrepareTask()
**********************************************************************************************************************/
/*!
 * \brief      Performs prepare task with regard to the requested job
 * \details    Performs prepare task with regard to the requested job
 * \return     EEP_OK: State was performed successfully
 *             EEP_NOT_OK: State failed
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_PerformPrepareTask(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_PerformExecuteTask()
**********************************************************************************************************************/
/*!
 * \brief      Performs execute task with regard to the requested job
 * \details    Performs execute task with regard to the requested job
 * \return     EEP_OK: State was performed successfully
 *             EEP_NOT_OK: State failed
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_PerformExecuteTask(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_PerformVerifyTask()
**********************************************************************************************************************/
/*!
 * \brief      Performs tasks according to verification state
 * \details    Performs tasks according to verification state. Read status register command is sent to Eeprom.
 * \return     EEP_OK: State was performed successfully
 *             EEP_NOT_OK: State failed
 * \pre        Verification depends on current job
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_PerformVerifyTask(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_PerformFinalizeTask()
**********************************************************************************************************************/
/*!
 * \brief      Performs tasks according to finalize state
 * \details    Performs tasks according to finalize state. Current job is finalized
 * \return     EEP_OK: Entire job was successfully
 *             EEP_NOT_OK: Entire job failed
 *             EEP_NOT_FINISHED: Part of job was successful. Start over with next part.
 *             EEP_BUSY: Eeprom is still busy. Start over with verify state
 *             EEP_INCONSISTENT: Entire job failed due to inconsistent data within a compare job
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_PerformFinalizeTask(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_FinalizeReadClassJob()
**********************************************************************************************************************/
/*!
 * \brief      Finalizes recent Spi communication for read-class jobs
 * \details    Finalizes recent Spi communication for read-class jobs and initiates next part if job is not yet finished.
 * \return     EEP_OK: Entire job is finished successfully
 *             EEP_NOT_OK: Entire job failed
 *             EEP_INCONSISTENT: Entire job failed due to inconsistent data within a compare job
 *             EEP_BUSY: Eeprom is still busy, status has to be checked again
 *             EEP_NOT_FINISHED: Part of job is successful, start over with next part
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_FinalizeReadClassJob(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_FinalizeWriteClassJob()
**********************************************************************************************************************/
/*!
 * \brief      Finalizes recent Spi communication for write-class jobs
 * \details    Finalizes recent Spi communication for write-class jobs and initiates next part if job is not yet finished.
 * \return     EEP_OK: Entire job is finished successfully
 *             EEP_NOT_OK: Entire job failed
 *             EEP_BUSY: Eeprom is still busy, status has to be checked again
 *             EEP_NOT_FINISHED: Part of job is successful, start over with next part
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_FinalizeWriteClassJob(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_Min()
**********************************************************************************************************************/
/*!
 * \brief      Compares and returns smaller value of both input parameters
 * \details    Compares and returns smaller value of both input parameters
 * \return     Smaller value of both input parameters
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(Eep_30_XXspi01_LengthType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Min(Eep_30_XXspi01_LengthType Param1, Eep_30_XXspi01_LengthType Param2);

/**********************************************************************************************************************
  Eep_30_XXspi01_CheckEepromBusy()
**********************************************************************************************************************/
/*!
 * \brief      Evaluates recently read status register value and checks if Eeprom is still busy
 * \details    Evaluates recently read status register value and checks if Eeprom is still busy
 * \return     EEP_OK: Entire job is finished successfully
 *             EEP_NOT_OK: Eeprom timed out
 *             EEP_BUSY: Eeprom is still busy, status has to be checked again
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_CheckEepromBusy(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_CompareBuffers()
**********************************************************************************************************************/
/*!
 * \brief      Compares recently read data with source buffer
 * \details    Compares recently read data with source buffer
 * \return     EEP_OK: Recently read data matches the source data
 *             EEP_INCONSISTENT: Recently read data is different to source data
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_CompareBuffers(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_SetDataAndStartTransfer()
**********************************************************************************************************************/
/*!
 * \brief      Invokes Spi's SetupEB and AsyncTransmit services with parameters according to current job
 * \details    Invokes Spi's SetupEB and AsyncTransmit services with parameters according to current job
 * \param[in]  Command
 * \param[in]  Address
 * \param[in]  SrcDataBufferPtr
 * \param[in]  DesDataBufferPtr
 * \param[in]  Length
 * \return     E_OK: Spi job was requested successfully
 *             E_NOT_OK: Setting up Spi job failed
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetDataAndStartTransfer(uint8 Command,
                                                            Eep_30_XXspi01_AddressType Address,
                                                            Eep_30_XXspi01_SpiConstDataPtrType SrcDataBufferPtr,
                                                            Eep_30_XXspi01_SpiDataPtrType DesDataBufferPtr,
                                                            Spi_NumberOfDataType Length);

/**********************************************************************************************************************
  Eep_30_XXspi01_SwitchState()
**********************************************************************************************************************/
/*!
 * \brief      Handles state machine transitions based on result of last state
 * \details    Handles state machine transitions based on result of last state
 * \param[in]  Result
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC (void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SwitchState(Eep_30_XXspi01_ProcessResultType Result);

/**********************************************************************************************************************
  Eep_30_XXspi01_IsWriteClassJob()
**********************************************************************************************************************/
/*!
 * \brief      Checks if current job is a write class job
 * \details    Checks if current job is a write class job
 * \return     TRUE: Write Class job
 * \return     FALSE: Read Class job
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(boolean, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_IsWriteClassJob(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_SetNrOfQueries()
**********************************************************************************************************************/
/*!
 * \brief      Sets number of queries for current job according to job type and current handling
 * \details    Sets number of queries for current job according to job type and current handling
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetNrOfQueries(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_SetChunkSizeAndCommand()
**********************************************************************************************************************/
/*!
 * \brief      Sets size of chunk for next SPI transmission. Returns EEPROM command for next SPI transmission.
 * \details    Sets size of chunk for next SPI transmission. Returns EEPROM command for next SPI transmission.
 * \return     Command
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(uint8, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetChunkSizeAndCommand(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_PrepareBuffer()
**********************************************************************************************************************/
/*!
 * \brief      Sets buffer according to current job.
 * \details    Sets buffer according to current job for upcoming Spi's SetupEB invocation.
 * \param[out]  SrcBufferPtrPtr
 * \param[out]  DesBufferPtrPtr
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_PrepareBuffer(Eep_30_XXspi01_SpiConstDataPtrPtrType SrcBufferPtrPtr,
                                                                              Eep_30_XXspi01_SpiDataPtrPtrType DesBufferPtrPtr);

/**********************************************************************************************************************
  Eep_30_XXspi01_FinishJob()
**********************************************************************************************************************/
/*!
 * \brief      Finishes current job with passed JobResult
 * \details    Resets internal parameters and state machine. Invokes upper layer's callback notifications if configured.
 * \param[in]  JobResult
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 * \trace DSGN-Eep22874
 * \trace DSGN-Eep22772
 */
EEP_LOCAL_INLINE FUNC (void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_FinishJob(MemIf_JobResultType JobResult);

/**********************************************************************************************************************
  Eep_30_XXspi01_ProcessFsm()
**********************************************************************************************************************/
/*!
 * \brief      Processes state machine
 * \details    Processes state machine
 * \pre        Will only be called if ProcessMainFunction flag is set
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ProcessFsm(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  Eep_30_XXspi01_ReportDemError()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ReportDemError(void)
{
    Dem_EventIdType CurrentId;

    /* #10 Set CurrentId depending on current job */
    switch (Eep_30_XXspi01_JobContext.CurrentJob)
    {
    case EEP_SPI_JOB_COMPARE:
    case EEP_SPI_JOB_COMPAREINC:
        CurrentId = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->ECompareFailed;
        break;
    case EEP_SPI_JOB_READ:
    case EEP_SPI_JOB_READINC:
        CurrentId = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->EReadFailed;
        break;
    case EEP_SPI_JOB_WRITE:
    case EEP_SPI_JOB_WRITEINC:
        CurrentId = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->EWriteFailed;
        break;
#if (EEP_30_XXSPI01_TEST_COM_API == STD_ON)
    case EEP_SPI_JOB_TESTCOM:
        CurrentId = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->ETestComFailed;
        break;
#endif
#if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
    case EEP_SPI_JOB_UNLOCK:
        CurrentId = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->EUnlockFailed;
        break;
#endif
    default: /* case EEP_SPI_JOB_ERASE: */
        CurrentId = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->EEraseFailed;
        break;
    }

    /* #20 Report error with CurrentId to DEM */
    Dem_ReportErrorStatus(CurrentId, DEM_EVENT_STATUS_FAILED);
}

/**********************************************************************************************************************
  Eep_30_XXspi01_ResetFsm()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL_INLINE FUNC (void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ResetFsm(void)
{
    /* #10 Reset state machine to IDLE state */
    Eep_30_XXspi01_ComponentParameter.FsmState = EEP_30_XXSPI01_STATE_IDLE;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_ResetMainFunctionFlag()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC (void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ResetMainFunctionFlag(void)
{
    /* #0 This service is always called after any processing function of the low level part is called */
    /* #10 Reset main function flag */
    Eep_30_XXspi01_ComponentFlags.ProcessMainFunction = FALSE;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_ResetCancelFlag()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL_INLINE FUNC (void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ResetCancelFlag(void)
{
    /* #10 Reset cancel flag to false */
    Eep_30_XXspi01_ComponentFlags.CancelRequested = FALSE;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_StartJob()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_StartJob(uint8 Index)
{
    /* #10 Set component parameter */
    Eep_30_XXspi01_ComponentParameter.Status = MEMIF_BUSY;
    Eep_30_XXspi01_ComponentParameter.JobResult = MEMIF_JOB_PENDING;

    /* #20 Initialize state machine */
    Eep_30_XXspi01_ResetFsm();

    /* #30 Set component flags */
    Eep_30_XXspi01_ComponentFlags.JobRequested = TRUE;
    Eep_30_XXspi01_ComponentFlags.ProcessMainFunction = TRUE;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_InitJobContext()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitJobContext(uint8 Index,
                                                              Eep_30_XXspi01_BufferPtrType DesDataBufferPtr,
                                                              Eep_30_XXspi01_ConstBufferPtrType SrcDataBufferPtr,
                                                              Eep_30_XXspi01_LengthType Length,
                                                              Eep_30_XXspi01_AddressType EepromAddress,
                                                              Eep_30_XXspi01_JobType JobType)
{
    /* #10 Initialize JobContext parameters with values passed by job request */
    Eep_30_XXspi01_JobContext.Index = Index;
    Eep_30_XXspi01_JobContext.DesDataBufferPtr = DesDataBufferPtr;
    Eep_30_XXspi01_JobContext.SrcDataBufferPtr = SrcDataBufferPtr;
    Eep_30_XXspi01_JobContext.RemainingBytes = Length;
    Eep_30_XXspi01_JobContext.EepromAddress = EepromAddress;
    Eep_30_XXspi01_JobContext.CurrentJob = JobType;

    /* #20 Reset JobContext values which are necessary to perform current job accordingly */
    Eep_30_XXspi01_JobContext.FirstWriteAttempt = TRUE;
    Eep_30_XXspi01_JobContext.DataBufferIndex = 0u;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
  Eep_30_XXspi01_InitiateFirstState()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitiateFirstState(void)
{
    /* #10 Preparation is necessary if either ResetLatch is enabled or the current job is a write class job */
    /* #20 First State depends on requested job */
#if (EEP_30_XXSPI01_RESET_LATCH == STD_OFF)
    if (Eep_30_XXspi01_IsWriteClassJob() == FALSE)
    {
        /* #30 First State is EEP_30_XXSPI01_STATE_EXECUTE upon Read class jobs */
        Eep_30_XXspi01_ComponentParameter.FsmState = EEP_30_XXSPI01_STATE_EXECUTE;

        /* #40 Execute Execute Task */
        if (Eep_30_XXspi01_PerformExecuteTask() != EEP_OK)
        {
            Eep_30_XXspi01_FinishJob(MEMIF_JOB_FAILED);
        }
    }
    else
#endif
    {
        /* #50 First State is EEP_30_XXSPI01_STATE_PREPARE upon Write class jobs */
        Eep_30_XXspi01_ComponentParameter.FsmState = EEP_30_XXSPI01_STATE_PREPARE;

        /* #60 Execute Prepare Task */
        if (Eep_30_XXspi01_PerformPrepareTask() != EEP_OK)
        {
            Eep_30_XXspi01_FinishJob(MEMIF_JOB_FAILED);
        }
    }
}

/**********************************************************************************************************************
  Eep_30_XXspi01_PerformPrepareTask()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
EEP_LOCAL FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_PerformPrepareTask(void)
{
    Eep_30_XXspi01_ProcessResultType retVal = EEP_NOT_OK;
    uint8 command;

#if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
    /* #10 Write protection pin has to be pulled to high in an unlock job */
    if (Eep_30_XXspi01_JobContext.CurrentJob == EEP_SPI_JOB_UNLOCK)
    {
        /* #20 Check if WP pin is used at all */
        if (Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->WriteProtectChannel != EEP_30_XXSPI01_WP_PIN_NOT_USED) /* COV_EEP_POSTBUILD_CONFIG */
        {
            /* #30 Pull WP pin to high if it's low */
            if (Dio_ReadChannel(Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->WriteProtectChannel) == STD_LOW)
            {
                Dio_WriteChannel(Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->WriteProtectChannel, STD_HIGH);
            }
        }
    }
#endif

#if (EEP_30_XXSPI01_RESET_LATCH == STD_ON)
    if (Eep_30_XXspi01_IsWriteClassJob() == FALSE)
    {
        /* #40 Set Command to CMD_WRDI due to Read class job */
        command = EEP_30_XXSPI01_CMD_WRDI;
    }
    else
#endif
    {
        /* #50 Set Command to CMD_WREN due to Write class job */
        command = EEP_30_XXSPI01_CMD_WREN;
    }

    /* #60 set data and start transfer */
    if (Eep_30_XXspi01_SetDataAndStartTransfer(command, EEP_30_XXSPI01_ADDRESS_DUMMY, NULL_PTR, NULL_PTR, EEP_30_XXSPI01_LENGTH_DUMMY) == E_OK) /* SBSW_EEP_06 */
    {
        retVal = EEP_OK;
    }

    return retVal;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_PerformExecuteTask()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
EEP_LOCAL FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_PerformExecuteTask(void)
{
    Eep_30_XXspi01_ProcessResultType retVal = EEP_NOT_OK;
    uint8 Command;
    Eep_30_XXspi01_SpiConstDataPtrType SrcSpiDataBufferPtr = NULL_PTR;
    Eep_30_XXspi01_SpiDataPtrType DesSpiDataBufferPtr = NULL_PTR;

    /* #10 Set number of queries */
    /* #20 Only necessary if verify state is active (=> Write class jobs) */
    if (Eep_30_XXspi01_IsWriteClassJob() == TRUE)
    {
        Eep_30_XXspi01_SetNrOfQueries();
    }

    /* #30 Set chunk size and command */
    Command = Eep_30_XXspi01_SetChunkSizeAndCommand();

    /* #40 Prepare buffer */
    Eep_30_XXspi01_PrepareBuffer(&SrcSpiDataBufferPtr, &DesSpiDataBufferPtr); /* SBSW_EEP_07 */

    /* #50 Set data and start transfer */
    if (Eep_30_XXspi01_SetDataAndStartTransfer(Command, Eep_30_XXspi01_JobContext.EepromAddress, SrcSpiDataBufferPtr, DesSpiDataBufferPtr, (Spi_NumberOfDataType) Eep_30_XXspi01_JobContext.ChunkSize) == E_OK) /* SBSW_EEP_08 */
    {
        retVal = EEP_OK;
    }

    return retVal;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_PerformVerifyTask()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_PerformVerifyTask(void)
{
    Eep_30_XXspi01_ProcessResultType retVal = EEP_NOT_OK;

    /* #10 Read Status Register to DataBuffer */
    if (Eep_30_XXspi01_SetDataAndStartTransfer(EEP_30_XXSPI01_CMD_RDSR, EEP_30_XXSPI01_ADDRESS_DUMMY, NULL_PTR, Eep_30_XXspi01_DataBufferPtr[Eep_30_XXspi01_JobContext.Index], EEP_30_XXSPI01_LENGTH_STATUSREG) == E_OK) /* SBSW_EEP_08 */
    {
        retVal = EEP_OK;
    }

    return retVal;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_PerformFinalizeTask()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
EEP_LOCAL FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_PerformFinalizeTask(void)
{
    Eep_30_XXspi01_ProcessResultType retVal;

    /* #10 If it's a write-class job finalize the Write-Class job */
    if (Eep_30_XXspi01_IsWriteClassJob() == TRUE)
    {
        retVal = Eep_30_XXspi01_FinalizeWriteClassJob();
    }
    /* #20 If it's a read-class job finalize the Read-Class job */
    else
    {
        retVal = Eep_30_XXspi01_FinalizeReadClassJob();
    }

    return retVal;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_FinalizeReadClassJob()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_FinalizeReadClassJob(void)
{
    Eep_30_XXspi01_ProcessResultType retVal = EEP_OK;

    /* #10 Perform job-specific post-processing */
    switch (Eep_30_XXspi01_JobContext.CurrentJob)
    {
    case EEP_SPI_JOB_READ:
    case EEP_SPI_JOB_READINC:
#if (EEP_30_XXSPI01_REARRANGE_DATA == STD_ON)
    {
        Eep_30_XXspi01_LengthType localCounter;
        for (localCounter = 0u; localCounter < Eep_30_XXspi01_JobContext.ChunkSize; localCounter++)
        {
            /* #12 Copy the read data at the location specified by the read job */
            Eep_30_XXspi01_JobContext.DesDataBufferPtr[Eep_30_XXspi01_JobContext.DataBufferIndex + localCounter] = (uint8)Eep_30_XXspi01_DataBufferPtr[Eep_30_XXspi01_JobContext.Index][localCounter]; /* SBSW_EEP_16 */
        }
    }

#endif
        break;
    default: /* EEP_SPI_JOB_COMPARE || EEP_SPI_JOB_COMPAREINC */
        retVal = Eep_30_XXspi01_CompareBuffers();
        break;
    }

    /*#20 Check if no compare error occurred */
    if (retVal == EEP_OK)
    {
        /* #23 Update job context */
        Eep_30_XXspi01_JobContext.DataBufferIndex += Eep_30_XXspi01_JobContext.ChunkSize;
        Eep_30_XXspi01_JobContext.EepromAddress += Eep_30_XXspi01_JobContext.ChunkSize;
        Eep_30_XXspi01_JobContext.RemainingBytes -= Eep_30_XXspi01_JobContext.ChunkSize;

        /* #25 Check if current job is not yet finished */
        if (Eep_30_XXspi01_JobContext.RemainingBytes != 0u)
        {
            retVal = EEP_NOT_FINISHED;
        }
    }

    return retVal;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_FinalizeWriteClassJob()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_FinalizeWriteClassJob(void)
{
    Eep_30_XXspi01_ProcessResultType retVal;

    /* #10 Check if EEPROM is still busy */
    /* #11 return EEP_OK if EEPROM is idle */
    /* #12 return EEP_BUSY if EEPROM is busy */
    /* #13 return EEP_TIMEOUT if timeout occurred */
    retVal = Eep_30_XXspi01_CheckEepromBusy();

    /* Proceed only if EEPROM is idle */
    if (retVal == EEP_OK)
    {
        /* #20 Check if write failed: Write Enable == 1 */
        /* #21 When the write cycle is completed, the write enable latch (WEL) should be reset to 0 */
        if ((Eep_30_XXspi01_DataBufferPtr[Eep_30_XXspi01_JobContext.Index][0u] & EEP_30_XXSPI01_MASK_WRITE_ENABLE) == EEP_30_XXSPI01_MASK_WRITE_ENABLE)
        {
            /* #25 Write was not successful: {EEP_30_XXSPI01_MASK_WRITE_ENABLE, EEP_30_XXSPI01_MASK_BUSY} = {1, 0} */
            /* #26 First write attempt is not necessarily an error for EEPROMs that deliver the status register in real-time */
            if (Eep_30_XXspi01_JobContext.FirstWriteAttempt == TRUE)
            {
                Eep_30_XXspi01_JobContext.FirstWriteAttempt = FALSE;
                /* #27 StatusRegister needs to be read again */
                retVal = EEP_BUSY;
            }
            else
            {
                /* #28 Writing failed */
                retVal = EEP_NOT_OK;
            }
        }
        else
        {
            /* #30 Write was successful */

            /* #31 Update job context */
            Eep_30_XXspi01_JobContext.DataBufferIndex += Eep_30_XXspi01_JobContext.ChunkSize;
            Eep_30_XXspi01_JobContext.EepromAddress += (Eep_30_XXspi01_AddressType) Eep_30_XXspi01_JobContext.ChunkSize;
            Eep_30_XXspi01_JobContext.RemainingBytes -= (Eep_30_XXspi01_LengthType) Eep_30_XXspi01_JobContext.ChunkSize;

            /* #32 Check if current job is not yet finished */
            if (Eep_30_XXspi01_JobContext.RemainingBytes != 0u)
            {
                retVal = EEP_NOT_FINISHED;
            }
#if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
            /* #40 Handle WP pin in case of Unlock job */
            else
            {
                if (Eep_30_XXspi01_JobContext.CurrentJob == EEP_SPI_JOB_UNLOCK)
                {
                    if (Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->WriteProtectChannel != EEP_30_XXSPI01_WP_PIN_NOT_USED) /* COV_EEP_POSTBUILD_CONFIG */
                    {
                        /* #45 There's no need to check if the pin is high, it has to be high. Pull WP pin to low */
                        Dio_WriteChannel(Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->WriteProtectChannel, STD_LOW);
                    }
                }
            }
#endif
        }

    }

    return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
  Eep_30_XXspi01_Min()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL_INLINE FUNC(Eep_30_XXspi01_LengthType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Min(Eep_30_XXspi01_LengthType Param1, Eep_30_XXspi01_LengthType Param2)
{
    /* #10 Returns Param1 if smaller than Param2, otherwise Param2 */
    return (Param1 < Param2) ? Param1 : Param2;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_CheckEepromBusy()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_CheckEepromBusy(void)
{
    Eep_30_XXspi01_ProcessResultType retVal = EEP_OK;

    /* #10 Check if EEPROM is still busy */
    if ((Eep_30_XXspi01_DataBufferPtr[Eep_30_XXspi01_JobContext.Index][0u] & EEP_30_XXSPI01_MASK_BUSY) == 1u)
    {
        Eep_30_XXspi01_JobContext.NrOfQueries--;
        retVal = EEP_BUSY;

        /* #20 Check if timeout occurred */
        if (Eep_30_XXspi01_JobContext.NrOfQueries == 0)
        {
            retVal = EEP_NOT_OK;
#if (EEP_30_XXSPI01_DEV_ERROR_REPORT == STD_ON)
            /* #25 Report DET for all jobs but TestCom */
            if (Eep_30_XXspi01_JobContext.CurrentJob != EEP_SPI_JOB_TESTCOM)
            {
                (void) Det_ReportError(EEP_30_XXSPI01_MODULE_ID, EEP_30_XXSPI01_INSTANCE_ID, EEP_30_XXSPI01_SID_MAIN_FUNCTION, EEP_30_XXSPI01_E_TIMEOUT);
            }
#endif
        }
    }

    return retVal;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_CompareBuffers()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL_INLINE FUNC(Eep_30_XXspi01_ProcessResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_CompareBuffers(void)
{
    Eep_30_XXspi01_ProcessResultType retVal = EEP_OK;
    Eep_30_XXspi01_LengthType localCounter;

    for (localCounter = 0u; localCounter < Eep_30_XXspi01_JobContext.ChunkSize; localCounter++)
    {
        /* #10 Compare read data with compare buffer */
        if (Eep_30_XXspi01_JobContext.SrcDataBufferPtr[Eep_30_XXspi01_JobContext.DataBufferIndex + localCounter] != (uint8)Eep_30_XXspi01_DataBufferPtr[Eep_30_XXspi01_JobContext.Index][localCounter])
        {
            retVal = EEP_INCONSISTENT;
            break;
        }
    }
    return retVal;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_SetDataAndStartTransfer()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
EEP_LOCAL FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetDataAndStartTransfer(uint8 Command,
                                                            Eep_30_XXspi01_AddressType Address,
                                                            Eep_30_XXspi01_SpiConstDataPtrType SrcDataBufferPtr,
                                                            Eep_30_XXspi01_SpiDataPtrType DesDataBufferPtr,
                                                            Spi_NumberOfDataType Length)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint16 localCounter;

    /* #10 The first byte of CommandBuffer is always the EEPROM command */
    Eep_30_XXspi01_CommandBufferPtr[Eep_30_XXspi01_JobContext.Index][0] = Command; /* SBSW_EEP_09 */

    /* #20 Setup Write Disable or Write Enable job */
    if ((Command == EEP_30_XXSPI01_CMD_WREN)
#if ((EEP_30_XXSPI01_RESET_LATCH == STD_ON) || (EEP_30_XXSPI01_TEST_COM_API == STD_ON))
     || (Command == EEP_30_XXSPI01_CMD_WRDI)
#endif
       )
    {
        /* #25 Setup command only job */
        retVal = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->SpiApiPtr->SetupEB(
                                                            Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->CoCommandChannel,
                                                            Eep_30_XXspi01_CommandBufferPtr[Eep_30_XXspi01_JobContext.Index],
                                                            NULL_PTR,
                                                            EEP_30_XXSPI01_LENGTH_COMMAND); /* SBSW_EEP_10 */ /* SBSW_EEP_17 */
        Eep_30_XXspi01_JobContext.CurrentSequence = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->CoSequence;
    }
    /* #30 Setup Read Status Register or Write Status Register job (only Unlock job) */
    else if ((Command == EEP_30_XXSPI01_CMD_RDSR)
#if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
            || (Command == EEP_30_XXSPI01_CMD_WRSR)
#endif
            )
    {
        /* #31 Setup command channel */
        if (Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->SpiApiPtr->SetupEB(
                                                            Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->CdCommandChannel,
                                                            Eep_30_XXspi01_CommandBufferPtr[Eep_30_XXspi01_JobContext.Index],
                                                            NULL_PTR,
                                                            EEP_30_XXSPI01_LENGTH_COMMAND) == E_OK) /* SBSW_EEP_10 */ /* SBSW_EEP_17 */
        {
            /* #32 Setup data channel */
            retVal = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->SpiApiPtr->SetupEB(
                                                                Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->CdDataChannel,
                                                                SrcDataBufferPtr,
                                                                DesDataBufferPtr,
                                                                Length); /* SBSW_EEP_11 */ /* SBSW_EEP_17 */
            Eep_30_XXspi01_JobContext.CurrentSequence = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->CdSequence;
        }
    }
    /* #40 Setup one of remaining commands */
    else
    {
        /* #41 Prepare first byte of CommandBuffer in case of small EEPROMs with 9 address bits */
        if (Eep_30_XXspi01_ChipPtr[Eep_30_XXspi01_JobContext.Index]->CommandBufferSize == 2u) /* COV_EEP_POSTBUILD_CONFIG */
        {
            /* #42 In case of 9-bit addressing, a part of address needs to be coded to command byte: */
            /* #43 Highest bit of 9-bit address is stored in bit 4 (0x08) of command byte */
            Eep_30_XXspi01_CommandBufferPtr[Eep_30_XXspi01_JobContext.Index][0] |= (Spi_DataType)((Address >> 5u) & 0x08u); /* SBSW_EEP_09 */
        }

        /* #45 Store address to second, third, etc. bytes (depending on addressing width) of CommandBuffer */
        for (localCounter = Eep_30_XXspi01_ChipPtr[Eep_30_XXspi01_JobContext.Index]->CommandBufferSize; localCounter > 1u; localCounter--)
        {
            Eep_30_XXspi01_CommandBufferPtr[Eep_30_XXspi01_JobContext.Index][localCounter - 1u] = (uint8)Address; /* SBSW_EEP_09 */
            Address >>= 8u;
        }

        /* #50 Setup command channel */
        if (Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->SpiApiPtr->SetupEB(
                                                            Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->CdCommandChannel,
                                                            Eep_30_XXspi01_CommandBufferPtr[Eep_30_XXspi01_JobContext.Index],
                                                            NULL_PTR,
                                                            Eep_30_XXspi01_ChipPtr[Eep_30_XXspi01_JobContext.Index]->CommandBufferSize)
            == E_OK) /* SBSW_EEP_10 */ /* SBSW_EEP_17 */
        {
            /* #55 Setup data channel */
            retVal = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->SpiApiPtr->SetupEB(
                                                                Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->CdDataChannel,
                                                                SrcDataBufferPtr,
                                                                DesDataBufferPtr,
                                                                Length); /* SBSW_EEP_11 */ /* SBSW_EEP_17 */
            Eep_30_XXspi01_JobContext.CurrentSequence = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->CdSequence;
        }
    }

    /* #60 Transmit current sequence if setup was successful */
    if (retVal == E_OK){
        retVal = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->SpiApiPtr->AsyncTransmit(Eep_30_XXspi01_JobContext.CurrentSequence); /* SBSW_EEP_17 */
    }

    return retVal;
}

/**********************************************************************************************************************
  Eep_SwitchState()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC (void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SwitchState(Eep_30_XXspi01_ProcessResultType Result)
{
    switch (Result)
    {
    case EEP_NOT_OK:
        /* #10 Finish job due to negative result */
        Eep_30_XXspi01_FinishJob(MEMIF_JOB_FAILED);
        break;
    case EEP_OK:
        /* #20 Finish job due to successful result */
        Eep_30_XXspi01_FinishJob(MEMIF_JOB_OK);
        break;
    case EEP_BUSY:
        /* #30 Verification needs to be performed again */
        Eep_30_XXspi01_ComponentParameter.FsmState = EEP_30_XXSPI01_STATE_VERIFY;

        if (Eep_30_XXspi01_PerformVerifyTask() != EEP_OK)
        {
            Eep_30_XXspi01_FinishJob(MEMIF_JOB_FAILED);
        }
        break;
    case EEP_NOT_FINISHED:
        /* #40 Job is not yet finished, thus start from the beginning */
        Eep_30_XXspi01_InitiateFirstState();
        break;
    case EEP_INCONSISTENT:
        /* #50 Inconsistency was detected upon comparing data areas */
        Eep_30_XXspi01_FinishJob(MEMIF_BLOCK_INCONSISTENT);
        break;
    default:    /* PRQA S 2018 */ /* MD_MSR_14.1 */ /* COV_EEP_DEFAULT */
        Eep_30_XXspi01_FinishJob(MEMIF_JOB_FAILED);
        break;
    }
}

/**********************************************************************************************************************
  Eep_30_XXspi01_IsWriteClassJob()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
EEP_LOCAL_INLINE FUNC(boolean, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_IsWriteClassJob(void)
{
    boolean retVal;

    /* #10 Return TRUE in case of write class job: Write, Erase, TestCom, Unlock */
    switch (Eep_30_XXspi01_JobContext.CurrentJob)
    {
    case EEP_SPI_JOB_WRITE:
    case EEP_SPI_JOB_WRITEINC:
    case EEP_SPI_JOB_ERASE:
    case EEP_SPI_JOB_TESTCOM:
    case EEP_SPI_JOB_UNLOCK:
        retVal = TRUE;
        break;
    default:
        retVal = FALSE;
        break;
    }

    return retVal;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_SetNrOfQueries()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetNrOfQueries(void)
{
    /* #10 NrOfQueries is only used in verify state. Thus it is only called while performing write-class jobs */
#if (EEP_30_XXSPI01_TEST_COM_API == STD_ON)
    if (Eep_30_XXspi01_JobContext.CurrentJob == EEP_SPI_JOB_TESTCOM)
    {
        /* #20 Set NrOfQueries to 1 in case of TestCom-Job */
        Eep_30_XXspi01_JobContext.NrOfQueries = 1u;
    }
    else
#endif
    {
        /* #30 Set NrOfQueries to configured value for Write, WriteInc, Erase and Unlock jobs */
        if (Eep_30_XXspi01_ComponentParameter.CurrentHandling == EEP_30_XXSPI01_HANDLING_RECURRENT) /* COV_EEP_POSTBUILD_CONFIG */
        {
            Eep_30_XXspi01_JobContext.NrOfQueries = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->NbOfRecurrentQueries;
        }
        else /* COV_EEP_POSTBUILD_CONFIG */
        {
            Eep_30_XXspi01_JobContext.NrOfQueries = Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->NbOfBurstQueries;
        }
    }
}

/**********************************************************************************************************************
  Eep_30_XXspi01_SetChunkSizeAndCommand()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC(uint8, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetChunkSizeAndCommand(void)
{
    uint8 Command;

    /* #10 Set ChunkSize and Command according to current job */
    if (Eep_30_XXspi01_IsWriteClassJob() == TRUE)
    {
        /* #20 Set ChunkSize and Command in case of Write class job */
#if (EEP_30_XXSPI01_TEST_COM_API == STD_ON)
        if (Eep_30_XXspi01_JobContext.CurrentJob == EEP_SPI_JOB_TESTCOM)
        {
            /* #30 TestCom job */
            Eep_30_XXspi01_JobContext.ChunkSize = EEP_30_XXSPI01_LENGTH_DUMMY;
            Command = EEP_30_XXSPI01_CMD_WRDI;
        }
        else
#endif
#if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
        if (Eep_30_XXspi01_JobContext.CurrentJob == EEP_SPI_JOB_UNLOCK)
        {
            /* #40 Unlock job */
            Eep_30_XXspi01_JobContext.ChunkSize = EEP_30_XXSPI01_LENGTH_STATUSREG;
            Command = EEP_30_XXSPI01_CMD_WRSR;
        }
        else
#endif
#if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
        if (Eep_30_XXspi01_JobContext.CurrentJob == EEP_SPI_JOB_WRITEINC)
        {
            /* #50 WriteInc job */
            Eep_30_XXspi01_JobContext.ChunkSize = EEP_30_XXSPI01_LENGTH_INCREMENTAL;
            Command = EEP_30_XXSPI01_CMD_WRINC;
        }
        else
#endif
        {
            /* #60 Write job, Erase job */

            /* #70 ChunkSize could be at maximum the amount of bytes until the upper page boundary is reached */
            Eep_30_XXspi01_JobContext.ChunkSize = (Eep_30_XXspi01_LengthType) (Eep_30_XXspi01_ChipPtr[Eep_30_XXspi01_JobContext.Index]->PageSize -
                                                                              (Eep_30_XXspi01_JobContext.EepromAddress &
                                                                              (Eep_30_XXspi01_ChipPtr[Eep_30_XXspi01_JobContext.Index]->PageSize - 1u)));

            /* #80 ChunkSize = min(ChunkSize, RemainingBytes, WriteSize) */
            Eep_30_XXspi01_JobContext.ChunkSize =  Eep_30_XXspi01_Min(Eep_30_XXspi01_Min(Eep_30_XXspi01_JobContext.ChunkSize,
                                                                                         Eep_30_XXspi01_JobContext.RemainingBytes),
                                                                      Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->WriteSize[Eep_30_XXspi01_ComponentParameter.CurrentMode]);

            Command = EEP_30_XXSPI01_CMD_WRITE;
        }
    }
    else
    {
        /* #120 Set ChunkSize and Command in case of Read class job */
        /* #130 ChunkSize = min(ReadSize, RemainingBytes) */
        Eep_30_XXspi01_JobContext.ChunkSize = Eep_30_XXspi01_Min(Eep_30_XXspi01_JobContext.RemainingBytes,
            Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->ReadSize[Eep_30_XXspi01_ComponentParameter.CurrentMode]);

        Command = EEP_30_XXSPI01_CMD_READ;
    }
    return Command;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
  Eep_30_XXspi01_PrepareBuffer()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_PrepareBuffer(Eep_30_XXspi01_SpiConstDataPtrPtrType SrcBufferPtrPtr,
                                                                              Eep_30_XXspi01_SpiDataPtrPtrType DesBufferPtrPtr)
{
    /* #10 Set buffers according to write class job */
    if (Eep_30_XXspi01_IsWriteClassJob() == TRUE)
    {
        /* #20 Write and WriteInc job */
        if ( (Eep_30_XXspi01_JobContext.CurrentJob == EEP_SPI_JOB_WRITE)
#if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
          || (Eep_30_XXspi01_JobContext.CurrentJob == EEP_SPI_JOB_WRITEINC)
#endif
        )
        {
#if (EEP_30_XXSPI01_REARRANGE_DATA == STD_ON)
            Eep_30_XXspi01_LengthType localCounter;
            for (localCounter = 0u; localCounter < Eep_30_XXspi01_JobContext.ChunkSize; localCounter++)
            {
                Eep_30_XXspi01_DataBufferPtr[Eep_30_XXspi01_JobContext.Index][localCounter] = Eep_30_XXspi01_JobContext.SrcDataBufferPtr[Eep_30_XXspi01_JobContext.DataBufferIndex + localCounter]; /* SBSW_EEP_13 */
            }

            *SrcBufferPtrPtr = Eep_30_XXspi01_DataBufferPtr[Eep_30_XXspi01_JobContext.Index];  /* SBSW_EEP_12 */
#else
            *SrcBufferPtrPtr = &Eep_30_XXspi01_JobContext.SrcDataBufferPtr[Eep_30_XXspi01_JobContext.DataBufferIndex];  /* SBSW_EEP_12 */
#endif
        }
        else
#if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
        /* #30 Unlock job */
        if (Eep_30_XXspi01_JobContext.CurrentJob == EEP_SPI_JOB_UNLOCK)
        {
            *SrcBufferPtrPtr = &Eep_30_XXspi01_JobContext.LockLevel;  /* SBSW_EEP_12 */
        }
        else
#endif
        {
            /* #40 Erase, TestCom job*/
            *SrcBufferPtrPtr = NULL_PTR;  /* SBSW_EEP_12 */
        }
    }
    /* #50 Set buffers according to read class job */
    else
    {
#if (EEP_30_XXSPI01_REARRANGE_DATA == STD_OFF)
        if ( (Eep_30_XXspi01_JobContext.CurrentJob == EEP_SPI_JOB_READ)
# if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
          || (Eep_30_XXspi01_JobContext.CurrentJob == EEP_SPI_JOB_READINC)
# endif
        )
        {
            *DesBufferPtrPtr = &Eep_30_XXspi01_JobContext.DesDataBufferPtr[Eep_30_XXspi01_JobContext.DataBufferIndex]; /* SBSW_EEP_12 */
        }
        else
#endif
        {
            *DesBufferPtrPtr = Eep_30_XXspi01_DataBufferPtr[Eep_30_XXspi01_JobContext.Index]; /* SBSW_EEP_12 */
        }
    }
}

/**********************************************************************************************************************
  Eep_30_XXspi01_FinishJob()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC (void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_FinishJob(MemIf_JobResultType JobResult)
{
    /* #10 Reset state machine */
    Eep_30_XXspi01_ResetFsm();

    /* #20 Reset ProcessMainFunction flag. MainFunction no longer needs to be processed */
    Eep_30_XXspi01_ResetMainFunctionFlag();

    /* #30 Set component global parameters */
    Eep_30_XXspi01_ComponentParameter.JobResult = JobResult;
    Eep_30_XXspi01_ComponentParameter.Status = MEMIF_IDLE;

    /* #40 Depending on configuration, job finish is reported to upper layer via callback hooks */
    if (JobResult == MEMIF_JOB_OK)
    {
        /* #41 Invoke JobEndNotification in case of successful job */
        if (Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->JobEndNotification != NULL_PTR) /* COV_EEP_POSTBUILD_CONFIG */
        {
            Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->JobEndNotification(); /* SBSW_EEP_14 */
        }
    }
    else
    {
        /* #42 Invoke JobErrorNotification in case of unsuccessful job */
        if (Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->JobErrorNotification != NULL_PTR) /* COV_EEP_POSTBUILD_CONFIG */
        {
            Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->JobErrorNotification(); /* SBSW_EEP_14 */
        }

        /* #45 Report DEM error in case of unsuccessful job finish */
        Eep_30_XXspi01_ReportDemError();
    }

}

/**********************************************************************************************************************
  Eep_30_XXspi01_ProcessFsm()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
EEP_LOCAL_INLINE FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ProcessFsm(void)
{
    /* #10 Reset MainFunction flag, so that this function can't be processed again */
    Eep_30_XXspi01_ResetMainFunctionFlag();

    /* #20 Perform cancel if cancel flag is set */
    if (Eep_30_XXspi01_ComponentFlags.CancelRequested == TRUE)
    {
        Eep_30_XXspi01_ResetFsm();
        Eep_30_XXspi01_ResetCancelFlag();
    }

    /* #30 State machine will only be processed if main function processing flag is true */
    switch (Eep_30_XXspi01_ComponentParameter.FsmState)
    {
    /* --------------------------------------------------------------- */
    /* --------------------------STATE IDLE--------------------------- */
    /* --------------------------------------------------------------- */
    case EEP_30_XXSPI01_STATE_IDLE:
        /* #40 Check if new job has been requested after cancellation */
        if (Eep_30_XXspi01_ComponentFlags.JobRequested == TRUE)
        {
            /* #50 Start new job */
            Eep_30_XXspi01_InitiateFirstState();
            Eep_30_XXspi01_ComponentFlags.JobRequested = FALSE;
        }
        break;
    /* --------------------------------------------------------------- */
    /* --------------------------STATE PREPARE------------------------ */
    /* --------------------------------------------------------------- */
    case EEP_30_XXSPI01_STATE_PREPARE:
        /* #60 Next state is always EEP_30_XXSPI01_STATE_EXECUTE */
        Eep_30_XXspi01_ComponentParameter.FsmState = EEP_30_XXSPI01_STATE_EXECUTE;

        if (Eep_30_XXspi01_PerformExecuteTask() != EEP_OK)
        {
            Eep_30_XXspi01_FinishJob(MEMIF_JOB_FAILED);
        }

        break;
    /* --------------------------------------------------------------- */
    /* --------------------------STATE EXECUTE------------------------ */
    /* --------------------------------------------------------------- */
    case EEP_30_XXSPI01_STATE_EXECUTE:
        /* #70 Verification is necessary if currently a write job is being processed */
        if (Eep_30_XXspi01_IsWriteClassJob() == TRUE)
        {
            /* #80 Next state is EEP_30_XXSPI01_STATE_VERIFY */
            Eep_30_XXspi01_ComponentParameter.FsmState = EEP_30_XXSPI01_STATE_VERIFY;

            if (Eep_30_XXspi01_PerformVerifyTask() != EEP_OK)
            {
                Eep_30_XXspi01_FinishJob(MEMIF_JOB_FAILED);
            }
        }
        else
        {
            /* #90 Finalize current job */
            Eep_30_XXspi01_SwitchState(Eep_30_XXspi01_PerformFinalizeTask());
        }

        break;
    /* --------------------------------------------------------------- */
    /* --------------------------STATE VERIFY------------------------- */
    /* --------------------------------------------------------------- */
    case EEP_30_XXSPI01_STATE_VERIFY:
        /* #100 Finalize current job */
        Eep_30_XXspi01_SwitchState(Eep_30_XXspi01_PerformFinalizeTask());
        break;
    /* --------------------------------------------------------------- */
    /* --------------------------DEFAULT------------------------------ */
    /* --------------------------------------------------------------- */
    default: /* PRQA S 2018 */ /* MD_MSR_14.1 */ /* COV_EEP_DEFAULT */
        Eep_30_XXspi01_FinishJob(MEMIF_JOB_FAILED);
        break;
    }
} /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  Eep_30_XXspi01_InitCfgArray()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitCfgArray(uint8 Index, P2CONST(Eep_30_XXspi01_ConfigType, AUTOMATIC, EEP_30_XXSPI01_PBCFG) ConfigPtr)
{
    /* #10 Initialize config array at given index */
    Eep_30_XXspi01_CfgPtr[Index] = ConfigPtr; /* SBSW_EEP_15 */
}

/**********************************************************************************************************************
  Eep_30_XXspi01_InitComponentParameter()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitComponentParameter(void)
{
    /* #10 Initialize component parameter */
    Eep_30_XXspi01_ComponentParameter.Status = MEMIF_IDLE;
    Eep_30_XXspi01_ComponentParameter.JobResult = MEMIF_JOB_OK;

    /* #20 Initialize state machine */
    Eep_30_XXspi01_ResetFsm();

    /* #30 Clear internal flags */
    Eep_30_XXspi01_ComponentFlags.JobRequested = FALSE;
    Eep_30_XXspi01_ComponentFlags.CancelRequested = FALSE;
    Eep_30_XXspi01_ComponentFlags.ProcessMainFunction = FALSE;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_InitAsyncJob()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitAsyncJob(Eep_30_XXspi01_AddressType EepromAddress,
                                                       Eep_30_XXspi01_BufferPtrType DesDataBufferPtr,
                                                       Eep_30_XXspi01_ConstBufferPtrType SrcDataBufferPtr,
                                                       Eep_30_XXspi01_LengthType Length,
                                                       uint8 Index,
                                                       Eep_30_XXspi01_JobType JobType)
{
    /* #10 Enter exclusive area */
    SchM_Enter_Eep_30_XXspi01_EEP_30_XXSPI01_EXCLUSIVE_AREA_0();

    /* #20 Init job and component parameters */
    Eep_30_XXspi01_InitJobContext(Index, DesDataBufferPtr, SrcDataBufferPtr, Length, EepromAddress, JobType); /* SBSW_EEP_04 */
    Eep_30_XXspi01_StartJob(Index);

    /* #30 Leave exclusive area */
    SchM_Exit_Eep_30_XXspi01_EEP_30_XXSPI01_EXCLUSIVE_AREA_0();
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

#if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_IsIncrementalJob()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_IsIncrementalJob(Eep_30_XXspi01_JobType CurrentJob)
{
    boolean retVal = FALSE;

    /* #10 Check if JobType is an incremental job */
    if ((CurrentJob == EEP_SPI_JOB_READINC) ||
        (CurrentJob == EEP_SPI_JOB_WRITEINC) ||
        (CurrentJob == EEP_SPI_JOB_COMPAREINC)
       )
    {
        retVal = TRUE;
    }

    return retVal;
}
#endif

#if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_SetLockLevel()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetLockLevel(Eep_30_XXspi01_LockLevelType LockLevel)
{
    /* #10 Set JobContext's lock level */
    Eep_30_XXspi01_JobContext.LockLevel = (Spi_DataType) LockLevel;
}
#endif

/**********************************************************************************************************************
  Eep_30_XXspi01_SetCurrentMode()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetCurrentMode(MemIf_ModeType Mode)
{
    /* #10 Set current mode to passed Mode */
    Eep_30_XXspi01_ComponentParameter.CurrentMode = Mode;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_SetCurrentHandling()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetCurrentHandling(Eep_30_XXspi01_HandlingType Handling)
{
    /* #10 Set current handling to passed Handling */
    Eep_30_XXspi01_ComponentParameter.CurrentHandling = Handling;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_GetCurrentJobResult()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC (MemIf_JobResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetCurrentJobResult(void)
{
    /* #10 Return component job result */
    return Eep_30_XXspi01_ComponentParameter.JobResult;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_GetCurrentStatus()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC (MemIf_StatusType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetCurrentStatus(void)
{
    /* #10 Return component status */
    return Eep_30_XXspi01_ComponentParameter.Status;
}

/**********************************************************************************************************************
  Eep_30_XXspi01_CancelJob()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC (void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_CancelJob(void)
{
    /* #10 If any job was requested but not yet processed, it's cancelled now */
    Eep_30_XXspi01_ComponentFlags.JobRequested = FALSE;
    /* #20 Set Cancel flag, which is processed in next call of MainFunction */
    Eep_30_XXspi01_ComponentFlags.CancelRequested = TRUE;

    /* #30 Set component global parameters accordingly */
    Eep_30_XXspi01_ComponentParameter.Status = MEMIF_IDLE;
    Eep_30_XXspi01_ComponentParameter.JobResult = MEMIF_JOB_CANCELED;

    /* #40 Call JobErrorNotification if configured */
    if (Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->JobErrorNotification != NULL_PTR) /* COV_EEP_POSTBUILD_CONFIG */
    {
        Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->JobErrorNotification(); /* SBSW_EEP_14 */
    }

}

/**********************************************************************************************************************
  Eep_30_XXspi01_MainFunctionStd()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_MainFunctionStd(void)
{
    /* #10 Check if state machine needs to be processed */
    if (Eep_30_XXspi01_ComponentFlags.ProcessMainFunction == TRUE)
    {
        /* #20 Process state machine */
        Eep_30_XXspi01_ProcessFsm();
    }
}

/**********************************************************************************************************************
  Eep_30_XXspi01_ComEndStd()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ComEndStd(void)
{
    if (Eep_30_XXspi01_CfgPtr[Eep_30_XXspi01_JobContext.Index]->SpiApiPtr->GetSequenceResult(Eep_30_XXspi01_JobContext.CurrentSequence) == SPI_SEQ_OK) /* SBSW_EEP_17 */
    {
        /* #10 Set MainFunction process flag to true, so that job processing goes on */
        Eep_30_XXspi01_ComponentFlags.ProcessMainFunction = TRUE;
    }
    else
    {
        /* #20 Finish job due to failed SPI sequence */
        Eep_30_XXspi01_FinishJob(MEMIF_JOB_FAILED);
    }
}

#define EEP_30_XXSPI01_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: Eep_30_XXspi01_Proc.c
 *********************************************************************************************************************/
