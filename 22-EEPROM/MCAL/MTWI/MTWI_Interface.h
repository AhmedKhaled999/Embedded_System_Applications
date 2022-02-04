/*
 * MTWI_Interface.h
 *
 *  Created on: Feb 3, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MTWI_MTWI_INTERFACE_H_
#define MCAL_MTWI_MTWI_INTERFACE_H_

typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
	MasterReadByteNErrNACK
}TWI_ErrStatus;

/*TWI Initialization as a master with set Master Address*/
//void MTWI_VidInitMaster(u8 Copy_u8Address);
/*TWI Initialization as a Slave with set Master Address*/
/*
void MTWI_VidInitSlave(u8 Copy_u8Address);
TWI_ErrStatus MTWI_SendStartCondition(void);
TWI_ErrStatus MTWI_SendRepeatedStart(void);
TWI_ErrStatus MTWI_SendSlaveAddresWithWrite(u8 Copy_u8SlaveAddress);
TWI_ErrStatus MTWI_SendSlaveAddresWithRead(u8 Copy_u8SlaveAddress);
TWI_ErrStatus MTWI_MasterWriteDataByte(u8 Copy_u8DataByte);
TWI_ErrStatus MTWI_MasterReadDataByte(u8* Copy_pu8DataByte);
void MTWI_SendStopCondition(void);
*/
void MTWI_VidInitMaster(void);
void MTWI_SendStartCondition(void);
void MTWI_SendStopCondition(void);
void MTWI_MasterWriteDataByte(u8 Copy_u8DataByte);
u8 MTWI_MasterReadDataByteWith_ACK(void); //read with send Ack
u8 MTWI_MasterReadDataByteWith_NACK(void);          //read without send Ack
u8 MTWI_MASTERGetStatus(void);



#endif /* MCAL_MTWI_MTWI_INTERFACE_H_ */




