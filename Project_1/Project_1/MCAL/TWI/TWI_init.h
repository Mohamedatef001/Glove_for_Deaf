/*
 * TWI_init.h
 *
 *  Created on: Mar 10, 2023
 *      Author: Mohamed_Atef
 */

#ifndef MCAL_TWI_TWI_INIT_H_
#define MCAL_TWI_TWI_INIT_H_


#include "TWI_Types.h"

void TWI_Wait(void);
void Init_M_TWI(void);
void M_TWI_Start_Condition(u8 DATA);
void M_TWI_Stop(void);
//-------------------------------------------------------------------------------------------//
void Init_S_TWI(void);
u8 Slave_TWI_Receive(void);


void MASTER_SEND_ADDRESS_WRITE(u8 adress);
void MASTER_SEND_DATA(u8 data);
void MASTER_SEND_ADDRESS_READ(u8 adress);
void vMASTER_REP_START_condition(void);
u8 MASTER_RECIVE_DATA(void);
void vMASTER_init(void);
void vMASTER_START_condition(void);
u8 M_I2C_RecieveByte_ACK(void);






#endif /* MCAL_TWI_TWI_INIT_H_ */
