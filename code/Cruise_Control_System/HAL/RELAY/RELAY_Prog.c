/*
 * RELAY_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nada Mekawy
 */

#include "RELAY_Config.h"
#include "RELAY_Interface.h"

void H_RELAY_Void_RELAYInit(u8 Copy_U8_Relay)
{
	switch(Copy_U8_Relay)
	{
	  case 1: M_DIO_Void_SetPinDirection(RELAY_PIN1,OUTPUT); break;
	  case 2: M_DIO_Void_SetPinDirection(RELAY_PIN2,OUTPUT); break;
	  default:                                           break;
	}
}
void H_RELAY_Void_RELAYOn(u8 Copy_U8_Relay)
{
	switch(Copy_U8_Relay)
		{
          case 1 : M_DIO_Void_SetPinValue(RELAY_PIN1,HIGH);  break;
          case 2 : M_DIO_Void_SetPinValue(RELAY_PIN2,HIGH);  break;
          default:                                       break;
		}
}
void H_RELAY_Void_RELAYOff(u8 Copy_U8_Relay)
{
	switch(Copy_U8_Relay)
			{
	       case 1 : M_DIO_Void_SetPinValue(RELAY_PIN1,LOW);  break;
	       case 2 : M_DIO_Void_SetPinValue(RELAY_PIN2,LOW);  break;
	       default:                                      break;
			}
}
void H_RELAY_Void_RELAYTog(u8 Copy_U8_Relay)
{
	switch(Copy_U8_Relay)
			{
		case 1: M_DIO_Void_TogPin(RELAY_PIN1);    break;
		case 2: M_DIO_Void_TogPin(RELAY_PIN2);    break;
		default:                              break;
             }
}

