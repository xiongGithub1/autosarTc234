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
 *              File: Os_Link_Core0.lsl
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
 *  CODE SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_INTVEC_CODE )
if (exists(".text.OS_INTVEC_CORE0_CODE"))
{
  group OS_INTVEC_CORE0_CODE_GROUP(align=32)
  {
    select ".text.OS_INTVEC_CORE0_CODE";
  }
  "_OS_INTVEC_CORE0_CODE_START" = "_lc_gb_OS_INTVEC_CORE0_CODE_GROUP";
  "_OS_INTVEC_CORE0_CODE_END" = "_lc_ge_OS_INTVEC_CORE0_CODE_GROUP";
}
else
{
  "_OS_INTVEC_CORE0_CODE_START" = 0;
  "_OS_INTVEC_CORE0_CODE_END" = 0;
}
#endif

#if defined ( OS_LINK_EXCVEC_CODE )
if (exists(".text.OS_EXCVEC_CORE0_CODE"))
{
  group OS_EXCVEC_CORE0_CODE_GROUP(align=32)
  {
    select ".text.OS_EXCVEC_CORE0_CODE";
  }
  "_OS_EXCVEC_CORE0_CODE_START" = "_lc_gb_OS_EXCVEC_CORE0_CODE_GROUP";
  "_OS_EXCVEC_CORE0_CODE_END" = "_lc_ge_OS_EXCVEC_CORE0_CODE_GROUP";
}
else
{
  "_OS_EXCVEC_CORE0_CODE_START" = 0;
  "_OS_EXCVEC_CORE0_CODE_END" = 0;
}
#endif

#if defined ( OS_LINK_CALLOUT_CODE )
if (exists(".text.OS_CanIsr_0_CODE"))
{
  group OS_CanIsr_0_CODE_GROUP(align=8)
  {
    select ".text.OS_CanIsr_0_CODE";
  }
  "_OS_CanIsr_0_CODE_START" = "_lc_gb_OS_CanIsr_0_CODE_GROUP";
  "_OS_CanIsr_0_CODE_END" = "_lc_ge_OS_CanIsr_0_CODE_GROUP";
}
else
{
  "_OS_CanIsr_0_CODE_START" = 0;
  "_OS_CanIsr_0_CODE_END" = 0;
}
if (exists(".text.OS_Default_Appl_Init_Task_CODE"))
{
  group OS_Default_Appl_Init_Task_CODE_GROUP(align=8)
  {
    select ".text.OS_Default_Appl_Init_Task_CODE";
  }
  "_OS_Default_Appl_Init_Task_CODE_START" = "_lc_gb_OS_Default_Appl_Init_Task_CODE_GROUP";
  "_OS_Default_Appl_Init_Task_CODE_END" = "_lc_ge_OS_Default_Appl_Init_Task_CODE_GROUP";
}
else
{
  "_OS_Default_Appl_Init_Task_CODE_START" = 0;
  "_OS_Default_Appl_Init_Task_CODE_END" = 0;
}
if (exists(".text.OS_Default_Appl_Task_CODE"))
{
  group OS_Default_Appl_Task_CODE_GROUP(align=8)
  {
    select ".text.OS_Default_Appl_Task_CODE";
  }
  "_OS_Default_Appl_Task_CODE_START" = "_lc_gb_OS_Default_Appl_Task_CODE_GROUP";
  "_OS_Default_Appl_Task_CODE_END" = "_lc_ge_OS_Default_Appl_Task_CODE_GROUP";
}
else
{
  "_OS_Default_Appl_Task_CODE_START" = 0;
  "_OS_Default_Appl_Task_CODE_END" = 0;
}
if (exists(".text.OS_Default_BSW_Async_Task_CODE"))
{
  group OS_Default_BSW_Async_Task_CODE_GROUP(align=8)
  {
    select ".text.OS_Default_BSW_Async_Task_CODE";
  }
  "_OS_Default_BSW_Async_Task_CODE_START" = "_lc_gb_OS_Default_BSW_Async_Task_CODE_GROUP";
  "_OS_Default_BSW_Async_Task_CODE_END" = "_lc_ge_OS_Default_BSW_Async_Task_CODE_GROUP";
}
else
{
  "_OS_Default_BSW_Async_Task_CODE_START" = 0;
  "_OS_Default_BSW_Async_Task_CODE_END" = 0;
}
if (exists(".text.OS_Default_BSW_Sync_Task_CODE"))
{
  group OS_Default_BSW_Sync_Task_CODE_GROUP(align=8)
  {
    select ".text.OS_Default_BSW_Sync_Task_CODE";
  }
  "_OS_Default_BSW_Sync_Task_CODE_START" = "_lc_gb_OS_Default_BSW_Sync_Task_CODE_GROUP";
  "_OS_Default_BSW_Sync_Task_CODE_END" = "_lc_ge_OS_Default_BSW_Sync_Task_CODE_GROUP";
}
else
{
  "_OS_Default_BSW_Sync_Task_CODE_START" = 0;
  "_OS_Default_BSW_Sync_Task_CODE_END" = 0;
}
if (exists(".text.OS_Default_Background_Task_CODE"))
{
  group OS_Default_Background_Task_CODE_GROUP(align=8)
  {
    select ".text.OS_Default_Background_Task_CODE";
  }
  "_OS_Default_Background_Task_CODE_START" = "_lc_gb_OS_Default_Background_Task_CODE_GROUP";
  "_OS_Default_Background_Task_CODE_END" = "_lc_ge_OS_Default_Background_Task_CODE_GROUP";
}
else
{
  "_OS_Default_Background_Task_CODE_START" = 0;
  "_OS_Default_Background_Task_CODE_END" = 0;
}
if (exists(".text.OS_Default_Init_Task_CODE"))
{
  group OS_Default_Init_Task_CODE_GROUP(align=8)
  {
    select ".text.OS_Default_Init_Task_CODE";
  }
  "_OS_Default_Init_Task_CODE_START" = "_lc_gb_OS_Default_Init_Task_CODE_GROUP";
  "_OS_Default_Init_Task_CODE_END" = "_lc_ge_OS_Default_Init_Task_CODE_GROUP";
}
else
{
  "_OS_Default_Init_Task_CODE_START" = 0;
  "_OS_Default_Init_Task_CODE_END" = 0;
}
if (exists(".text.OS_Default_RTE_Mode_switch_Task_CODE"))
{
  group OS_Default_RTE_Mode_switch_Task_CODE_GROUP(align=8)
  {
    select ".text.OS_Default_RTE_Mode_switch_Task_CODE";
  }
  "_OS_Default_RTE_Mode_switch_Task_CODE_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_CODE_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_CODE_END" = "_lc_ge_OS_Default_RTE_Mode_switch_Task_CODE_GROUP";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_CODE_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_CODE_END" = 0;
}
#endif

#ifdef OS_LINK_INTVEC_CODE
# undef OS_LINK_INTVEC_CODE
#endif

#ifdef OS_LINK_EXCVEC_CODE
# undef OS_LINK_EXCVEC_CODE
#endif

#ifdef OS_LINK_CALLOUT_CODE
# undef OS_LINK_CALLOUT_CODE
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_FAR )
if (exists(".rodata.OS_CORE0_CONST"))
{
  group OS_CORE0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_CORE0_CONST";
  }
  "_OS_CORE0_CONST_START" = "_lc_gb_OS_CORE0_CONST_GROUP";
  "_OS_CORE0_CONST_END" = "_lc_ge_OS_CORE0_CONST_GROUP";
}
else
{
  "_OS_CORE0_CONST_START" = 0;
  "_OS_CORE0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_NEAR )
if (exists(".zrodata.OS_CORE0_CONST_FAST"))
{
  group OS_CORE0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_CORE0_CONST_FAST";
  }
  "_OS_CORE0_CONST_FAST_START" = "_lc_gb_OS_CORE0_CONST_FAST_GROUP";
  "_OS_CORE0_CONST_FAST_END" = "_lc_ge_OS_CORE0_CONST_FAST_GROUP";
}
else
{
  "_OS_CORE0_CONST_FAST_START" = 0;
  "_OS_CORE0_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_INTVEC_CONST )
if (exists(".rodata.OS_INTVEC_CORE0_CONST"))
{
  group OS_INTVEC_CORE0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_INTVEC_CORE0_CONST";
  }
  "_OS_INTVEC_CORE0_CONST_START" = "_lc_gb_OS_INTVEC_CORE0_CONST_GROUP";
  "_OS_INTVEC_CORE0_CONST_END" = "_lc_ge_OS_INTVEC_CORE0_CONST_GROUP";
}
else
{
  "_OS_INTVEC_CORE0_CONST_START" = 0;
  "_OS_INTVEC_CORE0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_EXCVEC_CONST )
if (exists(".rodata.OS_EXCVEC_CORE0_CONST"))
{
  group OS_EXCVEC_CORE0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_EXCVEC_CORE0_CONST";
  }
  "_OS_EXCVEC_CORE0_CONST_START" = "_lc_gb_OS_EXCVEC_CORE0_CONST_GROUP";
  "_OS_EXCVEC_CORE0_CONST_END" = "_lc_ge_OS_EXCVEC_CORE0_CONST_GROUP";
}
else
{
  "_OS_EXCVEC_CORE0_CONST_START" = 0;
  "_OS_EXCVEC_CORE0_CONST_END" = 0;
}
#endif


#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR )
if (exists(".rodata.OS_SystemApplication_OsCore_Core0_CONST"))
{
  group OS_SystemApplication_OsCore_Core0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_SystemApplication_OsCore_Core0_CONST";
  }
  "_OS_SystemApplication_OsCore_Core0_CONST_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_CONST_GROUP";
  "_OS_SystemApplication_OsCore_Core0_CONST_END" = "_lc_ge_OS_SystemApplication_OsCore_Core0_CONST_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_CONST_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR )
if (exists(".zrodata.OS_SystemApplication_OsCore_Core0_CONST_FAST"))
{
  group OS_SystemApplication_OsCore_Core0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_SystemApplication_OsCore_Core0_CONST_FAST";
  }
  "_OS_SystemApplication_OsCore_Core0_CONST_FAST_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_CONST_FAST_GROUP";
  "_OS_SystemApplication_OsCore_Core0_CONST_FAST_END" = "_lc_ge_OS_SystemApplication_OsCore_Core0_CONST_FAST_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_CONST_FAST_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0_INIT )
















#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0_INIT
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK_FAR )
if (exists(".rodata.OS_Default_Appl_Init_Task_CONST"))
{
  group OS_Default_Appl_Init_Task_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_Default_Appl_Init_Task_CONST";
  }
  "_OS_Default_Appl_Init_Task_CONST_START" = "_lc_gb_OS_Default_Appl_Init_Task_CONST_GROUP";
  "_OS_Default_Appl_Init_Task_CONST_END" = "_lc_ge_OS_Default_Appl_Init_Task_CONST_GROUP";
}
else
{
  "_OS_Default_Appl_Init_Task_CONST_START" = 0;
  "_OS_Default_Appl_Init_Task_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK_NEAR )
if (exists(".zrodata.OS_Default_Appl_Init_Task_CONST_FAST"))
{
  group OS_Default_Appl_Init_Task_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_Default_Appl_Init_Task_CONST_FAST";
  }
  "_OS_Default_Appl_Init_Task_CONST_FAST_START" = "_lc_gb_OS_Default_Appl_Init_Task_CONST_FAST_GROUP";
  "_OS_Default_Appl_Init_Task_CONST_FAST_END" = "_lc_ge_OS_Default_Appl_Init_Task_CONST_FAST_GROUP";
}
else
{
  "_OS_Default_Appl_Init_Task_CONST_FAST_START" = 0;
  "_OS_Default_Appl_Init_Task_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK
# undef OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_APPL_INIT_TASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_APPL_TASK_FAR )
if (exists(".rodata.OS_Default_Appl_Task_CONST"))
{
  group OS_Default_Appl_Task_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_Default_Appl_Task_CONST";
  }
  "_OS_Default_Appl_Task_CONST_START" = "_lc_gb_OS_Default_Appl_Task_CONST_GROUP";
  "_OS_Default_Appl_Task_CONST_END" = "_lc_ge_OS_Default_Appl_Task_CONST_GROUP";
}
else
{
  "_OS_Default_Appl_Task_CONST_START" = 0;
  "_OS_Default_Appl_Task_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_APPL_TASK_NEAR )
if (exists(".zrodata.OS_Default_Appl_Task_CONST_FAST"))
{
  group OS_Default_Appl_Task_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_Default_Appl_Task_CONST_FAST";
  }
  "_OS_Default_Appl_Task_CONST_FAST_START" = "_lc_gb_OS_Default_Appl_Task_CONST_FAST_GROUP";
  "_OS_Default_Appl_Task_CONST_FAST_END" = "_lc_ge_OS_Default_Appl_Task_CONST_FAST_GROUP";
}
else
{
  "_OS_Default_Appl_Task_CONST_FAST_START" = 0;
  "_OS_Default_Appl_Task_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_APPL_TASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_APPL_TASK
# undef OS_LINK_CONST_TASK_DEFAULT_APPL_TASK
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_APPL_TASK_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_APPL_TASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_APPL_TASK_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_APPL_TASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_APPL_TASK_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_APPL_TASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_FAR )
if (exists(".rodata.OS_Default_BSW_Async_Task_CONST"))
{
  group OS_Default_BSW_Async_Task_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_Default_BSW_Async_Task_CONST";
  }
  "_OS_Default_BSW_Async_Task_CONST_START" = "_lc_gb_OS_Default_BSW_Async_Task_CONST_GROUP";
  "_OS_Default_BSW_Async_Task_CONST_END" = "_lc_ge_OS_Default_BSW_Async_Task_CONST_GROUP";
}
else
{
  "_OS_Default_BSW_Async_Task_CONST_START" = 0;
  "_OS_Default_BSW_Async_Task_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR )
if (exists(".zrodata.OS_Default_BSW_Async_Task_CONST_FAST"))
{
  group OS_Default_BSW_Async_Task_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_Default_BSW_Async_Task_CONST_FAST";
  }
  "_OS_Default_BSW_Async_Task_CONST_FAST_START" = "_lc_gb_OS_Default_BSW_Async_Task_CONST_FAST_GROUP";
  "_OS_Default_BSW_Async_Task_CONST_FAST_END" = "_lc_ge_OS_Default_BSW_Async_Task_CONST_FAST_GROUP";
}
else
{
  "_OS_Default_BSW_Async_Task_CONST_FAST_START" = 0;
  "_OS_Default_BSW_Async_Task_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK
# undef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK_FAR )
if (exists(".rodata.OS_Default_BSW_Sync_Task_CONST"))
{
  group OS_Default_BSW_Sync_Task_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_Default_BSW_Sync_Task_CONST";
  }
  "_OS_Default_BSW_Sync_Task_CONST_START" = "_lc_gb_OS_Default_BSW_Sync_Task_CONST_GROUP";
  "_OS_Default_BSW_Sync_Task_CONST_END" = "_lc_ge_OS_Default_BSW_Sync_Task_CONST_GROUP";
}
else
{
  "_OS_Default_BSW_Sync_Task_CONST_START" = 0;
  "_OS_Default_BSW_Sync_Task_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK_NEAR )
if (exists(".zrodata.OS_Default_BSW_Sync_Task_CONST_FAST"))
{
  group OS_Default_BSW_Sync_Task_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_Default_BSW_Sync_Task_CONST_FAST";
  }
  "_OS_Default_BSW_Sync_Task_CONST_FAST_START" = "_lc_gb_OS_Default_BSW_Sync_Task_CONST_FAST_GROUP";
  "_OS_Default_BSW_Sync_Task_CONST_FAST_END" = "_lc_ge_OS_Default_BSW_Sync_Task_CONST_FAST_GROUP";
}
else
{
  "_OS_Default_BSW_Sync_Task_CONST_FAST_START" = 0;
  "_OS_Default_BSW_Sync_Task_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK
# undef OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_BSW_SYNC_TASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK_FAR )
if (exists(".rodata.OS_Default_Background_Task_CONST"))
{
  group OS_Default_Background_Task_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_Default_Background_Task_CONST";
  }
  "_OS_Default_Background_Task_CONST_START" = "_lc_gb_OS_Default_Background_Task_CONST_GROUP";
  "_OS_Default_Background_Task_CONST_END" = "_lc_ge_OS_Default_Background_Task_CONST_GROUP";
}
else
{
  "_OS_Default_Background_Task_CONST_START" = 0;
  "_OS_Default_Background_Task_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK_NEAR )
if (exists(".zrodata.OS_Default_Background_Task_CONST_FAST"))
{
  group OS_Default_Background_Task_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_Default_Background_Task_CONST_FAST";
  }
  "_OS_Default_Background_Task_CONST_FAST_START" = "_lc_gb_OS_Default_Background_Task_CONST_FAST_GROUP";
  "_OS_Default_Background_Task_CONST_FAST_END" = "_lc_ge_OS_Default_Background_Task_CONST_FAST_GROUP";
}
else
{
  "_OS_Default_Background_Task_CONST_FAST_START" = 0;
  "_OS_Default_Background_Task_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK
# undef OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_BACKGROUND_TASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR )
if (exists(".rodata.OS_Default_Init_Task_CONST"))
{
  group OS_Default_Init_Task_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_Default_Init_Task_CONST";
  }
  "_OS_Default_Init_Task_CONST_START" = "_lc_gb_OS_Default_Init_Task_CONST_GROUP";
  "_OS_Default_Init_Task_CONST_END" = "_lc_ge_OS_Default_Init_Task_CONST_GROUP";
}
else
{
  "_OS_Default_Init_Task_CONST_START" = 0;
  "_OS_Default_Init_Task_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_NEAR )
if (exists(".zrodata.OS_Default_Init_Task_CONST_FAST"))
{
  group OS_Default_Init_Task_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_Default_Init_Task_CONST_FAST";
  }
  "_OS_Default_Init_Task_CONST_FAST_START" = "_lc_gb_OS_Default_Init_Task_CONST_FAST_GROUP";
  "_OS_Default_Init_Task_CONST_FAST_END" = "_lc_ge_OS_Default_Init_Task_CONST_FAST_GROUP";
}
else
{
  "_OS_Default_Init_Task_CONST_FAST_START" = 0;
  "_OS_Default_Init_Task_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR )
if (exists(".rodata.OS_Default_RTE_Mode_switch_Task_CONST"))
{
  group OS_Default_RTE_Mode_switch_Task_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_Default_RTE_Mode_switch_Task_CONST";
  }
  "_OS_Default_RTE_Mode_switch_Task_CONST_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_CONST_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_CONST_END" = "_lc_ge_OS_Default_RTE_Mode_switch_Task_CONST_GROUP";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_CONST_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR )
if (exists(".zrodata.OS_Default_RTE_Mode_switch_Task_CONST_FAST"))
{
  group OS_Default_RTE_Mode_switch_Task_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_Default_RTE_Mode_switch_Task_CONST_FAST";
  }
  "_OS_Default_RTE_Mode_switch_Task_CONST_FAST_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_CONST_FAST_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_CONST_FAST_END" = "_lc_ge_OS_Default_RTE_Mode_switch_Task_CONST_FAST_GROUP";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_CONST_FAST_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK
# undef OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0_FAR )
if (exists(".rodata.OS_IdleTask_OsCore_Core0_CONST"))
{
  group OS_IdleTask_OsCore_Core0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_IdleTask_OsCore_Core0_CONST";
  }
  "_OS_IdleTask_OsCore_Core0_CONST_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_CONST_GROUP";
  "_OS_IdleTask_OsCore_Core0_CONST_END" = "_lc_ge_OS_IdleTask_OsCore_Core0_CONST_GROUP";
}
else
{
  "_OS_IdleTask_OsCore_Core0_CONST_START" = 0;
  "_OS_IdleTask_OsCore_Core0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0_NEAR )
if (exists(".zrodata.OS_IdleTask_OsCore_Core0_CONST_FAST"))
{
  group OS_IdleTask_OsCore_Core0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_IdleTask_OsCore_Core0_CONST_FAST";
  }
  "_OS_IdleTask_OsCore_Core0_CONST_FAST_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_CONST_FAST_GROUP";
  "_OS_IdleTask_OsCore_Core0_CONST_FAST_END" = "_lc_ge_OS_IdleTask_OsCore_Core0_CONST_FAST_GROUP";
}
else
{
  "_OS_IdleTask_OsCore_Core0_CONST_FAST_START" = 0;
  "_OS_IdleTask_OsCore_Core0_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0_FAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0_FAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0_NEAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0_INIT
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISR_0 ) || defined ( OS_LINK_CONST_ISR_CANISR_0_FAR )
if (exists(".rodata.OS_CanIsr_0_CONST"))
{
  group OS_CanIsr_0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_CanIsr_0_CONST";
  }
  "_OS_CanIsr_0_CONST_START" = "_lc_gb_OS_CanIsr_0_CONST_GROUP";
  "_OS_CanIsr_0_CONST_END" = "_lc_ge_OS_CanIsr_0_CONST_GROUP";
}
else
{
  "_OS_CanIsr_0_CONST_START" = 0;
  "_OS_CanIsr_0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISR_0 ) || defined ( OS_LINK_CONST_ISR_CANISR_0_NEAR )
if (exists(".zrodata.OS_CanIsr_0_CONST_FAST"))
{
  group OS_CanIsr_0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_CanIsr_0_CONST_FAST";
  }
  "_OS_CanIsr_0_CONST_FAST_START" = "_lc_gb_OS_CanIsr_0_CONST_FAST_GROUP";
  "_OS_CanIsr_0_CONST_FAST_END" = "_lc_ge_OS_CanIsr_0_CONST_FAST_GROUP";
}
else
{
  "_OS_CanIsr_0_CONST_FAST_START" = 0;
  "_OS_CanIsr_0_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISR_0 ) || defined ( OS_LINK_CONST_ISR_CANISR_0_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_CANISR_0
# undef OS_LINK_CONST_ISR_CANISR_0
#endif

#ifdef OS_LINK_CONST_ISR_CANISR_0_FAR
# undef OS_LINK_CONST_ISR_CANISR_0_FAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISR_0_NEAR
# undef OS_LINK_CONST_ISR_CANISR_0_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISR_0_INIT
# undef OS_LINK_CONST_ISR_CANISR_0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR )
if (exists(".rodata.OS_CounterIsr_SystemTimer_CONST"))
{
  group OS_CounterIsr_SystemTimer_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_CounterIsr_SystemTimer_CONST";
  }
  "_OS_CounterIsr_SystemTimer_CONST_START" = "_lc_gb_OS_CounterIsr_SystemTimer_CONST_GROUP";
  "_OS_CounterIsr_SystemTimer_CONST_END" = "_lc_ge_OS_CounterIsr_SystemTimer_CONST_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_CONST_START" = 0;
  "_OS_CounterIsr_SystemTimer_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_NEAR )
if (exists(".zrodata.OS_CounterIsr_SystemTimer_CONST_FAST"))
{
  group OS_CounterIsr_SystemTimer_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_CounterIsr_SystemTimer_CONST_FAST";
  }
  "_OS_CounterIsr_SystemTimer_CONST_FAST_START" = "_lc_gb_OS_CounterIsr_SystemTimer_CONST_FAST_GROUP";
  "_OS_CounterIsr_SystemTimer_CONST_FAST_END" = "_lc_ge_OS_CounterIsr_SystemTimer_CONST_FAST_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_CONST_FAST_START" = 0;
  "_OS_CounterIsr_SystemTimer_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_NEAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_INIT
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_INIT
#endif



#ifdef OS_LINK_CONST
# undef OS_LINK_CONST
#endif

#ifdef OS_LINK_CONST_APP
# undef OS_LINK_CONST_APP
#endif

#ifdef OS_LINK_CONST_TASK
# undef OS_LINK_CONST_TASK
#endif

#ifdef OS_LINK_CONST_ISR
# undef OS_LINK_CONST_ISR
#endif

#ifdef OS_LINK_CONST_KERNEL
# undef OS_LINK_CONST_KERNEL
#endif

#ifdef OS_LINK_CONST_KERNEL_FAR
# undef OS_LINK_CONST_KERNEL_FAR
#endif

#ifdef OS_LINK_CONST_KERNEL_NEAR
# undef OS_LINK_CONST_KERNEL_NEAR
#endif

#ifdef OS_LINK_INTVEC_CONST
# undef OS_LINK_INTVEC_CONST
#endif

#ifdef OS_LINK_EXCVEC_CONST
# undef OS_LINK_EXCVEC_CONST
#endif


/**********************************************************************************************************************
 *  VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_INIT )
if (exists(".data.OS_CORE0_VAR"))
{
  group OS_CORE0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CORE0_VAR";
    }
    reserved ".pad.OS_CORE0_VAR" (size=16);
  }
  "_OS_CORE0_VAR_START" = "_lc_gb_OS_CORE0_VAR_GROUP";
  "_OS_CORE0_VAR_END" = "_lc_ub__pad_OS_CORE0_VAR";
}
else
{
  "_OS_CORE0_VAR_START" = 0;
  "_OS_CORE0_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT )
if (exists(".bss.OS_CORE0_VAR_NOINIT"))
{
  group OS_CORE0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CORE0_VAR_NOINIT";
    }
    reserved ".pad.OS_CORE0_VAR_NOINIT" (size=16);
  }
  "_OS_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_NOINIT_GROUP";
  "_OS_CORE0_VAR_NOINIT_END" = "_lc_ub__pad_OS_CORE0_VAR_NOINIT";
}
else
{
  "_OS_CORE0_VAR_NOINIT_START" = 0;
  "_OS_CORE0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT )
if (exists(".zdata.OS_CORE0_VAR_FAST"))
{
  group OS_CORE0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CORE0_VAR_FAST";
    }
    reserved ".pad.OS_CORE0_VAR_FAST" (size=16);
  }
  "_OS_CORE0_VAR_FAST_START" = "_lc_gb_OS_CORE0_VAR_FAST_GROUP";
  "_OS_CORE0_VAR_FAST_END" = "_lc_ub__pad_OS_CORE0_VAR_FAST";
}
else
{
  "_OS_CORE0_VAR_FAST_START" = 0;
  "_OS_CORE0_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_CORE0_VAR_FAST_NOINIT"))
{
  group OS_CORE0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CORE0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_CORE0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_CORE0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_FAST_NOINIT_GROUP";
  "_OS_CORE0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_CORE0_VAR_FAST_NOINIT";
}
else
{
  "_OS_CORE0_VAR_FAST_NOINIT_START" = 0;
  "_OS_CORE0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT )
if (exists(".data.OS_CORE0_VAR_NOCACHE"))
{
  group OS_CORE0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CORE0_VAR_NOCACHE";
    }
    reserved ".pad.OS_CORE0_VAR_NOCACHE" (size=16);
  }
  "_OS_CORE0_VAR_NOCACHE_START" = "_lc_gb_OS_CORE0_VAR_NOCACHE_GROUP";
  "_OS_CORE0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_CORE0_VAR_NOCACHE";
}
else
{
  "_OS_CORE0_VAR_NOCACHE_START" = 0;
  "_OS_CORE0_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_CORE0_VAR_NOCACHE_NOINIT"))
{
  group OS_CORE0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CORE0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORE0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORE0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CORE0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORE0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CORE0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CORE0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_CORE0_VAR_FAST_NOCACHE"))
{
  group OS_CORE0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CORE0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_CORE0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_CORE0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CORE0_VAR_FAST_NOCACHE_GROUP";
  "_OS_CORE0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_CORE0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_CORE0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_CORE0_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_CORE0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CORE0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORE0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORE0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_FAR )
if (exists(".bss.OS_PUBLIC_CORE0_VAR_NOINIT"))
{
  group OS_PUBLIC_CORE0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_PUBLIC_CORE0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_PUBLIC_CORE0_VAR_NOINIT";
    }
    reserved ".pad.OS_PUBLIC_CORE0_VAR_NOINIT" (size=16);
  }
  "_OS_PUBLIC_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_PUBLIC_CORE0_VAR_NOINIT_GROUP";
  "_OS_PUBLIC_CORE0_VAR_NOINIT_END" = "_lc_ub__pad_OS_PUBLIC_CORE0_VAR_NOINIT";
}
else
{
  "_OS_PUBLIC_CORE0_VAR_NOINIT_START" = 0;
  "_OS_PUBLIC_CORE0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_NEAR )
if (exists(".bss.OS_PUBLIC_CORE0_VAR_FAST_NOINIT"))
{
  group OS_PUBLIC_CORE0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_PUBLIC_CORE0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_PUBLIC_CORE0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_PUBLIC_CORE0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_GROUP";
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_PUBLIC_CORE0_VAR_FAST_NOINIT";
}
else
{
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_START" = 0;
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_FAR )
if (exists(".bss.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT"))
{
  group OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_NEAR )
if (exists(".bss.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_FAR )
if (exists(".bss.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT"))
{
  group OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_NEAR )
if (exists(".bss.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif


#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0
group OS_SystemApplication_OsCore_Core0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE_INIT )
if (exists(".data.OS_SystemApplication_OsCore_Core0_VAR"))
{
  group OS_SystemApplication_OsCore_Core0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore_Core0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_SystemApplication_OsCore_Core0_VAR";
    }
    reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR" (size=16);
  }
  "_OS_SystemApplication_OsCore_Core0_VAR_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_GROUP";
  "_OS_SystemApplication_OsCore_Core0_VAR_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_VAR_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_SystemApplication_OsCore_Core0_VAR_NOINIT"))
{
  group OS_SystemApplication_OsCore_Core0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore_Core0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOINIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR_NOINIT" (size=16);
  }
  "_OS_SystemApplication_OsCore_Core0_VAR_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore_Core0_VAR_NOINIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR_NOINIT";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_VAR_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_bss") || exists(".data.OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_bss";
      select ".data.OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST"))
{
  group OS_SystemApplication_OsCore_Core0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore_Core0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST";
    }
    reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR_FAST" (size=16);
  }
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_FAST_GROUP";
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR_FAST";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT"))
{
  group OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE"))
{
  group OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE";
    }
    reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE" (size=16);
  }
  "_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_GROUP";
  "_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT"))
{
  group OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE"))
{
  group OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_GROUP";
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_SystemApplication_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0
reserved ".pad.OS_SystemApplication_OsCore_Core0_VAR_ALL_GROUP" (size=16);
} /* OS_SystemApplication_OsCore_Core0_VAR_ALL_GROUP */
"_OS_SystemApplication_OsCore_Core0_VAR_ALL_START" = "_lc_gb_OS_SystemApplication_OsCore_Core0_VAR_ALL_GROUP";
"_OS_SystemApplication_OsCore_Core0_VAR_ALL_END" = "_lc_ub__pad_OS_SystemApplication_OsCore_Core0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK
group OS_Default_Appl_Init_Task_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE_INIT )
if (exists(".data.OS_Default_Appl_Init_Task_VAR"))
{
  group OS_Default_Appl_Init_Task_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Init_Task_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_Appl_Init_Task_VAR";
    }
    reserved ".pad.OS_Default_Appl_Init_Task_VAR" (size=16);
  }
  "_OS_Default_Appl_Init_Task_VAR_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_GROUP";
  "_OS_Default_Appl_Init_Task_VAR_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR";
}
else
{
  "_OS_Default_Appl_Init_Task_VAR_START" = 0;
  "_OS_Default_Appl_Init_Task_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Default_Appl_Init_Task_VAR_NOINIT"))
{
  group OS_Default_Appl_Init_Task_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Init_Task_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Appl_Init_Task_VAR_NOINIT";
    }
    reserved ".pad.OS_Default_Appl_Init_Task_VAR_NOINIT" (size=16);
  }
  "_OS_Default_Appl_Init_Task_VAR_NOINIT_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_NOINIT_GROUP";
  "_OS_Default_Appl_Init_Task_VAR_NOINIT_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR_NOINIT";
}
else
{
  "_OS_Default_Appl_Init_Task_VAR_NOINIT_START" = 0;
  "_OS_Default_Appl_Init_Task_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Appl_Init_Task_VAR_ZERO_INIT_bss") || exists(".data.OS_Default_Appl_Init_Task_VAR_ZERO_INIT"))
{
  group OS_Default_Appl_Init_Task_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Init_Task_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Appl_Init_Task_VAR_ZERO_INIT_bss";
      select ".data.OS_Default_Appl_Init_Task_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Appl_Init_Task_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Default_Appl_Init_Task_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_ZERO_INIT_GROUP";
  "_OS_Default_Appl_Init_Task_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR_ZERO_INIT";
}
else
{
  "_OS_Default_Appl_Init_Task_VAR_ZERO_INIT_START" = 0;
  "_OS_Default_Appl_Init_Task_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Default_Appl_Init_Task_VAR_FAST"))
{
  group OS_Default_Appl_Init_Task_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Init_Task_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_Appl_Init_Task_VAR_FAST";
    }
    reserved ".pad.OS_Default_Appl_Init_Task_VAR_FAST" (size=16);
  }
  "_OS_Default_Appl_Init_Task_VAR_FAST_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_FAST_GROUP";
  "_OS_Default_Appl_Init_Task_VAR_FAST_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR_FAST";
}
else
{
  "_OS_Default_Appl_Init_Task_VAR_FAST_START" = 0;
  "_OS_Default_Appl_Init_Task_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Default_Appl_Init_Task_VAR_FAST_NOINIT"))
{
  group OS_Default_Appl_Init_Task_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Init_Task_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Appl_Init_Task_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Default_Appl_Init_Task_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR_FAST_NOINIT";
}
else
{
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Default_Appl_Init_Task_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_Default_Appl_Init_Task_VAR_NOCACHE"))
{
  group OS_Default_Appl_Init_Task_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Init_Task_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_Appl_Init_Task_VAR_NOCACHE";
    }
    reserved ".pad.OS_Default_Appl_Init_Task_VAR_NOCACHE" (size=16);
  }
  "_OS_Default_Appl_Init_Task_VAR_NOCACHE_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_NOCACHE_GROUP";
  "_OS_Default_Appl_Init_Task_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR_NOCACHE";
}
else
{
  "_OS_Default_Appl_Init_Task_VAR_NOCACHE_START" = 0;
  "_OS_Default_Appl_Init_Task_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Default_Appl_Init_Task_VAR_NOCACHE_NOINIT"))
{
  group OS_Default_Appl_Init_Task_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Init_Task_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Appl_Init_Task_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Appl_Init_Task_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Appl_Init_Task_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Appl_Init_Task_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Appl_Init_Task_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Appl_Init_Task_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Appl_Init_Task_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE"))
{
  group OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Appl_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK
reserved ".pad.OS_Default_Appl_Init_Task_VAR_ALL_GROUP" (size=16);
} /* OS_Default_Appl_Init_Task_VAR_ALL_GROUP */
"_OS_Default_Appl_Init_Task_VAR_ALL_START" = "_lc_gb_OS_Default_Appl_Init_Task_VAR_ALL_GROUP";
"_OS_Default_Appl_Init_Task_VAR_ALL_END" = "_lc_ub__pad_OS_Default_Appl_Init_Task_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_INIT_TASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK
group OS_Default_Appl_Task_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE_INIT )
if (exists(".data.OS_Default_Appl_Task_VAR"))
{
  group OS_Default_Appl_Task_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Task_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_Appl_Task_VAR";
    }
    reserved ".pad.OS_Default_Appl_Task_VAR" (size=16);
  }
  "_OS_Default_Appl_Task_VAR_START" = "_lc_gb_OS_Default_Appl_Task_VAR_GROUP";
  "_OS_Default_Appl_Task_VAR_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR";
}
else
{
  "_OS_Default_Appl_Task_VAR_START" = 0;
  "_OS_Default_Appl_Task_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Default_Appl_Task_VAR_NOINIT"))
{
  group OS_Default_Appl_Task_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Task_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Appl_Task_VAR_NOINIT";
    }
    reserved ".pad.OS_Default_Appl_Task_VAR_NOINIT" (size=16);
  }
  "_OS_Default_Appl_Task_VAR_NOINIT_START" = "_lc_gb_OS_Default_Appl_Task_VAR_NOINIT_GROUP";
  "_OS_Default_Appl_Task_VAR_NOINIT_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR_NOINIT";
}
else
{
  "_OS_Default_Appl_Task_VAR_NOINIT_START" = 0;
  "_OS_Default_Appl_Task_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Appl_Task_VAR_ZERO_INIT_bss") || exists(".data.OS_Default_Appl_Task_VAR_ZERO_INIT"))
{
  group OS_Default_Appl_Task_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Task_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Appl_Task_VAR_ZERO_INIT_bss";
      select ".data.OS_Default_Appl_Task_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Appl_Task_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Default_Appl_Task_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_Appl_Task_VAR_ZERO_INIT_GROUP";
  "_OS_Default_Appl_Task_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR_ZERO_INIT";
}
else
{
  "_OS_Default_Appl_Task_VAR_ZERO_INIT_START" = 0;
  "_OS_Default_Appl_Task_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Default_Appl_Task_VAR_FAST"))
{
  group OS_Default_Appl_Task_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Task_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_Appl_Task_VAR_FAST";
    }
    reserved ".pad.OS_Default_Appl_Task_VAR_FAST" (size=16);
  }
  "_OS_Default_Appl_Task_VAR_FAST_START" = "_lc_gb_OS_Default_Appl_Task_VAR_FAST_GROUP";
  "_OS_Default_Appl_Task_VAR_FAST_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR_FAST";
}
else
{
  "_OS_Default_Appl_Task_VAR_FAST_START" = 0;
  "_OS_Default_Appl_Task_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Default_Appl_Task_VAR_FAST_NOINIT"))
{
  group OS_Default_Appl_Task_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Task_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Appl_Task_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Default_Appl_Task_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Default_Appl_Task_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_Appl_Task_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_Appl_Task_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR_FAST_NOINIT";
}
else
{
  "_OS_Default_Appl_Task_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_Appl_Task_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Appl_Task_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Default_Appl_Task_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_Appl_Task_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Task_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Appl_Task_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_Default_Appl_Task_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Appl_Task_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Default_Appl_Task_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_Appl_Task_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_Appl_Task_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Default_Appl_Task_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Default_Appl_Task_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_Default_Appl_Task_VAR_NOCACHE"))
{
  group OS_Default_Appl_Task_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Task_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_Appl_Task_VAR_NOCACHE";
    }
    reserved ".pad.OS_Default_Appl_Task_VAR_NOCACHE" (size=16);
  }
  "_OS_Default_Appl_Task_VAR_NOCACHE_START" = "_lc_gb_OS_Default_Appl_Task_VAR_NOCACHE_GROUP";
  "_OS_Default_Appl_Task_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR_NOCACHE";
}
else
{
  "_OS_Default_Appl_Task_VAR_NOCACHE_START" = 0;
  "_OS_Default_Appl_Task_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Default_Appl_Task_VAR_NOCACHE_NOINIT"))
{
  group OS_Default_Appl_Task_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Task_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Appl_Task_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Appl_Task_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Appl_Task_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Appl_Task_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Appl_Task_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Appl_Task_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Appl_Task_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Appl_Task_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Default_Appl_Task_VAR_FAST_NOCACHE"))
{
  group OS_Default_Appl_Task_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Task_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_Appl_Task_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Default_Appl_Task_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Default_Appl_Task_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_Appl_Task_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_Appl_Task_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Default_Appl_Task_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Default_Appl_Task_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Default_Appl_Task_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Default_Appl_Task_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Task_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Appl_Task_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Appl_Task_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Appl_Task_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Appl_Task_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Appl_Task_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Appl_Task_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Appl_Task_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Appl_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK
reserved ".pad.OS_Default_Appl_Task_VAR_ALL_GROUP" (size=16);
} /* OS_Default_Appl_Task_VAR_ALL_GROUP */
"_OS_Default_Appl_Task_VAR_ALL_START" = "_lc_gb_OS_Default_Appl_Task_VAR_ALL_GROUP";
"_OS_Default_Appl_Task_VAR_ALL_END" = "_lc_ub__pad_OS_Default_Appl_Task_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_APPL_TASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK
group OS_Default_BSW_Async_Task_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE_INIT )
if (exists(".data.OS_Default_BSW_Async_Task_VAR"))
{
  group OS_Default_BSW_Async_Task_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Async_Task_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_BSW_Async_Task_VAR";
    }
    reserved ".pad.OS_Default_BSW_Async_Task_VAR" (size=16);
  }
  "_OS_Default_BSW_Async_Task_VAR_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_GROUP";
  "_OS_Default_BSW_Async_Task_VAR_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR";
}
else
{
  "_OS_Default_BSW_Async_Task_VAR_START" = 0;
  "_OS_Default_BSW_Async_Task_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Default_BSW_Async_Task_VAR_NOINIT"))
{
  group OS_Default_BSW_Async_Task_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Async_Task_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_BSW_Async_Task_VAR_NOINIT";
    }
    reserved ".pad.OS_Default_BSW_Async_Task_VAR_NOINIT" (size=16);
  }
  "_OS_Default_BSW_Async_Task_VAR_NOINIT_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_NOINIT_GROUP";
  "_OS_Default_BSW_Async_Task_VAR_NOINIT_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR_NOINIT";
}
else
{
  "_OS_Default_BSW_Async_Task_VAR_NOINIT_START" = 0;
  "_OS_Default_BSW_Async_Task_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_BSW_Async_Task_VAR_ZERO_INIT_bss") || exists(".data.OS_Default_BSW_Async_Task_VAR_ZERO_INIT"))
{
  group OS_Default_BSW_Async_Task_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Async_Task_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_BSW_Async_Task_VAR_ZERO_INIT_bss";
      select ".data.OS_Default_BSW_Async_Task_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Default_BSW_Async_Task_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Default_BSW_Async_Task_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_ZERO_INIT_GROUP";
  "_OS_Default_BSW_Async_Task_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR_ZERO_INIT";
}
else
{
  "_OS_Default_BSW_Async_Task_VAR_ZERO_INIT_START" = 0;
  "_OS_Default_BSW_Async_Task_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Default_BSW_Async_Task_VAR_FAST"))
{
  group OS_Default_BSW_Async_Task_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Async_Task_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_BSW_Async_Task_VAR_FAST";
    }
    reserved ".pad.OS_Default_BSW_Async_Task_VAR_FAST" (size=16);
  }
  "_OS_Default_BSW_Async_Task_VAR_FAST_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_FAST_GROUP";
  "_OS_Default_BSW_Async_Task_VAR_FAST_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR_FAST";
}
else
{
  "_OS_Default_BSW_Async_Task_VAR_FAST_START" = 0;
  "_OS_Default_BSW_Async_Task_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Default_BSW_Async_Task_VAR_FAST_NOINIT"))
{
  group OS_Default_BSW_Async_Task_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Async_Task_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_BSW_Async_Task_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Default_BSW_Async_Task_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR_FAST_NOINIT";
}
else
{
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Default_BSW_Async_Task_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_Default_BSW_Async_Task_VAR_NOCACHE"))
{
  group OS_Default_BSW_Async_Task_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Async_Task_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_BSW_Async_Task_VAR_NOCACHE";
    }
    reserved ".pad.OS_Default_BSW_Async_Task_VAR_NOCACHE" (size=16);
  }
  "_OS_Default_BSW_Async_Task_VAR_NOCACHE_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_NOCACHE_GROUP";
  "_OS_Default_BSW_Async_Task_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR_NOCACHE";
}
else
{
  "_OS_Default_BSW_Async_Task_VAR_NOCACHE_START" = 0;
  "_OS_Default_BSW_Async_Task_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Default_BSW_Async_Task_VAR_NOCACHE_NOINIT"))
{
  group OS_Default_BSW_Async_Task_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Async_Task_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_BSW_Async_Task_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_BSW_Async_Task_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_BSW_Async_Task_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_BSW_Async_Task_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_BSW_Async_Task_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_BSW_Async_Task_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_BSW_Async_Task_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE"))
{
  group OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_BSW_Async_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK
reserved ".pad.OS_Default_BSW_Async_Task_VAR_ALL_GROUP" (size=16);
} /* OS_Default_BSW_Async_Task_VAR_ALL_GROUP */
"_OS_Default_BSW_Async_Task_VAR_ALL_START" = "_lc_gb_OS_Default_BSW_Async_Task_VAR_ALL_GROUP";
"_OS_Default_BSW_Async_Task_VAR_ALL_END" = "_lc_ub__pad_OS_Default_BSW_Async_Task_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK
group OS_Default_BSW_Sync_Task_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE_INIT )
if (exists(".data.OS_Default_BSW_Sync_Task_VAR"))
{
  group OS_Default_BSW_Sync_Task_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Sync_Task_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_BSW_Sync_Task_VAR";
    }
    reserved ".pad.OS_Default_BSW_Sync_Task_VAR" (size=16);
  }
  "_OS_Default_BSW_Sync_Task_VAR_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_GROUP";
  "_OS_Default_BSW_Sync_Task_VAR_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR";
}
else
{
  "_OS_Default_BSW_Sync_Task_VAR_START" = 0;
  "_OS_Default_BSW_Sync_Task_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Default_BSW_Sync_Task_VAR_NOINIT"))
{
  group OS_Default_BSW_Sync_Task_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Sync_Task_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_BSW_Sync_Task_VAR_NOINIT";
    }
    reserved ".pad.OS_Default_BSW_Sync_Task_VAR_NOINIT" (size=16);
  }
  "_OS_Default_BSW_Sync_Task_VAR_NOINIT_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_NOINIT_GROUP";
  "_OS_Default_BSW_Sync_Task_VAR_NOINIT_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR_NOINIT";
}
else
{
  "_OS_Default_BSW_Sync_Task_VAR_NOINIT_START" = 0;
  "_OS_Default_BSW_Sync_Task_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_BSW_Sync_Task_VAR_ZERO_INIT_bss") || exists(".data.OS_Default_BSW_Sync_Task_VAR_ZERO_INIT"))
{
  group OS_Default_BSW_Sync_Task_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Sync_Task_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_BSW_Sync_Task_VAR_ZERO_INIT_bss";
      select ".data.OS_Default_BSW_Sync_Task_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Default_BSW_Sync_Task_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Default_BSW_Sync_Task_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_ZERO_INIT_GROUP";
  "_OS_Default_BSW_Sync_Task_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR_ZERO_INIT";
}
else
{
  "_OS_Default_BSW_Sync_Task_VAR_ZERO_INIT_START" = 0;
  "_OS_Default_BSW_Sync_Task_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Default_BSW_Sync_Task_VAR_FAST"))
{
  group OS_Default_BSW_Sync_Task_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Sync_Task_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_BSW_Sync_Task_VAR_FAST";
    }
    reserved ".pad.OS_Default_BSW_Sync_Task_VAR_FAST" (size=16);
  }
  "_OS_Default_BSW_Sync_Task_VAR_FAST_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_FAST_GROUP";
  "_OS_Default_BSW_Sync_Task_VAR_FAST_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR_FAST";
}
else
{
  "_OS_Default_BSW_Sync_Task_VAR_FAST_START" = 0;
  "_OS_Default_BSW_Sync_Task_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Default_BSW_Sync_Task_VAR_FAST_NOINIT"))
{
  group OS_Default_BSW_Sync_Task_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Sync_Task_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_BSW_Sync_Task_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Default_BSW_Sync_Task_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR_FAST_NOINIT";
}
else
{
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Default_BSW_Sync_Task_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_Default_BSW_Sync_Task_VAR_NOCACHE"))
{
  group OS_Default_BSW_Sync_Task_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Sync_Task_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_BSW_Sync_Task_VAR_NOCACHE";
    }
    reserved ".pad.OS_Default_BSW_Sync_Task_VAR_NOCACHE" (size=16);
  }
  "_OS_Default_BSW_Sync_Task_VAR_NOCACHE_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_NOCACHE_GROUP";
  "_OS_Default_BSW_Sync_Task_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR_NOCACHE";
}
else
{
  "_OS_Default_BSW_Sync_Task_VAR_NOCACHE_START" = 0;
  "_OS_Default_BSW_Sync_Task_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Default_BSW_Sync_Task_VAR_NOCACHE_NOINIT"))
{
  group OS_Default_BSW_Sync_Task_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Sync_Task_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_BSW_Sync_Task_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_BSW_Sync_Task_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_BSW_Sync_Task_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_BSW_Sync_Task_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_BSW_Sync_Task_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_BSW_Sync_Task_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_BSW_Sync_Task_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE"))
{
  group OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_BSW_Sync_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK
reserved ".pad.OS_Default_BSW_Sync_Task_VAR_ALL_GROUP" (size=16);
} /* OS_Default_BSW_Sync_Task_VAR_ALL_GROUP */
"_OS_Default_BSW_Sync_Task_VAR_ALL_START" = "_lc_gb_OS_Default_BSW_Sync_Task_VAR_ALL_GROUP";
"_OS_Default_BSW_Sync_Task_VAR_ALL_END" = "_lc_ub__pad_OS_Default_BSW_Sync_Task_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_SYNC_TASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK
group OS_Default_Background_Task_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE_INIT )
if (exists(".data.OS_Default_Background_Task_VAR"))
{
  group OS_Default_Background_Task_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Background_Task_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_Background_Task_VAR";
    }
    reserved ".pad.OS_Default_Background_Task_VAR" (size=16);
  }
  "_OS_Default_Background_Task_VAR_START" = "_lc_gb_OS_Default_Background_Task_VAR_GROUP";
  "_OS_Default_Background_Task_VAR_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR";
}
else
{
  "_OS_Default_Background_Task_VAR_START" = 0;
  "_OS_Default_Background_Task_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Default_Background_Task_VAR_NOINIT"))
{
  group OS_Default_Background_Task_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Background_Task_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Background_Task_VAR_NOINIT";
    }
    reserved ".pad.OS_Default_Background_Task_VAR_NOINIT" (size=16);
  }
  "_OS_Default_Background_Task_VAR_NOINIT_START" = "_lc_gb_OS_Default_Background_Task_VAR_NOINIT_GROUP";
  "_OS_Default_Background_Task_VAR_NOINIT_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR_NOINIT";
}
else
{
  "_OS_Default_Background_Task_VAR_NOINIT_START" = 0;
  "_OS_Default_Background_Task_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Background_Task_VAR_ZERO_INIT_bss") || exists(".data.OS_Default_Background_Task_VAR_ZERO_INIT"))
{
  group OS_Default_Background_Task_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Background_Task_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Background_Task_VAR_ZERO_INIT_bss";
      select ".data.OS_Default_Background_Task_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Background_Task_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Default_Background_Task_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_Background_Task_VAR_ZERO_INIT_GROUP";
  "_OS_Default_Background_Task_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR_ZERO_INIT";
}
else
{
  "_OS_Default_Background_Task_VAR_ZERO_INIT_START" = 0;
  "_OS_Default_Background_Task_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Default_Background_Task_VAR_FAST"))
{
  group OS_Default_Background_Task_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Background_Task_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_Background_Task_VAR_FAST";
    }
    reserved ".pad.OS_Default_Background_Task_VAR_FAST" (size=16);
  }
  "_OS_Default_Background_Task_VAR_FAST_START" = "_lc_gb_OS_Default_Background_Task_VAR_FAST_GROUP";
  "_OS_Default_Background_Task_VAR_FAST_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR_FAST";
}
else
{
  "_OS_Default_Background_Task_VAR_FAST_START" = 0;
  "_OS_Default_Background_Task_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Default_Background_Task_VAR_FAST_NOINIT"))
{
  group OS_Default_Background_Task_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Background_Task_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Background_Task_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Default_Background_Task_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Default_Background_Task_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_Background_Task_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_Background_Task_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR_FAST_NOINIT";
}
else
{
  "_OS_Default_Background_Task_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_Background_Task_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Background_Task_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Default_Background_Task_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_Background_Task_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Background_Task_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Background_Task_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_Default_Background_Task_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Background_Task_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Default_Background_Task_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_Background_Task_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_Background_Task_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Default_Background_Task_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Default_Background_Task_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_Default_Background_Task_VAR_NOCACHE"))
{
  group OS_Default_Background_Task_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Background_Task_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_Background_Task_VAR_NOCACHE";
    }
    reserved ".pad.OS_Default_Background_Task_VAR_NOCACHE" (size=16);
  }
  "_OS_Default_Background_Task_VAR_NOCACHE_START" = "_lc_gb_OS_Default_Background_Task_VAR_NOCACHE_GROUP";
  "_OS_Default_Background_Task_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR_NOCACHE";
}
else
{
  "_OS_Default_Background_Task_VAR_NOCACHE_START" = 0;
  "_OS_Default_Background_Task_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Default_Background_Task_VAR_NOCACHE_NOINIT"))
{
  group OS_Default_Background_Task_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Background_Task_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Background_Task_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Background_Task_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Background_Task_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Background_Task_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Background_Task_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Background_Task_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Background_Task_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Background_Task_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Default_Background_Task_VAR_FAST_NOCACHE"))
{
  group OS_Default_Background_Task_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Background_Task_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_Background_Task_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Default_Background_Task_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Default_Background_Task_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_Background_Task_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_Background_Task_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Default_Background_Task_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Default_Background_Task_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Default_Background_Task_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Default_Background_Task_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Background_Task_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Background_Task_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Background_Task_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Background_Task_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Background_Task_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Background_Task_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Background_Task_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Background_Task_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Background_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK
reserved ".pad.OS_Default_Background_Task_VAR_ALL_GROUP" (size=16);
} /* OS_Default_Background_Task_VAR_ALL_GROUP */
"_OS_Default_Background_Task_VAR_ALL_START" = "_lc_gb_OS_Default_Background_Task_VAR_ALL_GROUP";
"_OS_Default_Background_Task_VAR_ALL_END" = "_lc_ub__pad_OS_Default_Background_Task_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BACKGROUND_TASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
group OS_Default_Init_Task_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT )
if (exists(".data.OS_Default_Init_Task_VAR"))
{
  group OS_Default_Init_Task_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_Init_Task_VAR";
    }
    reserved ".pad.OS_Default_Init_Task_VAR" (size=16);
  }
  "_OS_Default_Init_Task_VAR_START" = "_lc_gb_OS_Default_Init_Task_VAR_GROUP";
  "_OS_Default_Init_Task_VAR_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR";
}
else
{
  "_OS_Default_Init_Task_VAR_START" = 0;
  "_OS_Default_Init_Task_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Default_Init_Task_VAR_NOINIT"))
{
  group OS_Default_Init_Task_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Init_Task_VAR_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_NOINIT_GROUP";
  "_OS_Default_Init_Task_VAR_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_NOINIT";
}
else
{
  "_OS_Default_Init_Task_VAR_NOINIT_START" = 0;
  "_OS_Default_Init_Task_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_VAR_ZERO_INIT_bss") || exists(".data.OS_Default_Init_Task_VAR_ZERO_INIT"))
{
  group OS_Default_Init_Task_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Init_Task_VAR_ZERO_INIT_bss";
      select ".data.OS_Default_Init_Task_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_ZERO_INIT";
}
else
{
  "_OS_Default_Init_Task_VAR_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Default_Init_Task_VAR_FAST"))
{
  group OS_Default_Init_Task_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_Init_Task_VAR_FAST";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_FAST" (size=16);
  }
  "_OS_Default_Init_Task_VAR_FAST_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Default_Init_Task_VAR_FAST_NOINIT"))
{
  group OS_Default_Init_Task_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Init_Task_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_NOINIT";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Default_Init_Task_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_Init_Task_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Init_Task_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_Default_Init_Task_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_Default_Init_Task_VAR_NOCACHE"))
{
  group OS_Default_Init_Task_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_Init_Task_VAR_NOCACHE";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_NOCACHE" (size=16);
  }
  "_OS_Default_Init_Task_VAR_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_VAR_NOCACHE_GROUP";
  "_OS_Default_Init_Task_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_NOCACHE";
}
else
{
  "_OS_Default_Init_Task_VAR_NOCACHE_START" = 0;
  "_OS_Default_Init_Task_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Default_Init_Task_VAR_NOCACHE_NOINIT"))
{
  group OS_Default_Init_Task_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Init_Task_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Default_Init_Task_VAR_FAST_NOCACHE"))
{
  group OS_Default_Init_Task_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_Init_Task_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
reserved ".pad.OS_Default_Init_Task_VAR_ALL_GROUP" (size=16);
} /* OS_Default_Init_Task_VAR_ALL_GROUP */
"_OS_Default_Init_Task_VAR_ALL_START" = "_lc_gb_OS_Default_Init_Task_VAR_ALL_GROUP";
"_OS_Default_Init_Task_VAR_ALL_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK
group OS_Default_RTE_Mode_switch_Task_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE_INIT )
if (exists(".data.OS_Default_RTE_Mode_switch_Task_VAR"))
{
  group OS_Default_RTE_Mode_switch_Task_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_RTE_Mode_switch_Task_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_RTE_Mode_switch_Task_VAR";
    }
    reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR" (size=16);
  }
  "_OS_Default_RTE_Mode_switch_Task_VAR_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_VAR_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_VAR_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Default_RTE_Mode_switch_Task_VAR_NOINIT"))
{
  group OS_Default_RTE_Mode_switch_Task_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_RTE_Mode_switch_Task_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_RTE_Mode_switch_Task_VAR_NOINIT";
    }
    reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR_NOINIT" (size=16);
  }
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOINIT_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_NOINIT_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOINIT_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR_NOINIT";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOINIT_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT_bss") || exists(".data.OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT"))
{
  group OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT_bss";
      select ".data.OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Default_RTE_Mode_switch_Task_VAR_FAST"))
{
  group OS_Default_RTE_Mode_switch_Task_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_RTE_Mode_switch_Task_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_RTE_Mode_switch_Task_VAR_FAST";
    }
    reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR_FAST" (size=16);
  }
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_FAST_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR_FAST";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOINIT"))
{
  group OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOINIT";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE"))
{
  group OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE";
    }
    reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE" (size=16);
  }
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_NOINIT"))
{
  group OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE"))
{
  group OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_RTE_Mode_switch_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK
reserved ".pad.OS_Default_RTE_Mode_switch_Task_VAR_ALL_GROUP" (size=16);
} /* OS_Default_RTE_Mode_switch_Task_VAR_ALL_GROUP */
"_OS_Default_RTE_Mode_switch_Task_VAR_ALL_START" = "_lc_gb_OS_Default_RTE_Mode_switch_Task_VAR_ALL_GROUP";
"_OS_Default_RTE_Mode_switch_Task_VAR_ALL_END" = "_lc_ub__pad_OS_Default_RTE_Mode_switch_Task_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_RTE_MODE_SWITCH_TASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0
group OS_IdleTask_OsCore_Core0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE_INIT )
if (exists(".data.OS_IdleTask_OsCore_Core0_VAR"))
{
  group OS_IdleTask_OsCore_Core0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_Core0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_IdleTask_OsCore_Core0_VAR";
    }
    reserved ".pad.OS_IdleTask_OsCore_Core0_VAR" (size=16);
  }
  "_OS_IdleTask_OsCore_Core0_VAR_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_GROUP";
  "_OS_IdleTask_OsCore_Core0_VAR_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR";
}
else
{
  "_OS_IdleTask_OsCore_Core0_VAR_START" = 0;
  "_OS_IdleTask_OsCore_Core0_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_IdleTask_OsCore_Core0_VAR_NOINIT"))
{
  group OS_IdleTask_OsCore_Core0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_Core0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_IdleTask_OsCore_Core0_VAR_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_Core0_VAR_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore_Core0_VAR_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_NOINIT_GROUP";
  "_OS_IdleTask_OsCore_Core0_VAR_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore_Core0_VAR_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore_Core0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT_bss") || exists(".data.OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT"))
{
  group OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT_bss";
      select ".data.OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT";
}
else
{
  "_OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore_Core0_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_IdleTask_OsCore_Core0_VAR_FAST"))
{
  group OS_IdleTask_OsCore_Core0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_Core0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_IdleTask_OsCore_Core0_VAR_FAST";
    }
    reserved ".pad.OS_IdleTask_OsCore_Core0_VAR_FAST" (size=16);
  }
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_FAST_GROUP";
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR_FAST";
}
else
{
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_START" = 0;
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_IdleTask_OsCore_Core0_VAR_FAST_NOINIT"))
{
  group OS_IdleTask_OsCore_Core0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_Core0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_IdleTask_OsCore_Core0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_Core0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_FAST_NOINIT_GROUP";
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR_FAST_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT"))
{
  group OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_IdleTask_OsCore_Core0_VAR_NOCACHE"))
{
  group OS_IdleTask_OsCore_Core0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_Core0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_IdleTask_OsCore_Core0_VAR_NOCACHE";
    }
    reserved ".pad.OS_IdleTask_OsCore_Core0_VAR_NOCACHE" (size=16);
  }
  "_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_GROUP";
  "_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR_NOCACHE";
}
else
{
  "_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_START" = 0;
  "_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_IdleTask_OsCore_Core0_VAR_NOCACHE_NOINIT"))
{
  group OS_IdleTask_OsCore_Core0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_Core0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_IdleTask_OsCore_Core0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_Core0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE"))
{
  group OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_GROUP";
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0
reserved ".pad.OS_IdleTask_OsCore_Core0_VAR_ALL_GROUP" (size=16);
} /* OS_IdleTask_OsCore_Core0_VAR_ALL_GROUP */
"_OS_IdleTask_OsCore_Core0_VAR_ALL_START" = "_lc_gb_OS_IdleTask_OsCore_Core0_VAR_ALL_GROUP";
"_OS_IdleTask_OsCore_Core0_VAR_ALL_END" = "_lc_ub__pad_OS_IdleTask_OsCore_Core0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_CANISR_0
group OS_CanIsr_0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_0 ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE_INIT )
if (exists(".data.OS_CanIsr_0_VAR"))
{
  group OS_CanIsr_0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CanIsr_0_VAR";
    }
    reserved ".pad.OS_CanIsr_0_VAR" (size=16);
  }
  "_OS_CanIsr_0_VAR_START" = "_lc_gb_OS_CanIsr_0_VAR_GROUP";
  "_OS_CanIsr_0_VAR_END" = "_lc_ub__pad_OS_CanIsr_0_VAR";
}
else
{
  "_OS_CanIsr_0_VAR_START" = 0;
  "_OS_CanIsr_0_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_0 ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_CanIsr_0_VAR_NOINIT"))
{
  group OS_CanIsr_0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CanIsr_0_VAR_NOINIT";
    }
    reserved ".pad.OS_CanIsr_0_VAR_NOINIT" (size=16);
  }
  "_OS_CanIsr_0_VAR_NOINIT_START" = "_lc_gb_OS_CanIsr_0_VAR_NOINIT_GROUP";
  "_OS_CanIsr_0_VAR_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_0_VAR_NOINIT";
}
else
{
  "_OS_CanIsr_0_VAR_NOINIT_START" = 0;
  "_OS_CanIsr_0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_0 ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_CanIsr_0_VAR_ZERO_INIT_bss") || exists(".data.OS_CanIsr_0_VAR_ZERO_INIT"))
{
  group OS_CanIsr_0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CanIsr_0_VAR_ZERO_INIT_bss";
      select ".data.OS_CanIsr_0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_0_VAR_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_0_VAR_ZERO_INIT_GROUP";
  "_OS_CanIsr_0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_0_VAR_ZERO_INIT";
}
else
{
  "_OS_CanIsr_0_VAR_ZERO_INIT_START" = 0;
  "_OS_CanIsr_0_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_0 ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_CanIsr_0_VAR_FAST"))
{
  group OS_CanIsr_0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CanIsr_0_VAR_FAST";
    }
    reserved ".pad.OS_CanIsr_0_VAR_FAST" (size=16);
  }
  "_OS_CanIsr_0_VAR_FAST_START" = "_lc_gb_OS_CanIsr_0_VAR_FAST_GROUP";
  "_OS_CanIsr_0_VAR_FAST_END" = "_lc_ub__pad_OS_CanIsr_0_VAR_FAST";
}
else
{
  "_OS_CanIsr_0_VAR_FAST_START" = 0;
  "_OS_CanIsr_0_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_0 ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_CanIsr_0_VAR_FAST_NOINIT"))
{
  group OS_CanIsr_0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CanIsr_0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_CanIsr_0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_CanIsr_0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CanIsr_0_VAR_FAST_NOINIT_GROUP";
  "_OS_CanIsr_0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_0_VAR_FAST_NOINIT";
}
else
{
  "_OS_CanIsr_0_VAR_FAST_NOINIT_START" = 0;
  "_OS_CanIsr_0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_0 ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_CanIsr_0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_CanIsr_0_VAR_FAST_ZERO_INIT"))
{
  group OS_CanIsr_0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CanIsr_0_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_CanIsr_0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_CanIsr_0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_CanIsr_0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_CanIsr_0_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_0 ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE_INIT )
if (exists(".data.OS_CanIsr_0_VAR_NOCACHE"))
{
  group OS_CanIsr_0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CanIsr_0_VAR_NOCACHE";
    }
    reserved ".pad.OS_CanIsr_0_VAR_NOCACHE" (size=16);
  }
  "_OS_CanIsr_0_VAR_NOCACHE_START" = "_lc_gb_OS_CanIsr_0_VAR_NOCACHE_GROUP";
  "_OS_CanIsr_0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_CanIsr_0_VAR_NOCACHE";
}
else
{
  "_OS_CanIsr_0_VAR_NOCACHE_START" = 0;
  "_OS_CanIsr_0_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_0 ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_CanIsr_0_VAR_NOCACHE_NOINIT"))
{
  group OS_CanIsr_0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CanIsr_0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CanIsr_0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CanIsr_0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CanIsr_0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CanIsr_0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CanIsr_0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CanIsr_0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_0 ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CanIsr_0_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_0 ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_CanIsr_0_VAR_FAST_NOCACHE"))
{
  group OS_CanIsr_0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CanIsr_0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_CanIsr_0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_CanIsr_0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CanIsr_0_VAR_FAST_NOCACHE_GROUP";
  "_OS_CanIsr_0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_CanIsr_0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_CanIsr_0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_CanIsr_0_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_0 ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_CanIsr_0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CanIsr_0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CanIsr_0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CanIsr_0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CanIsr_0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CanIsr_0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CanIsr_0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CanIsr_0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CanIsr_0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_0 ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CanIsr_0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0
reserved ".pad.OS_CanIsr_0_VAR_ALL_GROUP" (size=16);
} /* OS_CanIsr_0_VAR_ALL_GROUP */
"_OS_CanIsr_0_VAR_ALL_START" = "_lc_gb_OS_CanIsr_0_VAR_ALL_GROUP";
"_OS_CanIsr_0_VAR_ALL_END" = "_lc_ub__pad_OS_CanIsr_0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_CANISR_0
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_FAR
# undef OS_LINK_VAR_ISR_CANISR_0_FAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE
# undef OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_NEAR
# undef OS_LINK_VAR_ISR_CANISR_0_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE
# undef OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
group OS_CounterIsr_SystemTimer_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT )
if (exists(".data.OS_CounterIsr_SystemTimer_VAR"))
{
  group OS_CounterIsr_SystemTimer_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CounterIsr_SystemTimer_VAR";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_NOINIT )
if (exists(".bss.OS_CounterIsr_SystemTimer_VAR_NOINIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CounterIsr_SystemTimer_VAR_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_bss") || exists(".data.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_bss";
      select ".data.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_INIT )
if (exists(".zdata.OS_CounterIsr_SystemTimer_VAR_FAST"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CounterIsr_SystemTimer_VAR_FAST";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_FAST" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_INIT )
if (exists(".data.OS_CounterIsr_SystemTimer_VAR_NOCACHE"))
{
  group OS_CounterIsr_SystemTimer_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CounterIsr_SystemTimer_VAR_NOCACHE";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_NOCACHE" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_NOCACHE_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_NOCACHE";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
reserved ".pad.OS_CounterIsr_SystemTimer_VAR_ALL_GROUP" (size=16);
} /* OS_CounterIsr_SystemTimer_VAR_ALL_GROUP */
"_OS_CounterIsr_SystemTimer_VAR_ALL_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_ALL_GROUP";
"_OS_CounterIsr_SystemTimer_VAR_ALL_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT
#endif


#ifdef OS_LINK_VAR
# undef OS_LINK_VAR
#endif

#ifdef OS_LINK_VAR_APP
# undef OS_LINK_VAR_APP
#endif

#ifdef OS_LINK_VAR_TASK
# undef OS_LINK_VAR_TASK
#endif

#ifdef OS_LINK_VAR_ISR
# undef OS_LINK_VAR_ISR
#endif

#ifdef OS_LINK_KERNEL_TRACE
# undef OS_LINK_KERNEL_TRACE
#endif

#ifdef OS_LINK_KERNEL_TRACE_FAR
# undef OS_LINK_KERNEL_TRACE_FAR
#endif

#ifdef OS_LINK_KERNEL_TRACE_NEAR
# undef OS_LINK_KERNEL_TRACE_NEAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS
# undef OS_LINK_KERNEL_BARRIERS
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_FAR
# undef OS_LINK_KERNEL_BARRIERS_FAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_NEAR
# undef OS_LINK_KERNEL_BARRIERS_NEAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS
# undef OS_LINK_KERNEL_CORESTATUS
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_FAR
# undef OS_LINK_KERNEL_CORESTATUS_FAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_NEAR
# undef OS_LINK_KERNEL_CORESTATUS_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL
# undef OS_LINK_VAR_KERNEL
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR
# undef OS_LINK_VAR_KERNEL_FAR
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE
# undef OS_LINK_VAR_KERNEL_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR
# undef OS_LINK_VAR_KERNEL_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif


