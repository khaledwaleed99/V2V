 /***************************************
 *  File		: Uart.h
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 ****************************************/
#ifndef UART_PROTOTYPES_H
#define UART_PROTOTYPES_H

#include "UART_PROTOTYPES.h"

#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"
#include "UART_CONFIG.h"

#define TX_BUFFER_MAX_SIZE			(50)
#define RX_BUFFER_MAX_SIZE			(50)

#define UART_BAUDRATE_1200			(0x340)
#define UART_BAUDRATE_2400			(0x19F)
#define UART_BAUDRATE_4800			(0xCF)
#define UART_BAUDRATE_9600			(0x67)
#define UART_BAUDRATE_19200			(0x51)
#define UART_BAUDRATE_115200		(0x7)


#define UART_5_BIT_DATA				(0<<UCSZ0_BIT_NO)
#define UART_6_BIT_DATA				(1<<UCSZ0_BIT_NO)
#define UART_7_BIT_DATA				(2<<UCSZ0_BIT_NO)
#define UART_8_BIT_DATA				(3<<UCSZ0_BIT_NO)

#define UART_1_STOP_BIT				(0<<USBS_BIT_NO)
#define UART_2_STOP_BIT				(1<<USBS_BIT_NO)

#define UART_EVEN_PARITY			(2<<UPM0_BIT_NO)
#define UART_ODD_PARITY				(3<<UPM0_BIT_NO)

#define USART0_TXC_VECT      __vector_20
#define USART0_RXC_VECT      __vector_18

#define USART1_TXC_VECT      __vector_32
#define USART1_RXC_VECT      __vector_30

//#define  TRUE   1
//#define  FALSE  0

void UART0_Init(uint16 baudRate);
void UART1_Init(uint16 baudRate);
void UART0_TransmitChr(uint8 data);
void UART1_TransmitChr(uint8 data);
uint8 UART0_ReceiveChr(void);
uint8 UART1_ReceiveChr(void);
void UART0_TransmitStrPoll(uint8 str[]);
void UART1_TransmitStrPoll(uint8 str[]);
#endif  /* UART_H */
