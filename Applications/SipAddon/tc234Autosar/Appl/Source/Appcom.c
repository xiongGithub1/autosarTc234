/*
 * Appcom.c
 *
 *  Created on: 2026Äê6ÔÂ16ÈÕ
 *      Author: Qxiong
 */



#include "Rte_Appcom.h"



boolean RearInteriorLightSta=0;

FUNC(void, AppCom_CODE) RWsignal(void)
{

	Rte_Read_AppCom_Pisignal_Rx1bit_RearInteriorLightState_RearInteriorLightState(&RearInteriorLightSta);
}
