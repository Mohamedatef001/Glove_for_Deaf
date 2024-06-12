/*
 * EXIT_Cfg.h
 *
 *  Created on: Nov 24, 2023
 *      Author: shady
 */

#ifndef MCAL_EXINT_EXIT_CFG_H_
#define MCAL_EXINT_EXIT_CFG_H_


typedef enum{
 LOW_LEVEL=0,
 LOGICAL_CHANGE=1,
 FALLING_EDGE=2,
 RISING_EDGE=3
}INT_State;

#define INT0 0
#define INT1 1
#define INT2 2


#endif /* MCAL_EXINT_EXIT_CFG_H_ */
