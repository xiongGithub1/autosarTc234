rem ****************************************************************************************************
rem     TODO:   Choose your Compiler - The compiler ini file needs to be located in the A2L_PATH.
rem             Possible values are (it will be concatenated to MASTER_*.INI):
rem             VISUALSTUDIO
rem             GREENHILLS
rem             TASKING
rem             DIAB
rem ****************************************************************************************************
set COMPILER_TYPE=TASKING

rem ****************************************************************************************************
rem     TODO:   Set the path to the directory of your ASAP2Updater.exe
rem             ASAP2Updater.exe is needed to Update the address information in your A2L File
rem             ASAP2 Updater is part of the ASAP2 Tool Set
rem             Possible locations for default installations:
rem              - "C:\Program Files (x86)\Vector CANwin 8.2\ASAP2Updater"
rem              - "C:\Program Files (x86)\Vector CANwin 8.5\ASAP2Updater\Exec"
rem              - "C:\Program Files (x86)\Vector CANwin 9.0\ASAP2Updater\Exec"
rem ****************************************************************************************************
set ASAP2UPDATEREXE_PATH="C:\Program Files (x86)\Vector CANwin 8.5\ASAP2Updater\Exec"

rem ****************************************************************************************************
rem     TODO:   Set the path to the directory of your Master.a2l file
rem             Master.a2l file needs to be adapted first
rem             Master.a2l file needs to be named exactly Master.a2l
rem ****************************************************************************************************
set A2L_PATH=%~dp0

rem ****************************************************************************************************
rem     TODO:   Set the path to used map / elf file of your compiled project
rem             map / elf file is needed for the Update of the Address information within the Master.a2l
rem             Exact path to the map / elf file is needed not only to the directory
rem ****************************************************************************************************
set MAPFILE_PATH_AND_NAME=%~dp0\Appl\TestSuit.elf

rem ****************************************************************************************************
rem     TODO:   Set the path to the directory where the A2L_AdressUpdate.log log file should be written
rem ****************************************************************************************************
set A2L_LOG_PATH_AND_NAME=%~dp0\A2L_AdressUpdate.log

