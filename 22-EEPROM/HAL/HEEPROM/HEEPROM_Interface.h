/*
 * HEPPROM_Interface.h
 *
 *  Created on: Feb 3, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef HAL_HEEPROM_HEEPROM_INTERFACE_H_
#define HAL_HEEPROM_HEEPROM_INTERFACE_H_


#define ERROR 0
#define SUCCESS 1

/*Initialize EEPROM*/
void HEEPROM_VidInit(void);
/*Send byte to EEPROM*/
u8 HEEPROM_VidWriteDataByte(u8 Copy_u8LocationAddress,u8 Copy_u8ChipNum,u8 Copy_u8BlockNum,u8 Copy_u8DataByte);
u8 HEEPROM_Write_Byte(u16 Copy_u16Address,u8 Copy_u8DataByte);

/*Read byte to EEPROM*/
u8 HEEPROM_VidReadDataByte(u8 Copy_u8LocationAddress,u8 Copy_u8ChipNum,u8 Copy_u8BlockNum);
u8 HEEPROM_Read_Byte(u16 Copy_u16Address,u8 *Copy_u8DataByte);

#endif /* HAL_HEEPROM_HEEPROM_INTERFACE_H_ */
