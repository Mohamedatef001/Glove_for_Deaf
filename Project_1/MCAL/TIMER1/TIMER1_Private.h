/*
 * TIMER1_Private.h
 *
 *  Created on: Jan 24, 2024
 *      Author: shady
 */

#ifndef MCAL_TIMER1_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_TIMER1_PRIVATE_H_

#define TCCR1A_REG 	(*(volatile u8*)0x4F)
#define TCCR1B_REG	(*(volatile u8*)0x4E)
#define TCNT1_REG 	(*(volatile 16*)0x4C)
#define OCR1A_REG 	(*(volatile u16*)0x4A)
#define OCR1B_REG 	(*(volatile u16*)0x48)
#define ICR1_REG 	(*(volatile u16*)0x46)
#define TIMSK1_REG 	(*(volatile u8*)0x59)
#define TIFR_REG 	(*(volatile u8*)0x58)


#define WGM10 0
#define WGM12 1
#define COM1A0 6
#define COM1B0 4
#define CS10 0
#endif /* MCAL_TIMER1_TIMER1_PRIVATE_H_ */
