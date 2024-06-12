/*
 * LCD_Interface.h
 *
 *  Created on: Nov 17, 2023
 *      Author: shady
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "STD_TYPES.h"

void LCD_VoidInit(void);
void LCD_VoidWriteData(u8 LCD_Char);
void LCD_VoidWriteNumber(u32 num);
void LCD_VoidWriteString(u8 *str);
void LCD_VoidClear(void);
void LCD_VoidSetCursor(u8 row, u8 col);
#endif /* HAL_LCD_LCD_INTERFACE_H_ */
