#!/usr/bin/perl
use XML::Simple;

$out_file=">Aurix_MC-ISAR_FEE_InitialData.hex";
$in_file="FEE_BLOCK_INFO.xml";

$xml = new XML::Simple;

@StatePageInfoS0 = (
"02000004AF004B",
"20000000591E000001000000000000000000000000000000000000000000000000000000",
"200020000000000000000000000000000000000000000000000000000000000000000000",
"200040000000000000000000000000000000000000000000000000000000000000000000",
"200060000000000000000000000000000000000000000000000000003AF5AFAFF5F5AFAF",
"200080000000000000000000000000000000000000000000000000000000000000000000",
"2000A0000000000000000000000000000000000000000000000000000000000000000000",
"2000C0000000000000000000000000000000000000000000000000000000000000000000",
"2000E0000000000000000000000000000000000000000000000000000000000000000000",
"200100000000000000000000000000000000000000000000000000000000000000000000",
"200120000000000000000000000000000000000000000000000000000000000000000000",
"200140000000000000000000000000000000000000000000000000000000000000000000",
"200160000000000000000000000000000000000000000000000000000000000000000000",
"200180000000000000000000000000000000000000000000000000000000000000000000",
"2001A0000000000000000000000000000000000000000000000000000000000000000000",
"2001C0000000000000000000000000000000000000000000000000000000000000000000",
"2001E0000000000000000000000000000000000000000000000000000000000000000000",
"2002000059D1000002000000000000000000000000000000000000000000000000000000",
"200220000000000000000000000000000000000000000000000000000000000000000000",
"200240000000000000000000000000000000000000000000000000000000000000000000",
"200260000000000000000000000000000000000000000000000000003AF5AFAFF5F5AFAF",
"200280000000000000000000000000000000000000000000000000000000000000000000",
"2002A0000000000000000000000000000000000000000000000000000000000000000000",
"2002C0000000000000000000000000000000000000000000000000000000000000000000",
"2002E0000000000000000000000000000000000000000000000000000000000000000000",
"200300000000000000000000000000000000000000000000000000000000000000000000",
"200320000000000000000000000000000000000000000000000000000000000000000000",
"200340000000000000000000000000000000000000000000000000000000000000000000",
"200360000000000000000000000000000000000000000000000000000000000000000000",
"200380000000000000000000000000000000000000000000000000000000000000000000",
"2003A0000000000000000000000000000000000000000000000000000000000000000000",
"2003C0000000000000000000000000000000000000000000000000000000000000000000",
"2003E0000000000000000000000000000000000000000000000000000000000000000000");

@StatePageInfoS1 = (
"00591E000003000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000003AF5AFAFF5F5AFAF",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000");

$HexFileEnd = "00000001FF";

open(OUT_FILE,$out_file);

# Print Sector 0 State Pages

foreach (@StatePageInfoS0)
{
  @LineData = unpack '(a2)*', $_;
  PrintHexLine();
}

# Read Block Information and print Block data

$PhysicalAddress = 1024;
$xml_input = $xml->XMLin($in_file);

foreach (@{$xml_input->{BLOCK_CONFIGURATION}->{BLOCK_INFO}})
{
  $Data = $_->{BLOCK_DATA};
  #Remove white spaces, if any.
  $Data =~ s/\s+//g;
  $BlockSize = $_->{BLOCK_SIZE};
  $BlockNumber = $_->{BLOCK_NUMBER};
  $BlockPageCount = GetBlockPageCount();
  PrintBlockData();
}

# Print Sector 0 State Pages

$PhysicalAddress = $xml_input->{FLS_TOTAL_SIZE}/2;

foreach (@StatePageInfoS1)
{
  CheckAndPrintSegmentAddress();
  $BlockData = "20";
  $BlockData = $BlockData.GetHexByte(($PhysicalAddress >> 8)%256).GetHexByte($PhysicalAddress % 256);
  $BlockData = $BlockData.$_;
  $PhysicalAddress+=32;

  @LineData = unpack '(a2)*', $BlockData;
  PrintHexLine();
}

# Print End of Hex file

@LineData = unpack '(a2)*', $HexFileEnd;
PrintHexLine();

# Subroutine for printing Individual Block data

sub PrintBlockData
{
  my $BlockData;
  my $index;
  my $BlockSizeTemp;

  # Print Block Header Page

  $BlockData = "08";
  CheckAndPrintSegmentAddress();
  $BlockData = $BlockData.GetHexByte($PhysicalAddress >> 8).GetHexByte($PhysicalAddress % 256);
  $BlockData = $BlockData."00A3";
  $BlockData = $BlockData.GetHexByte($BlockNumber % 256).GetHexByte($BlockNumber >> 8);
  $BlockData = $BlockData."010000";
  $BlockData = $BlockData.GetHexByte($BlockPageCount % 256).GetHexByte(($BlockPageCount>>8)|128);
  @LineData = unpack '(a2)*', $BlockData;
  PrintHexLine();
  $PhysicalAddress+=8;

  # Print Block Data Pages

  my @BlockDataTemp = unpack '(a14)*', $Data;
  for($index=0;$index<($BlockPageCount-1);$index++)
  {
    $BlockData = "08";
    CheckAndPrintSegmentAddress();
    $BlockData = $BlockData.GetHexByte($PhysicalAddress >> 8).GetHexByte($PhysicalAddress % 256);
    $BlockData = $BlockData."009C";
    $BlockData = $BlockData.$BlockDataTemp[$index];
    if($index==($BlockPageCount-2))
    {
      for($BlockSizeTemp = $BlockSize;($BlockSizeTemp%7)!=0;$BlockSizeTemp++)
      {
        $BlockData = $BlockData."FF";
      }
    }
    @LineData = unpack '(a2)*', $BlockData;
    PrintHexLine();
    $PhysicalAddress+=8;
  }

  # Print Block Marker Page

  $BlockData = "08";
  CheckAndPrintSegmentAddress();
  $BlockData = $BlockData.GetHexByte($PhysicalAddress >> 8).GetHexByte($PhysicalAddress % 256);
  $BlockData = $BlockData."0065AFF5F5";
  $BlockData = $BlockData.GetHexByte($BlockNumber % 256).GetHexByte($BlockNumber >> 8);
  $BlockData = $BlockData.GetHexByte($BlockPageCount % 256).GetHexByte(($BlockPageCount>>8)|128);
  @LineData = unpack '(a2)*', $BlockData;
  PrintHexLine();
  $PhysicalAddress+=8;
}

# Checks the current physical address; Segment address will be printed if it is 0xAFXX0000.

sub CheckAndPrintSegmentAddress
{
  if($PhysicalAddress % 65536 == 0)
  {
    my $TempAddress = "02000004AF";
    my $TempPhysicalAddress = $PhysicalAddress;
    my $SegmentAddress = 0;

    while( $TempPhysicalAddress > 65535 )
    {
      $TempPhysicalAddress -= 65536;
      $SegmentAddress++;
    }
    $TempAddress = $TempAddress.GetHexByte($SegmentAddress);
    @LineData = unpack '(a2)*', $TempAddress;
    PrintHexLine();
  }
}

# Returns DFlash Page count for a given Block size --> Number of data pages + 1.

sub GetBlockPageCount
{
  my $BlockSizeTemp = $BlockSize;
  my $BlkPageCount = 1;
  
  while ($BlockSizeTemp >= 7)
  {
    $BlkPageCount++;
    $BlockSizeTemp -= 7;
  }

  if ($BlockSizeTemp > 0)
  {
    $BlkPageCount++;
  }

  return ($BlkPageCount);
}

# Convert decimal value to HEX value (byte)

sub GetHexByte
{
  my @list = @_;
  my $LowerNibble = $list[0];
  my $HexValue = 0;

  while( $LowerNibble > 15 )
  {
    $LowerNibble -= 16;
    $HexValue++;
  }

  if($HexValue > 9)
  {
    $HexValue = GetHexNibble($HexValue);
  }

  if($LowerNibble < 10)
  { 
    $HexValue = $HexValue.$LowerNibble;
  }
  else
  {
    $HexValue = $HexValue.GetHexNibble($LowerNibble);
  }

  return $HexValue;
}

# Convert decimal value to HEX value (nibble)

sub GetHexNibble
{
  my @list = @_;
  my $HexValue = $list[0];

  if ($HexValue == 10)    { $HexValue = "A"; }
  elsif ($HexValue == 11) { $HexValue = "B"; }
  elsif ($HexValue == 12) { $HexValue = "C"; }
  elsif ($HexValue == 13) { $HexValue = "D"; }
  elsif ($HexValue == 14) { $HexValue = "E"; }
  elsif ($HexValue == 15) { $HexValue = "F"; }

  return $HexValue;
}

# Calculate checksum and print a line of HEX file

sub PrintHexLine
{
  my $checksum = 0;
  print OUT_FILE ":";

  for($index=0;$index<((hex $LineData[0])+4);$index++)
  {
    print OUT_FILE "${LineData[${index}]}";
  }

  for($index=0;$index<((hex $LineData[0])+4);$index++)
  {
    $checksum += hex $LineData[$index];
  }

  $checksum = $checksum % 256;
  if($checksum != 0)
  {
    $checksum = 256 - $checksum;
  }

  $checksum = GetHexByte($checksum);

  print OUT_FILE "${checksum}\n";
}

close(OUT_FILE);

