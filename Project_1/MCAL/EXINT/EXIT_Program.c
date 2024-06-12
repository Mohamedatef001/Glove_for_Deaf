/*
 * EXIT_Program.c
 *
 *  Created on: Nov 24, 2023
 *      Author: shady
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXIT_Private.h"
#include"EXIT_Cfg.h"

void EXIT_VoidEnableInt(u8 Interrupt_number, INT_State state) {

	switch (Interrupt_number) {
	case INT0: {
		/*state selection*/
		MCUCR_REG &= INT0_MSK;
		MCUCR_REG |= state;
		/*set specific interrupt enable*/
		SET_BIT(GICR_REG, INT0_PIN);
		break;
	}
	case INT1: {
		/*state selection*/
		MCUCR_REG &= INT1_MSK;
		MCUCR_REG |= state << ISC10;
		/*set specific interrupt enable*/
		SET_BIT(GICR_REG, INT1_PIN);
		break;
	}
	case INT2: {
		/*state selection*/
		MCUCSR_REG &= INT2_MSK;
		MCUCSR_REG |= state << ISC2;
		/*set specific interrupt enable*/
		SET_BIT(GICR_REG, INT2_PIN);
		break;
	}

	}

}

void EXIT_VoidDisableInt(u8 Interrupt_number) {
	switch (Interrupt_number) {
	case INT0:
		CLR_BIT(GICR_REG, INT0_PIN);
		break;
	case INT1:
		CLR_BIT(GICR_REG, INT1_PIN);
		break;
	case INT2:
		CLR_BIT(GICR_REG, INT2_PIN);
		break;
	}
}

void EXIT_VoidCallBack(u8 Interrupt_number, void (*Ptr_f)(void)) {

		switch (Interrupt_number) {
		case INT0:
			Ptr_func = Ptr_f;
			break;
		case INT1:
			Ptr_func1 = Ptr_f;
			break;
		case INT2:
			Ptr_func2 = Ptr_f;
			break;
		}

}

void __vector_1(void) {
	if (Ptr_func != NULL) {
		Ptr_func();
	}
}

void __vector_2(void) {
	if (Ptr_func1 != NULL) {
		Ptr_func1();
	}
}

void __vector_3(void) {
	if (Ptr_func2 != NULL) {
		Ptr_func2();
	}
}

