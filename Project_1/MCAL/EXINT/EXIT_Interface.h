/*
 * EXIT_Interface.h
 *
 *  Created on: Nov 24, 2023
 *      Author: shady
 */

#ifndef MCAL_EXINT_EXIT_INTERFACE_H_
#define MCAL_EXINT_EXIT_INTERFACE_H_

#include"EXIT_Cfg.h"

void EXIT_VoidEnableInt(u8 Interrupt_number,INT_State state);
void EXIT_VoidDisableInt(void);
void EXIT_VoidCallBack(u8 Interrupt_number,void(*Ptr_f)(void));



#endif /* MCAL_EXINT_EXIT_INTERFACE_H_ */
