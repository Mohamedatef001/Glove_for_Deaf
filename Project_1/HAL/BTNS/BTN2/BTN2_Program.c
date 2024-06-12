/* * BTN0_Program.c
 *
 *  Created on: Feb 22, 2024
 *      Author: newwo
 */


#include "BTN2_Cfg.h"
#include "BTN2_Interface.h"
#include "DIO_cfg.h"
#include "STD_TYPES.h"


void BTN2_Initialize(void)
{
	DIO_VoidSetPinDirection(B2,B2_INP);
}
u16 BTN2_Read(void)
{
	u16 BTN2_Val = BTN2_NPressed;
	BTN2_Val = DIO_U8GetPinValue(B2);
	return BTN2_Val;
}

