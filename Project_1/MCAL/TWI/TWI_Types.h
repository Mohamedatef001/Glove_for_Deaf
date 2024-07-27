/*
 * TWI_Types.h
 *
 *  Created on: Mar 10, 2023
 *      Author: Mohamed_Atef
 */

#ifndef MCAL_TWI_TWI_TYPES_H_
#define MCAL_TWI_TWI_TYPES_H_

typedef enum{
	Prescaler_1=0,
	Prescaler_4=1,
	Prescaler_16=2,
	Prescaler_64=3
}Prescaler;

typedef enum{
	start_condition_transmitted= 0x08,
	repeated_start_transmitted= 0x10,
	SLA_W_transmitted_ack_recieved=0x18,
	SLA_W_transmitted_NOT_ACK_received=0x20,
	Data_byte_transmitted_ACK_received=0x28,
	Data_byte_transmitted_NOT_ACK_received=0x30,
	Arbitration_lost=0x38,
	SLA_R_transmitted_ack_recieved=0x40,
	SLA_R_transmitted_NOT_ACK_received=0x48,
	Data_byte_recieved_ACK_received=0x50,
	Data_byte_recieved_NOT_ACK_received=0x55
}Master_Mode;
//typedef enum{
//	start_condition_transmitted= 0x08,
//	repeated_start_transmitted= 0x10,
//	SLA_W_transmitted_ack_recieved=0x18,
//	SLA_W_transmitted_NOT_ACK_received=0x20,
//	Data_byte_transmitted_ACK_received=0x28,
//	Data_byte_transmitted_NOT_ACK_received=0x30,
//	Arbitration_lost=0x38,
//	SLA_R_transmitted_ack_recieved=0x40,
//	SLA_R_transmitted_NOT_ACK_received=0x48,
//	Data_byte_recieved_ACK_received=0x50,
//	Data_byte_recieved_NOT_ACK_received=0x55
//}Slave_Mode;

#endif /* MCAL_TWI_TWI_TYPES_H_ */
