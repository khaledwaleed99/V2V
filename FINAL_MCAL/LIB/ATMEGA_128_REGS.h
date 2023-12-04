/*
 * ATMEGA_128_REGS.h
 *
 * Created: 11/27/2023 7:50:25 PM
 *  Author: khaled waleed
 */ 


#ifndef ATMEGA_128_REGS_H_
#define ATMEGA_128_REGS_H_

#include "STD_TYPES.h"

#define PORTA   	(*(volatile uint8*)(0x3B))
#define DDRA    	(*(volatile uint8*)(0x3A))
#define PINA		(*(volatile uint8*)(0x39))


#define PORTB   	(*(volatile uint8*)(0x38))
#define DDRB    	(*(volatile uint8*)(0x37))
#define PINB		(*(volatile uint8*)(0x36))

#define PORTC   	(*(volatile uint8*)(0x35))
#define DDRC    	(*(volatile uint8*)(0x34))
#define PINC		(*(volatile uint8*)(0x33))

#define PORTD   	(*(volatile uint8*)(0x32))
#define DDRD    	(*(volatile uint8*)(0x31))
#define PIND		(*(volatile uint8*)(0x30))


#define PORTE   	(*(volatile uint8*)(0x23))
#define DDRE    	(*(volatile uint8*)(0x22))
#define PINE		(*(volatile uint8*)(0x21))

#define PORTF   	(*(volatile uint8*)(0x62))
#define DDRF    	(*(volatile uint8*)(0x61))
#define PINF		(*(volatile uint8*)(0x20))

#define PORTG   	(*(volatile uint8*)(0x65))
#define DDRG    	(*(volatile uint8*)(0x64))
#define PING		(*(volatile uint8*)(0x63))




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                         // ENTERNAL_INTERRUPTS //


#define SREG (*(volatile uint8*)(0x5F))      


#define MCUCR (*(volatile uint8*)(0x55))  

#define MCUCSR (*(volatile uint8*)(0x54))

#define EICRA  (*((volatile uint8 *)0x6A)) // External Interrupt Control Register A

#define EICRB  (*((volatile uint8 *)0x5A)) // External Interrupt Control Register B

#define EIMSK  (*((volatile uint8 *)0x59)) // External Interrupt Mask Register

#define EIFR   (*((volatile uint8 *)0x58)) // External Interrupt Flag Register


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                   // ADC //

/*

 ( NAME :ADC MULTIPLIXER SELECTION ) 

 BITS 6 & 7 ARE THE ONES REPONSIBLE FOR SELECTING THE VREFF SCOURCE (SEE THE TABLE BELOW TO CHOOSE THE VALUES)

 BIT 5 IS THE ONE RESPONSIBLE FOR SELECTING THE TYPE OF ADJUST ( RIGHT ADJUST .. 0 , LEFT ADJUST .. 1 )
 
 BIT 0 -> BIT 4 .. FOR SELECTINHG A CHANNEL FOR ADC .. ( SEE THE TABLE BELOW )
 
*/

#define ADMUX				(*(volatile uint8 *)(0x27))  
                                                        
/*

( NAME :ADC CONTROL AND STATUS ) 

 BIT 7 FOR ENEBLING THE ADC
 BIT 5 IN THIS REGISTER IS THE ONE RESPONSIBLE FOR ENEBLING THE AUTO_TRIGGER ( ENEBLE 1 .. DISABLE .. 0 )
 BITS 0 & 1 & 2 ARE RESPONSIBLE FOR SELECTING THE PRESCALLER ( SEE THE TABLE BELOW ) 
 BIT 6 FOR STARTING THE CONVERSION
 BIT 4 END OF CONVERSION AND SEND THE FLAG
 BIT 3 IS THE ONE RESPOSIBLE FOR ENEBLING THE ADC INTERRUPT 

*/                                                       


#define ADCSRA			    (*(volatile uint8 *)(0x26))   
                                                      

/*
   REGISTERS NEEDED WITH THE LEFT ADJUST CASE 
*/

#define ADCH				(*(volatile uint8 *)(0x25))   
#define ADCL				(*(volatile uint8 *)(0x24))   

/*
RIGHT ADJUST CACSE .. FOR POINTER MANPULATION
*/

#define ADC_ADJUST			(*(volatile uint16 *)(0x24))  

#define SFIOR				(*(volatile uint8 *)(0x40))



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                               // TIMER_0 //
															   

/*
 BITS NO.3 & 6 ARE THE ONES RESPONSIBLE FOR SELECTING THE MODE OF OPERTAION.. ( SEE THE TABLE BELOW)
 BITS NO.0 & 1 & 2 ARE THE ONES REPONSIBLE FOR SELECTING THE VALUE OF PRE_SCALLER .. ( SEE THE TABLE BELOW) 
 BITS NO.4 & 5 FOR PWM CONFIGURATIONS .. REPONSIBLE FOR SELECTING THE MODE ( INVERTED OR NON_INVERTED ) .. ( SEE THE TABLE BELOW )
*/

#define TCCR0       (*(volatile uint8*) (0x53))    

/*
 COUNTER REGISTER
*/

#define TCNT0       (*(volatile uint8*) (0x52))  
 
/*
 BIT NO.0 IS THE ONE RESPONSIBLE FOR ENEBLING INTERRUPT FOR TIMER_0 .. ( EACH TIMER AS ITS OWN BIT )
 
 KEEP IN MIND .. TIMER_0 HAS THE ABILITY TO GEBERATE TWO TYPES OF INTERRUPTS ( OVERFLOW / COMPARE ) WE CHOSE BIT0 FOR THE OVER FLOW . BIT1 FOR COMPARE (CTC)
*/

#define TIMSK		(*(volatile uint8*) (0x57))	

/*
 REG. WHERE THE NO. OF TICKS IS SAVED WHILE USING CTC_MODE
*/

#define OCR0        (*(volatile uint8*) (0x51))	

#define TIFR        (*(volatile uint8*) (0x56))


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                                                                    // TIMER_1 //
																	
/*
 BITS NO.3 & 4 AND BITS NO. 0 & 1 ( IN REG TCCR1A ) ARE REPONSIBLE FOR SELECTING THE MODE .. ( SEE THE TABLE )
 BITS NO. 0 & 1 & 2 ARE THE ONES RESPONSIBLE FOR PRE_SCALLER .. (SEE THE TABLE) & REPONSIBLE FOR STOPPING THE TIMER
*/
																
#define TCCR1B      (*(volatile uint8*) (0x4E))     
                                                    
/*
 BITS NO.0 & 1 AND BITS NO. 3 & 4 ( IN REG TCCR1B ) ARE REPONSIBLE FOR SELECTING THE MODE .. ( SEE THE TABLE )
 BITS NO.4 & 5 ( FOR CHANNEL B ) & BITS NO. 6 & 7 ( CHANNEL A ) RESPONSIBLE FOR SELECTING INTERING OR NON INVERTING MODE IN PWM
*/

#define TCCR1A      (*(volatile uint8*) (0x4F))
       

/*
 REG. WHERE THE NO. OF TICKS IS SAVED WHILE USING CTC_MODE
 
 A IS THE DEFULT REGISTER USED BY TIMER_1
*/

#define OCR1AL        (*(volatile uint16*) (0x4A))
#define OCR1AH       (*(volatile uint16*) (0x4B))

#define OCR1BL        (*(volatile uint16*) (0x48))
#define OCR1BH       (*(volatile uint16*) (0x49))

/*
 COUNTER REGISTERS
*/
#define TCNT1H      (*(volatile uint16*) (0x4D))
#define TCNT1l      (*(volatile uint16*) (0x4C))

#define ICR1L        (*(volatile uint16*) (0x46))
#define ICR1H        (*(volatile uint16*) (0x47)) 


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                               // TIMER_2 //
															   

/*
 BITS NO.3 & 6 ARE THE ONES RESPONSIBLE FOR SELECTING THE MODE OF OPERTAION.. ( SEE THE TABLE BELOW)
 BITS NO.0 & 1 & 2 ARE THE ONES REPONSIBLE FOR SELECTING THE VALUE OF PRE_SCALLER .. ( SEE THE TABLE BELOW) 
 BITS NO.4 & 5 FOR PWM CONFIGURATIONS .. REPONSIBLE FOR SELECTING THE MODE ( INVERTED OR NON_INVERTED ) .. ( SEE THE TABLE BELOW )
*/

#define TCCR2       (*(volatile uint8*) (0x45))    

/*
 COUNTER REGISTER
*/

#define TCNT2       (*(volatile uint8*) (0x44))  
 

/*
 REG. WHERE THE NO. OF TICKS IS SAVED WHILE USING CTC_MODE
*/

#define OCR2        (*(volatile uint8*) (0x43))


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



                                                                    // TIMER_3 //
																	
/*
 BITS NO.3 & 4 AND BITS NO. 0 & 1 ( IN REG TCCR1A ) ARE REPONSIBLE FOR SELECTING THE MODE .. ( SEE THE TABLE )
 BITS NO. 0 & 1 & 2 ARE THE ONES RESPONSIBLE FOR PRE_SCALLER .. (SEE THE TABLE) & REPONSIBLE FOR STOPPING THE TIMER
*/
																
#define TCCR3B      (*(volatile uint8*) (0x8A))     
                                                    
/*
 BITS NO.0 & 1 AND BITS NO. 3 & 4 ( IN REG TCCR1B ) ARE REPONSIBLE FOR SELECTING THE MODE .. ( SEE THE TABLE )
 BITS NO.4 & 5 ( FOR CHANNEL B ) & BITS NO. 6 & 7 ( CHANNEL A ) RESPONSIBLE FOR SELECTING INTERING OR NON INVERTING MODE IN PWM
*/

#define TCCR3A      (*(volatile uint8*) (0x8B))
       

/*
 REG. WHERE THE NO. OF TICKS IS SAVED WHILE USING CTC_MODE
 
 A IS THE DEFULT REGISTER USED BY TIMER_1
*/

#define OCR3AL        (*(volatile uint16*) (0x86))
#define OCR3AH        (*(volatile uint16*) (0x87))

#define OCR3BL        (*(volatile uint16*) (0x84))
#define OCR3BH        (*(volatile uint16*) (0x85))

/*
 COUNTER REGISTERS
*/
#define TCNT3H      (*(volatile uint16*) (0x89))
#define TCNT3L      (*(volatile uint16*) (0x88))

#define ICR3L        (*(volatile uint16*) (0x80))
#define ICR3H        (*(volatile uint16*) (0x81)) 


                                                                   // WATCH_DOG //

#define WDTCR    	(*(volatile uint8*)(0x41))


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                                                                    // UART //
/*
  PLEASE KEEP IN MIND THAT ( UCSRC ) & ( UBRRH ) ARE BOTH HAVING THE SAME ADDRESS, TO CHOOSE WHICH REG TO USE 
  
  WRITE 1 ON BIT.7 IN ( UCSRC ) TO USE UCSRC : BY DEFULT IS SET	
  
  WRITE 0 ON BIT.7 IN ( UCSRC ) TO USE UBRRH		
 */						
																	
/*
 DATA REG.  
 
 WHEN READING  (RECIEVING ) : RX 
 
 WHEN WRITTING ( SENDING ) :  TX
*/
														
#define UDR0 				(*(volatile uint8 *)(0x2C))	
#define UDR1 				(*(volatile uint8 *)(0x9C))	


// THE ONES RESPONSIBLE FOR INITILIZING ALL THE CONFIGURATIONS IN UART //


#define UCSR0A 				(*(volatile uint8 *)(0x2B))
#define UCSR0B 				(*(volatile uint8 *)(0x2A))
#define UCSR0C				(*(volatile uint8 *)(0x95))

#define UCSR1A 				(*(volatile uint8 *)(0x9B))
#define UCSR1B 				(*(volatile uint8 *)(0x9A))
#define UCSR1C				(*(volatile uint8 *)(0x9D))


/*
 RESPONSIBLE FOR SELECTING THE BAUD RATE
-> THE " HIGH " & " LOW " IDEA WAS MADE IN ORDER TO BE ABLE TO DIVIDE BY LARGE NUMBER AS HAVING ONLY 8 BITS IS NOT ENOUGH 
-> FIRST IT WIL FILL THE 8 BITS OF UBRRL THEN USE THE FOUR BITS ( IF NEEDED ) OF UBRRH 
*/

#define UBRR0H 				(*(volatile uint8 *)(0x90))
#define UBRR0L    			(*(volatile uint8 *)(0x29))


#define UBRR1H 				(*(volatile uint8 *)(0x98))
#define UBRR1L    			(*(volatile uint8 *)(0x99))
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                                                                     // SPI //

/*
// BIT NO.4 IS THE ONE RESPONSIBLE FOR MAKING THE SPI MASTER OR SLAVE ( 1 : MASTER ... 0 : SLAVE )
// BIT NO.7 RESPONSIBLE FOR ENEBLING THE INTERRUPT 
// BIT NO.6 FOR ENEBALING THE SPI ( 1 : ENABLE .. 0 : DISABLE )
// BITS NO.0 & NO.1 ARE THE ONES REPONSIBLE FOR SLECTING THE PRE_SCALLER ( SEE THE TABLE BELOW )
// BITS NO.2 & NO.3 ARE THE ONES REPONSBLE FOR THE POLARITY & PHASE OF THE CLOCK 
*/
																	 
#define SPCR          (*(volatile uint8 *)(0x2D))   

/*
 // BIT NO.7 IN THIS REG. IS THE ONE RESPONSIBLE FOR GENERATIG THE INTERRUPT ( FLAG ) FOR THE SPI 
*/

#define SPSR          (*(volatile uint8 *)(0x2E)) 

/*
// DATA REGISTER
*/
   
#define SPDR 		  (*(volatile uint8 *)(0x2F))

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                                                                  // I2C //

/* TWI Control register */
#define TWCR			*((volatile uint8*)(0x74))

/* TWI Data register */
#define TWDR			*((volatile uint8*)(0x73))

/* TWI Address register */
#define TWAR			*((volatile uint8*)(0x72))

/* TWI Status register */
#define TWSR			*((volatile uint8*)(0x71))

/* TWI Bit rate register */
#define TWBR			*((volatile uint8*)(0x70))


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                                                                 // ICU //



/**********************************************************************************************************************
 *  REGISTERS ADDRESSES
 **********************************************************************************************************************/


#define TCCR3A (*((volatile uint8 *)0x8B))  // Timer/Counter 3 Control Register A
#define TCCR3B (*((volatile uint8 *)0x8A))  // Timer/Counter 3 Control Register B
#define ICR1   (*((volatile uint16*)0x46))  // Timer1 Input Capture Register
#define ICR3   (*((volatile uint16*)0x80))  // Timer3 Input Capture Register

#define ETIMSK (*((volatile uint8 *)0x7D))  // Extended Timer/Counter Interrupt Mask Register

#define ETIFR  (*((volatile uint8 *)0x7C))  // Extended Timer/Counter Interrupt Flag Register




#endif /* ATMEGA_128_REGS_H_ */