/* * BTN0_Program.c
 *
 *  Created on: Feb 22, 2024
 *      Author: newwo
 */

#include "BTN0_Interface.h"
#include"DIO_cfg.h"
#include "STD_TYPES.h"
#include "BTN0_Cfg.h"


void BTN0_Initialize(void)
{
	DIO_VoidSetPinDirection(B0,B0_INP);
}
u16 BTN0_Read(void)
{
	u16 BTN0_Val = BTN0_NPressed;
	BTN0_Val = DIO_U8GetPinValue(B0);
	return BTN0_Val;
}

