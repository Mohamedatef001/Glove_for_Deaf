/*
 * TIMER0_Private.h
 *
 *  Created on: Dec 1, 2023
 *      Author: shady
 */

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_

#define TCCR0 (*(volatile u8*)0x53)
#define OC0      0
#define WGM00    1
#define COM01    2
#define COM00    3
#define WGM01    4
#define CS02     5
#define CS01     6
#define CS00     7

#define TCNT0 (*(volatile u8*)0x52)
#define OCR0  (*(volatile u8*)0x5C)
#define TIMSK (*(volatile u8*)0x59)
#define TIFR  (*(volatile u8*)0x58)


#define FCPU 16000000
#define OverFlowTicks 256



#define TOIE0 0
#define OCIE0 1

void __vector_11(void)__attribute__((signal));
void __vector_10(void)__attribute__((signal));
#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
