/*
 * ICU_CONFIG.h
 *
 * Created: 11/28/2023 1:50:20 PM
 *  Author: khaled waleed
 */ 


#ifndef ICU_CONFIG_H_
#define ICU_CONFIG_H_

#include "ATMEGA_128_REGS.h"
#include "BIT_MATH.h"


/**********************************************************************************************************************
 * USER DEFINED DATA TYPES
 **********************************************************************************************************************/
typedef enum {
	FALLING, RISING
} Edge_t;

typedef enum {
	ICU1, ICU3
} ICU_t;

/**********************************************************************************************************************
 *  NON SHARABLE MACROS
 **********************************************************************************************************************/
#define CLOCK_SELECT_MASK (0b11111000)
/** Prescaler Select **/
#define NO_CLK                                (0)
#define FCPU                                  (1)
#define PRESCALER_8                           (2)
#define PRESCALER_64                          (3)
#define PRESCALER_256                         (4)
#define PRESCALER_1024                        (5)
#define T0_FALL_EDGE                          (6)
#define T0_RISE_EDGE                          (7)
/** ICU Noise Canceler Status **/
#define NOISE_CANCELER_ENABLED                (1)
#define NOISE_CANCELER_DISABLED               (2)
/** ICI Initial Edge Trigger **/
#define FALLING_EDGE                          (1)
#define RISING_EDGE                           (2)


/**
 *  Configure Prescaler:
 *   - NO_CLK --> Means Timer Turned OFF
 *   - FCPU
 *   - PRESCALER_8
 *   - PRESCALER_64
 *   - PRESCALER_256
 *   - PRESCALER_1024
 *   - T0_FALL_EDGE
 *   - T0_RISE_EDGE
 **/

#define MICU1_CLOCK_SELECT  PRESCALER_256
#define MICU3_CLOCK_SELECT  PRESCALER_256

/**
 *  Adjust ICU Noise Canceler:
 *   - NOISE_CANCELER_ENABLED
 *   - NOISE_CANCELER_DISABLED
 */

#define MICU1_NOISE_CANCELER_STATUS NOISE_CANCELER_ENABLED
#define MICU3_NOISE_CANCELER_STATUS NOISE_CANCELER_ENABLED
/**
 *  Select ICU Initial Edge Trigger:
 *  - FALLING_EDGE
 *  - RISING_EDGE
 */

#define MICU1_INITIAL_EDGE FALLING_EDGE
#define MICU3_INITIAL_EDGE FALLING_EDGE

/**********************************************************************************************************************
 *  REGISTERS BIT NUMBER
 **********************************************************************************************************************/
#define TCCR1A_WGM11  (1) // Timer1 Waveform Generation Mode 1
#define TCCR1A_WGM10  (0) // Timer1 Waveform Generation Mode 0

#define TCCR1B_ICNC1  (7) // Timer1 Input Capture Noise Canceler
#define TCCR1B_ICES1  (6) // Timer1 Input Capture Edge Select
#define TCCR1B_WGM13  (4) // Timer1 Waveform Generation Mode 4
#define TCCR1B_WGM12  (3) // Timer1 Waveform Generation Mode 2
#define TCCR1B_CS12   (2) // Timer1 Clock Select 2
#define TCCR1B_CS11   (1) // Timer1 Clock Select 1
#define TCCR1B_CS10   (0) // Timer1 Clock Select 0

#define TCCR3A_WGM31  (1) // Timer3 Waveform Generation Mode 1
#define TCCR3A_WGM30  (0) // Timer3 Waveform Generation Mode 0

#define TCCR3B_ICNC3  (7) // TIMER3 Input Capture Noise Canceler
#define TCCR3B_ICES3  (6) // TIMER3 Input Capture Edge Select
#define TCCR3B_WGM33  (4) // TIMER3 Waveform Generation Mode 4
#define TCCR3B_WGM32  (3) // TIMER3 Waveform Generation Mode 2
#define TCCR3B_Csint32   (2) // TIMER3 Clock Select 2
#define TCCR3B_CS31   (1) // TIMER3 Clock Select 1
#define TCCR3B_CS30   (0) // TIMER3 Clock Select 0

#define TIMSK_TICIE1  (5) // Timer/Counter1, Input Capture Interrupt Enable

#define ETIMSK_TICIE3 (5) // Timer/Counter3 Input Capture Interrupt Enable

#define TIFR_ICF1     (5) // Timer/Counter1, Input Capture Flag

#define ETIFR_ICF3    (5) // Timer/Counter3, Input Capture Flag


#endif /* ICU_CONFIG_H_ */