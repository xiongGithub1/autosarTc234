@echo off

if "%1"=="" echo You can call "%0 --nopause" to skip the pause at the end.

call "%~dp0\Config_A2LUpdater.bat"

set A2L_INI_FILE_NAME=MASTER_%COMPILER_TYPE%.INI

call %ASAP2UPDATEREXE_PATH%\ASAP2Updater.exe -I "%A2L_PATH%\Master.a2l" -A %MAPFILE_PATH_AND_NAME% -T "%A2L_PATH%\%A2L_INI_FILE_NAME%" -O "%A2L_PATH%\Master_Updated.a2l" -L %A2L_LOG_PATH_AND_NAME%

echo:
if %errorlevel% EQU 0 echo A2L update finished successfully (No errors, no warnings)
if %errorlevel% EQU 1 echo A2L update finished (No errors, but warnings in log file)
if %errorlevel% EQU 2 echo A2L update failed (Error messages in log file)
if %errorlevel% EQU 3 echo A2L update failed (No license available)
if %errorlevel% EQU 100 echo A2L update finished (No errors, but warnings in log file)
if %errorlevel% GTR 3 if %errorlevel% NEQ 100 echo A2L update failed (Exit code %errorlevel%), see Manual.pdf in %ASAP2UPDATEREXE_PATH%
if %errorlevel% GTR 0 echo Find further details in %A2L_LOG_PATH_AND_NAME% 

if "%1"=="--nopause" goto:eof
pause

