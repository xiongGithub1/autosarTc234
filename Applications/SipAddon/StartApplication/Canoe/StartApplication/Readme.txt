*****************************************************************************
* Usage of CANoe DLLs in the start application DIAG use case                *
*                                                                           *
* The start application DIAG use case requires the osek_tp.dll for          *
* handling CanTp and/or FlexRayTPISO.DLL for handling FrTpIso.              *
*                                                                           *
*                                        2016-07-27, Vector Informatik GmbH *
*****************************************************************************

StartApplication.cfg
  If the configuration cannot find the required DLLs during loading, please
  provide the path to the needed DLL from your CANoe Exec folder, for
  example: C:\Program Files (x86)\Vector CANwin 8.5\Exec32\osek_tp.dll

  Those DLLs are typically referenced by the node "PanelAbstraction" which
  handles the bus-specific logic in the CAPL file "CanoePanelAbstraction.can".
  I.e., if your DIAG use case somehow does not work, check if the
  referenced DLL is the one from your CANoe Exec folder.


*****************************************************************************
* Usage of CANoe SCC AddOn in the start application SCC use case            *
*                                                                           *
* The start application SCC use case requires the SCC_ChargePoint.dll for   *
* handling the Electric Vehicle Supply Equipment.                           *
*                                                                           *
*                                        2017-06-20, Vector Informatik GmbH *
*****************************************************************************

StartApplication.cfg
  If the configuration cannot find the required DLL during loading, please
  provide the path to the needed DLL from your CANoe Exec folder, for
  example: C:\Program Files (x86)\Vector CANwin 8.5\Exec32\SCC_ChargePoint.dll

  This DLL is typically referenced by the node "PanelAbstraction" which
  handles the bus-specific logic in the CAPL file "CanoePanelAbstraction.can".
  I.e., if your SCC use case somehow does not work, check if the
  referenced DLL is available.

  The AddOn can be downloaded from the Vector homepage:
  https://vector.com > Downloads > select "Electric Vehicles" within the
  "Products and Topics" category. Afterwards select "Add-Ons/Freeware" within
  the "Categories" tab. Finally click on the "show result" button and download
  the package as 32bit or 64bit version according to your requirements.


*****************************************************************************
* Usage of SecOC in the start application COM use case                      *
*                                                                           *
* The start application COM use case with SecOC requires importing the      *
* StartApplicationSecOCProfile.xml into your Vector Security Manager        *
* and the SecMgrCANoeClient.dll for the SecOC handling.                     *
*                                                                           *
*                                        2017-10-04, Vector Informatik GmbH *
*****************************************************************************

CANoe Version: SecOC is only available for CANoe 10 SP3 and later!

Vector Security Manager
  Open the Vector Security Manager from the CANoe ribbon "Tools" and import
  the file "Configuration\StartApplicationSecOCProfile.xml" located in the
  same path as your "StartApplication.cfg".

StartApplication.cfg
  Check the security configuration of your CANoe configuration: Therefore go
  to the ribbon "Simulation" and open the security configuration.
  Ensure that the previously imported security profile "StartApplicationSecOC"
  is assigned to all channels using SecOC.

  If the configuration cannot find the required DLL during loading, please
  provide the path to the needed DLL from your CANoe Exec folder, e.g.:
  "C:\Program Files (x86)\Vector CANwin 10.0\Exec32\SecMgrCANoeClient.dll"

  This DLL must be referenced by the node which handles the SecOC specific
  part in the CAPL file "StartApplicationSecOCMgr.can".
  I.e., if SecOC somehow does not work, check if the referenced DLL is
  available.
