/*
 * ADC_Interface.h
 *
 *  Created on: Feb 29, 2024
 *      Author: newwo
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "ADC_Cfg.h"
#include "ADC_Private.h"

void ADC_INIT(Voltage_Reference Voltage_Selection);
u32 ADC_READ(ADC_channel chanel);
void ADC_VoidCallBack(void (*Ptr_f)(void));

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
