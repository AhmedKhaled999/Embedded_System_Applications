/*
 * MWDT_Program.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

#include "../../LIB/LSTD_TYPES.h"

#include "../../LIB/LBIT_MATH.h"
#include"MWDT_Private.h"

#define F_CPU  8000000UL
#include<util\delay.h>
void MWDT_VidEnable(void)
{
	SET_BIT(WDTCR,3);
}
void MWDT_VidDisable(void)
{
	/*******************************************Not Accepted*******************************
                 WDTCR |= 0b00011000;----------------> WDTCR = WDTCR |0b00011000
	             CLR_BIT(WDTCR,3);   //Within 4 cycle
	 *************************************************************************************/
	/*******************************************Not Accepted*******************************
	                 WDTCR |= 0b00011000;
		             WDTCR &= 0b11110111;   //Within 4 cycle
	 *************************************************************************************/
	/*******************************************Not Accepted*******************************
		                 WDTCR = 0b00011000;
			             WDTCR = 0b11110111;
    *************************************************************************************/
	 WDTCR =0b00011000; // in one instruction 1 cycle

     WDTCR = 0x00;     	// must be all bits in this Register assigned with zeros


	/**************************************Accepted**************************************
	                 This function use for disable the watchdog timer.
	WDTCR = (1<<4)|(1<<3);
	WDTCR = 0x00;
	 ************************************************************************************/
	/**************************************Accepted**************************************
		                 This function use for disable the watchdog timer.
		WDTCR = 0b00011000;   //in one instruction 1 cycle
		WDTCR = 0x00;         //must be all bits in this Register assigned with zeros
	 ************************************************************************************/


}
void MWDT_VidWDT_Sleep(u8 Copy_u8SleepValue)
{
	WDTCR&=0xF8;
	WDTCR|=Copy_u8SleepValue;
}
