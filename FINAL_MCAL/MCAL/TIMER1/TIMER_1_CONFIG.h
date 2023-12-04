/*
 * TIMER_1_CONFIG.h
 *
 * Created: 11/27/2023 9:42:08 PM
 *  Author: khaled waleed
 */ 


#ifndef TIMER_1_CONFIG_H_
#define TIMER_1_CONFIG_H_


#include "ATMEGA_128_REGS.h"
#include "BIT_MATH.h"

/*
MACROS FOR THE TIMER'S MODES OF OPERATION 
*/

#define TIMER_1_NORMAL_MODE                             0
#define TIMER_1_PWM_PHASE_CORRET_8_BIT_MODE             1
#define TIMER_1_PWM_PHASE_CORRET_9_BIT_MODE             2
#define TIMER_1_PWM_PHASE_CORRET_10_BIT_MODE            3
#define TIMER_1_CTC_MODE_OCR1A                          4
#define TIMER_1_FAST_PWM_8_BIT_MODE                     5  
#define TIMER_1_FAST_PWM_9_BIT_MODE                     6  
#define TIMER_1_FAST_PWM_10_BIT_MODE                    7  
#define TIMER_1_PWM_PHASE_FREQU_CORRECT_ICR1            8  
#define TIMER_1_PWM_PHASE_FREQU_CORRECT_OCR1A           9   
#define TIMER_1_PWM_PHASE_CORRECT_ICR1                 10  
#define TIMER_1_PWM_PHASE_CORRECT_OCR1A                11  
#define TIMER_1_CTC_MODE_ICR1                          12
#define TIMER_1_REVERSED_MODE                          13
#define TIMER_1_FAST_PWM_MODE_ICR1                     14   // TO PUT WHATEVER VALUE NEEDED IN THE ICR1 REG ( TOP VALUE .. TO HAVE DIFF FREQU VALUES) 
#define TIMER_1_FAST_PWM_MODE_OCR1A                    15



/*
 THE VALUES BY WHICH THE PRE-SCALLER WILL DIVIDE THE CLOCK FREQU. IN ORDER TO HAVE A LARGER TIME RANGE
*/

#define TIMER_1_PRE_SCALLER_DIV_NO       0
#define TIMER_1_PRE_SCALLER_DIV_8        8
#define TIMER_1_PRE_SCALLER_DIV_64       64
#define TIMER_1_PRE_SCALLER_DIV_256      256
#define TIMER_1_PRE_SCALLER_DIV_1024     1024

/*
FOR STATING THE STATE OF TIMER_1 INTERRUPT
*/

#define   TIMER_1_INTERRUPT_DISABLE     0
#define   TIMER_1_INTERRUPT_ENEBLE      1

/*
  CHOOSE WHICH INTERRUPT NEEDED
 */

#define   TIMER_1_OVER_FLOW_INTERRUPT            0
#define   TIMER_1_COMPARE_MATCH_A_INTERRUPT      1
#define   TIMER_1_COMPARE_MATCH_B_INTERRUPT      2
#define   TIMER_1_ICU_INTERRUPT                  3

/*
 CHOOSE INVERTED OR NON INVERTED FOR FAST_PWM_MODE 
 */

#define TIMER_1_FAST_PWM_MODE_NON_INVERTED           0
#define TIMER_1_FAST_PWM_MODE_INVERTED               1


// PWM PIN

#define TIMER_1_DIO_PORT                                DIO_PORTB
#define TIMER_1_DIO_PIN_OC1A                            DIO_PIN5
#define TIMER_1_DIO_PIN_OC1B                            DIO_PIN6

#define TIMER_1_MODE_OF_OPERATION                   TIMER_1_FAST_PWM_MODE_ICR1 

#define TIMER_1_PRE_SCALLER_VALUE                   TIMER_1_PRE_SCALLER_DIV_1024 

#define TIMER_1_INTERRUPT_STATE                     TIMER_1_INTERRUPT_ENEBLE

#define TIMER_1_FAST_PWM_STATE                      TIMER_1_FAST_PWM_MODE_NON_INVERTED
  
#define TIMER_1_WANTED_INTERRUPT                    TIMER_1_COMPARE_MATCH_A_INTERRUPT



#endif /* TIMER_1_CONFIG_H_ */