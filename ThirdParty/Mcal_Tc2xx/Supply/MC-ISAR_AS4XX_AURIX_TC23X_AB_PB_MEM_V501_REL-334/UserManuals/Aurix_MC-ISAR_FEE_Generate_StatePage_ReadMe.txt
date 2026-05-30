This is a tool for creating hex file with initial state pages i.e., Erased and Valid state page in first FEE sector and Erased state page in the second FEE sector. 
Total flash size used for EEPROM emulation (FlsTotalSize) is the input parameter to this tool.

Steps:
1. Run Aurix_MC-ISAR_FEE_Generate_StatePage.exe
2. Provide the value of FlsTotalSize as input (in KB, in decimal)
   Eg. For FlsTotalSize of 384kB, the input shall be 384
3. Output file InitialStatePage.hex will be generated in hex format

Note: The input (FlsTotalSize) should always be a multiple of 16kB.
Note: This tool is just for evaluation purpose (Not productive). Minimal testing is done on WIN32 machines only.


