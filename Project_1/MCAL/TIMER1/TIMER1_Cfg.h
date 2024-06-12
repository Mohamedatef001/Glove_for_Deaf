/*
 * TIMER1_Cfg.h
 *
 *  Created on: Jan 24, 2024
 *      Author: shady
 */

#ifndef MCAL_TIMER1_TIMER1_CFG_H_
#define MCAL_TIMER1_TIMER1_CFG_H_

#define FCPU 16000000UL

typedef enum{
	Timer1_normal					=0,
	Timer1_PWM_Phase_Correct_8_bit	=1,
	Timer1_PWM_Phase_Correct_9_bit	=2,
	Timer1_PWM_Phase_Correct_10_bit	=3,
	Timer1_CTC						=4,
	Timer1_Fast_PWM_8_bit			=5,
	Timer1_Fast_PWM_9_bit			=6,
	Timer1_Fast_PWM_10_bit			=7,
	Timer1_PWM_Phase_Correct_ICR1	=8,
	Timer1_PWM_Phase_Correct_OCR1A	=9,
	PWM_Phase_Correct_ICR1			=10,
	PWM_Phase_Correct_OCR1A			=11,
	CTC_ICR1						=12,
	Reserved						=13,
	Fast_PWM_ICR1					=14,
	Fast_PWM_OCR1A					=15

}Timer1_WaveGenerationMode;



typedef enum{
	Timer1_NormalMode		=0,
	Timer1_ToggleMode		=1,
	Timer1_ClearOC1Mode		=2,
	Timer1_SetOC1Mode		=3
}Timer1_mode;


typedef enum{
	TIMER1_clk_1				=1,
	TIMER1_clk_8				=2,
	TIMER1_clk_64				=3,
	TIMER1_clk_256				=4,
	TIMER1_clk_1024				=5,
	TIMER1_External_clock_falling_edge	=6,
	TIMER1_External_Clock_rising_edge	=7

}Timer1_ClockSelect;


typedef enum{
	Timer1_OC1A   =0,
	Timer1_OC1B	  =1
}Timer1_Output_Compare_pins;

typedef struct{
	Timer1_WaveGenerationMode WGM;
	Timer1_mode Mode;
	Timer1_ClockSelect Prescaler;
	Timer1_Output_Compare_pins Timer1_0C1;
}Timer1_init;
#endif /* MCAL_TIMER1_TIMER1_CFG_H_ */
