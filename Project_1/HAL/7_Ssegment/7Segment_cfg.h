/*
 * 7Segement_cfg.h
 *
 *  Created on: Feb 18, 2024
 *      Author: newwo
 */

#ifndef HAL_7_SSEGMENT_7SEGMENT_CFG_H_
#define HAL_7_SSEGMENT_7SEGMENT_CFG_H_

#include "DIO_cfg.h"

#define A4  DIO_PINA4
#define A5  DIO_PINA5
#define A6  DIO_PINA6
#define A7  DIO_PINA7

#define DP DIO_PINB3

#define EN1 DIO_PINB1
#define EN2 DIO_PINB2

//#define SEVSEG_PORT         PORTA
//#define SEVSEG_DATA_PORT    DIO_PORTA
//#define SEVSEG_CONTROL_PORT DIO_PORTB
////Renaming pin
//#define SEVSEG_DATA_A       DIO_PINA4
//#define SEVSEG_DATA_B       DIO_PINA5
//#define SEVSEG_DATA_C       DIO_PINA6
//#define SEVSEG_DATA_D       DIO_PINA7
//#define SEVSEG_CONTROL_EN1  DIO_PINB1
//#define SEVSEG_CONTROL_EN2  DIO_PINB2
//#define SEVSEG_CONTROL_DIP  DIO_PINB3

#endif /* HAL_7_SSEGMENT_7SEGMENT_CFG_H_ */
