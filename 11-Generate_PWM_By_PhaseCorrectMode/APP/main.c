/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task11****************************/
/*Write a C code that that Generate PWM With F =  245.0980392Hz ,D = 75%  by phase Correct Fast PWM mode and control the  Motor Speed with it :
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


	/*F_cpu = 8MHz, prescaler = 64 -->F_timer = 125000HZ , T_tick = 8 micro second ,One_OVF = 256*8 = 2048  micro second ,
	 * F_out = Fcpu/N*510
	 * F_out           |   N     |
	 * ----------------|---------|
	 * 15686.27451Hz   |   1     |
	 * ----------------|---------|    510 ticks---->4.08ms
	 * 1960.784314Hz   |   8     |     ?? ticks---->3.06ms   ----------->??=382.5 ticks   so,OCR = 382.5/2 = 191 Ticks
	 * ----------------|---------|
	 * 245.0980392Hz   |   64    |
	 *-----------------|---------|
	 * 61.2745098Hz    |   256   |
	 *-----------------|---------|
	 * 15.31862745Hz   |   1024  |
	 *-----------------|---------|
	 * T = 1 / F_out --> 1/245.0980392 = 4080 micro second  = 4.08 ms
	 * Duty cycle = (T_on*100)/T
	 * T_on depend on the  the value of OCR
	 * if you need D = 75% --> T_on = T*D = 4.08 * 0.75 = 3.06 ms -->Note OCR = 192 ticks    if you in NON_Inverting mode
	 * V_out = D * V_in
	 * */

	MTIMER0_VidSetCTCValue(191);
	/*Timer Initialization*/
	MTIMER0_VidInit();
	//MGIE_VidEnable();

	/*Generate PWM on this OC0-->Pin PB3*/
	HLED_VidInit(&Y_LED4);

	while(1)
	{
		/*change in T_on*/
		/*MTIMER0_VidSetCTCValue(100);
		_delay_ms(3000);
		MTIMER0_VidSetCTCValue(128);
		_delay_ms(3000);
		MTIMER0_VidSetCTCValue(192);   //D= 75%
		_delay_ms(3000);
		MTIMER0_VidSetCTCValue(220);
		_delay_ms(3000);
		MTIMER0_VidSetCTCValue(255);   //D = 100%
		_delay_ms(3000);*/
	}
	return 0 ;

}


