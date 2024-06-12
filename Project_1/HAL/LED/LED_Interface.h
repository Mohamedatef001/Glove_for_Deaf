/*
 * LED_Interface.h
 *
 *  Created on: Feb 25, 2024
 *      Author: newwo
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_
#include "LED_Cfg.h"
#include "STD_TYPES.h"

void LED_ON(u16 number);
void LED_OFF(u16 number);

void LED_TOGGLE(u16 number);

#endif /* HAL_LED_LED_INTERFACE_H_ */
