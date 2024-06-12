/*
 * UART_Program.c
 *
 *  Created on: Dec 9, 2023
 *      Author: Mohamed_Atef
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_Private.h"
#include "UART_Cfg.h"
#include "string.h"

#define UART_RX_BUFFER_SIZE 128
char uart_rx_buffer[UART_RX_BUFFER_SIZE];
volatile u32 uart_rx_buffer_index = 0;
volatile u32 uart_rx_buffer_full = 0;

void UART_Voidinit(Init_mode *Init_value)
{
	u8 UCSRC_var=128;//0b1000 0000
	u16 Baud_var=0;

	/*U2X Mode Select*/
	UCSRA &= U2X_MSK;
	UCSRA |= (Init_value->U2X_init)<<U2X;

	/* RX enable*/
	UCSRB &= Rx_MSK;
	UCSRB |= (Init_value->RX_init)<<4;

	/*Tx enable*/
	UCSRB &= Tx_MSK;
	UCSRB |= (Init_value->TX_init)<<3;

	/*char size select*/
	UCSRB &=CharSize_Msk;
	UCSRB |= (GET_BIT((Init_value->Char_Size_init),2))<<2;

	/*synchronous and asynchronous select*/
	UCSRC_var|=(Init_value->UART_init_mode)<<6;
	/*parity select*/
	UCSRC_var|=(Init_value->Parity_init)<<4;

	/*number of stop bits select*/
	UCSRC_var|=(Init_value->Stop_init)<<3;

	/*char size 3rd bit clear*/
	CLR_BIT((Init_value->Char_Size_init),2);
	/*char size first two bits select*/
	UCSRC_var|=((Init_value->Char_Size_init)<<1);
	UCSRC=UCSRC_var;

	Baud_var=BaudRate_Func((Init_value->BaudRate));//300
	UBRRL=(Baud_var&0xFF);
	if(Baud_var>255)
	{
		Baud_var=Baud_var>>8;
		UBRRH=Baud_var;
	}
}

void UART_VoidTransmitMessagesynchronous(u8 signal)
{
	while(GET_BIT(UCSRA,5)==0)
	{

	}
	UDR=signal;

}

void UART_voidTransmitSting(u8 *str)
{
	for(u8 i=0;str[i] != '\0';i++)
	{
		UART_VoidTransmitMessagesynchronous(str[i]);

	}
}

u8 UART_VoidReceiveMessagesynchronous(void)
{
	while(GET_BIT(UCSRA,7)==0)
	{

	}
	return UDR;
}

void UART_voidReceiveString(u8 *buffer) {
    u8 i = 0;
    while (1) {

        buffer[i] = UART_VoidReceiveMessagesynchronous();
        if (buffer[i] == '.')
        {
            break;
        }
        i++;
    }
    buffer[i+1] = '\0';
}

void resetString(u8 *str, u8 size) {
    for (u8 i = 0; i < size; i++) {
        str[i] = 0x00; // Set each character to null
    }
}
