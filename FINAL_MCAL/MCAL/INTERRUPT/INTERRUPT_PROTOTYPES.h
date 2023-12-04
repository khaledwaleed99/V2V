/*
 * INTERRUPT_PROTOTYPES.h
 *
 * Created: 11/27/2023 8:16:41 PM
 *  Author: khaled waleed
 */ 


#ifndef INTERRUPT_PROTOTYPES_H_
#define INTERRUPT_PROTOTYPES_H_

#include "INTERRUPT_CONFIG.h"

/**********************************************************************************************************************
 * GLOBAL FUNCTIONS PROTOTYPES
 **********************************************************************************************************************/

 /**
 * Input:  		 1- Interrupt ID:
					- INT0
					- INT1
					- INT2
					- INT3
					- INT4
					- INT5
					- INT6
					- INT7
				 2- Sense Control:
				 	- LOW_LEVEL
					- ANY_CHANGE
					- FALL_EDGE
					- RISE_EDGE
 * Output: 		 No Output
 * In/Out: 		 No In/Out
 * Description:  This function Enable the Specific Interrupt Enable for Selected External Interrupt with selecting its Sense Control
 */
ErrorState_t MEXTI_enEnable(InterruptID_t copy_enINT, Interrupt_signal copy_enSC);

 /**
 * Input:  		 Interrupt ID:
					- INT0
					- INT1
					- INT2
					- INT3
					- INT4
					- INT5
					- INT6
					- INT7
 * Output: 		 No Output
 * In/Out: 		 No In/Out
 * Description:  This function Disable Specific Interrupt Enable for selectrd Interrupt Source
 */
ErrorState_t MEXTI_enDisable(InterruptID_t copy_enINT);

 /**
 * Input:  		 1- Interrupt ID:
					- INT0
					- INT1
					- INT2
					- INT3
					- INT4
					- INT5
					- INT6
					- INT7
				 2- Call Back Function for selected Interrupt
 * Output: 		 No Output
 * In/Out: 		 No In/Out
 * Description:  This function Set the Callback Function for selected Interrupt
 */
ErrorState_t MEXTI_enSetCallBack(InterruptID_t copy_enINT, void (*ptrFn)(void));





#endif /* INTERRUPT_PROTOTYPES_H_ */