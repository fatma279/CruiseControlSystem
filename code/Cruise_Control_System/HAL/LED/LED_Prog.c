/*
 * LED_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */



#include "LED_Config.h"
#include "LED_Interface.h"
#include "LED_Private.h"

void H_LED_Void_LEDInit(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case LED_BLU: M_DIO_Void_SetPinDirection(LED_BLU_PIN,OUTPUT); break;
	case LED_GRN: M_DIO_Void_SetPinDirection(LED_GRN_PIN,OUTPUT); break;
	case LED_RED: M_DIO_Void_SetPinDirection(LED_RED_PIN,OUTPUT); break;
	default:                                                      break;
	}
}
void H_LED_Void_LEDOn(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case LED_BLU: M_DIO_Void_SetPinValue(LED_BLU_PIN,HIGH); break;
	case LED_GRN: M_DIO_Void_SetPinValue(LED_GRN_PIN,HIGH); break;
	case LED_RED: M_DIO_Void_SetPinValue(LED_RED_PIN,HIGH); break;
	default:                                                break;
	}
}
void H_LED_Void_LEDOff(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case LED_BLU: M_DIO_Void_SetPinValue(LED_BLU_PIN,LOW); break;
	case LED_GRN: M_DIO_Void_SetPinValue(LED_GRN_PIN,LOW); break;
	case LED_RED: M_DIO_Void_SetPinValue(LED_RED_PIN,LOW); break;
	default:                                               break;
	}
}
void H_LED_Void_LEDTog(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case LED_BLU: M_DIO_Void_TogPin(LED_BLU_PIN); break;
	case LED_GRN: M_DIO_Void_TogPin(LED_GRN_PIN); break;
	case LED_RED: M_DIO_Void_TogPin(LED_RED_PIN); break;
	default:                                      break;
	}
}
void H_LED_Void_LEDBlink(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case LED_BLU:
		M_DIO_Void_SetPinValue(LED_BLU_PIN,HIGH);
		_delay_ms(LED_ON_TIME);
		M_DIO_Void_SetPinValue(LED_BLU_PIN,LOW);
		break;
	case LED_GRN:
		M_DIO_Void_SetPinValue(LED_GRN_PIN,HIGH);
		_delay_ms(LED_ON_TIME);
		M_DIO_Void_SetPinValue(LED_GRN_PIN,LOW);
		break;
	case LED_RED:
		M_DIO_Void_SetPinValue(LED_RED_PIN,HIGH);
		_delay_ms(LED_ON_TIME);
		M_DIO_Void_SetPinValue(LED_RED_PIN,LOW);
		break;
	default:                                      break;
	}
}
