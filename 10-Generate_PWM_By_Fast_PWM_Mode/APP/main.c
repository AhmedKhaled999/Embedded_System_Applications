/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task10****************************/
/*Write a C code that that Generate PWM With F = 3906.25Hz ,D = 75%  by Fast PWM mode and control the  Motor Speed with it :
 */


#include"../LIB/LSTD_TYPES.h"
#include"../HAL/HLED/HLED_Interface.h"
#include"../MCAL/MGIE/MGIE_Interface.h"
#include"../MCAL/MTIMER/MTIMER_Interface.h"
#define F_CPU  8000000UL
#include<util\delay.h>

/*Hardware Interface--> OC0*/
LED_t Y_LED4 = {HLED_PORTB,PIN3};



int main(void)
{


	/*F_cpu = 8MHz, prescaler = 8 -->F_timer = 1MHZ , T_tick = 1 micro second ,One_OVF = 256*1 = 256  micro second ,
	 * F_out = Fcpu/N*256
	 * F_out           |   N     |
	 * ----------------|---------|
	 * 31250Hz         |   1     |
	 * ----------------|---------|
	 * 3906.25Hz       |   8     |
	 * ----------------|---------|
	 * 488.28125Hz     |   64    |
	 *-----------------|---------|
	 * 122.0703125Hz   |   256   |
	 *-----------------|---------|
	 * 30.51757813Hz   |   1024  |
	 *-----------------|---------|
	 * T = 1 / F_out --> 1/3906.25 = 256 micro second
	 * Duty cycle = (T_on*100)/T
	 * T_on depend on the  the value of OCR
	 * if you need D = 75% --> T_on = T*D = 256 * 0.75 = 192 micro second -->Note OCR = 192 ticks    if you in NON_Inverting mode
	 * V_out = D * V_in
	 * */

	//MTIMER0_VidSetCTCValue(192);
	/*Timer Initialization*/
	MTIMER0_VidInit();
	//MGIE_VidEnable();

	/*Generate PWM on this OC0-->Pin PB3*/
	HLED_VidInit(&Y_LED4);

	while(1)
	{
		/*change in T_on*/
		MTIMER0_VidSetCTCValue(100);
		_delay_ms(3000);
		MTIMER0_VidSetCTCValue(128);
		_delay_ms(3000);
		MTIMER0_VidSetCTCValue(192);   //D= 75%
		_delay_ms(3000);
		MTIMER0_VidSetCTCValue(220);
		_delay_ms(3000);
		MTIMER0_VidSetCTCValue(255);   //D = 100%
		_delay_ms(3000);
	}
	return 0 ;

}


