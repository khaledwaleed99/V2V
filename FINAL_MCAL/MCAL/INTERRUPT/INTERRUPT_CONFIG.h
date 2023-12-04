/*
 * INTERRUPT_CONFIG.h
 *
 * Created: 11/27/2023 8:16:03 PM
 *  Author: khaled waleed
 */ 


#ifndef INTERRUPT_CONFIG_H_
#define INTERRUPT_CONFIG_H_

#include "ATMEGA_128_REGS.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"

typedef enum 
{
	LOW_LEVEL  = 0, // 00
	ANY_CHANGE = 1, // 01
	FALL_EDGE  = 2, // 10
	RISE_EDGE  = 3, // 11
} Interrupt_signal;

typedef enum
{
	INT0_ID,
	INT1_ID,
	INT2_ID,
	INT3_ID,
	INT4_ID,
	INT5_ID,
	INT6_ID,
	INT7_ID,
}InterruptID_t;

/**********************************************************************************************************************
 *  NON SHARABLE MACROS
 **********************************************************************************************************************/
#define INT_0_4_SC_MASK  (0b11111100)
#define INT_1_5_SC_MASK  (0b11110011)
#define INT_2_6_SC_MASK  (0b11001111)
#define INT_3_7_SC_MASK  (0b00111111)
#define SHIFT_BY_2       (2)
#define SHIFT_BY_4       (4)
#define SHIFT_BY_6       (6)

#define EIMSK_INT0 (0) // External Interrupt Request 0 Enable
#define EIMSK_INT1 (1) // External Interrupt Request 1 Enable
#define EIMSK_INT2 (2) // External Interrupt Request 2 Enable
#define EIMSK_INT3 (3) // External Interrupt Request 3 Enable
#define EIMSK_INT4 (4) // External Interrupt Request 4 Enable
#define EIMSK_INT5 (5) // External Interrupt Request 5 Enable
#define EIMSK_INT6 (6) // External Interrupt Request 6 Enable
#define EIMSK_INT7 (7) // External Interrupt Request 7 Enable

#define EIFR_INT0  (0) //  External Interrupt Flags 0
#define EIFR_INT1  (1) //  External Interrupt Flags 1
#define EIFR_INT2  (2) //  External Interrupt Flags 2
#define EIFR_INT3  (3) //  External Interrupt Flags 3
#define EIFR_INT4  (4) //  External Interrupt Flags 4
#define EIFR_INT5  (5) //  External Interrupt Flags 5
#define EIFR_INT6  (6) //  External Interrupt Flags 6
#define EIFR_INT7  (7) //  External Interrupt Flags 7


#define INT0_VECT     __vector_1
#define INT1_VECT     __vector_2
#define INT2_VECT     __vector_3
#define INT3_VECT     __vector_4
#define INT4_VECT     __vector_5
#define INT5_VECT     __vector_6
#define INT6_VECT     __vector_7
#define INT7_VECT     __vector_8
#define TIMER1_CAPT   __vector_11
#define TIMER3_CAPT   __vector_25



#define ISR(INT_vect)void INT_vect(void) __attribute__((signal)); \
void INT_vect (void)

#endif /* INTERRUPT_CONFIG_H_ */