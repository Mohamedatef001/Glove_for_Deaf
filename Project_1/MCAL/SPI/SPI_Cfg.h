/*
 * SPI_Cfg.h
 *
 *  Created on: Dec 15, 2023
 *      Author: shady
 */

#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_

typedef enum{
	SPI_DISABLE=0,
	SPI_ENABLE=1
}SPI_MODE;

typedef enum{
	SPI_MSB=0,
	SPI_LSB=1

}SPI_DataOrder;


typedef enum{
	SPI_SLAVE=0,
	SPI_MASTER=1
}SPI_MS;


typedef enum{
	SPI_Rising=0,
	SPI_Falling=1
}SPI_ClockPolarity;


typedef enum{
	SPI_SampleSetup=0,
	SPI_SetupSample=1
}SPI_ClockPhase;

typedef enum{
	SPI_Frequency_4=0,
	SPI_Frequency_16=1,
	SPI_Frequency_64=2,
	SPI_Frequency_128=3
}SPI_ClockFrequency;

typedef enum{
	SPI_NormalSpeed=0,
	SPI_DoubleSpeed=1
}SPI_Speed;


//typedef struct{
//	SPI_MODE SPI_ModeSelect;
//	SPI_DataOrder SPI_DataOrderSelect;
//	SPI_MS SPI_MSSelect;
//	SPI_ClockPolarity SPI_ClockPolaritySelect;
//	SPI_ClockPhase SPI_ClockPhaseSelect;
//	SPI_ClockFrequency SPI_ClockFrequencySelect;
//	SPI_Speed SPI_SpeedSelect;
//}SPI_Init;
#endif /* MCAL_SPI_SPI_CFG_H_ */
