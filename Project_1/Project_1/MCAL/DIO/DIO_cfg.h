/*
 * DIO_cfg.h
 *
 *  Created on: Feb 9, 2024
 *      Author: newwo
 */

#ifndef MCAL_DIO_DIO_CFG_H_
#define MCAL_DIO_DIO_CFG_H_

/*Direction of Registers*/
#define OUTPUT 1
#define INPUT 0

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3


typedef enum{
	DIO_PINA0,
	DIO_PINA1,
	DIO_PINA2,
	DIO_PINA3,
	DIO_PINA4,
	DIO_PINA5,
	DIO_PINA6,
	DIO_PINA7,

	DIO_PINB0,
	DIO_PINB1,
	DIO_PINB2,
	DIO_PINB3,
	DIO_PINB4,
	DIO_PINB5,
	DIO_PINB6,
	DIO_PINB7,

	DIO_PINC0,
	DIO_PINC1,
	DIO_PINC2,
	DIO_PINC3,
	DIO_PINC4,
	DIO_PINC5,
	DIO_PINC6,
	DIO_PINC7,

	DIO_PIND0,
	DIO_PIND1,
	DIO_PIND2,
	DIO_PIND3,
	DIO_PIND4,
	DIO_PIND5,
	DIO_PIND6,
	DIO_PIND7,
}PIN_NUM;


#define DIO_HIGH 1
#define DIO_LOW  0


#endif /* MCAL_DIO_DIO_CFG_H_ */
