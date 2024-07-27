/*
 * ADC_Interface.h
 *
 *  Created on: Feb 29, 2024
 *      Author: Mohamed_Atef
 */
#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "ADC_Cfg.h"
#include "ADC_Private.h"

void ADC_INIT(Voltage_Reference Voltage_Selection);
void ADC_VoidCallBack(void (*Ptr_f)(void));
void start_ADC_conversion(ADC_channel channel);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
