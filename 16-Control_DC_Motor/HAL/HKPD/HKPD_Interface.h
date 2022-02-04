/*
 * HKPD_Interface.h
 *
 *  Created on: Jan 16, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef HAL_HKPD_HKPD_INTERFACE_H_
#define HAL_HKPD_HKPD_INTERFACE_H_

#define NOT_PRESSED 255
/*KPD INIT*/
void HKPD_VidInit(void);
/*KPD Get Pressed*/
u8 HKPD_U8GetKeyPressed(void);

#endif /* HAL_HKPD_HKPD_INTERFACE_H_ */
