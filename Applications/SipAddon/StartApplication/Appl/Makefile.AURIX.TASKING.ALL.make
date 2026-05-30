#######################################################################################################################
# File Name  : Makefile.AURIX.TASKING.ALL.make                                                                        #
# Description: Linker/Symbol Preprocessor command file generation                                                     #
# Project    : Vector Basic Runtime System                                                                            #
# Module     : BrsHw for Platform Infineon Aurix                                                                      #
#              and Compiler Tasking                                                                                   #
#                                                                                                                     #
#---------------------------------------------------------------------------------------------------------------------#
# COPYRIGHT                                                                                                           #
#---------------------------------------------------------------------------------------------------------------------#
# Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved. #
#                                                                                                                     #
#---------------------------------------------------------------------------------------------------------------------#
# AUTHOR IDENTITY                                                                                                     #
#---------------------------------------------------------------------------------------------------------------------#
# Name                          Initials      Company                                                                 #
# ----------------------------  ------------  ------------------------------------------------------------------------#
# Benjamin Walter               visbwa        Vector Informatik GmbH                                                  #
#---------------------------------------------------------------------------------------------------------------------#
# REVISION HISTORY                                                                                                    #
#---------------------------------------------------------------------------------------------------------------------#
# Version   Date        Author  Description                                                                           #
# --------  ----------  ------  --------------------------------------------------------------------------------------#
# 04.00.00  2014-03-11  visbwa  First version for Aurix-only, adapted LINK_RULE mechanism,                            #
#                               SafeContext OS support added                                                          #
# 04.00.01  2015-11-26  visbwa  Changed platform name to AURIX                                                        #
# 04.00.02  2016-05-24  visbwa  Added support for Os_CoreGen7                                                         #
# 04.01.00  2016-06-23  visbwa  Reworked file header structure to fit with Brs_Template 2.00.01                       #
# 01.00.01  2016-12-22  visbwa  Review according to Brs_Template 2.00.03                                              #
#######################################################################################################################

#------------------------------------------------------------------------
# For derivatives without LINK_LOCATE_RULE_ use original Tasking lsl file
# For SafeContext OS, specific lsl file has to be used
#------------------------------------------------------------------------
define LINK_LOCATE_RULE
 $(ECHO) '#include "$(REG_DEF).lsl"' > $@;
endef

ifeq ($(OS_USECASE),SAFECTX)
  define LINK_LOCATE_RULE
    $(ECHO) '#include "$(REG_DEF).lsl"'  > $@; \
    $(ECHO) '#include "TC_SafeCtx.lsl"' >> $@;
  endef
endif

ifeq ($(OS_USECASE),OSGEN7)
  define LINK_LOCATE_RULE
    $(ECHO) '#include "$(REG_DEF).lsl"'  > $@; \
    $(ECHO) '#include "TC_OSGen7.lsl"' >> $@;
  endef
endif

#------------------------------------------------------------------------------
# rule to generate linker command file
#------------------------------------------------------------------------------
$(PROJECT_NAME).$(LNK_SUFFIX): Makefile \
                               Makefile.config \
                               Makefile.Project.Part.Defines \
                               Makefile.$(PLATFORM).$(COMPILER_MANUFACTURER).$(EMULATOR).make

#---------------------------------------------------------------------------------
# _NEVER_ delete the leading "Tab" in the first ECHO-line below!!!
# The Linker-Command-File which will be generated:
#---------------------------------------------------------------------------------
	@$(ECHO) "Generating linker command file $@ for derivative $(CPU_TYPE):"; \
  $(LINK_LOCATE_RULE)                                                       \
  $(ECHO) "...done";                                                        \
  $(ECHO) "";

$(PROJECT_NAME).i:
	@$(ECHO) "Generating $@:";                              \
  $(ECHO) "#define RESET 0xA0000000"                > $@; \
  $(ECHO) "#define INTTAB 0xA00F0000"              >> $@; \
  $(ECHO) "#define TRAPTAB 0xA00F2000"             >> $@; \
  $(ECHO) "#define XVWBUF 0"                       >> $@; \
  $(ECHO) "#define USTACK 8k"                      >> $@; \
  $(ECHO) "#define ISTACK 1k"                      >> $@; \
  $(ECHO) "#define CSA 64"                         >> $@; \
  $(ECHO) "#define HEAP 16k"                       >> $@; \
  $(ECHO) "RAM(ext_d, 0xA0080000, 0xA00EFFFF)"     >> $@; \
  $(ECHO) "RAM(dsram, 0xD0000000, 0xD0007FFF)"     >> $@; \
  $(ECHO) "ROM(ext_c, 0xA0000000, 0xA007FFFF)"     >> $@; \
  $(ECHO) "ROM(vecttable, 0xA00F0000, 0xA00F20FF)" >> $@; \
  $(ECHO) "PCPRAM(pram, 0xf0010000, 0xf00107FF)"   >> $@; \
  $(ECHO) "PCPROM(prom, 0xf0020000, 0xf00203FF)"   >> $@; \
  $(ECHO) "...done";                                      \
  $(ECHO) "";

#End of Makefile.AURIX.TASKING.ALL.make
