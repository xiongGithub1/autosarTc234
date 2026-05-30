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
 *          File:  SchM_Fls_17_Pmu.h
 *        Config:  TsiStandard.dpa
 *   ECU-Project:  MyECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700982 for Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *
 *   Description:  Header of BSW Scheduler for BSW Module <Fls_17_Pmu>
 *********************************************************************************************************************/
#ifndef SCHM_FLS_17_PMU_H
# define SCHM_FLS_17_PMU_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Fls_17_Pmu_Type.h"

# define FLS_17_PMU_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, FLS_17_PMU_CODE) Fls_17_Pmu_MainFunction(void); /* PRQA S 3451 */ /* MD_Rte_3451 */

# define FLS_17_PMU_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Pmu_Erase(void);
FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Pmu_Erase(void);
FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Pmu_Init(void);
FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Pmu_Init(void);
FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Pmu_Main(void);
FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Pmu_Main(void);
FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Pmu_ResumeErase(void);
FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Pmu_ResumeErase(void);
FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Pmu_Write(void);
FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Pmu_Write(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_FLS_17_PMU_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
