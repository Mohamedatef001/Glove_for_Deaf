/*
 * DIO_Interface.h
 *
 *  Created on: Feb 9, 2024
 *      Author: newwo
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include"DIO_cfg.h"

void DIO_VoidSetPinDirection(PIN_NUM PIN,u8 Value);
void DIO_VoidSetPinValue(PIN_NUM PIN,u8 Value);
void DIO_VoidSetPortValue(u8 PORT,u8 Value);
void DIO_VoidSetPortDirection(u8 PORT,u8 Value);
u8 DIO_U8GetPinValue(PIN_NUM PIN);
void DIO_SetPin_PULLUP(PIN_NUM PIN);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
