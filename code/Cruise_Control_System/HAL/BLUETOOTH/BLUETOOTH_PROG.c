/*
 * BLUETOOTH_PROG.c
 *
 *  Created on: Oct 26, 2022
 *      Author: Mohamed Saad
 */

#include "UART_Interface.h"
#include "BLUETOOTH_Int.h"
#include "BLUETOOTH_Config.h"
#include "BLUETOOTH_Private.h"
#include "STD.h"
void H_BLUETOOTH_Void_BLUETOOTHInit(void)
{
	M_UART_Void_UARTInit() ;

}
void H_BLUETOOTH_u8_BLUETOOTHReadStr(u8 *Copy_U8_Str)
{
	M_UART_u8_UARTReadStr(Copy_U8_Str) ;
}
