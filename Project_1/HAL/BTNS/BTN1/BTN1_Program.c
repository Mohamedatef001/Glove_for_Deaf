/* * BTN0_Program.c
 *
 *  Created on: Feb 22, 2024
 *      Author: newwo
 */


#include <BTNS/BTN1/BTN1_Cfg.h>
#include <BTNS/BTN1/BTN1_Interface.h>
#include"DIO_cfg.h"
#include "STD_TYPES.h"


void BTN1_Initialize(void)
{
	DIO_VoidSetPinDirection(B1,B1_INP);
}
u16 BTN1_Read(void)
{
	u16 BTN1_Val = BTN1_NPressed;
	BTN1_Val = DIO_U8GetPinValue(B1);
	return BTN1_Val;
}

