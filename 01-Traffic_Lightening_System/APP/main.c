/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task1****************************/
/*Write a C code that simulate the traffic lightening system:
1- Turn On Green LED for 10 seconds
2- Turn On Yellow LED for 3 seconds
3- Turn On Red LED for 10 seconds
4- Apply these forever while counting the seconds down on a 2 7-segment
displays.*/


#include"../LIB/LSTD_TYPES.h"
//#include<util\delay.h>
#include"../HAL/HSEVEN_SEGMENT/HSEVEN_SEGMENT_Interface.h"
#include"../HAL/HLED/HLED_Interface.h"

/*Define 8 LEDs from PA0--->PA7*/
LED_t R_LED1 = {HLED_PORTA,PIN0};
LED_t Y_LED2 = {HLED_PORTA,PIN1};
LED_t G_LED3 = {HLED_PORTA,PIN2};

/*Define 2 Seven Segment*/

SEVEN_SEGMENT_t SEVEN_SEG1={HSEVEN_SEGMENT_PORTB,COMMON_CATHODE};
SEVEN_SEGMENT_t SEVEN_SEG2={HSEVEN_SEGMENT_PORTD,COMMON_CATHODE};

void APP_Delay_ms(u16 Copy_u16Delay_ms)
{

	u64 i  ;
	/*look at this code in Assembly and you detect That it takes 8 instructions in assembly and each instruction take 1 clock cycle
	 * so for one iteration we need 1*8 = 8 clock cycles , Fcpu = 8MHz so, tick time = 1/8MHz = 0.125 micro sec , one iteration take 8*0.125 =1 micro sec
	 * 1ms--->1000 iterations */
	for(i= (Copy_u16Delay_ms * 1000); i > 0 ; i--)
	{
		/*Do Nothing*/
	}
}
void APP_CountDown(u8 Copy_u8Number)
{
	u8 j=0;
	if(Copy_u8Number==10){
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,1);
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG2,0);
		APP_Delay_ms(1000);
		HSEVEN_SEGMENT_VidOff(&SEVEN_SEG1,OFF);
		j = 9;
	}
	else
	{
		j = Copy_u8Number;
	}
	for(;j>0;j--)
	{
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG2,j);
		APP_Delay_ms(1000);
	}

}
int main(void)
{

	HLED_VidInit(&R_LED1);
	HLED_VidInit(&Y_LED2);
	HLED_VidInit(&G_LED3);
	HSEVEN_SEGMENT_VidInit(&SEVEN_SEG1);
	HSEVEN_SEGMENT_VidInit(&SEVEN_SEG2);

	while(1)
	{
		/*1- Turn On Green LED for 10 seconds*/
		HLED_VidLed_Off(&G_LED3);
		HLED_VidLed_On(&R_LED1);
		APP_CountDown(10);
		/*2- Turn On Yellow LED for 3 seconds*/
		HLED_VidLed_Off(&R_LED1);
		HLED_VidLed_On(&Y_LED2);
		APP_CountDown(3);
		/*3- Turn On Red LED for 10 seconds*/
		HLED_VidLed_Off(&R_LED1);
		HLED_VidLed_Off(&Y_LED2);
		HLED_VidLed_On(&G_LED3);
		APP_CountDown(10);
	}
}
