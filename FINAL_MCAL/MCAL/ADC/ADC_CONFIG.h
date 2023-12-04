/*
 * ADC_CONFIG.h
 *
 * Created: 11/27/2023 8:55:29 PM
 *  Author: khaled waleed
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#include "ATMEGA_128_REGS.h"
#include "BIT_MATH.h"

typedef enum
{
	VREFF_AVCC = 0x40      ,
	VREFF_INTERNAL = 0xC0  ,
	VREFF_AREF = 0x00
}ADC_VOLTAGE;


typedef enum{
	ADC_CHANNEL_0 = 0x00     ,
	ADC_CHANNEL_1 = 0x01     ,
	ADC_CHANNEL_2 = 0x02     ,
	ADC_CHANNEL_3 = 0x03     ,
	ADC_CHANNEL_4 = 0x04     ,
	ADC_CHANNEL_5 = 0x05     ,
	ADC_CHANNEL_6 = 0x06     ,
	ADC_CHANNEL_7 = 0x07
}ADC_CHANNEL_ID;


typedef enum {
	ADC_MANUAL_TRIGGER,
	ADC_AUTO_TRIGGER
}ACD_TRIGGER_CONTROL;



typedef enum{
	ADC_RIGHT_ADJUST   ,
	ADC_LEFT_ADJUST = 0x20
}ADC_ADJUSTMENT_CONRTOL;


typedef enum{
	ADC_DIV_2    = 0x01         ,
	ADC_DIV_4    = 0x02         ,
	ADC_DIV_8    = 0x03         ,
	ADC_DIV_16   = 0x04         ,
	ADC_DIV_32   = 0x05         ,
	ADC_DIV_64   = 0x06         ,
	ADC_DIV_128  = 0x07
}ADC_PRESCALER_VALUE;


typedef enum{
	ADC_INTERRUPT_DISABLE  ,
	ADC_INTERRUPT_ENEBLE
}ADC_INTERRUPT_STATUS;




#endif /* ADC_CONFIG_H_ */