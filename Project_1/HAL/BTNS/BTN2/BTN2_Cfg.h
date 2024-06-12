/*
 * BTN0_Cfg.h
 *
 *  Created on: Feb 22, 2024
 *      Author: newwo
 */

#ifndef HAL_BTNS_BTN0_BTN0_CFG_H_
#define HAL_BTNS_BTN0_BTN0_CFG_H_

#include "DIO_cfg.h"
#include "DIO_Private.h"

#define  B2         DIO_PIND2
#define  BTN2_PORT  PORTD_REG
#define  B2_INP     INPUT

#define BTN2_Pressed  DIO_HIGH
#define BTN2_NPressed  DIO_LOW


#endif /* HAL_BTNS_BTN0_BTN0_CFG_H_ */
