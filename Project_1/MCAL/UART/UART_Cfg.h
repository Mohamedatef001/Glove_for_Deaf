/*
 * UART_Cfg.h
 *
 *  Created on: Dec 9, 2023
 *      Author: shady
 */

#ifndef MCAL_UART_UART_CFG_H_
#define MCAL_UART_UART_CFG_H_

#include "STD_TYPES.H"
typedef enum{
	U2X_Disable=0,
	U2X_enable=1
}U2X_mode;

typedef enum{
	Receiver_disable=0,
	Recevier_enable=1
}Receiver_mode;

typedef enum{
	Transmit_disable=0,
	Transmit_enable=1
}Transmit_mode;


typedef enum{
	Char_Size_5=0,
	Char_Size_6=1,
	Char_Size_7=2,
	Char_Size_8=3,
	Char_Size_9=7
}Char_Size_mode;

typedef enum{
	Parity_disable=0,
	Even_Parity=2,
	Odd_parity=3
}Parity_mode;

typedef enum{
	Stop_bit1=0,
	Stop_bit2=1
}Stop_mode;

typedef enum{
	Asynchronus_UART=0,
	Synchronus_UART=1
}UART_mode;

typedef struct{
	Receiver_mode RX_init;
	Transmit_mode TX_init;
	U2X_mode U2X_init;
	Char_Size_mode Char_Size_init;
	Stop_mode Stop_init;
	UART_mode UART_init_mode;
	Parity_mode Parity_init;
	u32 BaudRate;
}Init_mode;
#endif /* MCAL_UART_UART_CFG_H_ */
