/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task13****************************/
/*Write a C code that that Generate PWM With F =  245.0980392Hz ,D = 75%  by phase Correct Fast PWM mode IN TIMER0  and control the  Motor Speed with it
 * Then use Input Capture unit Hardware  To Measure The Frequency and Duty Cycle :
 */


#include"../LIB/LSTD_TYPES.h"
#include"../MCAL/MDIO/MDIO_Interface.h"
#include"../HAL/HLED/HLED_Interface.h"
#include"../MCAL/MGIE/MGIE_Interface.h"
#include"../MCAL/MTIMER/MTIMER_Interface.h"
#include"../HAL/HCLCD/HCLCD_Interface.h"

#define F_CPU  8000000UL
#include<util\delay.h>

/*Hardware Interface--> OC0*/
LED_t Y_LED4 = {HLED_PORTB,PIN3};


static u8 Flag=0;
static u8 Count=0;
static u32 T1=0;
static u32 T2=0;
static u32 T3=0;

void App_TIMER1_OVF_ISR(void);
void App_TIMER1_ICF_ISR(void);


int main(void)
{
	/*Generate PWM on this OC0-->Pin PB3*/
	HLED_VidInit(&Y_LED4);
	/*LCD Initialization*/
	HCLCD_Vid4Bits_Init();
	/*Send Welcome message*/
	HCLCD_Vid4Bits_DisplayString((u8*)"Welcome....");
	_delay_ms(1000);
	HCLCD_Vid4Bits_ClearScreen();

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
	/*Set CTC Value-->DutyCycle=75%*/
	MTIMER0_VidSetCTCValue(191);

	/*Timer0 Initialization in Phase Correct PWM */
	MTIMER0_VidInit();
	/*Timer1 Initialization-->-->Set timer1 in Input Capture Mode
	 * F_cpu = 8MHz, NO_Prescaler --> F_timer = 8MHz -->T_tick = 0.125 micro second-->one_OFV = 0.125 *65536 = 8192 micro second = 8.192 ms
	 * TIMER1 Sense Control----> Rising Edge*/
	MTIMER1_VidInit();
	/*Set EXTI Call Back*/
	MTIMER1_VidICF_SetCallBack(&App_TIMER1_ICF_ISR);
	MTIMER1_VidOVF_SetCallBack(&App_TIMER1_OVF_ISR);

	/*Enable To GIE*/
	MGIE_VidEnable();
	u32 Freq = 0;
	u16 DutyCycle = 0;

	while(1)
	{
		if(Flag==3)
		{
			/*Frequency in HZ*/
			Freq=(1000000/((T3-T1)*0.125));  //T3-T1=32651  * 0.125 = 4081.375 micro second  f= 2.45 *10^-4 MHz ---*10^6-->245 HZ
			DutyCycle=((f32)(T2-T1)/(T3-T1)*100);
			HCLCD_Vid4Bits_SetPosition(1,0);
			HCLCD_Vid4Bits_DisplayString((u8*) "DutyCycle=");
		    HCLCD_Vid4Bits_DisplayNumber(DutyCycle);
			HCLCD_Vid4Bits_DisplayString((u8*)"%");
			HCLCD_Vid4Bits_SetPosition(2,0);
			HCLCD_Vid4Bits_DisplayString((u8*)"Freq=");
			HCLCD_Vid4Bits_DisplayNumber(Freq);
			HCLCD_Vid4Bits_DisplayString((u8*)" Hz");
			//HCLCD_Vid4Bits_DisplayNumber(T1);
			//HCLCD_Vid4Bits_DisplayString((u8*)",");
			//HCLCD_Vid4Bits_DisplayNumber(T3);

			Flag = 4 ;
		}
	}
	return 0 ;

}
void App_TIMER1_ICF_ISR(void)
{
	if(Flag==0)
	{
		T1= MTIMER1_u16GetICR1Value()+Count*65536;
		MTIMER1_VidSenseControl(MTIMER1_ICU_FALLING_EDGE);
		Flag=1;
	}
	else if(Flag==1)
	{
		T2=	 MTIMER1_u16GetICR1Value()+Count*65536;
		MTIMER1_VidSenseControl(MTIMER1_ICU_RISING_EDGE);
		Flag=2;
	}
	else if(Flag==2)
	{
		T3= MTIMER1_u16GetICR1Value()+Count*65536;
		Flag=3;
	}
}

void App_TIMER1_OVF_ISR(void)
{
	Count++ ;
}
