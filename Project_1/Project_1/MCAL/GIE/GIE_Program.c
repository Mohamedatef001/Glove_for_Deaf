/*
 * GIE_Program.c
 *
 *  Created on: Feb 24, 2023
 *      Author: shady
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Private.h"

#include"GIE_Private.h"
#include"GIE_init.h"

void M_GIE_VoidEnable(void)
{
	SET_BIT(SREG,7);
}
void M_GIE_VoidDisable(void)
{
	CLR_BIT(SREG,7);
}

