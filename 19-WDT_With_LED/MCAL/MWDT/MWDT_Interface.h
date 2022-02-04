/*
 * MWDT_Interface.h
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MWDT_MWDT_INTERFACE_H_
#define MCAL_MWDT_MWDT_INTERFACE_H_


void MWDT_VidEnable(void);
void MWDT_VidDisable(void);

/*Copy_u8SleepValue Options
 * 0  0-->16.ms
 * 1  1-->32.5ms
 * 2  2-->65ms
 * 3  3-->0.13s
 * 4  4-->0.26s
 * 5  5-->0.52s
 * 6  6-->1.0s
 * 7  7-->2.1s*/

void MWDT_VidWDT_Sleep(u8 Copy_u8SleepValue);

#endif /* MCAL_MWDT_MWDT_INTERFACE_H_ */
