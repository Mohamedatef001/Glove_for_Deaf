/*
 * WDT_Program.c
 *
 *  Created on: Jun 7, 2024
 *      Author: newwo
 */

#include "WDT_Private.h"
#include "STD_TYPES.h"

void WDT_Enable(WDT_T time)
{
	WDTCR = 0b11101000 | time ;
}

void WDT_Disable(void)
{
	/* Write logical one to WDTOE and WDE */
	WDTCR = (1<<WDTOE) | (1<<WDE);
	/* Turn off WDT */
	WDTCR = 0x00;
}
