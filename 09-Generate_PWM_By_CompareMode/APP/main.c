/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task9****************************/
/*Write a C code that that Generate PWM by Compare mode and control the motor speed with it :
 */


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

LED_t Y_LED4 = {HLED_PORTB,PIN3};

/*ISR Function Prototype*/
void APP_VidTIMER0_CTC_ISR(void);


int main(void)
{

	/*ISR Function*/
	MTIMER0_VidCTC_SetCallBack(APP_VidTIMER0_CTC_ISR);
	 /*F_cpu = 8MHz, prescaler = 1024 -->F_timer = 7812.5 HZ , T_tick = 128 micro second ,One_CTF = 250*128 = 32000  micro second , 1 second = 1000000 micro sec
		 * we need NO_CTFs= 31.25 ==(30+0.25)--> 0.25*256 = 64  --->SetCTCValue With 64
		 * at first time then 250 in each time  to make 32 ovf for 1 second
		 * F_out = Fcpu/N*2*(1+OCR)-->@250 in OCR F_out = 8000000/1024*2*(1+250) = 15.56 Hz  --> T = 64.27 ms
		 * F_out @64 in OCR --> F_out = 8000000/1024*2(64+1) = 60.09 Hz   --> T =0.01664 sec = 16.64 ms
		 * */

	MTIMER0_VidSetCTCValue(64);
	/*Timer Initialization*/
	MTIMER0_VidInit();
	MGIE_VidEnable();
	/*Initialize LEDs Positive Logic */

	HLED_VidInit(&B_LED1);
	HLED_VidInit(&R_LED2);
	HLED_VidInit(&G_LED3);
   /*Generate PWM on this Pin PB3*/
	HLED_VidInit(&Y_LED4);

	while(1)
	{

	}
	return 0 ;

}
void APP_VidTIMER0_CTC_ISR(void)
{
	static u8 Count = 0 ;
	Count++;
	//MTIMER0_VidSetCTCValue(64);
	/*one Second*/
	if (Count==32)
	{
		HLED_VidLed_On(&B_LED1);
		HLED_VidLed_Off(&R_LED2);
		HLED_VidLed_Off(&G_LED3);
		//MTIMER0_VidSetCTCValue(64);
	}
	/*Two second*/

	else if(Count==64){
		HLED_VidLed_Off(&B_LED1);
		HLED_VidLed_On(&R_LED2);
		HLED_VidLed_Off(&G_LED3);
		//MTIMER0_VidSetCTCValue(64);

	}
	/*Third Second*/
	else if(Count==96){
		HLED_VidLed_Off(&B_LED1);
		HLED_VidLed_Off(&R_LED2);
		HLED_VidLed_On(&G_LED3);
		//MTIMER0_VidSetCTCValue(64);
		Count = 0 ;
	}
	else{
		/*Do Nothing*/
	}

}

