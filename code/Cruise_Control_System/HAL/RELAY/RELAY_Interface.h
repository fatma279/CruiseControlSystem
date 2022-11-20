/*
 * RELAY_Interface.h

 *
 *  Created on: ??þ/??þ/????
 *      Author: Nada Mekawy
 */


#ifndef HAL_RELAY_RELAY_INTERFACE_H_
#define HAL_RELAY_RELAY_INTERFACE_H_

#include "DIO_Interface.h"

#define RELAY1     1
#define RELAY2     2


void H_RELAY_Void_RELAYInit(u8);
void H_RELAY_Void_RELAYOn(u8);
void H_RELAY_Void_RELAYOff(u8);
void H_RELAY_Void_RELAYTog(u8);

#endif /* HAL_RELAY_RELAY_INTERFACE_H_ */
