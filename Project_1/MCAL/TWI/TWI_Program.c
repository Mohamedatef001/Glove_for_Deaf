/*
 * TWI_Program.c
 *
 *  Created on: Mar 10, 2023
 *      Author: Mohamed_Atef
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI_Private.h"
#include "TWI_Types.h"
#include "TWI_cfg.h"
#include "TWI_init.h"

void MASTER_SEND_ADDRESS_WRITE(u8 adress)
{

	if(adress<128)
	{
		//WRITE ADDRESS IN REG TWAR
		TWDR=adress<<1;
		// CLEAR BIT 0 TO WTITE
		CLR_BIT(TWDR,0);
		// CLEAR START BIT
		CLR_BIT(TWCR,TWSTA);
		//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
		SET_BIT(TWCR,TWINT);
		//BUSY W8 OF FLAG
		while(!GET_BIT(TWCR,TWINT));
		//check in status code
		//while(STATUSE_CODE != ADDRESS_W_transmitted);


	}
}
void MASTER_SEND_DATA             (u8 data)
{
	TWDR=data;

	//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
	SET_BIT(TWCR,TWINT);

	//BUSY W8 OF FLAG
	while(!GET_BIT(TWCR,TWINT));
	//check in status code
	//while(STATUSE_CODE != DATA_TRASMIT_WITH_ACK);

}
void vMASTER_REP_START_condition  (void)
{
	//SET START BIT CONDITION
	SET_BIT(TWCR,TWSTA);

	//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
	SET_BIT(TWCR,TWINT);
	//BUSY W8 OF FLAG
	while(!GET_BIT(TWCR,TWINT));
	//check in status code
	//while(STATUSE_CODE != repSTART_condition_transmitted);
}
void MASTER_SEND_ADDRESS_READ     (u8 adress)
{

	if(adress<128)
	{
		//WRITE ADDRESS IN REG TWAR
		TWDR=adress<<1;
		// SET BIT 0 TO READ  -> SALVE TRASMIT
		SET_BIT(TWDR,TWGCE);
		// CLEAR START BIT
		CLR_BIT(TWCR,TWSTA);

		//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
		SET_BIT(TWCR,TWINT);
		//BUSY W8 OF FLAG
		while(!GET_BIT(TWCR,TWINT));
		//check in status code
		//while(STATUSE_CODE != ADDRESS_R_RECIVE);
	}
}
u8 MASTER_RECIVE_DATA             (void)
{
	SET_BIT(TWCR, TWEA);
	//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
	SET_BIT(TWCR,TWINT);

	//BUSY W8 OF FLAG
	while(!GET_BIT(TWCR,TWINT));
	//check in status code
	//while(STATUSE_CODE != DATA_RECIVE_WITH_ACK);


	return TWDR;
}

void vMASTER_init                 (void)
{
	/* set pre-scaler -> 0 */
	/* TWPS1, TWPS0 @ TWSR -> 0, 0 (default) */
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);

	/* select bit rate */
	/* TWBR	-> 12 */
	/* FTWI = 400KHZ*/

	TWBR=12;
	/* enable acknowledge  */
	/* TWEA @ TWCR -> 1 */
	SET_BIT(TWCR,TWEA);


	/* enable TWI */
	/* TWEN @ TWCR -> 1 */
	SET_BIT(TWCR,TWEN);

}
void vMASTER_START_condition      (void)
{
	//SET START BIT CONDITION
	SET_BIT(TWCR,TWSTA);

	//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
	SET_BIT(TWCR,TWINT);
	//BUSY W8 OF FLAG
	while(!GET_BIT(TWCR,TWINT));
	//check in status code
	//while(STATUSE_CODE != START_condition_transmitted);


}

u8 M_I2C_RecieveByte_ACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(GET_BIT(TWCR,TWINT)==0)
		{

		}
	return TWDR;
	CLR_BIT(TWCR,TWEA);
}
/*---------------------------------------------------------------------------------------*/
//void M_Start_Condition(void)
//{
//	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
//		TWI_Wait();
//}
//
//
//void TWI_Wait(void)
//{
//	while(GET_BIT(TWCR,TWINT)==0);
//}
//
//void Init_M_TWI(void)
//{
//	TWBR=12;
//	TWCR = (1<<TWEN);
//}
//
//
//void M_TWI_Start_Condition(u8 DATA)
//{
//	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
//	TWI_Wait();
////	while((TWSR & 0xF8) != start_condition_transmitted);
//	TWDR = SLA_W;
//	TWCR = (1<<TWINT) | (1<<TWEN);
//	TWI_Wait();
////	while((TWSR & 0xF8) != SLA_W_transmitted_ack_recieved);
//	TWDR = DATA;
//	TWCR = (1<<TWINT) | (1<<TWEN);
//	TWI_Wait();
////	while((TWSR & 0xF8) != Data_byte_transmitted_ACK_received);
//	M_TWI_Stop();
//}
//
void M_TWI_Stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}


//-------------------------------------------------------------------------------------------//
void Init_S_TWI(void)
{
	TWAR = SLA_W;
	TWCR &= ~(1 << TWSTA);
	TWCR &= ~(1 << TWSTO);
	TWCR |= (1<<TWEA) | (1<<TWEN);
}

u8 Slave_TWI_Receive(void)
{
	while(GET_BIT(TWCR,TWINT)==0);
	if ((TWSR & 0xF8) != 60 || (TWSR & 0xF8) != 68 || (TWSR & 0xF8) != 70 || (TWSR & 0xF8) != 78)
	{
		TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
		while (GET_BIT(TWCR,TWINT) == 0);
		u8 ReceivedData = TWDR;
		return ReceivedData;
		TWCR = (1 << TWINT) | (1 << TWEN); // Clear TWINT and retain TWI enabled
	}
	   // If there's no data or an error, return an invalid value (e.g., 0xFF)
	    return 0xFF;
}
