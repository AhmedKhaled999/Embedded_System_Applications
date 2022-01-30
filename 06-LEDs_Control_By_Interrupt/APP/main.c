/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task6****************************/
/*Write a C code that Control Three LEDs by one PushButton Switch with use Interrupt:
1- Turn on Blue  LED for first  pressed
2- Turn on Red   LED for second pressed
3- Turn on Green LED for Third  pressed
4- Turn off all LEDs for Fourth Pressed
 */


#include"../LIB/LSTD_TYPES.h"
#include"../HAL/HLED/HLED_Interface.h"
#include"../HAL/HSWITCH/HSWITCH_Interface.h"
#include"../MCAL/MGIE/MGIE_Interface.h"
#include"../MCAL/MEXTI/MEXTI_Interface.h"

#define F_CPU  8000000UL
#include<util\delay.h>

/*Define 8 LEDs from PA0--->PA7*/
LED_t B_LED1 = {HLED_PORTA,PIN0};
LED_t R_LED2 = {HLED_PORTA,PIN1};
LED_t G_LED3 = {HLED_PORTA,PIN2};

/*Define Switch*/
SWITCH_t Switch_1 ={HSWITCH_PORTD,PIN3} ;

static u8 Flag = 0 ;
int main(void)
{

	/*Initialize LEDs Positive Logic */

	HLED_VidInit(&B_LED1);
	HLED_VidInit(&R_LED2);
	HLED_VidInit(&G_LED3);
	/*Initialize Switch interface as Pull resistance */
	HSWITCH_VidInit_PullUP(&Switch_1);
    _delay_ms(2000);

	MEXTI1_VidInit();
	MGIE_VidEnable();
	while(1)
	{
		if(Flag == 0)
		{
			HLED_VidLed_Off(&B_LED1);
			HLED_VidLed_Off(&R_LED2);
			HLED_VidLed_Off(&G_LED3);
		}
		else if(Flag == 1)
		{
			HLED_VidLed_On(&B_LED1);
		}
		else if(Flag == 2)
		{
			HLED_VidLed_On(&R_LED2);
		}
		else if(Flag == 3)
		{
			HLED_VidLed_On(&G_LED3);
		}


	}

	return 0 ;
}

	void __vector_2(void)       __attribute__((signal));
	void __vector_2(void)
	{
		//HLED_VidLed_Toggle(&LED1);
		Flag++;
		if(Flag==4)
		{
			Flag = 0;
		}
	}

