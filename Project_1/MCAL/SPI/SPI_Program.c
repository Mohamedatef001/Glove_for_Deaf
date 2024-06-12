/*
 * SPI_Program.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Mohamed Atef
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_Private.h"
#include "SPI_Cfg.h"
#include "DIO_Interface.h"

//void SPI_VoidInit(SPI_Init *SPI_initVariable)
//{
//	SPCR|=(SPI_initVariable->SPI_ModeSelect)<<6;
//	SPCR|=(SPI_initVariable->SPI_DataOrderSelect)<<5;
//	SPCR|=(SPI_initVariable->SPI_MSSelect)<<4;
//	SPCR|=(SPI_initVariable->SPI_ClockPolaritySelect)<<3;
//	SPCR|=(SPI_initVariable->SPI_ClockPhaseSelect)<<2;
//	SPCR|=(SPI_initVariable->SPI_ClockFrequencySelect);
//
//}

void SPI_MasterInit(void)
{
/* Set MOSI and SCK output, all others input */
	 DIO_VoidSetPinDirection(DIO_PINB5,OUTPUT);
		 DIO_VoidSetPinDirection(DIO_PINB7,OUTPUT);
/* Enable SPI, Master, set clock rate fck/16 */
     SPCR = (1<<6)|(1<<4)|(1<<0)|(1<<1);
}

u8 SPI_U8SendReceiveSynchronous(u8 Data)
{
	SPDR=Data;
	while(GET_BIT(SPSR,7)==0)
	{

	}
	return SPDR;
}
void SPI_voidTransmitSting(u8 *str)
{
	for(u8 i=0;str[i] != '\0';i++)
	{
		SPI_U8SendReceiveSynchronous(str[i]);

	}
}
void SPI_voidReceiveString(u8 *buffer) {
    u8 i = 0;
    while (1) {


        buffer[i] = SPI_U8SendReceiveSynchronous(0x00);
        if (buffer[i] == '.') {
            break;
        }
        i++;
    }
    // Null-terminate the string
    buffer[i+1] = '\0';
}
