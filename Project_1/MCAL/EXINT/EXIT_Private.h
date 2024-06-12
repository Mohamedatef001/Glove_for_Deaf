/*
 * EXIT_Private.h
 *
 *  Created on: Nov 24, 2023
 *      Author: shady
 */

#ifndef MCAL_EXINT_EXIT_PRIVATE_H_
#define MCAL_EXINT_EXIT_PRIVATE_H_

#define MCUCR_REG (*(volatile u8*)0x55)
#define MCUCSR_REG (*(volatile u8*)0x54)
#define GICR_REG (*(volatile u8*)0x5B)
#define GIFR_REG (*(volatile u8*)0x5A)


#define INT0_MSK 0xFC
#define INT1_MSK 0xF3
#define INT2_MSK 0xBF

#define ISC10 2

#define INT0_PIN 6
#define INT1_PIN 7
#define INT2_PIN 5

#define ISC2 6

void (*Ptr_func)(void)=NULL;
void (*Ptr_func1)(void)=NULL;
void (*Ptr_func2)(void)=NULL;

void __vector_1(void)__attribute__((signal));
void __vector_2(void)__attribute__((signal));
void __vector_3(void)__attribute__((signal));


#endif /* MCAL_EXINT_EXIT_PRIVATE_H_ */
