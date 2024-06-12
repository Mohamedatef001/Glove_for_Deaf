/*
 * TIMER_Program.c
 *
 *  Created on: Jan 24, 2024
 *      Author: shady
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TIMER1_Private.h"
#include "TIMER1_Cfg.h"


Timer1_ClockSelect Global_prescaler;
Timer1_Output_Compare_pins OC1_GlobalValue;
void TIMER1_VoidInit(Timer1_init *Timer1_InitValues)
{
	/*select wave generation mode*/

	/*wave generation masking in TCCR1A_REG*/
	TCCR1A_REG &= 0xFC;
	/*select wave generation first two bits for TCCR1A*/
	TCCR1A_REG |=(((Timer1_InitValues->WGM)&3)<<WGM10);
	/*wave generation masking in TCCR1B_REG*/
	TCCR1B_REG &= 0XE7;
	/*select wave generation third and forth  bits for TCCR1B*/
	TCCR1B_REG |= (((Timer1_InitValues->WGM)&12)<<WGM12);

	/*select mode and output pins*/

	/*switch on output pins */
	switch(Timer1_InitValues->Timer1_0C1)
	{
	case Timer1_OC1A:
	{
		OC1_GlobalValue=Timer1_OC1A;
		TCCR1A_REG &= 0x3F;
		TCCR1A_REG |= ((Timer1_InitValues->Mode)<<COM1A0);
		break;
	}
	case Timer1_OC1B:
	{
		OC1_GlobalValue=Timer1_OC1B;
		TCCR1A_REG &= 0xCF;
		TCCR1A_REG |= ((Timer1_InitValues->Mode)<<COM1B0);
		break;
	}
	}
	/****************************************************************/

	/****************************************************************/
	/*Prescaler select*/
	Global_prescaler=(Timer1_InitValues->Prescaler);
	/****************************************************************/
}

void TIMER1_Voidstart(void)
{
	TCCR1B_REG&=0xF8;
	TCCR1B_REG|=Global_prescaler;
}

void TIMER1_VoidStop(void)
{
	TCCR1B_REG &= 0xF8;
}

void TIMER1_VoidPwmDuty(f32 duty,u16 freq)
{
	u16 x=0;
	ICR1_REG=(1000000UL/(freq*4))-1;
	x=((duty*(ICR1_REG+1))/100)-1;
	switch(OC1_GlobalValue)
	{
	case Timer1_OC1A:
	{
		OCR1A_REG=x;
		break;
	}
	case Timer1_OC1B:
	{
		OCR1B_REG=x;
		break;
	}
	}
}


