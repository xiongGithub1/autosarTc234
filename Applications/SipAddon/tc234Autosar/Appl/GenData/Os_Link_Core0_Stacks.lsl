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
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Shanghai Huizhong Automotive Manufacturing Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC234LP
 *    License Scope : The usage is restricted to CBD1700982_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Link_Core0_Stacks.lsl
 *   Generation Time: 2026-06-15 14:55:31
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
 *  STACK SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_KERNEL_STACKS )
group OS_CORE0_STACKS_GROUP(ordered, contiguous, fill)
{

/* Stack: Default_Appl_Task (1024 Byte) */
group OS_STACK_DEFAULT_APPL_TASK_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_DEFAULT_APPL_TASK_VAR_NOINIT";
  reserved ".pad.OS_STACK_DEFAULT_APPL_TASK_VAR_NOINIT" (size=16);
}
"_OS_STACK_DEFAULT_APPL_TASK_VAR_NOINIT_START" = "_lc_gb_OS_STACK_DEFAULT_APPL_TASK_VAR_NOINIT_GROUP";
"_OS_STACK_DEFAULT_APPL_TASK_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_DEFAULT_APPL_TASK_VAR_NOINIT";

/* Stack: Default_BSW_Async_Task (2048 Byte) */
group OS_STACK_DEFAULT_BSW_ASYNC_TASK_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_DEFAULT_BSW_ASYNC_TASK_VAR_NOINIT";
  reserved ".pad.OS_STACK_DEFAULT_BSW_ASYNC_TASK_VAR_NOINIT" (size=16);
}
"_OS_STACK_DEFAULT_BSW_ASYNC_TASK_VAR_NOINIT_START" = "_lc_gb_OS_STACK_DEFAULT_BSW_ASYNC_TASK_VAR_NOINIT_GROUP";
"_OS_STACK_DEFAULT_BSW_ASYNC_TASK_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_DEFAULT_BSW_ASYNC_TASK_VAR_NOINIT";

/* Stack: OsCore_Core0_Error (1024 Byte) */
group OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT";

/* Stack: OsCore_Core0_Init (1024 Byte) */
group OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT";

/* Stack: OsCore_Core0_Isr_Core (1024 Byte) */
group OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT";

/* Stack: OsCore_Core0_Kernel (1024 Byte) */
group OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT";

/* Stack: OsCore_Core0_Task_Prio0 (1024 Byte) */
group OS_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT";

/* Stack: OsCore_Core0_Task_Prio1 (1024 Byte) */
group OS_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT";

/* Stack: OsCore_Core0_Task_Prio2 (1024 Byte) */
group OS_STACK_OSCORE_CORE0_TASK_PRIO2_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE_CORE0_TASK_PRIO2_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE_CORE0_TASK_PRIO2_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE_CORE0_TASK_PRIO2_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE_CORE0_TASK_PRIO2_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE_CORE0_TASK_PRIO2_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE_CORE0_TASK_PRIO2_VAR_NOINIT";

/* Stack: OsCore_Core0_Task_Prio4 (1024 Byte) */
group OS_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT";

/* Stack: OsCore_Core0_Task_Prio6 (1024 Byte) */
group OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT";

/* Stack: OsCore_Core0_Task_Prio7 (1024 Byte) */
group OS_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT";

} /* OS_CORE0_STACKS_GROUP */
"_OS_CORE0_STACKS_START" = "_lc_gb_OS_CORE0_STACKS_GROUP";
"_OS_CORE0_STACKS_END" = "_lc_ge_OS_CORE0_STACKS_GROUP";
"_OS_CORE0_STACKS_END_ALIAS" = (("_lc_ge_OS_CORE0_STACKS_GROUP")&~0xF0000000)|0xD0000000;

#endif

#ifdef OS_LINK_KERNEL_STACKS
# undef OS_LINK_KERNEL_STACKS
#endif


