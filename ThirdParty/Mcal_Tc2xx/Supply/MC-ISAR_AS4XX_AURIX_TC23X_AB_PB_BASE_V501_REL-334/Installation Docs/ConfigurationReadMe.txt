
-------------------------------------------------------------------------------
Configuration Read Me
-------------------------------------------------------------------------------

This file and Demo_App.txt forms the total "ReadMe" for running the Demo Application.

Only the configuration part is separated out and placed here.

-----------------------------------------------------------------------------------  
Getting started: Configuration and pointing to workspace
-----------------------------------------------------------------------------------   
1. Install your exe's as written in Installation Guide document.
2. For Aurix (TC27x) Version of Tresos Studio used is Tresos Build: Studio 13.0.0 (b120625-0327)
3. Close tresos Studio GUI, if you have already installed and running.
4. The following activity is optional the installer will copy all the plugins to tresos integration if the option was provided : 
     As an one time activity copy all the plugins provided into tresos plugin folder.We have provided a batch file to copy the same.  
   a) Goto Selectable_bin/Loadable_bin folder (C:\UserData\MC-ISAR_AS4X_Aurix_TC2x_YYYY_Vnnn\Aurix_MC-ISAR\demoapp\Selectable_bin)
   b) Run CopyTresosPlugins.bat with the following parameters
      1) Path where your tresos tool plugins are located.
      2) YES -> If License file should also be copied. 
         NO or empty -> If License need not be copied.
   c) For instance
      CopyTresosPlugins.bat c:\EB\tresos\2012a\plugins YES
5. Open tresos tool. 
6. If you want to use "Selectable" , switch the tresos workspace to respective Selectable_Cfg workspace (assuming the extraction has done in the same folder). 
7. This will take some time as Tresos will close itself and open again with the new given workspace.
8. Close the Tresos tool after you have choosen Selectable_Cfg
9. Open command prompt.
10. Run DemoAppWipe before running the DemoAppStart batch file. these files are placed in demoapp folder.
11. To Build and Run the application, refer DemoApp.txt given in the same folder.

------------------------------------------------------
Running DemoApp for other driver packages
------------------------------------------------------
1) Install BASE package and the workspace is already pointing to "Selectable_Cfg"
2) To run module (Eg: CAN) demo, Install corresponding package (COM basic for CAN)  and give the same path as "BASE" path. Refer Note below for list of modules and corresponding packages.
3) Open the Tresos tool.
4) In the Tresos tool, add the module (Eg: CAN) through module configuration option.(From the Project Right click, select Module Configuration option and "add" CAN Module)
5) Check "Load Existing" option in the available GUI, in order to use the configured xdm.
6) In the Tresos Tool, add module (Eg: CAN) reference to Ecum container under EcuMConfiguration/EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef
7) Map the selected module (Eg: CAN) reference under EcuMConfiguration/EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]/EcuMDriverInitItem/*[n]
8) Close the Tresos tool.
9) Follow step 9 of "Getting Started", for running the Batch file.

NOTE: 
1. Repeat the above sequence to run the DemoApp for other module packages.
2. Modules and corresponding packages are listed below.
   Module                   Package
   CAN, LIN, CanTrcv        COM Basic
   Fray, Eth                COM Enhanced
   Fls, FEE                 MEM
   MSC, FlsLoader           CD
   BFX, CRC                 LIB
  
------------------------------------------------------
Code generation using EPC
------------------------------------------------------
As an example for code generation using EPC, an EPC of the demoapp is provided in Aurix_MC-ISAR\demoapp\Selectable_bin\epc\Demoapp.epc location.
This EPC is applicable for TC275 controller
A batch file DemoAppEpcCodeGen.bat is provided to generate files from the EPC.

For invocation, please use the following command, in case AS version 4.0 Rev 2 code generation is desired. 
DemoAppEpcCodeGen.bat c:\EB\tresos\2012a <AS_Version>
<AS_Version> --> AS402 for AS4.0Rev2 and AS321 for AS3.2Rev1

The generated files will be available in Selectable_bin\outputdir
