/*
 * LCD_cfg.h
 *
 *  Created on: Nov 17, 2023
 *      Author: shady
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

#include"DIO_Cfg.h"

#define RS DIO_PINB1
#define RW DIO_PINB2
#define En DIO_PINB3


#define D4 DIO_PIND4
#define D5 DIO_PIND5
#define D6 DIO_PIND6
#define D7 DIO_PIND7


#define LCD_PORT PORTD
/************** LCD mode selection*************/
#define LCD_4_bit  4
#define LCD_8_bit  8

#define LCD_MODE LCD_4_bit



#endif /* HAL_LCD_LCD_CFG_H_ */
