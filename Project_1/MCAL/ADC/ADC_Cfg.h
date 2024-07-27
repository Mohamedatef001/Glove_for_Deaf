/*
 * ADC.Cfg.h
 *
 *  Created on: Feb 29, 2024
 *      Author: Mohamed_Atef
 */
#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

#define F_CPU 16000000UL

typedef enum {
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}ADC_channel;

typedef enum {
  Internal_Vref_turned_off,
  AVCC,
  Res,
  Internal_Voltage_Reference
}Voltage_Reference;


#endif /* MCAL_ADC_ADC_CFG_H_ */
