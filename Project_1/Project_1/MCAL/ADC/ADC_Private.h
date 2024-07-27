/*
 * ADC_Private.h
 *
 *  Created on: Feb 29, 2024
 *      Author: Mohamed_Atef
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#include "STD_TYPES.h"

#define ADMUX (*(volatile u8*)0x27)
#define ADCSRA  (*(volatile u8*)0x26)
#define ADCL  (*(volatile u8*)0x24)
#define ADCH  (*(volatile u8*)0x25)

#define REFS1   7
#define REFS0   6
#define ADEN    7
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0
#define ADSC    6
#define ADIF    4
#define ADATE   5
#define ADLAR   5
#define ADIE    3


void __vector_16(void)__attribute__((signal));

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
