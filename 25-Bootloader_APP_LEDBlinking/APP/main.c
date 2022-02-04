/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task 25****************************/
/*Write a C code that control
 * that toggle LED every 1 sec
 *
 */

#include "avr/io.h"

#define F_CPU 8000000UL

#include"avr/delay.h"

int main()
{

	DDRA =0xFF ;
	while(1)
	{
		PORTA ^= 0x01 ;
		_delay_ms(1000);
	}

	return 1 ;

}
