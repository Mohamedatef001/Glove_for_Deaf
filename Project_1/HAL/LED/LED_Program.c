/*
 * LED_Program.c
 *
 *  Created on: Feb 25, 2024
 *      Author: newwo
 */

#include "LED_Interface.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"

void LED_ON(u16 number) {
	if (number == 0) {
		DIO_VoidSetPinValue(LED0, DIO_HIGH);
	}
	if (number == 1) {
		DIO_VoidSetPinValue(LED1, DIO_HIGH);
	}
	if (number == 2) {
		DIO_VoidSetPinValue(LED2, DIO_HIGH);
	}
}
void LED_OFF(u16 num) {
	if (num == 0) {
		DIO_VoidSetPinValue(LED0, DIO_LOW);
	}
	if (num == 1) {
		DIO_VoidSetPinValue(LED1, DIO_LOW);
	}
	if (num == 2) {
		DIO_VoidSetPinValue(LED2, DIO_LOW);
	}
}

void LED_TOGGLE(u16 number) {

	if (number == 0) {
		TOGGLE_BIT(PORTC_REG, 2);
	}
	if (number == 1) {
		TOGGLE_BIT(PORTC_REG, 7);
	}
	if (number == 2) {
		TOGGLE_BIT(PORTD_REG, 3);
	}
}
