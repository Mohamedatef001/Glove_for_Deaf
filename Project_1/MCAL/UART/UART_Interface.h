/*
 * UART_Interface.h
 *
 *  Created on: Dec 9, 2023
 *      Author: shady
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#include "STD_TYPES.h"
#include "UART_Cfg.h"

void UART_Voidinit(Init_mode *Init_value);
void UART_VoidTransmitMessagesynchronous(u8 signal);
u8 UART_VoidReceiveMessagesynchronous(void);
void UART_voidTransmitSting(u8 *str);
void UART_voidReceiveString(u8 *buffer);
void resetString(u8 *str, u8 size);
#endif /* MCAL_UART_UART_INTERFACE_H_ */
