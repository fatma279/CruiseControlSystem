/*
 * UART_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#include "STD.h"
#include "BitMath.h"

void M_UART_Void_UARTInit(void);

void M_UART_Void_UARTWrite(u8 Copy_UART_DataToSend);

u8 M_UART_u8_UARTRead(void);
void M_UART_u8_UARTReadStr(u8 *Copy_U8_Str);



#endif /* MCAL_UART_UART_INTERFACE_H_ */
