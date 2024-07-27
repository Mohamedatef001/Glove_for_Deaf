/*
 * ADC_Program.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Mohamed_Atef
 */
#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "BIT_MATH.h"
#include "avr/io.h"
#include<util/delay.h>

void (*ADC_f)(void)=NULL;

void ADC_INIT(Voltage_Reference Voltage_Selection) {
    switch (Voltage_Selection) {
        case Internal_Vref_turned_off:
            CLR_BIT(ADMUX, REFS0);
            CLR_BIT(ADMUX, REFS1);
            break;
        case AVCC:
            SET_BIT(ADMUX, REFS0);
            CLR_BIT(ADMUX, REFS1);
            break;
        case Res:
            CLR_BIT(ADMUX, REFS0);
            SET_BIT(ADMUX, REFS1);
            break;
        case Internal_Voltage_Reference:
            SET_BIT(ADMUX, REFS0);
            SET_BIT(ADMUX, REFS1);
            break;
    }
    SET_BIT(ADCSRA, ADPS2); // select the prescaler
    SET_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS0);
    CLR_BIT(ADMUX, ADLAR);
    CLR_BIT(ADCSRA, ADATE);
    SET_BIT(ADCSRA, ADIE); // enable ADC interrupt
    SET_BIT(ADCSRA, ADEN); // enable the ADC
}

void start_ADC_conversion(ADC_channel channel) {
    ADMUX = (ADMUX & 0xE0) | channel; // Masking and then select the input pin
    SET_BIT(ADCSRA, ADSC); // ADC Start Conversion
}

void __vector_16(void) {
    if (ADC_f != NULL) {
        ADC_f();
    }
    SET_BIT(ADCSRA, ADIF); // Clear the interrupt flag
}

void ADC_VoidCallBack(void (*Ptr_f)(void)) {
    ADC_f = Ptr_f;
}
