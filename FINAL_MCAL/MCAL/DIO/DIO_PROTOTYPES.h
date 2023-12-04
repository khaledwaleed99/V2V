/*
 * DIO_PROTOTYPES.h
 *
 * Created: 11/27/2023 7:58:10 PM
 *  Author: khaled waleed
 */ 


#ifndef DIO_PROTOTYPES_H_
#define DIO_PROTOTYPES_H_

#include "DIO_CONFIG.h"


/*
NAME : DIO_SETPORT_DIREC
USED TO : STATE THE DIRECTION (INPUT OR OUTPUT) FOR A WHOLE PORT
ARGUMENTS : NAME OF THE PORT & DIRECTION
*/

void  DIO_SET_PORT_DIREC  (DIO_PORT_ID PORT , DIO_DIRECTION DIREC);

/*
NAME : DIO_SETPIN_DIREC
USED TO : STATE THE DIRECTION (INPUT OR OUTPUT) FOR A SINGLE PIN
ARGUMENTS : NAME OF THE PORT & NUMBER OF PIN & DIRECTION
*/

void  DIO_SET_PIN_DIREC   (DIO_PORT_ID PORT , DIO_PIN_ID PIN , DIO_DIRECTION DIREC);

/*
NAME : DIO_SETPORT_VALUE
USED TO : STATE THE VALUE (HIGH OR LOW ) THAT WILL BE (INPUT OR OUTPUT ) TO OR FROM THE WHOLE PORT
ARGUMENTS : NAME OF THE PORT & VALUE NEEDED
*/

void DIO_SET_PORT_VALUE   (DIO_PORT_ID PORT , uint8 VALUE );

/*
NAME : DIO_SETPIN_VALUE
USED TO : STATE THE VALUE (HIGH OR LOW ) THAT WILL BE (INPUT OR OUTPUT ) TO OR FROM SINGLE PIN
ARGUMENTS : NAME OF THE PORT & NUMBER OF THE PIN & VALUE NEEDED
*/

void DIO_SET_PIN_VALUE    (DIO_PORT_ID PORT , DIO_PIN_ID PIN , DIO_VALUE VALUE );

/*
NAME : DIO_TOOGLE_PIN
USED TO : CHANGE THE STATE OF A PIN
ARGUMENTS : NAME OF THE PORT & NUMBER OF THE PIN
*/

void DIO_TOOGLE_PIN      (DIO_PORT_ID PORT , DIO_PIN_ID PIN );

void DIO_READ_PORT       (DIO_PORT_ID PORT , uint8*VALUE );
void DIO_READ_PIN        (DIO_PORT_ID PORT , DIO_PIN_ID PIN , uint8*VALUE );

void DIO_SET_PULL_UP_RES (DIO_PORT_ID PORT , uint8 PIN );



#endif /* DIO_PROTOTYPES_H_ */