/*
 * I2C_PROTOTYPES.h
 *
 * Created: 11/27/2023 10:31:00 PM
 *  Author: khaled waleed
 */ 


#ifndef I2C_PROTOTYPES_H_
#define I2C_PROTOTYPES_H_


#include "I2C_CONFIG.h"

void TWI_vInitMaster(uint8 Copy_uint8Address);

void TWI_vSendStartCondition(void);

void TWI_vSendRepStartCondition(void);

void TWI_vSendStopCondition(void);

void TWI_vSendSlaveAddressWithWrite(uint8 Copy_uint8SlaveAddress);

void TWI_vSendSlaveAddressWithRead(uint8 Copy_uint8SlaveAddress);

void TWI_vWriteMasterDataByte(uint8 Copy_uint8TxData);

void TWI_vReadMasterDataByte(uint8* Copy_puint8RxData,uint8 Copy_uint8AckNack);

#endif /* I2C_PROTOTYPES_H_ */