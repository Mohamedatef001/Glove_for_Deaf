/*
 * KEYPAD_cfg.h
 *
 *  Created on: Nov 18, 2023
 *      Author: shady
 */

#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_
#include "DIO_Cfg.h"

#define ROWS     4
#define COLUMNS  4

#define FIRST_OUTPUT DIO_PINB4
#define FIRST_INPUT DIO_PINC3

#define UNPRESSED_KEY  150
#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
