 /**************************************************
 *  File		: Uart.c
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *
 ***************************************************/
#include "../../LIB/ATMEGA_128_REGS.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/ERROR_STATES.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_PROTOTYPES.h"
#include <avr/interrupt.h>
#include "UART_PROTOTYPES.h"

void (*G_UART0_CallBack_Transmit)(void)=NULL;
void (*G_UART0_CallBack_Rec)(void)=NULL;

void (*G_UART1_CallBack_Transmit)(void)=NULL;
void (*G_UART1_CallBack_Rec)(void)=NULL;


void UART0_Init(uint16 baudRate)
{
	/* Set baud rate */
	UBRR0H = (uint8)(baudRate>>8);
	UBRR0L = (uint8)baudRate;
	/* Enable receiver and transmitter */
	SET_BIT(UCSR0B,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UCSR0B,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UCSR0C |= (1 << URSEL_BIT_NO)|UART_8_BIT_DATA | UART_EVEN_PARITY;


	/*	Enable Rx complete	*/
	SET_BIT(UCSR0B,RXC_BIT_NO);
	/*	Enable Tx complete	*/
	SET_BIT(UCSR0B,TXC_BIT_NO);
}

void UART1_Init(uint16 baudRate)
{
	/* Set baud rate */
	UBRR1H = (uint8)(baudRate>>8);
	UBRR1L = (uint8)baudRate;
	/* Enable receiver and transmitter */
	SET_BIT(UCSR1B,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UCSR1B,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UCSR1C |= (1 << URSEL_BIT_NO)|UART_8_BIT_DATA | UART_EVEN_PARITY;

	
	/*	Enable Rx complete	*/
	SET_BIT(UCSR1B,RXC_BIT_NO);
	/*	Enable Tx complete	*/
	SET_BIT(UCSR1B,TXC_BIT_NO);
}

void UART0_TransmitChr(uint8 data)
{
	/* Wait for empty transmit buffer */
//	while (!(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
//			;
	while (GET_BIT(UCSR0A, 5)==0);   //UDRE
	/* Put data into buffer, sends the data */
	UDR0 = data;

	while (GET_BIT(UCSR0A, 6)==0);    //TXC
}

void UART1_TransmitChr(uint8 data)
{
	/* Wait for empty transmit buffer */
//	while (!(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
//			;
	while (GET_BIT(UCSR1A, 5)==0);   //UDRE
	/* Put data into buffer, sends the data */
	UDR1 = data;

	while (GET_BIT(UCSR1A, 6)==0);    //TXC
}

#if(0)
void UART0_TransmitStr(const uint8 *str)
{
	while (*str != 0)
	{
		/* Wait for empty transmit buffer */
		//	while (!(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
		//			;
		while (GET_BIT(UCSR0A, 5)==0);   //UDRE
		/* Put data into buffer, sends the data */
		UDR0 = *str;
		str++;

		while (GET_BIT(UCSR0A, 6)==0);    //TXC
	}
}

void UART1_TransmitStr(const uint8 *str)
{
	while (*str != 0)
	{
		/* Wait for empty transmit buffer */
		//	while (!(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
		//			;
		while (GET_BIT(UCSR1A, 5)==0);   //UDRE
		/* Put data into buffer, sends the data */
		UDR1 = *str;
		str++;

		while (GET_BIT(UCSR1A, 6)==0);    //TXC
	}
}
#endif

uint8 UART0_ReceiveChr(void)
{
	/* Wait for data to be received */
//	while (!(CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
//			;
	while (GET_BIT(UCSR0A, 7)==0);   //RXC
	/* Get and return received data from buffer */
	return UDR0;
}

uint8 UART1_ReceiveChr(void)
{
	/* Wait for data to be received */
//	while (!(CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
//			;
	while (GET_BIT(UCSR0A, 7)==0);   //RXC
	/* Get and return received data from buffer */
	return UDR1;
}

void UART0_TransmitStrPoll(uint8 str[])
{
	while (*str != '\0')
	{
		UART0_TransmitChr(*str);
		str++;
	}
}

void UART1_TransmitStrPoll(uint8 str[])
{
	while (*str != '\0')
	{
		UART1_TransmitChr(*str);
		str++;
	}
}

// Function CallBack
void Uart0_CALLBACKFUNC_T(void( *Copy_ptr)(void))
{
	if (Copy_ptr != NULL)
	{
		G_UART0_CallBack_Transmit=Copy_ptr;
	}
}

void Uart1_CALLBACKFUNC_T(void( *Copy_ptr)(void))
{
	if (Copy_ptr != NULL)
	{
		G_UART1_CallBack_Transmit=Copy_ptr;
	}
}

void Uart0_CALLBACKFUNC_R(void ( *Copy_ptr)(void))
{
	if (Copy_ptr != NULL)
	{
		G_UART0_CallBack_Rec=Copy_ptr;
	}
}

void Uart1_CALLBACKFUNC_R(void ( *Copy_ptr)(void))
{
	if (Copy_ptr != NULL)
	{
		G_UART1_CallBack_Rec=Copy_ptr;
	}
}


ISR(USART0_TXC_VECT)
{
  if(G_UART0_CallBack_Transmit !=NULL)
   {
	G_UART0_CallBack_Transmit();
   }
}


ISR(USART0_RXC_VECT)
{
	
	G_UART0_CallBack_Rec();

}


ISR(USART1_TXC_VECT)
{
  if(G_UART1_CallBack_Transmit !=NULL)
   {
	G_UART1_CallBack_Transmit();
   }
}


ISR(USART1_RXC_VECT)
{
	
	G_UART1_CallBack_Rec();

}
