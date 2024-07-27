/*
 * TWI_Private.h
 *
 *  Created on: Mar 10, 2023
 *      Author: Mohamed_Atef
 */

#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_



#define TWBR (*((volatile u8*)0x20))
#define TWCR (*((volatile u8*)0x56))
#define TWSR (*((volatile u8*)0x21))
#define TWDR (*((volatile u8*)0x23))
#define TWAR (*((volatile u8*)0x22))


/**********************************TWBR_REG*************************************/
#define TWBR0 0
#define TWBR1 1
#define TWBR2 2
#define TWBR3 3
#define TWBR4 4
#define TWBR5 5
#define TWBR6 6
#define TWBR7 7
/*********************************************************************/
/**********************************TWCR_REG*************************/
#define TWIE  0
#define TWEN  2
#define TWWC  3
#define TWSTO 4
#define TWSTA 5
#define TWEA  6
#define TWINT 7
/***********************************************************************/

/*********************************TWSR_REG**************************/
#define TWPS0 0
#define TWPS1 1
#define TWS3 3
#define TWS4 4
#define TWS5 5
#define TWS6 6
#define TWS7 7
/***********************************************************************/
/************************************TWDR_REG*************************/
#define TWD0 0
#define TWD1 1
#define TWD2 2
#define TWD3 3
#define TWD4 4
#define TWD5 5
#define TWD6 6
#define TWD7 7
/***********************************************************************/
/*********************************TWAR_REG******************************/
#define TWGCE 0
#define TWA0 1
#define TWA1 2
#define TWA2 3
#define TWA3 4
#define TWA4 5
#define TWA5 6
#define TWA6 7
/***********************************************************************/

#define Speed_rate_EEPROM 12
//#define Speed_rate_RTC

#define SLA_W 0x04
#define SLA_R 0x05

#endif /* MCAL_TWI_TWI_PRIVATE_H_ */
