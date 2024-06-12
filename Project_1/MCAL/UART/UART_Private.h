/*
 * UART_Private.h
 *
 *  Created on: Dec 9, 2023
 *      Author: shady
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define UDR   (*(volatile u8*)0x2C)
#define UCSRA (*(volatile u8*)0x2B)
#define UCSRB (*(volatile u8*)0x2A)
#define RXCIE    7
#define TXCIE    6
#define UDRIE    5
#define RXEN     4
#define TXEN     3
#define UCSZ2    2
#define RXB8     1
#define TXB8     0

#define UCSRC (*(volatile u8*)0x40)
#define  URSEL   7
#define  UMSEL   6
#define  UPM1    5
#define  UPM0    4
#define  USBS    3
#define  UCSZ1   2
#define  UCSZ0   1
#define  UCPOL   0
#define UBRRH (*(volatile u8*)0x40)
#define UBRRL (*(volatile u8*)0x29)


#define BaudRate_Func(x) (16000000/(16*x))-1


#define U2X 1
#define U2X_MSK 0xFC
#define Rx_MSK 0xEF
#define Tx_MSK 0xF7
#define CharSize_Msk 0xFB
#endif /* MCAL_UART_UART_PRIVATE_H_ */
