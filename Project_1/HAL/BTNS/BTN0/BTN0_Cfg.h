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

#define  B0         DIO_PIND0
#define  BTN0_PORT  PORTD_REG
#define  B0_INP     INPUT

#define BTN0_NPressed  150


#endif /* HAL_BTNS_BTN0_BTN0_CFG_H_ */
