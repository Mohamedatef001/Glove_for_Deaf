/*
 * DC_MOTOR_Program.c
 *
 *  Created on: Dec 30, 2023
 *      Author: shady
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DC_MOTOR_Private.h"
#include"DC_MOTOR_Cfg.h"
#include"DIO_Interface.h"
#include"TIMER0_Interface.h"


void DC_VoidDCMOTORInit()
{
	DIO_VoidSetPinDirection(DIO_PIND4,INPUT); //this pin will be input
	DIO_VoidSetPinDirection(DIO_PIND5,INPUT); //this pin will be input
	DIO_VoidSetPinDirection(DIO_PINC3,OUTPUT);
	DIO_VoidSetPinDirection(DIO_PINC4,OUTPUT);
	DIO_VoidSetPinDirection(DIO_PINC5,OUTPUT);
	DIO_VoidSetPinDirection(DIO_PINC6,OUTPUT);
	DIO_VoidSetPinDirection(DIO_PINB3,OUTPUT);  //when i want to control the speed through pwm on the enable pin
	TIMER0_VoidInit(FAST_PWM,prescalar_64,Clear_OC0);
	TIMER0_Voidstart();
}

void DC_VoidMOTORON(u8 DutyCycle,DC_MOTORDIRECTION MOTORDIRECTION)
{

	DIO_VoidSetPinValue(DIO_PIND4,DIO_HIGH);
	DIO_VoidSetPinValue(DIO_PIND5,DIO_HIGH);

	if(MOTORDIRECTION==DC_FORWARD)
	{
		DIO_VoidSetPinValue(DIO_PINC3,DIO_HIGH);
		DIO_VoidSetPinValue(DIO_PINC4,DIO_LOW);
	}else
	{
		DIO_VoidSetPinValue(DIO_PINC3,DIO_LOW);
		DIO_VoidSetPinValue(DIO_PINC4,DIO_HIGH);
	}

	TIMER_VoidPwmDuty(DutyCycle); //if i want to control the speed

}

void DC_VoidDCMOTORStop(void)
{
	TIMER_VoidPwmDuty(0);
}
