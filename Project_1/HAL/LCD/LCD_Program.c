/*
 * LCD_Program.c
 *
 *  Created on: Nov 17, 2023
 *      Author: shady
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "LCD_Private.h"
#include "LCD_cfg.h"

const u8 heartSymbol[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000,
    0b00000
};

static void LCD_VoidLatch(u8 Copy_byte) {
#if LCD_MODE == LCD_8_bit
	DIO_VoidSetPortValue(LCD_PORT,Copy_byte);
	DIO_VoidSetPinValue(En,DIO_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(En,DIO_LOW);
#elif LCD_MODE == LCD_4_bit
//	DIO_VoidSetPinValue(D7,GET_BIT(Copy_byte,7));
//	DIO_VoidSetPinValue(D6,GET_BIT(Copy_byte,6));
//	DIO_VoidSetPinValue(D5,GET_BIT(Copy_byte,5));
//	DIO_VoidSetPinValue(D4,GET_BIT(Copy_byte,4));
	PORTD_REG = (PORTD_REG & 0x0F) | ((Copy_byte) & 0xF0);
	DIO_VoidSetPinValue(En, DIO_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(En, DIO_LOW);
//	DIO_VoidSetPinValue(D7,GET_BIT(Copy_byte,3));
//	DIO_VoidSetPinValue(D6,GET_BIT(Copy_byte,2));
//	DIO_VoidSetPinValue(D5,GET_BIT(Copy_byte,1));
//	DIO_VoidSetPinValue(D4,GET_BIT(Copy_byte,0));
	PORTD_REG = (PORTD_REG & 0x0F) | ((Copy_byte & 0x0F) << 4);
	DIO_VoidSetPinValue(En, DIO_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(En, DIO_LOW);
#endif
}

static void LCD_VoidWriteInst(u8 ins) {
	DIO_VoidSetPinValue(RS, DIO_LOW);
	DIO_VoidSetPinValue(RW, DIO_LOW);
	LCD_VoidLatch(ins);

}
void LCD_VoidInit(void) {
	DIO_VoidSetPinDirection(En, OUTPUT);
	DIO_VoidSetPinDirection(RS, OUTPUT);
	DIO_VoidSetPinDirection(RW, OUTPUT);

#if LCD_MODE == LCD_8_bit
	DIO_VoidSetPortDirection(PORTD,0xFF);
	_delay_ms(50);
	LCD_VoidWriteInst(0x38);
	_delay_ms(1);
	LCD_VoidWriteInst(0x0E);
	_delay_ms(1);
	LCD_VoidWriteInst(0x01);
	_delay_ms(2);
	LCD_VoidWriteInst(0x06);
#elif LCD_MODE == LCD_4_bit
	DIO_VoidSetPinDirection(D4, OUTPUT);
	DIO_VoidSetPinDirection(D5, OUTPUT);
	DIO_VoidSetPinDirection(D6, OUTPUT);
	DIO_VoidSetPinDirection(D7, OUTPUT);
	_delay_ms(50);
	LCD_VoidWriteInst(0x33);
	LCD_VoidWriteInst(0x32);
	LCD_VoidWriteInst(0x28);
	_delay_ms(1);
	LCD_VoidWriteInst(0x0F);
	_delay_ms(1);
	LCD_VoidWriteInst(0x01);
	_delay_ms(2);
	LCD_VoidWriteInst(0x06);
#endif

}
void LCD_VoidWriteData(u8 LCD_Char) {
	DIO_VoidSetPinValue(RS, DIO_HIGH);
	DIO_VoidSetPinValue(RW, DIO_LOW);
	LCD_VoidLatch(LCD_Char);
}

void LCD_VoidWriteString(u8 *str) {
	for (u8 i = 0; str[i]; i++) {
		LCD_VoidWriteData(str[i]);
		_delay_ms(100);

	}
}

void LCD_VoidWriteNumber(u32 num) {
	u32 copy_num = num, Rev;
	u8 digit = 0, c = 0;
	while (copy_num != 0) {
		c++;
		copy_num = copy_num / 10;
	}
	while (num > 0) {
		Rev = Rev * 10 + num % 10;
		num = num / 10;
	}
	while (c != 0) {
		digit = Rev % 10;
		Rev = Rev / 10;
		LCD_VoidWriteData(digit + '0');
		c--;
	}

}

void LCD_VoidClearScreen(void) {
	LCD_VoidWriteInst(CLR_Screen);
}

void LCD_VoidSetCursor(u8 row, u8 col) {
	if (row == 1) {
		LCD_VoidWriteInst(0x80 + col);
	} else if (row == 2) {
		LCD_VoidWriteInst(0x80 + 0x40 + col);
	}
}
void LCD_VoidDisplayHeart(void) {
    // Load the heart symbol into CGRAM
    LCD_VoidWriteInst(0x40); // Start CGRAM address for custom characters
    for (u8 i = 0; i < 8; i++) {
        LCD_VoidWriteData(heartSymbol[i]);
    }
    LCD_VoidSetCursor(1, 2);
}
void displayMessage(const char* message) {
    LCD_VoidClearScreen();
    LCD_VoidWriteString(message);
}
