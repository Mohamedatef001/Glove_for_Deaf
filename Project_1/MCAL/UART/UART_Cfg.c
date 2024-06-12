/*
 * UART_Cfg.c
 *
 *  Created on: Dec 14, 2023
 *      Author:
 */

/*
Receiver_mode:
	Receiver_disable=0,
	Recevier_enable=1

Transmit_mode:
	Transmit_disable=0,
	Transmit_enable=1



U2X_mode:
	U2X_Disable=0,
	U2X_enable=1


Char_Size_mode:
	Char_Size_5=0,
	Char_Size_6=1,
	Char_Size_7=2,
	Char_Size_8=3,
	Char_Size_9=7


Parity_mode:
	Parity_disable=0,
	Even_Parity=2,
	Odd_parity=3


Stop_mode:
	Stop_bit1=0,
	Stop_bit2=1


UART_mode:
	Asynchronus_UART=0,
	Synchronus_UART=1

Init_mode
	Receiver_mode RX_init;
	Transmit_mode TX_init;
	U2X_mode U2X_init;
	Char_Size_mode Char_Size_init;
	Stop_mode Stop_init;
	UART_mode UART_init;
	Parity_mode Parity_init;
	u16 BaudRate;


*/
//Init_mode UART_init={
//		Recevier_enable,
//		Transmit_enable,
//		U2X_Disable,
//		Char_Size_8,
//		Stop_bit1,
//		Asynchronus_UART,
//		Parity_disable,
//		9600,
//};
