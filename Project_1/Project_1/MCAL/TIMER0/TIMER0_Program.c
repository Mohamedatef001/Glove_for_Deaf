/*
 * TIMER0_Program.c
 *
 *  Created on: Dec 1, 2023
 *      Author: shady
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TIMER0_Private.h"
#include"TIMER0_cfg.h"

Waveform_Generation_Mode GLobal_Timer_mode;
Clock_Select Global_prescaler;
extern u16 Prescaler_Arr[Prescaler_Number];
u32 NumberOfOverFlows=0;
u8 RemainingCounts=0;

void(*Ptr_OverFlowInterrupt)(void)=NULL;
void(*Ptr_CTCInterrupt)(void)=NULL;
void TIMER0_VoidInit(Waveform_Generation_Mode Timer_mode,Clock_Select Prescaler,Compare_Output_Mode mode)
{
	/*select timer mode*/
	GLobal_Timer_mode=Timer_mode;
	TCCR0&=0xB7;
	TCCR0|=((Timer_mode&1)<<6);
	TCCR0|=((Timer_mode&2)<<2);
	/*select prescaler*/
	Global_prescaler=Prescaler;
	/*select output comapare mode*/
	TCCR0&=0xCF;
	TCCR0|=mode<<4;

}

void TIMER0_Voidstart(void)
{
	TCCR0&=0xF8;
	TCCR0|=Global_prescaler;
}

void TIMER0_VoidStop(void)
{
	TCCR0&=0xF8;
}


void TIMER0_VoidDelayTimeMillisec(u32 Millisecond)
{
	u32 TickTime=(Prescaler_Arr[Global_prescaler-1]*1000000)/(FCPU);
	u32 DesiredTicks=(Millisecond*1000)/TickTime;
	if(GLobal_Timer_mode==NORMAL)
	{
		NumberOfOverFlows=DesiredTicks/OverFlowTicks;
		RemainingCounts=DesiredTicks%OverFlowTicks;
		if(RemainingCounts!=0)
		{

			TCNT0=OverFlowTicks-RemainingCounts;
			NumberOfOverFlows++;
		}
	}else if(GLobal_Timer_mode==CTC)
	{
		u16 value=OverFlowTicks;
		while(DesiredTicks%value!=0)
		{
			value--;
		}
		OCR0=value-1;
		NumberOfOverFlows=DesiredTicks/value;
	}

}


void TIMER0_VoidAsynchronous(void(*TIMER0)(void))
{
	if(GLobal_Timer_mode==NORMAL)
	{
		TIMSK&=0xFC;
		SET_BIT(TIMSK,TOIE0);
		Ptr_OverFlowInterrupt=TIMER0;
	}else if(GLobal_Timer_mode==CTC)
	{
		TIMSK&=0xFC;
		SET_BIT(TIMSK,OCIE0);
		Ptr_CTCInterrupt=TIMER0;
	}
}

void TIMER_VoidPwmDuty(u8 duty)
{
	u16 x=0;
	x=((duty*256)/100)-1;
	OCR0=x;
}


void __vector_11(void)
{

	static u32 count=0;
	count++;
	if(count == NumberOfOverFlows)
	{
		TCNT0=OverFlowTicks-RemainingCounts;
		count=0;
		if(Ptr_OverFlowInterrupt!=NULL)
		{
			Ptr_OverFlowInterrupt();
		}


	}

}

void __vector_10(void)
{
	static u32 count=0;
	count++;
	if(count == NumberOfOverFlows)
	{
		if(Ptr_CTCInterrupt!=NULL)
		{
			Ptr_CTCInterrupt();
		}
		count=0;
	}
}
