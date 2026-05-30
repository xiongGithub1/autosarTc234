This tool can be used for creating hex file with initial state pages with/without first version of data blocks with initial data.

Initial state page includes: Erased and Valid state page in FEE sector 0 and Erased state page in FEE sector 1. 
First version of data blocks includes: One version for all the data blocks with the given initial data.

Usage:
- Create the input file FEE_BLOCK_INFO.xml as per the format mentioned under the section "Format of FEE_BLOCK_INFO.xml".
- Place the tool Aurix_MC-ISAR_FEE_Generate_InitialData.pl and the input file FEE_BLOCK_INFO.xml in the same folder.
- Run the tool “Aurix_MC-ISAR_FEE_Generate_InitialData.pl” (perl script - no input parameters - tool takes “FEE_BLOCK_INFO.xml” as the input file).
- Output hex file “Aurix_MC-ISAR_FEE_InitialData.hex” will be generated in the same folder.

Format of FEE_BLOCK_INFO.xml:

Case 1: Initial state page generation (No data blocks):

<FEE_INFO>
  <FLS_TOTAL_SIZE>FlsTotalSize</FLS_TOTAL_SIZE>
</FEE_INFO>

where FlsTotalSize is the value of FLS driver configuration parameter FlsTotalSize.

Example: For FlsTotalSize of 393216 i.e., 384kB:

<FEE_INFO>
  <FLS_TOTAL_SIZE>65536</FLS_TOTAL_SIZE>
</FEE_INFO>

Case 2: Initial state page and data block generation:

<FEE_INFO>
  <FLS_TOTAL_SIZE>FlsTotalSize</FLS_TOTAL_SIZE>
  <BLOCK_CONFIGURATION>
    <BLOCK_INFO>
      <BLOCK_NUMBER>BlockNumber_x</BLOCK_NUMBER>
      <BLOCK_SIZE>BlockSize_x</BLOCK_SIZE>
      <BLOCK_DATA>BlockData_x</BLOCK_DATA>
    </BLOCK_INFO>
    <BLOCK_INFO>
      <BLOCK_NUMBER>BlockNumber_y</BLOCK_NUMBER>
      <BLOCK_SIZE>BlockSize_y</BLOCK_SIZE>
      <BLOCK_DATA>BlockData_y</BLOCK_DATA>
    </BLOCK_INFO>
    .
    .
    .
    .    
    <BLOCK_INFO>
      <BLOCK_NUMBER>BlockNumber_z</BLOCK_NUMBER>
      <BLOCK_SIZE>BlockSize_z</BLOCK_SIZE>
      <BLOCK_DATA>BlockData_z</BLOCK_DATA>
    </BLOCK_INFO>
  </BLOCK_CONFIGURATION>
</FEE_INFO>

where, 
FlsTotalSize is the value of FLS driver configuration parameter FlsTotalSize;
BlockNumber_x is the FEE logical block number in decimal;
BlockSize_x is the FEE logical block size in decimal;
BlockData_x is the FEE logical block data bytes (byte-wise) in hex without space.

Example: 
FlsTotalSize of 393216 i.e., 384kB:
3 blocks with the following configuration:
-> Block #1:
   - BlockNumber: 1
   - BlockSize: 7
   - BlockData: 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
-> Block #2:
   - BlockNumber: 2
   - BlockSize: 14
   - BlockData: 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10, 0x11, 0x12, 0x13, 0x14
-> Block #3:
   - BlockNumber: 3
   - BlockSize: 21
   - BlockData: 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x20, 0x21

<FEE_INFO>
  <FLS_TOTAL_SIZE>393216</FLS_TOTAL_SIZE>
  <BLOCK_CONFIGURATION>
    <BLOCK_INFO>
      <BLOCK_NUMBER>1</BLOCK_NUMBER>
      <BLOCK_SIZE>7</BLOCK_SIZE>
      <BLOCK_DATA>01020304050607</BLOCK_DATA>
    </BLOCK_INFO>
    <BLOCK_INFO>
      <BLOCK_NUMBER>2</BLOCK_NUMBER>
      <BLOCK_SIZE>14</BLOCK_SIZE>
      <BLOCK_DATA>0102030405060708091011121314</BLOCK_DATA>
    </BLOCK_INFO>
    <BLOCK_INFO>
      <BLOCK_NUMBER>3</BLOCK_NUMBER>
      <BLOCK_SIZE>21</BLOCK_SIZE>
      <BLOCK_DATA>010203040506070809101112131415161718192021</BLOCK_DATA>
    </BLOCK_INFO>
  </BLOCK_CONFIGURATION>
</FEE_INFO>

Note: The input (FlsTotalSize) should always be a multiple of 16kB.
Note: This tool is just for evaluation purpose (Not productive). Minimal testing is done on WIN32 machines only.


