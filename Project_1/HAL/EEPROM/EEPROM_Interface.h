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
void EEPROM_WRITE_String(u16 wordadd, u8 *data);
void EEPROM_READ_String(u16 wordadd, u8 *buffer, u16 length);



#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
