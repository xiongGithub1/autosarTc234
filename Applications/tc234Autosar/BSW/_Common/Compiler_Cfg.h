#ifndef COMPILER_CFG_WRAPPER_H
#define COMPILER_CFG_WRAPPER_H

#include "_Compiler_Cfg.h"

/* Cdd_Com generated callbacks expect these symbols. Map them to CDD defaults. */
#ifndef CDD_COM_CODE
#define CDD_COM_CODE _CDD_CODE
#endif

#ifndef CDD_COM_APPL_DATA
#define CDD_COM_APPL_DATA _CDD_APPL_DATA
#endif

/* Cdd_Tp generated callbacks expect these symbols. Map them to CDD defaults. */
#ifndef CDD_TP_CODE
#define CDD_TP_CODE _CDD_CODE
#endif

#ifndef CDD_TP_APPL_DATA
#define CDD_TP_APPL_DATA _CDD_APPL_DATA
#endif

#endif
