/*
 * 7Segment_Program.c
 *
 *  Created on: Feb 18, 2024
 *      Author: newwo
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "7Segment_Interface.h"
#include "7Segment_cfg.h"
#include "DIO_Private.h"

void Segment_Display(char num) {
	char SegmentArr[10] = { 0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70,
			0x80, 0x90 };
	if (num <= 9) {
		DIO_VoidSetPortValue(PORTA, SegmentArr[num]);

	}

}
void SEVSEG_Display(u32 number)
{
	u32 units = number % 10;
	u32 tens = number / 10;
	PORTA_REG = units << 4;
	DIO_VoidSetPinValue(EN1, DIO_HIGH);
	DIO_VoidSetPinValue(EN2, DIO_LOW);
	_delay_ms(10);
	PORTA_REG = tens <<4;
	DIO_VoidSetPinValue(EN2, DIO_HIGH);
	DIO_VoidSetPinValue(EN1, DIO_LOW);
	_delay_ms(10);
}
//void SEVENSEGMENT_Initialize(void)
//{
//	DIO_VoidSetPinDirection(DIO_PINA4,OUTPUT);
//	DIO_VoidSetPinDirection(DIO_PINA5,OUTPUT);
//	DIO_VoidSetPinDirection(DIO_PINA6,OUTPUT);
//	DIO_VoidSetPinDirection(DIO_PINA7,OUTPUT);
//
//	DIO_VoidSetPinDirection(DIO_PINB1,OUTPUT);
//	DIO_VoidSetPinDirection(DIO_PINB2,OUTPUT);
//	DIO_VoidSetPinDirection(DIO_PINB3,OUTPUT);
//
//}
//void SEVENSEGMENT_Enable1(void)
//{
//	DIO_VoidSetPinValue(DIO_PINB1,DIO_HIGH);
//}
//void SEVENSEGMENT_Disable1(void)
//{
//	DIO_VoidSetPinValue(DIO_PINB1,DIO_LOW);
//}
//void SEVENSEGMENT_Enable2(void)
//{
//	DIO_VoidSetPinValue(DIO_PINB2,DIO_HIGH);
//}
//void SEVENSEGMENT_Disable2(void)
//{
//	DIO_VoidSetPinValue(DIO_PINB2,DIO_LOW);
//}
//void SEVENSEGMENT_DIP_Enable(void)
//{
//	DIO_VoidSetPinValue(DIO_PINB3,DIO_HIGH);
//}
//void SEVENSEGMENT_DIP_Disable(void)
//{
//	DIO_VoidSetPinValue(DIO_PINB3,DIO_HIGH);
//}
//
//
//void SEVENSEGMENT_Display_Number(u16 number)
//{
//	u16 units = number % 10;
//	u16 tenth = number / 10;
//	PORTA_REG = units << 4;
//	SEVENSEGMENT_Enable1();
//	SEVENSEGMENT_Disable2();
//	_delay_ms(10);
//	PORTA_REG = tenth << 4;
//	SEVENSEGMENT_Enable2();
//	SEVENSEGMENT_Disable1();
//	_delay_ms(10);
//}
