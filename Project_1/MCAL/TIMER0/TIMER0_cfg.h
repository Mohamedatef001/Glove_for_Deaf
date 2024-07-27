/*
 * TIMER0_cfg.h
 *
 *  Created on: Dec 1, 2023
 *      Author: shady
 */

#ifndef MCAL_TIMER0_TIMER0_CFG_H_
#define MCAL_TIMER0_TIMER0_CFG_H_

typedef enum{
	NORMAL=0,
	Phase_Correct_PWM=1,
	CTC=2,
	FAST_PWM=3,
}Waveform_Generation_Mode;

typedef enum{
	prescalar_No=0,
	prescalar_1=1,//0
	prescalar_8=2,//1
	prescalar_64=3,//2
	prescalar_256=4,//3
	prescalar_1024=5,//4
	EXT_clk_Falling=6,
	EXT_clk_Rising=7
} Clock_Select;




typedef enum{
	Normal_port=0,
	Toggle_OC0=1,
	Clear_OC0=2,
	Set_OC0=3
}Compare_Output_Mode;


#define TIMER0_Preload_Value  OverFlowTicks*(1-(NumberOfOverFlows-(int)NumberOfOverFlows))

#define Prescaler_Number 5

#endif /* MCAL_TIMER0_TIMER0_CFG_H_ */
