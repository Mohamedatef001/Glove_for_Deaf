/*
 * BIT_MATH.h
 *
 *  Created on: Feb 9, 2024
 *      Author: newwo
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define GET_BIT(Reg,Bit_Num) ((Reg>>Bit_Num)&0x01)
#define SET_BIT(reg,bit_num) reg |=(1<<bit_num)
#define CLR_BIT(reg,bit_num) reg &= ~(1<<bit_num)
#define TOGGLE_BIT(reg,bit_num) reg^=(1<<bit_num)

#endif /* BIT_MATH_H_ */
