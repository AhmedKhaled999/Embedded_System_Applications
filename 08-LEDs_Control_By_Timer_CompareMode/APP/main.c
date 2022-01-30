/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task8****************************/
/*Write a C code that Control Three LEDs by Timer0 in Compare Mode with use Interrupt:
1- Turn on Blue  LED for one Second and RED,Green Turn off
2- Turn on Red   LED for Two  Second and Blue,Green Turn off
3- Turn on Green LED for THree Second and RED,Blue Turn off
 */

 /*F_cpu = 8MHz, prescaler = 1024 -->F_timer = 7812.5 HZ , T_tick = 128 micro second ,One_OFV = 256*128 = 32768  micro second , 1 second = 1000000 micro sec
	 * we need NO_OFVs = 30.51757813 ==(30+0.51757813)--> 0.51757813*256 = 132.5 -->256-132.5 =123.5 --->Set Preload With 124 to make 31 ovf for 1 second
	MTIMER0_VidSetPreload(124);*/


  /*F_cpu = 8MHz, prescaler = 1024 -->F_timer = 7812.5 HZ , T_tick = 128 micro second ,One_OFV = 250*128 = 32000  micro second , 1 second = 1000000 micro sec
	 * we need NO_OFVs = 31.25 ==(31+0.25)--> 0.25*256 = 64 -->256-64 =192 --->Set Preload With 192 at first time then 6 in each time  to make 32 ovf for 1 second
	MTIMER0_VidSetPreload(192);*/


#include"../LIB/LSTD_TYPES.h"
#include"../HAL/HLED/HLED_Interface.h"
#include"../MCAL/MGIE/MGIE_Interface.h"
#include"../MCAL/MTIMER/MTIMER_Interface.h"
//#define F_CPU  8000000UL
//#include<util\delay.h>

/*Define 8 LEDs from PA0--->PA7*/
LED_t B_LED1 = {HLED_PORTA,PIN0};
LED_t R_LED2 = {HLED_PORTA,PIN1};
LED_t G_LED3 = {HLED_PORTA,PIN2};

/*ISR Function Prototype*/
void APP_VidTIMER0_CTC_ISR(void);


int main(void)
{

	/*ISR Function*/
	MTIMER0_VidCTC_SetCallBack(APP_VidTIMER0_CTC_ISR);
	 /*F_cpu = 8MHz, prescaler = 1024 -->F_timer = 7812.5 HZ , T_tick = 128 micro second ,One_CTF = 250*128 = 32000  micro second , 1 second = 1000000 micro sec
		 * we need NO_CTFs= 31.25 ==(30+0.25)--> 0.25*256 = 64  --->SetCTCValue With 64
		 * at first time then 250 in each time  to make 32 ovf for 1 second*/
	MTIMER0_VidSetCTCValue(64);
	/*Timer Initialization*/
	MTIMER0_VidInit();
	MGIE_VidEnable();
	/*Initialize LEDs Positive Logic */

	HLED_VidInit(&B_LED1);
	HLED_VidInit(&R_LED2);
	HLED_VidInit(&G_LED3);


	while(1)
	{


	}
	return 0 ;

}
void APP_VidTIMER0_CTC_ISR(void)
{
	static u8 Count = 0 ;
	Count++;
	MTIMER0_VidSetCTCValue(250);
	/*one Second*/
	if (Count==32)
	{
		HLED_VidLed_On(&B_LED1);
		HLED_VidLed_Off(&R_LED2);
		HLED_VidLed_Off(&G_LED3);
		MTIMER0_VidSetCTCValue(64);
	}
	/*Two second*/

	else if(Count==64){
		HLED_VidLed_Off(&B_LED1);
		HLED_VidLed_On(&R_LED2);
		HLED_VidLed_Off(&G_LED3);
		MTIMER0_VidSetCTCValue(64);

	}
	/*Third Second*/
	else if(Count==96){
		HLED_VidLed_Off(&B_LED1);
		HLED_VidLed_Off(&R_LED2);
		HLED_VidLed_On(&G_LED3);
		MTIMER0_VidSetCTCValue(64);
		Count = 0 ;
	}
	else{
		/*Do Nothing*/
	}

}

