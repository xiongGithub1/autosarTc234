/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_StartApplication_Type.h
 *        Config:  TsiStandard.dpa
 *   ECU-Project:  MyECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700982 for Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *
 *   Description:  Application types header file for SW-C <StartApplication>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_STARTAPPLICATION_TYPE_H
# define _RTE_STARTAPPLICATION_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef COMM_NO_COMMUNICATION
#   define COMM_NO_COMMUNICATION (0U)
#  endif

#  ifndef COMM_SILENT_COMMUNICATION
#   define COMM_SILENT_COMMUNICATION (1U)
#  endif

#  ifndef COMM_FULL_COMMUNICATION
#   define COMM_FULL_COMMUNICATION (2U)
#  endif

#  ifndef ECUM_SUBSTATE_MASK
#   define ECUM_SUBSTATE_MASK (15U)
#  endif

#  ifndef ECUM_STATE_STARTUP
#   define ECUM_STATE_STARTUP (16U)
#  endif

#  ifndef ECUM_STATE_STARTUP_ONE
#   define ECUM_STATE_STARTUP_ONE (17U)
#  endif

#  ifndef ECUM_STATE_STARTUP_TWO
#   define ECUM_STATE_STARTUP_TWO (18U)
#  endif

#  ifndef ECUM_STATE_WAKEUP
#   define ECUM_STATE_WAKEUP (32U)
#  endif

#  ifndef ECUM_STATE_WAKEUP_ONE
#   define ECUM_STATE_WAKEUP_ONE (33U)
#  endif

#  ifndef ECUM_STATE_WAKEUP_VALIDATION
#   define ECUM_STATE_WAKEUP_VALIDATION (34U)
#  endif

#  ifndef ECUM_STATE_WAKEUP_REACTION
#   define ECUM_STATE_WAKEUP_REACTION (35U)
#  endif

#  ifndef ECUM_STATE_WAKEUP_TWO
#   define ECUM_STATE_WAKEUP_TWO (36U)
#  endif

#  ifndef ECUM_STATE_WAKEUP_WAKESLEEP
#   define ECUM_STATE_WAKEUP_WAKESLEEP (37U)
#  endif

#  ifndef ECUM_STATE_WAKEUP_TTII
#   define ECUM_STATE_WAKEUP_TTII (38U)
#  endif

#  ifndef ECUM_STATE_RUN
#   define ECUM_STATE_RUN (48U)
#  endif

#  ifndef ECUM_STATE_APP_RUN
#   define ECUM_STATE_APP_RUN (50U)
#  endif

#  ifndef ECUM_STATE_APP_POST_RUN
#   define ECUM_STATE_APP_POST_RUN (51U)
#  endif

#  ifndef ECUM_STATE_SHUTDOWN
#   define ECUM_STATE_SHUTDOWN (64U)
#  endif

#  ifndef ECUM_STATE_PREP_SHUTDOWN
#   define ECUM_STATE_PREP_SHUTDOWN (68U)
#  endif

#  ifndef ECUM_STATE_GO_SLEEP
#   define ECUM_STATE_GO_SLEEP (73U)
#  endif

#  ifndef ECUM_STATE_GO_OFF_ONE
#   define ECUM_STATE_GO_OFF_ONE (77U)
#  endif

#  ifndef ECUM_STATE_GO_OFF_TWO
#   define ECUM_STATE_GO_OFF_TWO (78U)
#  endif

#  ifndef ECUM_STATE_SLEEP
#   define ECUM_STATE_SLEEP (80U)
#  endif

#  ifndef ECUM_STATE_OFF
#   define ECUM_STATE_OFF (128U)
#  endif

#  ifndef ECUM_STATE_RESET
#   define ECUM_STATE_RESET (144U)
#  endif

#  ifndef STARTAPPLICATION_ACTIVE_COMPONENT_COM_RXTX
#   define STARTAPPLICATION_ACTIVE_COMPONENT_COM_RXTX (0U)
#  endif

#  ifndef STARTAPPLICATION_ACTIVE_COMPONENT_MEM
#   define STARTAPPLICATION_ACTIVE_COMPONENT_MEM (1U)
#  endif

#  ifndef STARTAPPLICATION_ACTIVE_COMPONENT_DIAG
#   define STARTAPPLICATION_ACTIVE_COMPONENT_DIAG (2U)
#  endif

#  ifndef STARTAPPLICATION_ACTIVE_COMPONENT_COM_TXONLY
#   define STARTAPPLICATION_ACTIVE_COMPONENT_COM_TXONLY (3U)
#  endif

#  ifndef STARTAPPLICATION_ACTIVE_COMPONENT_XCP
#   define STARTAPPLICATION_ACTIVE_COMPONENT_XCP (5U)
#  endif

#  ifndef STARTAPPLICATION_ACTIVE_COMPONENT_NM
#   define STARTAPPLICATION_ACTIVE_COMPONENT_NM (10U)
#  endif

#  ifndef STARTAPPLICATION_ACTIVE_COMPONENT_INVALID
#   define STARTAPPLICATION_ACTIVE_COMPONENT_INVALID (255U)
#  endif

#  ifndef MEM_STATE_UNKNOWN
#   define MEM_STATE_UNKNOWN (0U)
#  endif

#  ifndef MEM_STATE_WRITE_PENDING
#   define MEM_STATE_WRITE_PENDING (1U)
#  endif

#  ifndef MEM_STATE_WRITE_FINISHED
#   define MEM_STATE_WRITE_FINISHED (2U)
#  endif

#  ifndef MEM_STATE_READ_PENDING
#   define MEM_STATE_READ_PENDING (3U)
#  endif

#  ifndef MEM_STATE_READ_FINISHED
#   define MEM_STATE_READ_FINISHED (4U)
#  endif

#  ifndef MEM_STATE_WRITE_FAILED
#   define MEM_STATE_WRITE_FAILED (5U)
#  endif

#  ifndef MEM_STATE_READ_FAILED
#   define MEM_STATE_READ_FAILED (6U)
#  endif

#  ifndef NM_APPL_STATE_FULL_COMM_EXTERN
#   define NM_APPL_STATE_FULL_COMM_EXTERN (0U)
#  endif

#  ifndef NM_APPL_STATE_FULL_COMM_INTERN
#   define NM_APPL_STATE_FULL_COMM_INTERN (1U)
#  endif

#  ifndef NM_APPL_STATE_NO_COMM_EXTERN
#   define NM_APPL_STATE_NO_COMM_EXTERN (2U)
#  endif

#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif

#  ifndef NVM_READ_BLOCK
#   define NVM_READ_BLOCK (6U)
#  endif

#  ifndef NVM_WRITE_BLOCK
#   define NVM_WRITE_BLOCK (7U)
#  endif

#  ifndef NVM_RESTORE_BLOCK_DEFAULTS
#   define NVM_RESTORE_BLOCK_DEFAULTS (8U)
#  endif

#  ifndef NVM_ERASE_BLOCK
#   define NVM_ERASE_BLOCK (9U)
#  endif

#  ifndef NVM_INVALIDATE_NV_BLOCK
#   define NVM_INVALIDATE_NV_BLOCK (11U)
#  endif

#  ifndef NVM_READ_ALL
#   define NVM_READ_ALL (12U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_STARTAPPLICATION_TYPE_H */
