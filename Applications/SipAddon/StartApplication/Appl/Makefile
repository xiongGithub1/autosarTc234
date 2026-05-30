#######################################################################################################################
# File Name  : Makefile                                                                                               #
# Description: local main project Makefile                                                                            #
# Project    : Vector Basic Runtime System                                                                            #
# Module     : BrsHw for Platform Infineon Aurix                                                                      #
#              and Compiler Tasking,                                                                                  #
#              using Vector PES Makesupport 3.13                                                                      #
# Template   : This Makefile is reviewed according to zBrs_Template@root[2.02.00]                                     #
#                                                                                                                     #
#---------------------------------------------------------------------------------------------------------------------#
# COPYRIGHT                                                                                                           #
#---------------------------------------------------------------------------------------------------------------------#
# Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved. #
#                                                                                                                     #
#---------------------------------------------------------------------------------------------------------------------#
# AUTHOR IDENTITY                                                                                                     #
#---------------------------------------------------------------------------------------------------------------------#
# Name                          Initials      Company                                                                 #
# ----------------------------  ------------  ------------------------------------------------------------------------#
# Benjamin Walter               visbwa        Vector Informatik GmbH                                                  #
# Alexander Gronbach            visagh        Vector Informatik GmbH                                                  #
#---------------------------------------------------------------------------------------------------------------------#
# REVISION HISTORY                                                                                                    #
#---------------------------------------------------------------------------------------------------------------------#
# Version   Date        Author  Description                                                                           #
# --------  ----------  ------  --------------------------------------------------------------------------------------#
# 01.00.00  2014-09-02  visbwa  First Version (derived from zBrs_Tricore 2.01.24)                                     #
# 01.00.01  2015-02-24  visbwa  Added BRS_EVA_BOARD_$(EVA_BOARD)                                                      #
# 01.00.02  2015-02-25  visbwa  Adopted resource-script                                                               #
# 01.00.03  2015-11-26  visbwa  Fixed BRS_CPU_ to proper BRS_PLATFORM_ defines                                        #
# 01.00.04  2015-12-16  visbwa  Moved -d Linker-Option to mandatory flags                                             #
# 02.00.00  2016-03-09  visbwa  Updated to zBrs_Template@root[2.00.00] and Makesupport 3.13,                          #
#                               default Assembler/Compiler/Linker options reworked                                    #
# 02.00.01  2016-03-24  visagh  New default compiler option added for postbuild                                       #
# 02.01.00  2016-06-23  visbwa  Reworked file header structure to fit with Brs_Template 2.00.01                       #
# 02.01.01  2016-12-22  visbwa  Review according to Brs_Template 2.00.03                                              #
# 03.00.00  2017-05-02  visbwa  Splitted platform/compiler static settings into Makefile.static (Brs_Template 2.01.00)#
# 03.00.01  2018-01-05  visbwa  Disabled “Control flow simplification” (f/F) in Vector default compiler options       #
#######################################################################################################################

#------------------------------------------------------------------------------
# Name of this project (dir under which the appl dir resides)
# E.g.: TestSuit
#------------------------------------------------------------------------------
PROJECT_NAME = TestSuit

#------------------------------------------------------------------------------
# More static settings placed inside separate file
#------------------------------------------------------------------------------
include Makefile.static

#------------------------------------------------------------------------------
# Define Compiler path
# E.g.: COMPILER_BASE = D:\uti\%vendor%\%platform%\%version%
#       COMPILER_BIN  = $(COMPILER_BASE)\bin
#       COMPILER_INC  = $(COMPILER_BASE)\inc
#       COMPILER_LIB  = $(COMPILER_BASE)\lib
#------------------------------------------------------------------------------
COMPILER_BASE = C:\Program Files (x86)\TASKING\TriCore v6.0r1\ctc
COMPILER_BIN  = $(COMPILER_BASE)\bin
COMPILER_INC  = $(COMPILER_BASE)\include
COMPILER_LIB  = $(COMPILER_BASE)\lib

DEBUG_EXE = $(COMPILER_BIN)\..\eclipse\eclipse.exe

ELFCONVERTER_BIN = ..\..\..\external\Generators\Os\ElfConverter.exe

#------------------------------------------------------------------------------
# Build Options Selection: VECTOR / CUSTOMER
#------------------------------------------------------------------------------
ASFLAGS_SELECTOR = VECTOR
CFLAGS_SELECTOR  = VECTOR
LDFLAGS_SELECTOR = VECTOR

#------------------------------------------------------------------------------
# Define location of license.dat used by FlexLm
#------------------------------------------------------------------------------
LM_LICENSE = C:\flexlm\license.dat

#------------------------------------------------------------------------------
# Define Emulator path
# E.g.: EMU_PATH = C:\UTI\HITOPWIN\P6811
#------------------------------------------------------------------------------
EMU_PATH =

#------------------------------------------------------------------------------
# Set NANT_USED to '1', to enable the usage of NAnt support within
# Global Makefile. If this is enabled, the Makesupport will include the
# NAnt support from a intranel link and the NAnt build-targets can be used.
#------------------------------------------------------------------------------
NANT_USED=1

#------------------------------------------------------------------------------
# Set MKVERBOSE to a various value, to enable enhanced debug output from 
# Makesupport. To disable this afterwards, set MKVERBOSE to nothing
# (comment out this line and type "set MKVERBOSE=" in command window)
#------------------------------------------------------------------------------
#MKVERBOSE=1

#------------------------------------------------------------------------------
# Set BRSVINFO_USED to '1', to enable the generation of BrsVInfo.h within the
# GenData folder by the Makesupport.
# The BrsVInfo.h will contain e.g. kBrsCompilerVersion, to use this 
# information within the embedded code.
#------------------------------------------------------------------------------
#BRSVINFO_USED=1

#------------------------------------------------------------------------------
# Turn off strict c setting for dependency generation
#------------------------------------------------------------------------------
#STRICT_C_OFF=1

#------------------------------------------------------------------------------
# Set DELETE_DLD to '1', to enable the deleting of previously 
# generated/outdated Linker-script file, before every new linkage request.
#------------------------------------------------------------------------------
#DELETE_DLD=1

#------------------------------------------------------------------------------
# Set NEW_DEPENDENCY_FORMAT to '1' to enable parallel creation of dependencies.
# You have to ensure that you call m.bat with -jX to use this feature.
#------------------------------------------------------------------------------
NEW_DEPENDENCY_FORMAT=1

#------------------------------------------------------------------------------
# If you want to use code analysis tools like PC-Lint or QAC,
# configure them within Makefile.analysis (part of global-make-package)
# and inlcude this file here
#------------------------------------------------------------------------------
#include Makefile.analysis

ifeq ($(CORE1_START_IMMEDIATE),)
#Default is 0
CORE1_START_IMMEDIATE = 0
endif
ifeq ($(CORE2_START_IMMEDIATE),)
#Default is 0
CORE2_START_IMMEDIATE = 0
endif

#------------------------------------------------------------------------------
# Dependency defines
# These defines are used for the GNU-Preprocessor,
# e.g.: BRS_TIMEBASE_CLOCK=$(TIMEBASE_CLOCK)
#------------------------------------------------------------------------------
DEP_DEFINES = BRS_DERIVATIVE_$(DERIVATIVE)                       \
              BRS_OSC_CLK=$(MAIN_OSC_CLK)                        \
              BRS_TIMEBASE_CLOCK=$(TIMEBASE_CLOCK)               \
              BRS_OS_USECASE_$(OS_USECASE)                       \
              BRS_EVA_BOARD_$(EVA_BOARD)                         \
              BRS_PLATFORM_$(PLATFORM)                           \
              BRS_COMP_$(COMPILER_MANUFACTURER)                  \
              BRS_CORE1_START_IMMEDIATE=$(CORE1_START_IMMEDIATE) \
              BRS_CORE2_START_IMMEDIATE=$(CORE2_START_IMMEDIATE) \
              __CTC__

#------------------------------------------------------------------------------
# $(AS_ENV) is the environment necessary to run the assembler
# $(AS) defines the path to the assembler
# $(ASFLAGS_VECTOR_MAKESUPPORT) defines all assembler switches, mandatory for
#                               the Vector build environment (Makesupport/BrsHw)
# $(ASFLAGS_VECTOR_OPTIONS) defines the Vector default assembler switches
# $(ASFLAGS_CUSTOMER_OPTIONS) defines the customer requested assembler switches
# Depending of ASFLAGS_SELECTOR, ASFLAGS_VECTOR_OPTIONS or ASFLAGS_CUSTOMER_OPTIONS
# are used together with ASFLAGS_VECTOR_MAKESUPPORT for Build.
#------------------------------------------------------------------------------
# Used options:
# -------------
#  --cpu=$(AurixDerivative)                /* specify the Aurix derivative TC21x, TC22x, TC23x, TC24x, TC26x, TC27x, TC29x */
#  --create=o                              /* compile and assemble within one call of cctc.exe; will stop when *.o files have been generated */
#  --debug-info                            /* generates debug information into the object files */
#  --define=macro_name[=macro_definition]  /* specify defines on control program level. They will be passed to compiler AND assembler */
#  --iso=99                                /* selects the C99 standard */
#  --keep-temporary-files                  /* the assembler files *.src are not removed after successfully build the *.o */
#  --include-directory=<path>              /* specifies an include path; it will be passed to compiler AND assembler */
#
#  -Wa--emit-locals=+equ,+symbols          /* emits symbols into object file */
#  -Wa--list-file                          /* generate assembler list files */
#  -Wa--section-info=+list,-console        /* options for assembler list files */
#  -Wa--optimize=+generics,+instr-size     /* assembler optimization switched on */
#  -Wa--debug-info[=flags]  -Wa-g[flags]   /* tell the assembler which kind of debug information to emit in the object file */
#      a/A +/-asm    -  Assembly source line information
#      h/H +/-hll    -  Pass high level language debug information (HLL)
#      l/L +/-local  -  Assembler local symbols debug information
#      s/S +/-smart  -  Smart debug information
#------------------------------------------------------------------------------
AS_ENV  = $(CC_ENV)
AS      = $(CC)

#Please add only absolutely mandatory options below
ASFLAGS_VECTOR_MAKESUPPORT = --create=o                                  \
                             --include-directory=$(COMPILER_INC)\sfr     \
                             -Wa--list-file=$(LST_PATH)\$*.$(LST_SUFFIX)

#Please add any other option below (vector default options)
ASFLAGS_VECTOR_OPTIONS = --cpu=$(REG_DEF)                    \
                         -gAHLs                              \
                         --emit-locals=-equ,-symbols         \
                         --section-info=+list                \
                         --debug-info                        \
                         --iso=99                            \
                         --keep-temporary-files              \
                         -Wa--emit-locals=+equ,+symbols      \
                         -Wa--section-info=+list,-console    \
                         -Wa--optimize=+generics,+instr-size \
                         -Wa--debug-info=+asm,+hll,+local,+smart

#Please enter all customer options below
ASFLAGS_CUSTOMER_OPTIONS =

#------------------------------------------------------------------------------
# $(ASVERSION) defines the assembler switch for version report
# E.g.: ASVERSION = -V
#------------------------------------------------------------------------------
ASVERSION = -Wa-V dummy.asm

#------------------------------------------------------------------------------
# $(AS_LC) defines the number of lines used for assembler version information
# in BrsVinfo.h and Deliverydescription (default is 5)
#------------------------------------------------------------------------------
AS_LC =

#------------------------------------------------------------------------------
#------------------------- MUST be filled out ---------------------------------
# $(CC_ENV) is the environment necessary to run the compiler
# $(CC) defines the path to the C-Compiler
# $(CFLAGS_VECTOR_MAKESUPPORT) defines all compiler switches, mandatory for
#                               the Vector build environment (Makesupport/BrsHw)
# $(CFLAGS_VECTOR_OPTIONS) defines the Vector default compiler switches
# $(CFLAGS_CUSTOMER_OPTIONS) defines the customer requested compiler switches
# Depending of CFLAGS_SELECTOR, CFLAGS_VECTOR_OPTIONS or CFLAGS_CUSTOMER_OPTIONS
# are used together with CFLAGS_VECTOR_MAKESUPPORT for Build.
#------------------------------------------------------------------------------
# Used options:
# -------------
#  --cpu=$(AurixDerivative)                         /* specify the Aurix derivative TC21x, TC22x, TC23x, TC24x, TC26x, TC27x, TC29x */
#  --create=o                                       /* compile and assemble within one call of cctc.exe; will stop when *.o files have been generated */
#  --debug-info                                     /* generates debug information into the object files */
#  --define=macro_name[=macro_definition]           /* specify defines on control program level. They will be passed to compiler AND assembler */
#  --iso=99                                         /* selects the C99 standard */
#  --keep-temporary-files                           /* the assembler files *.src are not removed after successfully build the *.o */
#  --include-directory=<path>                       /* specifies an include path; it will be passed to compiler AND assembler */
#
#  -Wc--align=4                                     /* default alignment */
#  -Wc--default-a0-size=0                           /* OS mandatory option */
#  -Wc--default-a1-size=0                           /* OS mandatory option */
#  -Wc--default-near-size=0                         /* threshold value for near allocation */
#  -Wc--optimize=acefgIklMnopRsUvwy,+predict        /* Enable most of the optimization flags; same as –O2, but w/o code compaction (reverse inlining) */
#  -Wc--tradeoff=2                                  /* balance between size (tradeoff=4) and speed (tradeoff = 0) optimization */
#  -Wc--language=-gcc,+volatile,-strings,-comments  /* language options */
#  -Wc--debug-info[=suboption]  -Wc-g[suboption]    /*  tell the compiler to add directives to the output file for including symbolic information */
#      small    -  Emit small set of debug information
#      default  -  Emit default symbolic debug information
#      all      -  Emit full symbolic debug information
#
#  -Wa--emit-locals=+equ,+symbols                   /* emits symbols into object file */
#  -Wa--list-file                                   /* generate assembler list files */
#  -Wa--section-info=+list,-console                 /* options for assembler list files */
#  -Wa--optimize=+generics,+instr-size              /* assembler optimization switched on */
#  -Wa--debug-info[=flags]  -Wa-g[flags]            /* tell the assembler which kind of debug information to emit in the object file */
#      a/A +/-asm    -  Assembly source line information
#      h/H +/-hll    -  Pass high level language debug information (HLL)
#      l/L +/-local  -  Assembler local symbols debug information
#      s/S +/-smart  -  Smart debug information
#------------------------------------------------------------------------------
CC_ENV  = export LM_LICENSE_FILE=$(LM_LICENSE);
CC      = $(COMPILER_BIN)\cctc.exe

#Please add only absolutely mandatory options below
CFLAGS_VECTOR_MAKESUPPORT = -DBRS_DERIVATIVE_$(DERIVATIVE)                       \
                            -DBRS_OSC_CLK=$(MAIN_OSC_CLK)                        \
                            -DBRS_TIMEBASE_CLOCK=$(TIMEBASE_CLOCK)               \
                            -DBRS_OS_USECASE_$(OS_USECASE)                       \
                            -DBRS_EVA_BOARD_$(EVA_BOARD)                         \
                            -DBRS_PLATFORM_$(PLATFORM)                           \
                            -DBRS_COMP_$(COMPILER_MANUFACTURER)                  \
                            -DBRS_CORE1_START_IMMEDIATE=$(CORE1_START_IMMEDIATE) \
                            -DBRS_CORE2_START_IMMEDIATE=$(CORE2_START_IMMEDIATE) \
                            --create=o                                           \
                            --output=$(OBJ_PATH)\$*.$(OBJ_SUFFIX)                \
                            -Wa--list-file=$(LST_PATH)\$*.$(LST_SUFFIX)          \
                            -Wc--error-file=$(ERR_PATH)\$*.$(ERR_SUFFIX)

#Please add any other option below (vector default options)
CFLAGS_VECTOR_OPTIONS = --cpu=$(REG_DEF)                          \
                        --iso=99                                  \
                        --keep-temporary-files                    \
                        --integer-enumeration                     \
                        -Wa--emit-locals=+equ,+symbols            \
                        -Wa--section-info=+list,-console          \
                        -Wa--optimize=+generics,+instr-size       \
                        -Wa--debug-info=+asm,+hll,+local,+smart   \
                        -Wc--debug-info=default                   \
                        -Wc--align=4                              \
                        -Wc--default-a0-size=0                    \
                        -Wc--default-a1-size=0                    \
                        -Wc--default-near-size=0                  \
                        -Wc--optimize=aceFgIklMnopRsUvwy,+predict \
                        -Wc--tradeoff=2                           \
                        -Wc--language=-gcc,+volatile,-strings,-comments \
                        -Wc--no-structs-in-registers

#Please enter all customer options below
CFLAGS_CUSTOMER_OPTIONS =

#------------------------------------------------------------------------------
# Specific compiler options for TC2XX startup code
# cstart.c, cstart_tc1.c and cstart_tc2.c only used by compiler version 4
#------------------------------------------------------------------------------
CFLAGS_CSTART =     -D_CALL_ENDINIT     \
                    -D_WATCHDOG_DISABLE \
                    -D_NO_ISP_INIT      \
                    -D__NO_CSTART_DEFAULT_CONFIG

CFLAGS_CSTART_TC1 = -D_CALL_ENDINIT       \
                    -D_WATCHDOG_DISABLE   \
                    -D_NO_ISP_INIT        \
                    -D_USERDEFINED_TRAP_1 \
                    -D_USERDEFINED_TRAP_2 \
                    -D_USERDEFINED_TRAP_6 \
                    -D__NO_CSTART_DEFAULT_CONFIG

CFLAGS_CSTART_TC2 = -D_CALL_ENDINIT       \
                    -D_WATCHDOG_DISABLE   \
                    -D_NO_ISP_INIT        \
                    -D_USERDEFINED_TRAP_1 \
                    -D_USERDEFINED_TRAP_2 \
                    -D_USERDEFINED_TRAP_6 \
                    -D__NO_CSTART_DEFAULT_CONFIG

#------------------------------------------------------------------------------
# $(CVERSION) defines the compiler switch for version report
# E.g.: CVERSION = -V
#------------------------------------------------------------------------------
CVERSION = -Wc-V dummy.c

#------------------------------------------------------------------------------
# $(CC_LC) defines the number of lines used for compiler version information
# in BrsVinfo.h and Deliverydescription (default is 5)
#------------------------------------------------------------------------------
CC_LC =

#------------------------------------------------------------------------------
# $(CINC) defines the include switch of the used compiler.
# E.g.: COSMIC Compiler use: CINC = -i
#------------------------------------------------------------------------------
CINC = -I

#------------------------------------------------------------------------------
#------------------------- MUST be filled out ---------------------------------
# $(LD_ENV) is the environment necessary to run the linker
# $(LD) defines the path linker
# $(LDFLAGS_VECTOR_MAKESUPPORT) defines all linker switches, mandatory for
#                               the Vector build environment (Makesupport/BrsHw)
# $(LDFLAGS_VECTOR_OPTIONS) defines the Vector default linker switches
# $(LDFLAGS_CUSTOMER_OPTIONS) defines the customer requested linker switches
# Depending of LDFLAGS_SELECTOR, LDFLAGS_VECTOR_OPTIONS or LDFLAGS_CUSTOMER_OPTIONS
# are used together with LDFLAGS_VECTOR_MAKESUPPORT for Build.
#------------------------------------------------------------------------------
# Used options:
# -------------
#  --cpu=$(AurixDerivative)                   /* specify the Aurix derivative TC21x, TC22x, TC23x, TC24x, TC26x, TC27x, TC29x */
#  --output=<elf result file name>            /* specify the output file */
#  --lsl-file=<base linker command file>      /* specifies the base linker command file */
#  -Wl--output=<resultFileName>.hex:IHEX      /* specify additional hex output file */
#  -Wl--define=macro_name[=macro_definition]  /* specify a define */
#  -Wl--include-directory=<path>              /* specify include directories */
#  -Wl--map-file                              /* generates a map file */
#  -Wl--map-file-format=2                     /* most information in linker command file */
#  -Wl--optimize=1                            /* default linker optimization */
#------------------------------------------------------------------------------
LD_ENV  = $(CC_ENV)
LD      = $(CC)

#Please add only absolutely mandatory options below
LDFLAGS_VECTOR_MAKESUPPORT = --output=$(PROJECT_NAME).$(BINARY_SUFFIX) \
                             --lsl-file=$(LINKER_COMMAND_FILE)         \
                             -Wl--map-file                             \
                             -Wl--map-file-format=2

#Please add any other option below (vector default options)
LDFLAGS_VECTOR_OPTIONS = --cpu=$(REG_DEF)                     \
                         -Wl--output=$(PROJECT_NAME).hex:IHEX \
                         -Wl--optimize=1

#Please enter all customer options below
LDFLAGS_CUSTOMER_OPTIONS =

#------------------------------------------------------------------------------
# $(LDVERSION) defines the linker switch for version report
# E.g.: LDVERSION = -v
#------------------------------------------------------------------------------
LDVERSION = -Wl-V dummy.o

#------------------------------------------------------------------------------
# $(LD_LC) defines the number of lines used for linker version information
# in BrsVinfo.h and Deliverydescription (default is 5)
#------------------------------------------------------------------------------
LD_LC =

#------------------------------------------------------------------------------
#------------------------- MUST be filled out ---------------------------------
# $(LB_ENV) is the environment necessary to run the librarian
# $(LB) defines the path to the C-librarian
# $(LBFLAGS) defines all librarian switches
#------------------------------------------------------------------------------
LB_ENV  =
LB      = $(COMPILER_BIN)\artc.exe

LBFLAGS = -cr $@

#------------------------------------------------------------------------------
# $(LBVERSION) defines the archiver switch for version report
# E.g.: LBVERSION = -v
#------------------------------------------------------------------------------
LBVERSION = -V

#------------------------------------------------------------------------------
# $(LB_LC) defines the number of lines used for librarian version information
# in BrsVinfo.h
#------------------------------------------------------------------------------
LB_LC = 1

#------------------------------------------------------------------------------
# Additional includes essentially for compilation
#------------------------------------------------------------------------------
ADDITIONAL_INCLUDES +=

#------------------------------------------------------------------------------
# Additional objects essentially for linking
# E.g.: ADDITIONAL_OBJECTS = $(OBJ_PATH)\myobject.$(OBJ_SUFFIX)
#------------------------------------------------------------------------------
ADDITIONAL_OBJECTS +=

#------------------------------------------------------------------------------
# List of assembler source files
# E.g.: ASM_SOURCES = source\startup.$(ASM_SUFFIX)
#------------------------------------------------------------------------------
ASM_SOURCES +=

#------------------------------------------------------------------------------
# Add Startup code to application source list
# E.g.: APP_SOURCE_LST += source\startup.c
#------------------------------------------------------------------------------
APP_SOURCE_LST +=

#------------------------------------------------------------------------------
# Check if all necessary variables are set
# (Checks that are not possible to be performed within Makefile.static)
#------------------------------------------------------------------------------

###############################################################################
######### DO NOT remove these lines from the end of the Makefile!!! ###########
###############################################################################

#------------------------------------------------------------------------------
# Platform/compiler/derivative/emulator dependant makefile is included here
# It defines a rule to generate the linker and a rule to generate the
# symbol preprocessor command file.
# A template for this Makefile can be found under
#     R:\Can_Base\CANtate\BRS\PlatformSpecific\...\OrganiAndMake\...
#------------------------------------------------------------------------------
include Makefile.$(PLATFORM).$(COMPILER_MANUFACTURER).$(EMULATOR).make

#------------------------------------------------------------------------------
# Include the main makefile where all the targets are defined
#------------------------------------------------------------------------------
include $(MAKESUPPORT_DIR)\Global.Makefile.target.make.$(VERSION)

#End of Makefile
