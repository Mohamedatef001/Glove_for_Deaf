/*
 * KEYPAD_Program.c
 *
 *  Created on: Nov 18, 2023
 *      Author: shady
 */
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "KEYPAD_Private.h"
#include "KEYPAD_cfg.h"
#include "util/delay.h"

extern u8 KEYARR[ROWS][COLUMNS];

void KEYPAD_VoidInit(void)
{
	DIO_VoidSetPinDirection(DIO_PINB4,OUTPUT);
	DIO_VoidSetPinDirection(DIO_PINB5,OUTPUT);
	DIO_VoidSetPinDirection(DIO_PINB6,OUTPUT);
	DIO_VoidSetPinDirection(DIO_PINB7,OUTPUT);
	DIO_VoidSetPinValue(DIO_PINB4,DIO_HIGH);
	DIO_VoidSetPinValue(DIO_PINB5,DIO_HIGH);
	DIO_VoidSetPinValue(DIO_PINB6,DIO_HIGH);
	DIO_VoidSetPinValue(DIO_PINB7,DIO_HIGH);
	DIO_VoidSetPortDirection(PORTC,0x00); //set the input pins
	DIO_VoidSetPortValue(PORTC,0x78); // active the Pull up resistance
}

u8 KEYPAD_U8GetPressedKey(void)
{
	u8 Row,Col,key=UNPRESSED_KEY;

	for(Row=0;Row<ROWS;Row++)
	{
		DIO_VoidSetPinValue((FIRST_OUTPUT+Row),DIO_LOW);
		for(Col=0;Col<COLUMNS;Col++)
		{
			if(DIO_U8GetPinValue((FIRST_INPUT+Col))==0)
			{
				key=KEYARR[Row][Col];
				while(DIO_U8GetPinValue((FIRST_INPUT+Col))==0);
				_delay_ms(50);
			}
		}
		DIO_VoidSetPinValue((FIRST_OUTPUT+Row),DIO_HIGH);
	}
	return key;
}





