/*
 * SPI_Interface.h
 *
 *  Created on: Dec 15, 2023
 *      Author: shady
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "SPI_Cfg.h"
#include "SPI_Private.h"

//void SPI_VoidInit(SPI_Init *SPI_initVariable);
u8 SPI_U8SendReceiveSynchronous(u8 Data);
void SPI_MasterInit(void);
void SPI_voidReceiveString(u8 *buffer);
void SPI_voidTransmitSting(u8 *str);



#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
