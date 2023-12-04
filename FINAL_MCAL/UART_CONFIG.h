 /******************************************
 *  File		: Uart.h
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *******************************************/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#include "../../LIB/STD_TYPES.h"
#include "UART_PROTOTYPES.h"



#define RXEN_BIT_NO						(4)
#define TXEN_BIT_NO						(3)
#define URSEL_BIT_NO					(7)
#define USBS_BIT_NO						(3)
#define UCSZ0_BIT_NO					(1)
#define UPM0_BIT_NO						(4)
#define UDRE_BIT_NO						(5)
#define TXC_BIT_NO						(6)
#define RXC_BIT_NO						(7)

#endif  /* UART_PRIVATE_H */
