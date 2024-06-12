/*
 * DC_MOTOR_Interface.h
 *
 *  Created on: Dec 30, 2023
 *      Author: shady
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_
#define HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_
#include"STD_TYPES.h"
#include"DC_MOTOR_Cfg.h"
void DC_VoidDCMOTORInit();
void DC_VoidMOTORON(u8 DutyCycle,DC_MOTORDIRECTION MOTORDIRECTION);
void DC_VoidDCMOTORStop(void);



#endif /* HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_ */
