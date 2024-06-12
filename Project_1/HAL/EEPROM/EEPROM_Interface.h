/*
 * EEPROM_Interface.h
 *
 *  Created on: Dec 22, 2023
 *      Author: shady
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_


void EEPROM_WRITE(u16 wordadd, u8 data);
u8 EEPROM_READ(u16 wordadd);


#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
