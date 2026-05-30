/* Vector Informatik 2016 */
/* This is a template file for application callouts, necessary for Infineon TC2xx MCAL */

#include "Std_Types.h"
#include "Mcal_WdgLib.h"

void Mcal_SafeErrorHandler(uint32 ErrorType)
{
  (void)ErrorType;
}

void Appl_UnlockEndinit(void)
{
  Mcal_ResetENDINIT();
}

void Appl_LockEndinit(void)
{
  Mcal_SetENDINIT();
}

void ApplCanWaitSetMCR(void)
{
  /* Minimum stub for CAN MCR switch timing callback. */
}
