/*
 * HEEPROM_Program.c
 *
 *  Created on: Feb 3, 2022
 *      Author: Ahmed Khaled Hammad
 */


#define F_CPU 8000000UL
#include"..\..\LIB\LSTD_TYPES.h"

#include"..\..\MCAL\MTWI\MTWI_Interface.h"
#include"..\..\MCAL\MTWI\MTWI_Private.h"

#include"HEEPROM_Private.h"

#include<util\delay.h>



/*Initialize EEPROM*/
void HEEPROM_VidInit(void)
{
	MTWI_VidInitMaster();
}
/*Send byte to EEPROM*/
u8 HEEPROM_VidWriteDataByte(u8 Copy_u8LocationAddress,u8 Copy_u8ChipNum,u8 Copy_u8BlockNum,u8 Copy_u8DataByte)
{
	return NoError;
}
u8 HEEPROM_Write_Byte(u16 Copy_u16Address,u8 Copy_u8DataByte)
{
	MTWI_SendStartCondition();
	if(MTWI_MASTERGetStatus() !=START_ACK)
	{
		return StartConditionErr;
	}
	//write the device address and so we need to get A8 A9 A10 address bits and R/W=0 (write)
	MTWI_MasterWriteDataByte((u8)(0xA0 | ((Copy_u16Address & 0x0700)>>7)));   //0x0700-->0000 0111 0000 0000
	if (MTWI_MASTERGetStatus() != SLAVE_ADD_AND_WR_ACK)
		return SlaveAddressWithWriteErr;

	//send the required location address
	MTWI_MasterWriteDataByte((u8)(Copy_u16Address));
	if (MTWI_MASTERGetStatus() != MSTR_WR_BYTE_ACK)
		return MasterWriteByteErr;

	//write byte to eeprom
	MTWI_MasterWriteDataByte(Copy_u8DataByte);
	if (MTWI_MASTERGetStatus() != MSTR_WR_BYTE_ACK)
		return MasterWriteByteErr;

	MTWI_SendStopCondition();

	return NoError;

}

/*Read byte to EEPROM*/
u8 HEEPROM_VidReadDataByte(u8 Copy_u8LocationAddress,u8 Copy_u8ChipNum,u8 Copy_u8BlockNum)
{
	return NoError;
}
u8 HEEPROM_Read_Byte(u16 Copy_u16Address,u8 *Copy_u8DataByte)
{
	MTWI_SendStartCondition();
	if(MTWI_MASTERGetStatus() !=START_ACK)
	{
		return StartConditionErr;
	}
	//write the device address and so we need to get A8 A9 A10 address bits and R/W=0 (write)
	MTWI_MasterWriteDataByte((u8)(0xA0 | ((Copy_u16Address & 0x0700)>>7)));   //0x0700-->011100000000
	if (MTWI_MASTERGetStatus() != SLAVE_ADD_AND_WR_ACK)
		return SlaveAddressWithWriteErr;

	//send the required location address
	MTWI_MasterWriteDataByte((u8)(Copy_u16Address));
	if (MTWI_MASTERGetStatus() != MSTR_WR_BYTE_ACK)
		return MasterWriteByteErr;
	//send a repeated start
	MTWI_SendStartCondition();
	if (MTWI_MASTERGetStatus() != REP_START_ACK)
		return RepeatedStartErr;

	//write the device address and so we need to get A8 A9 A10 address bits and R/W=1 (Read)
	MTWI_MasterWriteDataByte((u8)(0xA0 | ((Copy_u16Address & 0x0700)>>7) | 1));   //0x0700-->011100000000
	if (MTWI_MASTERGetStatus() != SLAVE_ADD_AND_RD_ACK)
		return SlaveAddressWithReadErr;

	*Copy_u8DataByte = MTWI_MasterReadDataByteWith_NACK();
	if (MTWI_MASTERGetStatus() != MSTR_RD_BYTE_NACK)
		return MasterReadByteNErrNACK;

	MTWI_SendStopCondition();

	return NoError;
}

