################################################################################
# Automatically-generated file. Do not edit!
################################################################################

PROJ 	= tc234Autosar
PRODDIR = D:\Program Files (x86)\TASKING\TriCore v6.2r2\ctc

-include "..\makefile.init"

all :

-include "subdir.mk"
-include "Appl\GenData\subdir.mk"
-include "Appl\GenData\src\subdir.mk"
-include "Appl\Source\subdir.mk"
-include "BSW\BswM\subdir.mk"
-include "BSW\Can\subdir.mk"
-include "BSW\CanIf\subdir.mk"
-include "BSW\CanNm\subdir.mk"
-include "BSW\CanSM\subdir.mk"
-include "BSW\CanTp\subdir.mk"
-include "BSW\CanXcp\subdir.mk"
-include "BSW\Com\subdir.mk"
-include "BSW\ComM\subdir.mk"
-include "BSW\Crc\subdir.mk"
-include "BSW\Dcm\subdir.mk"
-include "BSW\Dem\subdir.mk"
-include "BSW\Det\subdir.mk"
-include "BSW\EcuM\subdir.mk"
-include "BSW\Mcal_Tc2xx\subdir.mk"
-include "BSW\MemIf\subdir.mk"
-include "BSW\Nm\subdir.mk"
-include "BSW\NvM\subdir.mk"
-include "BSW\Os\subdir.mk"
-include "BSW\PduR\subdir.mk"
-include "BSW\VStdLib\subdir.mk"
-include "BSW\WdgIf\subdir.mk"
-include "BSW\WdgM\subdir.mk"
-include "BSW\Xcp\subdir.mk"
-include "MCAL\adc_infineon_tricore\ssc\src\subdir.mk"
-include "MCAL\dio_infineon_tricore\ssc\src\subdir.mk"
-include "MCAL\fee_infineon_tricore\ssc\src\subdir.mk"
-include "MCAL\fls_17_pmu_infineon_tricore\ssc\src\subdir.mk"
-include "MCAL\gpt_infineon_tricore\ssc\src\subdir.mk"
-include "MCAL\icu_17_gtmccu6_infineon_tricore\ssc\src\subdir.mk"
-include "MCAL\mcu_infineon_tricore\ssc\src\subdir.mk"
-include "MCAL\port_infineon_tricore\ssc\src\subdir.mk"
-include "MCAL\pwm_17_gtm_infineon_tricore\ssc\src\subdir.mk"
-include "MCAL\spi_infineon_tricore\ssc\src\subdir.mk"
-include "MCAL\tricore_general\ssc\src\subdir.mk"
-include "MCAL\wdg_17_scu_infineon_tricore\ssc\src\subdir.mk"
-include "..\makefile.defs"

PCP_FILES :=
EXT_LIBRARIES =

all : "tc234Autosar.elf"

"tc234Autosar.elf" : $(OBJ_FILES) $(EXT_LIBRARIES) ".tc234Autosar.elf.opt"
	@echo Linking to ${@F}
	@"${PRODDIR}\bin\cctc" -f ".tc234Autosar.elf.opt"

".tc234Autosar.elf.opt" : .refresh
	@argfile ".tc234Autosar.elf.opt" -o "tc234Autosar.elf" $(OBJ_FILES) $(EXT_LIBRARIES) $(PCP_FILES)  -Ctc23x --lsl-core=vtc -t -I"E:\workFiles\newAutosar\Vector\Applications\tc234Autosar" "E:\workFiles\newAutosar\Vector\Applications\tc234Autosar\newTc234.lsl" -Wl-OtxycL --no-map-file -Wl--map-file="${PROJ}.mapxml":XML -Wl-mcrfiklSmNOduQ -Wl--error-limit=42 -g --fp-model=3 -Wl--dep-file=".tc234Autosar.elf.d" -Wl--make-target="tc234Autosar.elf"
DEPENDENCY_FILES += ".tc234Autosar.elf.d"
-include $(DEPENDENCY_FILES)

$(EXT_LIBRARIES) : .dummy

GENERATED_FILES += "tc234Autosar.elf" "tc234Autosar*.sre" "tc234Autosar*.hex" "tc234Autosar.map*" "tc234Autosar.mdf" ".tc234Autosar.elf.opt" ".tc234Autosar.elf.d"
-include "..\makefile.targets"


clean : ".clean.opt"
	@echo Cleaning
	@rm -f -m ".clean.opt"

".clean.opt" : .refresh
	@argfile ".clean.opt" $(GENERATED_FILES) $(OPTIONAL_FILES)

GENERATED_FILES += ".clean.opt"
OPTIONAL_FILES +=  "*.pre" "*.lst" "*.p.o" "*.p.a"


.PHONY : .dummy .refresh
