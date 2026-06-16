//######################################################################################################################
// File Name  : TC_OSGen7.lsl                                                                                          #
// Description: Linker/Symbol Preprocessor command file for UseCase OS-Core Gen7                                       #
// Project    : Vector Basic Runtime System                                                                            #
// Module     : BrsHw for Platform Aurix                                                                               #
//                                                                                                                     #
//---------------------------------------------------------------------------------------------------------------------#
// COPYRIGHT                                                                                                           #
//---------------------------------------------------------------------------------------------------------------------#
// Copyright (c) 2017 by Vector Informatik GmbH.                                                  All rights reserved. #
//                                                                                                                     #
//---------------------------------------------------------------------------------------------------------------------#
// AUTHOR IDENTITY                                                                                                     #
//---------------------------------------------------------------------------------------------------------------------#
// Name                          Initials      Company                                                                 #
// ----------------------------  ------------  ------------------------------------------------------------------------#
// Benjamin Walter               visbwa        Vector Informatik GmbH                                                  #
// Thomas Bintz                  vistbi        Vector Informatik GmbH                                                  #
//---------------------------------------------------------------------------------------------------------------------#
// REVISION HISTORY                                                                                                    #
//---------------------------------------------------------------------------------------------------------------------#
// Version   Date        Author  Description                                                                           #
// --------  ----------  ------  --------------------------------------------------------------------------------------#
// 01.00.00  2016-05-24  visbwa  Initial creation, tested with Os_CoreGen7@root[1.01.01]                               #
// 01.00.01  2016-06-15  visbwa  Harmonized linkage with OS-Team and enhanced support for all Aurix derivatives        #
// 01.00.02  2016-09-13  vistbi  Changed groups Executable/Constants from (clustered) to (contiguous) restriction      #
// 01.00.03  2017-04-12  visbwa  Fixed support for derivatives with less than 3 Cores                                  #
//######################################################################################################################

section_layout mpe:vtc:linear
{
  group Core0_RAM( ordered, contiguous, fill, run_addr = mem:mpe:dspr0 )
  {
    // stacks core 0
    group osAllStacksCore0(ordered, contiguous, fill, align=8)
    {
     #include "GenData/Os_Link_Core0_Stacks.lsl"
    }

    // Variables of OS Applications: AppBSW_Core0 (QM), AppModeHandling (QM), AppWarning (ASIL B)
    group Var_NOINIT_Core0
    {
     #define OS_LINK_NOINIT_FAST
     #define OS_LINK_NOINIT
     #include "GenData/Os_Link_Core0.lsl"
     #undef OS_LINK_NOINIT_FAST
     #undef OS_LINK_NOINIT
    }
    group Var_INIT_Core0
    {
     #define OS_LINK_INIT_FAST
     #define OS_LINK_INIT
     #define OS_LINK_ZERO_INIT
     #include "GenData/Os_Link_Core0.lsl"
     #undef OS_LINK_INIT_FAST
     #undef OS_LINK_INIT
     #undef OS_LINK_ZERO_INIT
    }
  }

#if defined(__PROC_TC29X__) || defined(__PROC_TC27X__) || defined(__PROC_TC26X__)
  group Core1_RAM( ordered, contiguous, fill, run_addr = mem:mpe:dspr1 )
  {
    // stacks core 1
    group osAllStacksCore1(ordered, contiguous, fill, align=8)
    {
     #include "GenData/Os_Link_Core1_Stacks.lsl"
    }

    // Variables of OS Applications: 
    group Var_NOINIT_Core1
    {
     #define OS_LINK_NOINIT_FAST
     #define OS_LINK_NOINIT
     #include "GenData/Os_Link_Core1.lsl"
     #undef OS_LINK_NOINIT_FAST
     #undef OS_LINK_NOINIT
    }
    group Var_INIT_Core1
    {
     #define OS_LINK_INIT_FAST
     #define OS_LINK_INIT
     #define OS_LINK_ZERO_INIT
     #include "GenData/Os_Link_Core1.lsl"
     #undef OS_LINK_INIT_FAST
     #undef OS_LINK_INIT
     #undef OS_LINK_ZERO_INIT
    }
  }
#endif

#if defined(__PROC_TC29X__) || defined(__PROC_TC27X__)
  group Core2_RAM( ordered, contiguous, fill, run_addr = mem:mpe:dspr2 )
  {
    // stacks core 2
    group osAllStacksCore2(ordered, contiguous, fill, align=8)
    {
     #include "GenData/Os_Link_Core2_Stacks.lsl"
    }

    // Variables of OS Applications: 
    group Var_NOINIT_Core2
    {
     #define OS_LINK_NOINIT_FAST
     #define OS_LINK_NOINIT
     #include "GenData/Os_Link_Core2.lsl"
     #undef OS_LINK_NOINIT_FAST
     #undef OS_LINK_NOINIT
    }
    group Var_INIT_Core2
    {
     #define OS_LINK_INIT_FAST
     #define OS_LINK_INIT
     #define OS_LINK_ZERO_INIT
     #include "GenData/Os_Link_Core2.lsl"
     #undef OS_LINK_INIT_FAST
     #undef OS_LINK_INIT
     #undef OS_LINK_ZERO_INIT
    }
  }
#endif

  group NOCACHE (run_addr = mem:mpe:dspr0 )
  {
    group Var_NOCACHE_NOINIT_Core0
    {
     #define OS_LINK_NOCACHE_INIT_FAST
     #define OS_LINK_NOCACHE_INIT
     #define OS_LINK_NOCACHE_ZERO_INIT
     #include "GenData/Os_Link_Core0.lsl"
     #undef OS_LINK_NOCACHE_INIT_FAST
     #undef OS_LINK_NOCACHE_INIT
     #undef OS_LINK_NOCACHE_ZERO_INIT
    }
    group Var_NOCACHE_INIT_Core0
    {
     #define OS_LINK_NOCACHE_NOINIT_FAST
     #define OS_LINK_NOCACHE_NOINIT
     #include "GenData/Os_Link_Core0.lsl"
     #undef OS_LINK_NOCACHE_NOINIT_FAST
     #undef OS_LINK_NOCACHE_NOINIT
    }
#if defined(__PROC_TC29X__) || defined(__PROC_TC27X__) || defined(__PROC_TC26X__)
    group Var_NOCACHE_NOINIT_Core1
    {
     #define OS_LINK_NOCACHE_INIT_FAST
     #define OS_LINK_NOCACHE_INIT
     #define OS_LINK_NOCACHE_ZERO_INIT
     #include "GenData/Os_Link_Core1.lsl"
     #undef OS_LINK_NOCACHE_INIT_FAST
     #undef OS_LINK_NOCACHE_INIT
     #undef OS_LINK_NOCACHE_ZERO_INIT
    }
    group Var_NOCACHE_INIT_Core1
    {
     #define OS_LINK_NOCACHE_NOINIT_FAST
     #define OS_LINK_NOCACHE_NOINIT
     #include "GenData/Os_Link_Core1.lsl"
     #undef OS_LINK_NOCACHE_NOINIT_FAST
     #undef OS_LINK_NOCACHE_NOINIT
    }
#endif
#if defined(__PROC_TC29X__) || defined(__PROC_TC27X__)
    group Var_NOCACHE_NOINIT_Core2
    {
     #define OS_LINK_NOCACHE_INIT_FAST
     #define OS_LINK_NOCACHE_INIT
     #define OS_LINK_NOCACHE_ZERO_INIT
     #include "GenData/Os_Link_Core2.lsl"
     #undef OS_LINK_NOCACHE_INIT_FAST
     #undef OS_LINK_NOCACHE_INIT
     #undef OS_LINK_NOCACHE_ZERO_INIT
    }
    group Var_NOCACHE_INIT_Core2
    {
     #define OS_LINK_NOCACHE_NOINIT_FAST
     #define OS_LINK_NOCACHE_NOINIT
     #include "GenData/Os_Link_Core2.lsl"
     #undef OS_LINK_NOCACHE_NOINIT_FAST
     #undef OS_LINK_NOCACHE_NOINIT
    }
#endif

    group GlobalShared_NOCACHE
    {
     #define OS_LINK_NOCACHE_INIT
     #define OS_LINK_NOCACHE_ZERO_INIT
     #define OS_LINK_NOCACHE_NOINIT
     #define OS_LINK_SPINLOCKS
     #include "GenData/Os_Link.lsl"
     #undef OS_LINK_NOCACHE_INIT
     #undef OS_LINK_NOCACHE_ZERO_INIT
     #undef OS_LINK_NOCACHE_NOINIT
     #undef OS_LINK_SPINLOCKS
    }
  }

  group GlobalShared_CACHED ( align = 4 )
  {
   #define OS_LINK_INIT
   #define OS_LINK_ZERO_INIT
   #define OS_LINK_NOINIT
   #include "GenData/Os_Link.lsl"
   #undef OS_LINK_INIT
   #undef OS_LINK_ZERO_INIT
   #undef OS_LINK_NOINIT
  }

#if defined(__PROC_TC29X__) || defined(__PROC_TC27X__) || defined(__PROC_TC26X__)
  group CodeConst( run_addr = mem:mpe:pflash1 )
#else
  group CodeConst( ordered, run_addr = 0x80110000 )
#endif
  {
    group Executable (contiguous)
    {
     #define OS_LINK_CODE
     #define OS_INTVEC_CODE
     #define OS_LINK_CALLOUT_CODE
     #define OS_LINK_EXCVEC_CODE
     #include "GenData/Os_Link.lsl"
     #include "GenData/Os_Link_Core0.lsl"
#if defined(__PROC_TC29X__) || defined(__PROC_TC27X__) || defined(__PROC_TC26X__)
     #include "GenData/Os_Link_Core1.lsl"
#endif
#if defined(__PROC_TC29X__) || defined(__PROC_TC27X__)
     #include "GenData/Os_Link_Core2.lsl"
#endif
     #undef OS_LINK_CODE
     #undef OS_LINK_CALLOUT_CODE
     #undef OS_LINK_EXCVEC_CODE
     
      select ".text.sec_general_code";
    }

    group Constants (contiguous)
    {
     #define OS_LINK_CONST_FAST
     #define OS_LINK_CONST
     #include "GenData/Os_Link.lsl"
     #include "GenData/Os_Link_Core0.lsl"
#if defined(__PROC_TC29X__) || defined(__PROC_TC27X__) || defined(__PROC_TC26X__)
     #include "GenData/Os_Link_Core1.lsl"
#endif
#if defined(__PROC_TC29X__) || defined(__PROC_TC27X__)
     #include "GenData/Os_Link_Core2.lsl"
#endif
     #undef OS_LINK_COST_FAST
     #undef OS_LINK_CONST
    }
  }
}
