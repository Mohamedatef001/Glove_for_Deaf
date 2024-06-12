/*
 * Timer1_Interface.h
 *
 *  Created on: Jan 24, 2024
 *      Author: shady
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

#include"STD_TYPES.h"
#include"TIMER1_Cfg.h"

void TIMER1_VoidInit(Timer1_init *Timer1_InitValues);
void TIMER1_Voidstart(void);
void TIMER1_VoidStop(void);
void TIMER1_VoidPwmDuty(u8 duty, u16 freq);

#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
