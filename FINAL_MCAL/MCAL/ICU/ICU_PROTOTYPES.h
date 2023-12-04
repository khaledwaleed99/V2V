/*
 * ICU_PROTOTYPES.h
 *
 * Created: 11/28/2023 1:49:58 PM
 *  Author: khaled waleed
 */ 


#ifndef ICU_PROTOTYPES_H_
#define ICU_PROTOTYPES_H_

#include "ICU_CONFIG.h"

/**
 * Input:  		ICU Source:
 * 					- ICU1
 * 					- ICU3
 * Output: 		No Output
 * In/Out: 		No In/Out
 * Description:  This function initialize ICU:
 * 					- Timer1 or 3 in Normal Mode
 * 					- Clock
 * 					- Noise Canceler
 * 					- Initial Edge Trigger
 * Pre-request:  1-Make ICP1 --> PIN PD4 Input or ICP3 --> Pin PE7
 * 				 2-Set Callback for CAPT Event
 * 				 3-Enable GIE
 */
ErrorState_t MICU_enInit(ICU_t copy_enID);

/**
 * Input:  		1-ICU Source:
 *					- ICU1
 *					- ICU3
 * 				2-ICU Edge Trigger:
 * 					- FALLING
 * 					- RISING
 * Output: 		No Output
 * In/Out: 		No In/Out
 * Description:  This function select the Edge that you want to capture the event at
 */
ErrorState_t MICU_enEdgeSelect(ICU_t copy_enID, Edge_t copy_enEdge);

/**
 * Input:  		ICU Source:
 * 					- ICU1
 * 					- ICU3
 * Output: 		No Output
 * In/Out: 		No In/Out
 * Description:  This function enable the ICU interrupt event
 */
ErrorState_t MICU_enInterruptEnable(ICU_t copy_enID);

/**
 * Input:  		ICU Source:
 * 					- ICU1
 * 					- ICU3
 * Output: 		No Output
 * In/Out: 		No In/Out
 * Description:  This function disable the ICU interrupt event
 */
ErrorState_t MICU_enInterruptDisable(ICU_t copy_enID);

/**
 * Input:  		ICU Source:
 * 					- ICU1
 * 					- ICU3
 * Output: 		The value in the ICR1 or ICR3 Register
 * In/Out: 		No In/Out
 * Description:  This function get the value in the ICR1 Register which indicates the occurrence of selected edge trigger
 */
ErrorState_t MICU_enReadICR(ICU_t copy_enID, uint16 *ptrVal);

/**
 * Input:  		The interrupt source:
 * 					- ICU1
 * 					- ICU3
 * Output: 		Callback Function for ICU1 or ICU3
 * In/Out: 		No In/Out
 * Description:  This function set the call back function for the 2 sources of interrupts
 */
ErrorState_t MICU_enSetCallBack(ICU_t copy_enID, void (*ptrFUN)(void));



#endif /* ICU_PROTOTYPES_H_ */