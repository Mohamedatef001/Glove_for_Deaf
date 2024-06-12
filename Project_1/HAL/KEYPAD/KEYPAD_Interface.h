/*
 * KEYPAD_Interface.h
 *
 *  Created on: Nov 18, 2023
 *      Author: shady
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

#include"STD_TYPES.h"
#include "KEYPAD_cfg.h"

void KEYPAD_VoidInit(void);
u8 KEYPAD_U8GetPressedKey(void);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
