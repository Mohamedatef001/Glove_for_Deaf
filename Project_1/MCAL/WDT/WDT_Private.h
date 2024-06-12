/*
 * WDT_Private.h
 *
 *  Created on: Jun 7, 2024
 *      Author: newwo
 */

#ifndef MCAL_WDT_WDT_PRIVATE_H_
#define MCAL_WDT_WDT_PRIVATE_H_
#include "WDT.h"

#define WDTCR  (*((volatile u8*)0x41))

#define WDTOE 4
#define WDE   3
#define WDP2  2
#define WDP1  1
#define WDP0  0

#endif /* MCAL_WDT_WDT_PRIVATE_H_ */
