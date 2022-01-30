/*
 * MTIMER_Interface.h
 *
 *  Created on: Jan 17, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MTIMER_MTIMER_INTERFACE_H_
#define MCAL_MTIMER_MTIMER_INTERFACE_H_



/*Timer0 Initialization*/
void MTIMER0_VidInit(void);
/*Set Preload Function*/
void MTIMER0_VidSetPreload(u8 Copy_u8Preload);
/*Set CTC Value Function*/
void MTIMER0_VidSetCTCValue(u8 Copy_u8CTCValue);
void MTIMER0_VidOVF_SetCallBack(void(*Copy_VidCallBack)(void));
void MTIMER0_VidCTC_SetCallBack(void(*Copy_VidCallBack)(void));

#endif /* MCAL_MTIMER_MTIMER_INTERFACE_H_ */
