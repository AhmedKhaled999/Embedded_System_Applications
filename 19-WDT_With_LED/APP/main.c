/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task19****************************/
/*Write a C code that control
 * The LED and use  WDT                  //task --> 20 ms
 *
 */
#include"../LIB/LSTD_TYPES.h"
#include"../MCAL/MWDT/MWDT_Interface.h"
#include"../HAL/HLED/HLED_Interface.h"

#define F_CPU  8000000UL
#include<util\delay.h>

	LED_t LED1 = {HLED_PORTA,PIN0};

void APP_VidLedBlinking(void)
{
	HLED_VidLed_On(&LED1);
   _delay_ms(500);
   HLED_VidLed_Off(&LED1);
   _delay_ms(200);
}
int main(void)
{
	HLED_VidInit(&LED1);
	MWDT_VidEnable();
	/*Sleep for 1 sec*/
	MWDT_VidWDT_Sleep(6);
	APP_VidLedBlinking();
	MWDT_VidDisable();
	while(1)
	{

	}
	return 0 ;
}
