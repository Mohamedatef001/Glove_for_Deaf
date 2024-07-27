/*
 * DIO_program.c
 *
 *  Created on: Feb 9, 2024
 *      Author: newwo
 */

#include <DIO_Private.h>
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_cfg.h"

void DIO_VoidSetPinDirection(PIN_NUM PIN, u8 Value) {
	if (Value == OUTPUT) /*OUTPUT*/
	{
		switch (PIN / 8) {
		case PORTA:
			SET_BIT(DDRA_REG, (PIN % 8));
			break;
		case PORTB:
			SET_BIT(DDRB_REG, (PIN % 8));
			break;
		case PORTC:
			SET_BIT(DDRC_REG, (PIN % 8));
			break;
		case PORTD:
			SET_BIT(DDRD_REG, (PIN % 8));
			break;
		}

	} else if (Value == INPUT) /*input*/
	{
		switch (PIN / 8) {
		case PORTA:
			CLR_BIT(DDRA_REG, (PIN % 8));
			break;
		case PORTB:
			CLR_BIT(DDRB_REG, (PIN % 8));
			break;
		case PORTC:
			CLR_BIT(DDRC_REG, (PIN % 8));
			break;
		case PORTD:
			CLR_BIT(DDRD_REG, (PIN % 8));
			break;
		}

	}

}

void DIO_VoidSetPinValue(PIN_NUM PIN, u8 Value) {
	if (Value == DIO_HIGH) /*OUTPUT*/
	{
		switch (PIN / 8) {
		case PORTA:
			SET_BIT(PORTA_REG, (PIN % 8));
			break;
		case PORTB:
			SET_BIT(PORTB_REG, (PIN % 8));
			break;
		case PORTC:
			SET_BIT(PORTC_REG, (PIN % 8));
			break;
		case PORTD:
			SET_BIT(PORTD_REG, (PIN % 8));
			break;
		}

	} else if (Value == DIO_LOW) /*input*/
	{
		switch (PIN / 8) {
		case PORTA:
			CLR_BIT(PORTA_REG, (PIN % 8));
			break;
		case PORTB:
			CLR_BIT(PORTB_REG, (PIN % 8));
			break;
		case PORTC:
			CLR_BIT(PORTC_REG, (PIN % 8));
			break;
		case PORTD:
			CLR_BIT(PORTD_REG, (PIN % 8));
			break;
		}

	}

}

void DIO_VoidSetPortValue(u8 PORT, u8 Value) {
	switch (PORT) {
	case PORTA:
		PORTA_REG = Value;
		break;
	case PORTB:
		PORTB_REG = Value;
		break;
	case PORTC:
		PORTC_REG = Value;
		break;
	case PORTD:
		PORTD_REG = Value;
		break;
	}
}

void DIO_VoidSetPortDirection(u8 PORT, u8 Value) {
	switch (PORT) {
	case PORTA:
		DDRA_REG = Value;
		break;
	case PORTB:
		DDRB_REG = Value;
		break;
	case PORTC:
		DDRC_REG = Value;
		break;
	case PORTD:
		DDRD_REG = Value;
		break;
	}
}

u8 DIO_U8GetPinValue(PIN_NUM PIN) {
	u8 value = 0;
	switch (PIN / 8) {
	case PORTA:
		value = GET_BIT(PINA_REG, (PIN % 8));
		break;
	case PORTB:
		value = GET_BIT(PINB_REG, (PIN % 8));
		break;
	case PORTC:
		value = GET_BIT(PINC_REG, (PIN % 8));
		break;
	case PORTD:
		value = GET_BIT(PIND_REG, (PIN % 8));
		break;
	}
	return value;
}
void DIO_SetPin_PULLUP(PIN_NUM PIN)
{
	switch (PIN / 8)
	{
	case PORTA:
		SET_BIT(PORTA_REG, (PIN % 8));
		break;
	case PORTB:
		SET_BIT(PORTB_REG, (PIN % 8));
		break;
	case PORTC:
		SET_BIT(PORTC_REG, (PIN % 8));
		break;
	case PORTD:
		SET_BIT(PORTD_REG, (PIN % 8));
		break;
	}
}
