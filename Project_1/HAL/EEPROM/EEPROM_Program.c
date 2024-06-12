/*
 * EEPROM_Program.c
 *
 *  Created on: Dec 22, 2023
 *      Author: shady
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EEPROM_Private.h"
#include"EEPROM_Cfg.h"
#include"TWI_init.h"
#include "TWI_Private.h"
#include "EEPROM_Interface.h"
#include "util/delay.h"

//void EEPROM_VoidInit(void)
//{
//	 Init_M_TWI();
//}
//
//u8 EEPROM_Write(u16 address,u8 data)
//{
//	u8 _2MSB=0;
//	M_Start_Condition();
//	if((TWSR & 0xF8)!=start_condition_transmitted)
//	{
//		return 0;
//	}
//	_2MSB=(u8)((address & 0x700)>>7);
//	M_TWI_Start_Condition(0xA0|_2MSB);
//	if((TWSR & 0xF8)!=SLA_W_transmitted_ack_recieved)
//	{
//		return 0;
//	}
//	M_TWI_Start_Condition((u8)address);
//	if((TWSR & 0xF8)!=Data_byte_transmitted_ACK_received)
//	{
//		return 0;
//	}
//	M_TWI_Start_Condition(data);
//	if((TWSR & 0xF8)!=Data_byte_transmitted_ACK_received)
//	{
//		return 0;
//	}
//	M_TWI_Stop();
//	return 1;
//}
//
//
//u8 EEPROM_VoidRead(u16 address, u8*Data)
//{
//	u8 _2MSB=0;
//	M_Start_Condition();
//	if((TWSR & 0xF8)!=start_condition_transmitted)
//	{
//		return 0;
//	}
//	_2MSB=(u8)((address & 0x700)>>7);
//	M_TWI_Start_Condition(0xA0|_2MSB);
//	if((TWSR & 0xF8)!=SLA_W_transmitted_ack_recieved)
//	{
//		return 0;
//	}
//	M_TWI_Start_Condition((u8)address);
//	if((TWSR & 0xF8)!=Data_byte_transmitted_ACK_received)
//	{
//		return 0;
//	}
//	M_Start_Condition();
//	if((TWSR & 0xF8)!=repeated_start_transmitted)
//	{
//		return 0;
//	}
//	M_TWI_Start_Condition(0xA0|1);
//	if((TWSR & 0xF8)!=SLA_R_transmitted_ack_recieved)
//	{
//		return 0;
//	}
//	*Data=M_I2C_RecieveByte_ACK();
//	if((TWSR & 0xF8)!=Data_byte_recieved_ACK_received)
//	{
//		return 0;
//	}
//
//	M_TWI_Stop();
//	return 1;
//}
/*----------------------------------------------------------------------------------*/
void EEPROM_WRITE(u16 wordadd, u8 data)
{
	u8 add = (wordadd >> 8) | 0b01010000;

	vMASTER_init();
	vMASTER_START_condition();

	MASTER_SEND_ADDRESS_WRITE(add);
	MASTER_SEND_DATA((u8) wordadd);

	MASTER_SEND_DATA(data);
	M_TWI_Stop();
	_delay_ms(5);

}
void EEPROM_WRITE_String(u16 wordadd, u8 *data)
{
	for(u8 i=0;data[i] != '\0';i++)
	{

	u8 add = (wordadd >> 8) | 0b01010000;

	vMASTER_init();
	vMASTER_START_condition();

	MASTER_SEND_ADDRESS_WRITE(add);
	MASTER_SEND_DATA((u8) wordadd);

	MASTER_SEND_DATA(*data);
	M_TWI_Stop();
	_delay_ms(5);
	wordadd++;
	}
	_delay_ms(5);

}
u8 EEPROM_READ(u16 wordadd)
{
	u8 add = (wordadd >> 8) | 0b01010000;
	vMASTER_init();
	vMASTER_START_condition();
	MASTER_SEND_ADDRESS_WRITE(add);
	MASTER_SEND_DATA((u8) wordadd);
	vMASTER_REP_START_condition();
	MASTER_SEND_ADDRESS_READ(add);
	u8 data = MASTER_RECIVE_DATA();
	M_TWI_Stop();
	return data;
	_delay_ms(5);

}
