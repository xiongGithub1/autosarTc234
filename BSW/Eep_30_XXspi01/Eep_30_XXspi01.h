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
 *       \file     Eep_30_XXspi01.h
 *       \brief    Eep Spi header file
 *
 *       \details  Eep provides API services to upper layer (Ea). Eep performs jobs on underlying EEPROM device via
 *                 SPI bus communication.
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  AUTHOR IDENTITY
 *--------------------------------------------------------------------------------------------------------------------
 *  Initials    Name                    Company
 *  --------    ---------------------   ----------------------------------------------------------------------------
 *  virgmi      Michael Goss            Vector Informatik GmbH
 *--------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *--------------------------------------------------------------------------------------------------------------------
 *  Version     Date        Author      Change Id      Description
 * -------------------------------------------------------------------------------------------------------------------
 *  3.00.00     2016-12-01  virgmi      ESCAN00093190  Rework implementation: Do not use HL/LL concept
 *  3.00.01     2017-10-20  virgmi      ESCAN00097120  Incorrect MemMap section is used
 *                                      ESCAN00095369  Compiler error: Undefined compiler abstraction symbol used
 *                                      ESCAN00097177  Compiler warning: Function declared but never referenced
 *********************************************************************************************************************/

#if !defined (EEP_30_XXSPI01_H)
# define EEP_30_XXSPI01_H

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* vendor, module and instance identification */
# define EEP_30_XXSPI01_VENDOR_ID                   (30u)
# define EEP_30_XXSPI01_MODULE_ID                   (90u)
# define EEP_30_XXSPI01_INSTANCE_ID                 (0u)

/* specification version */
# define EEP_30_XXSPI01_AR_RELEASE_MAJOR_VERSION    (4u)
# define EEP_30_XXSPI01_AR_RELEASE_MINOR_VERSION    (0u)
# define EEP_30_XXSPI01_AR_RELEASE_REVISION_VERSION (3u)

/* version - as expected in API Eep_30_XXspi01_GetVersionInfo() */
# define EEP_30_XXSPI01_SW_MAJOR_VERSION            (3u)
# define EEP_30_XXSPI01_SW_MINOR_VERSION            (0u)
# define EEP_30_XXSPI01_SW_PATCH_VERSION            (1u)

# define EEP_30_XXSPI01_WP_PIN_NOT_USED             ((Dio_ChannelType)0xFFFFFFFFu)
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "Eep_30_XXspi01_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* API IDs */
# define EEP_30_XXSPI01_SID_INIT                   (0x00u)
# define EEP_30_XXSPI01_SID_SET_MODE               (0x01u)
# define EEP_30_XXSPI01_SID_READ                   (0x02u)
# define EEP_30_XXSPI01_SID_WRITE                  (0x03u)
# define EEP_30_XXSPI01_SID_ERASE                  (0x04u)
# define EEP_30_XXSPI01_SID_COMPARE                (0x05u)
# define EEP_30_XXSPI01_SID_CANCEL                 (0x06u)
# define EEP_30_XXSPI01_SID_GET_STATUS             (0x07u)
# define EEP_30_XXSPI01_SID_GET_JOB_RESULT         (0x08u)
# define EEP_30_XXSPI01_SID_MAIN_FUNCTION          (0x09u)
# define EEP_30_XXSPI01_SID_GET_VERSION_INFO       (0x0Au)
# define EEP_30_XXSPI01_SID_COM_END                (0x0Bu)
# define EEP_30_XXSPI01_SID_SET_HANDLING           (0x0Cu)
# define EEP_30_XXSPI01_SID_TEST_COM               (0x0Du)
# define EEP_30_XXSPI01_SID_SET_LOCK_LEVEL         (0x0Eu)

/* DET error codes */
# define EEP_30_XXSPI01_E_NO_ERROR                 (0x00u)
# define EEP_30_XXSPI01_E_PARAM_CONFIG             (0x10u)
# define EEP_30_XXSPI01_E_PARAM_ADDRESS            (0x11u)
# define EEP_30_XXSPI01_E_PARAM_DATA               (0x12u)
# define EEP_30_XXSPI01_E_PARAM_LENGTH             (0x13u)
# define EEP_30_XXSPI01_E_UNINIT                   (0x20u)
# define EEP_30_XXSPI01_E_BUSY                     (0x21u)
# define EEP_30_XXSPI01_E_TIMEOUT                  (0x22u)
# define EEP_30_XXSPI01_E_PARAM_POINTER            (0x23u)


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define EEP_30_XXSPI01_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2VAR(uint8, AUTOMATIC, EEP_30_XXSPI01_APPL_DATA) Eep_30_XXspi01_BufferPtrType;
typedef P2CONST(uint8, AUTOMATIC, EEP_30_XXSPI01_APPL_DATA) Eep_30_XXspi01_ConstBufferPtrType;
typedef P2CONST(Eep_30_XXspi01_ConfigType, AUTOMATIC, EEP_30_XXSPI01_PBCFG) Eep_30_XXspi01_ConfigPtrType;
typedef P2VAR(Std_VersionInfoType, AUTOMATIC, EEP_30_XXSPI01_APPL_DATA) Eep_30_XXspi01_VersionInfoPtrType;

#define EEP_30_XXSPI01_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define EEP_30_XXSPI01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
  Eep_30_XXspi01_InitMemory()
**********************************************************************************************************************/
/*!
 * \brief      Initializes chip, command buffer and data buffer structures
 * \details    Initializes chip, command buffer and data buffer structures. Service is called upon module initialization
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 * \trace CREQ-103337
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_InitMemory(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_Init()
**********************************************************************************************************************/
/*!
 * \brief      Initializes configuration structure
 * \details    Initializes configuration structure. Service is called upon module initialization
 * \param[in]  ConfigPtr
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 * \trace CREQ-103329
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Init(Eep_30_XXspi01_ConfigPtrType ConfigPtr);

/**********************************************************************************************************************
  Eep_30_XXspi01_SetMode()
**********************************************************************************************************************/
/*!
 * \brief      Sets mode for jobs.
 * \details    Sets mode for jobs. Jobs can either be performed in fast or in slow mode.
 * \param[in]  Mode
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 * \trace CREQ-106479
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetMode(MemIf_ModeType Mode);

/**********************************************************************************************************************
  Eep_30_XXspi01_SetHandling()
**********************************************************************************************************************/
/*!
 * \brief      Sets handling for jobs.
 * \details    Sets handling for jobs. Jobs can either be performed in burst or with recurrent handling.
 * \param[in]  Handling
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 * \trace CREQ-106480
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_SetHandling(Eep_30_XXspi01_HandlingType Handling);

/**********************************************************************************************************************
  Eep_30_XXspi01_Read()
**********************************************************************************************************************/
/*!
 * \brief      Reads a number of bytes (Length) from EepromAddress in EEPROM to buffer referenced by DataBufferPtr.
 * \details    Reads a number of bytes (Length) from EepromAddress in EEPROM to buffer referenced by DataBufferPtr.
 * \param[in]  EepromAddress
 * \param[out]  DataBufferPtr
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 * \trace CREQ-103325
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Read(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_BufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);

# if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_ReadIncReg()
**********************************************************************************************************************/
/*!
 * \brief      Reads a number of bytes (Length) from EepromAddress in EEPROM to buffer referenced by DataBufferPtr.
 * \details    Reads a number of bytes (Length) from address in incremental address area in EEPROM to buffer referenced by DataBufferPtr.
 * \param[in]  EepromAddress
 * \param[out]  DataBufferPtr
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Incremental feature enabled
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_ReadIncReg(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_BufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);
# endif

/**********************************************************************************************************************
  Eep_30_XXspi01_Write()
**********************************************************************************************************************/
/*!
 * \brief      Writes a number of bytes (Length) to EepromAddress in EEPROM from buffer referenced by DataBufferPtr.
 * \details    Writes a number of bytes (Length) to EepromAddress in EEPROM from buffer referenced by DataBufferPtr.
 * \param[in]  EepromAddress
 * \param[in]  DataBufferPtr
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 * \trace CREQ-103324
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Write(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);

# if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_WriteIncReg()
**********************************************************************************************************************/
/*!
 * \brief      Writes a number of bytes (Length) to EepromAddress in EEPROM from buffer referenced by DataBufferPtr.
 * \details    Writes a number of bytes (Length) to address in incremental address area in EEPROM from buffer referenced by DataBufferPtr.
 * \param[in]  EepromAddress
 * \param[in]  DataBufferPtr
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Incremental feature enabled
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_WriteIncReg(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);
# endif

/**********************************************************************************************************************
  Eep_30_XXspi01_Erase()
**********************************************************************************************************************/
/*!
 * \brief      Erases a number of bytes (Length) at EepromAddress in EEPROM.
 * \details    Erases a number of bytes (Length) at EepromAddress in EEPROM.
 * \param[in]  EepromAddress
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 * \trace CREQ-103326
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Erase(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_LengthType Length);

/**********************************************************************************************************************
  Eep_30_XXspi01_Compare()
**********************************************************************************************************************/
/*!
 * \brief      Compares a number of bytes (Length) from EepromAddress in EEPROM with buffer referenced by DataBufferPtr.
 * \details    Compares a number of bytes (Length) from EepromAddress in EEPROM with buffer referenced by DataBufferPtr.
 * \param[in]  EepromAddress
 * \param[in]  DataBufferPtr
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 * \trace CREQ-103327
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Compare(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);

# if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_CompareIncReg()
**********************************************************************************************************************/
/*!
 * \brief      Compares a number of bytes (Length) from EepromAddress in EEPROM with buffer referenced by DataBufferPtr.
 * \details    Compares a number of bytes (Length) from address in incremental address area of EEPROM with buffer referenced by DataBufferPtr.
 * \param[in]  EepromAddress
 * \param[in]  DataBufferPtr
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Incremental feature enabled
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_CompareIncReg(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);
# endif

# if (EEP_30_XXSPI01_TEST_COM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_TestCom()
**********************************************************************************************************************/
/*!
 * \brief      Performs test communication job in order to assert that Spi communication is setup correctly.
 * \details    Performs test communication job in order to assert that Spi communication is setup correctly.
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Test Communication API is enabled via configuration
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 * \trace CREQ-106475
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_TestCom(void);
# endif

# if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Unlock()
**********************************************************************************************************************/
/*!
 * \brief      Sets lock level of Eeprom to LockLevel.
 * \details    Sets lock level of Eeprom by adjusting block protection bits in status register according to LockLevel.
 * \param[in]  LockLevel
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Unlock Eeprom API is enabled via configuration
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 * \trace CREQ-106476
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Unlock(Eep_30_XXspi01_LockLevelType LockLevel);
# endif

/**********************************************************************************************************************
  Eep_30_XXspi01_GetStatus()
**********************************************************************************************************************/
/*!
 * \brief      Returns current overall module status
 * \details    Returns current overall module status
 * \return     Status of module
 * \pre        -
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 * \trace CREQ-103331
 */
FUNC(MemIf_StatusType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetStatus(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_GetJobResult()
**********************************************************************************************************************/
/*!
 * \brief      Returns current overall module job result
 * \details    Returns current overall module job result
 * \return     Recent job result of module
 * \pre        -
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 * \trace CREQ-103330
 */
FUNC(MemIf_JobResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetJobResult(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_Cancel()
**********************************************************************************************************************/
/*!
 * \brief      Cancels ongoing asynchronous job
 * \details    Cancels ongoing asynchronous job
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 * \trace CREQ-103332
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Cancel(void);

# if (EEP_30_XXSPI01_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_GetVersionInfo()
**********************************************************************************************************************/
/*!
 * \brief      Service to get the version information of Eep module.
 * \details    Stores version information, i.e. Module Id, Vendor Id, Vendor specific version numbers,
 *             to structure pointed by versioninfo.
 * \param[in]  versioninfo
 * \pre        -
 * \config     Version Info API is enabled via configuration
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 * \trace CREQ-103333
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_GetVersionInfo(Eep_30_XXspi01_VersionInfoPtrType versioninfo);
# endif

/**********************************************************************************************************************
  Eep_30_XXspi01_MainFunction()
**********************************************************************************************************************/
/*!
 * \brief      Service to handle the requested jobs and the internal management operations.
 * \details    Service to handle the requested jobs and the internal management operations.
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 * \trace DSGN-Eep22877
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_MainFunction(void);


/* ---------------------------- INST 2 SERVICES -------------------------------------------------------------------- */
# if (EEP_30_XXSPI01_MULTI_CHANNEL == STD_ON)


/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_InitMemory()
**********************************************************************************************************************/
/*!
 * \brief      Initializes chip, command buffer and data buffer structures
 * \details    Initializes chip, command buffer and data buffer structures. Service is called upon module initialization
 * \pre        -
 * \config     Second EEP instance configured
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_InitMemory(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Init()
**********************************************************************************************************************/
/*!
 * \brief      Initializes configuration structure
 * \details    Initializes configuration structure. Service is called upon module initialization
 * \param[in]  ConfigPtr
 * \pre        -
 * \config     Second EEP instance configured
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Init(Eep_30_XXspi01_ConfigPtrType ConfigPtr);

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_SetMode()
**********************************************************************************************************************/
/*!
 * \brief      Sets mode for jobs.
 * \details    Sets mode for jobs. Jobs can either be performed in fast or in slow mode.
 * \param[in]  Mode
 * \pre        -
 * \config     Second EEP instance configured
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_SetMode(MemIf_ModeType Mode);

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_SetHandling()
**********************************************************************************************************************/
/*!
 * \brief      Sets handling for jobs.
 * \details    Sets handling for jobs. Jobs can either be performed in burst or with recurrent handling.
 * \param[in]  Handling
 * \pre        -
 * \config     Second EEP instance configured
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_SetHandling(Eep_30_XXspi01_HandlingType Handling);

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Read()
**********************************************************************************************************************/
/*!
 * \brief      Reads a number of bytes (Length) from EepromAddress in EEPROM to buffer referenced by DataBufferPtr.
 * \details    Reads a number of bytes (Length) from EepromAddress in EEPROM to buffer referenced by DataBufferPtr.
 * \param[in]  EepromAddress
 * \param[out]  DataBufferPtr
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Second EEP instance configured
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Read(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_BufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);

#  if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_ReadIncReg()
**********************************************************************************************************************/
/*!
 * \brief      Reads a number of bytes (Length) from EepromAddress in EEPROM to buffer referenced by DataBufferPtr.
 * \details    Reads a number of bytes (Length) from address in incremental address area in EEPROM to buffer referenced by DataBufferPtr.
 * \param[in]  EepromAddress
 * \param[out]  DataBufferPtr
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Incremental feature enabled. Second EEP instance configured.
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_ReadIncReg(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_BufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);
#  endif

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Write()
**********************************************************************************************************************/
/*!
 * \brief      Writes a number of bytes (Length) to EepromAddress in EEPROM from buffer referenced by DataBufferPtr.
 * \details    Writes a number of bytes (Length) to EepromAddress in EEPROM from buffer referenced by DataBufferPtr.
 * \param[in]  EepromAddress
 * \param[in]  DataBufferPtr
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Second EEP instance configured
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Write(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);

#  if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_WriteIncReg()
**********************************************************************************************************************/
/*!
 * \brief      Writes a number of bytes (Length) to EepromAddress in EEPROM from buffer referenced by DataBufferPtr.
 * \details    Writes a number of bytes (Length) to address in incremental address area in EEPROM from buffer referenced by DataBufferPtr.
 * \param[in]  EepromAddress
 * \param[in]  DataBufferPtr
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Incremental feature enabled. Second EEP instance configured.
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_WriteIncReg(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);
#  endif

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Erase()
**********************************************************************************************************************/
/*!
 * \brief      Erases a number of bytes (Length) at EepromAddress in EEPROM.
 * \details    Erases a number of bytes (Length) at EepromAddress in EEPROM.
 * \param[in]  EepromAddress
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Second EEP instance configured
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Erase(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_LengthType Length);

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Compare()
**********************************************************************************************************************/
/*!
 * \brief      Compares a number of bytes (Length) from EepromAddress in EEPROM with buffer referenced by DataBufferPtr.
 * \details    Compares a number of bytes (Length) from EepromAddress in EEPROM with buffer referenced by DataBufferPtr.
 * \param[in]  EepromAddress
 * \param[in]  DataBufferPtr
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Second EEP instance configured
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Compare(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);

#  if (EEP_30_XXSPI01_INCREG_PARTITION == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_CompareIncReg()
**********************************************************************************************************************/
/*!
 * \brief      Compares a number of bytes (Length) from EepromAddress in EEPROM with buffer referenced by DataBufferPtr.
 * \details    Compares a number of bytes (Length) from address in incremental address area of EEPROM with buffer referenced by DataBufferPtr.
 * \param[in]  EepromAddress
 * \param[in]  DataBufferPtr
 * \param[in]  Length in bytes
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Incremental feature enabled. Second EEP instance configured.
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_CompareIncReg(Eep_30_XXspi01_AddressType EepromAddress,
                                                    Eep_30_XXspi01_ConstBufferPtrType DataBufferPtr,
                                                    Eep_30_XXspi01_LengthType Length);
#  endif

#  if (EEP_30_XXSPI01_TEST_COM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_TestCom()
**********************************************************************************************************************/
/*!
 * \brief      Performs test communication job in order to assert that Spi communication is setup correctly.
 * \details    Performs test communication job in order to assert that Spi communication is setup correctly.
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Test Communication API is enabled via configuration. Second EEP instance configured.
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_TestCom(void);
#  endif

#  if (EEP_30_XXSPI01_UNLOCK_EEPROM_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Unlock()
**********************************************************************************************************************/
/*!
 * \brief      Sets lock level of Eeprom to LockLevel.
 * \details    Sets lock level of Eeprom by adjusting block protection bits in status register according to LockLevel.
 * \param[in]  LockLevel
 * \return     E_OK: Job request was accepted
 *             E_NOT_OK: Job request was declined
 * \pre        -
 * \config     Unlock Eeprom API is enabled via configuration. Second EEP instance configured.
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 */
FUNC(Std_ReturnType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Unlock(Eep_30_XXspi01_LockLevelType LockLevel);
#  endif

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_GetStatus()
**********************************************************************************************************************/
/*!
 * \brief      Returns current overall module status
 * \details    Returns current overall module status
 * \return     Status of module
 * \pre        -
 * \config     Second EEP instance configured
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 */
FUNC(MemIf_StatusType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_GetStatus(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_GetJobResult()
**********************************************************************************************************************/
/*!
 * \brief      Returns current overall module job result
 * \details    Returns current overall module job result
 * \return     Recent job result of module
 * \pre        -
 * \config     Second EEP instance configured
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 */
FUNC(MemIf_JobResultType, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_GetJobResult(void);

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_Cancel()
**********************************************************************************************************************/
/*!
 * \brief      Cancels ongoing asynchronous job
 * \details    Cancels ongoing asynchronous job
 * \pre        -
 * \config     Second EEP instance configured
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_Cancel(void);

#  if (EEP_30_XXSPI01_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_GetVersionInfo()
**********************************************************************************************************************/
/*!
 * \brief      Service to get the version information of Eep module.
 * \details    Stores version information, i.e. Module Id, Vendor Id, Vendor specific version numbers,
 *             to structure pointed by versioninfo.
 * \param[in]  versioninfo
 * \pre        -
 * \config     Version Info API is enabled via configuration. Second EEP instance configured.
 * \context    TASK
 * \reentrant  TRUE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_GetVersionInfo(Eep_30_XXspi01_VersionInfoPtrType versioninfo);
#  endif

/**********************************************************************************************************************
  Eep_30_XXspi01_Inst2_MainFunction()
**********************************************************************************************************************/
/*!
 * \brief      Service to handle the requested jobs and the internal management operations.
 * \details    Service to handle the requested jobs and the internal management operations.
 * \pre        -
 * \config     Second EEP instance configured
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
FUNC(void, EEP_30_XXSPI01_CODE) Eep_30_XXspi01_Inst2_MainFunction(void);

# endif

# define EEP_30_XXSPI01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* EEP_30_XXSPI01_H */


/*!
 * \exclusivearea EEP_30_XXSPI01_EXCLUSIVE_AREA_0
 * Ensures consistency while job is setup including high level and low level implementation.
 * \protects Internal job parameters of DrvEep
 * \usedin Eep_30_XXspi01_Read, Eep_30_XXspi01_Write, Eep_30_XXspi01_Erase, Eep_30_XXspi01_Compare, Eep_30_XXspi01_Inst2_Read, Eep_30_XXspi01_Inst2_Write, Eep_30_XXspi01_Inst2_Erase, Eep_30_XXspi01_Inst2_Compare
 * \exclude Eep_30_XXspi01_MainFunction
 * \length SHORT Job parameters are initialized.
 * \endexclusivearea
 */

/**********************************************************************************************************************
 *  END OF FILE: Eep_30_XXspi01.h
 *********************************************************************************************************************/
