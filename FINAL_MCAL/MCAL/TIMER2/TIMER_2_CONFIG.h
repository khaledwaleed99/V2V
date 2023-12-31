/*
 * TIMER_2_CONFIG.h
 *
 * Created: 11/28/2023 2:20:00 PM
 *  Author: khaled waleed
 */ 


#ifndef TIMER_2_CONFIG_H_
#define TIMER_2_CONFIG_H_


#include "ATMEGA_128_REGS.h"
#include "BIT_MATH.h"

/*
MACROS FOR THE TIMER'S MODES OF OPERATION 
*/

#define TIMER_2_NORMAL_MODE                          0
#define TIMER_2_PWM_MODE                             1
#define TIMER_2_CTC_MODE                             2
#define TIMER_2_FAST_PWM_MODE                        3


#define TIMER_2_FAST_PWM_MODE_NON_INVERTED           4
#define TIMER_2_FAST_PWM_MODE_INVERTED               5
			  
#define TIMER_2_PHASE_CORRECT_PWM_MODE_NON_INVERTED  6
#define TIMER_2_PHASE_CORRECT_PWM_MODE_INVERTED      7


// PWM PIN

#define TIMER_2_DIO_PORT                           DIO_PORTB
#define TIMER_2_DIO_PIN                            DIO_PIN7



/*
 THE VALUES BY WHICH THE PRE-SCALLER WILL DIVIDE THE CLOCK FREQU. IN ORDER TO HAVE A LARGER TIME RANGE
 
 KEEP IN MIND THAT SELECTING THE PRE_SCALLER VALUE FOR THE PWM MODE ( FAST , PHASE CORRECT ) IS BASED ON THE FREQUNECY OF THE WAVE NEEDED
*/

#define TIMER_2_PRE_SCALLER_DIV_NO       0
#define TIMER_2_PRE_SCALLER_DIV_8        8
#define TIMER_2_PRE_SCALLER_DIV_64       64
#define TIMER_2_PRE_SCALLER_DIV_256      256
#define TIMER_2_PRE_SCALLER_DIV_1024     1024

/*
FOR STATING THE STATE OF TIMER_0 INTERRUPT
*/

#define   TIMER_2_INTERRUPT_DISABLE   0
#define   TIMER_2_INTERRUPT_ENEBLE    1


#define TIMER_2_MODE_OF_OPERATION              TIMER_2_FAST_PWM_MODE

#define TIMER_2_PRE_SCALLER_VALUE              TIMER_2_PRE_SCALLER_DIV_1024

#define TIMER_2_INTERRUPT_STATE                TIMER_2_INTERRUPT_ENEBLE

#define TIMER_2_FAST_PWM_STATE                 TIMER_2_FAST_PWM_MODE_NON_INVERTED

#define TIMER_2_PWM_MODE_STATE                 TIMER_2_PHASE_CORRECT_PWM_MODE_NON_INVERTED


#endif /* TIMER_2_CONFIG_H_ */