/*
 * SPI_Private.h
 *
 *  Created on: Dec 15, 2023
 *      Author: shady
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_


#include"STD_TYPES.h"

#define SPCR (*(volatile u8*)0x2D)
#define SPSR (*(volatile u8*)0x2E)
#define SPDR (*(volatile u8*)0x2F)


#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
