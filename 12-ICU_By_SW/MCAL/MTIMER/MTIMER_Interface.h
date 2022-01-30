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

/***************************************************TIMER1************************************************************/
/*Timer1 Initialization*/
void MTIMER1_VidInit(void);
/*Set Preload Function*/
void MTIMER1_VidSetPreload(u16 Copy_u16Preload);
/*Get Counter Value In Timer1*/
u16 MTIMER1_u16GetTCNT1Value(void);

void MTIMER1_VidOVF_SetCallBack(void(*Copy_VidCallBack)(void));
void MTIMER1_VidICF_SetCallBack(void(*Copy_VidCallBack)(void));

#endif /* MCAL_MTIMER_MTIMER_INTERFACE_H_ */
