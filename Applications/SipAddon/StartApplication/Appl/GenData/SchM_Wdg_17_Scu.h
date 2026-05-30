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
 *          File:  SchM_Wdg_17_Scu.h
 *        Config:  TsiStandard.dpa
 *   ECU-Project:  MyECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700982 for Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *
 *   Description:  Header of BSW Scheduler for BSW Module <Wdg_17_Scu>
 *********************************************************************************************************************/
#ifndef SCHM_WDG_17_SCU_H
# define SCHM_WDG_17_SCU_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Wdg_17_Scu_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_Wdg_17_Scu_ChangeMode(void);
FUNC(void, RTE_CODE) SchM_Exit_Wdg_17_Scu_ChangeMode(void);
FUNC(void, RTE_CODE) SchM_Enter_Wdg_17_Scu_SafetyInit(void);
FUNC(void, RTE_CODE) SchM_Exit_Wdg_17_Scu_SafetyInit(void);
FUNC(void, RTE_CODE) SchM_Enter_Wdg_17_Scu_SafetyOffMode(void);
FUNC(void, RTE_CODE) SchM_Exit_Wdg_17_Scu_SafetyOffMode(void);
FUNC(void, RTE_CODE) SchM_Enter_Wdg_17_Scu_SafetyTrigger(void);
FUNC(void, RTE_CODE) SchM_Exit_Wdg_17_Scu_SafetyTrigger(void);
FUNC(void, RTE_CODE) SchM_Enter_Wdg_17_Scu_TimerHandling(void);
FUNC(void, RTE_CODE) SchM_Exit_Wdg_17_Scu_TimerHandling(void);
FUNC(void, RTE_CODE) SchM_Enter_Wdg_17_Scu_Trigger(void);
FUNC(void, RTE_CODE) SchM_Exit_Wdg_17_Scu_Trigger(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_WDG_17_SCU_H */
