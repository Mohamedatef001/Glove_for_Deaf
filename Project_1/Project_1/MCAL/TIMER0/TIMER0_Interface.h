/*
 * TIMER_Interface.h
 *
 *  Created on: Dec 1, 2023
 *      Author: shady
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_
#include"STD_TYPES.h"
#include"TIMER0_cfg.h"
void TIMER0_VoidInit(Waveform_Generation_Mode Timer_mode,Clock_Select Prescaler,Compare_Output_Mode mode);
void TIMER0_Voidstart(void);
void TIMER0_VoidDelayTimeMillisec(u32 millisecond);
void TIMER0_VoidAsynchronous(void(*TIMER0)(void));
void TIMER_VoidPwmDuty(u8 duty);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
