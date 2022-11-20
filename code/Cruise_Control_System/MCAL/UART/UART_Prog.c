/*
 * UART_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"
#include "DIO_Interface.h"
#include "util/delay.h"

void M_UART_Void_UARTInit(void)
{
	/* set pin tx as output and rx as input */
	M_DIO_Void_SetPinDirection(PD0_PIN , INPUT)  ;
	M_DIO_Void_SetPinDirection(PD1_PIN , OUTPUT) ;

	SET_BIT(UCSRB_REG,RXEN_Bit);
	SET_BIT(UCSRB_REG,TXEN_Bit);

	UCSRC_REG |= (1 << URSEL_Bit)| (1 << UCSZ0_Bit) | (1 << UCSZ1_Bit);	// Write USCRC for 8 bit data and 1 stop bit

	/* select rigister as ucsrc not ubrrh
	SET_BIT(UCSRC_REG,URSEL_Bit);

	CLR_BIT(UCSRB_REG,UCSZ2_Bit);
	SET_BIT(UCSRC_REG,UCSZ1_Bit);
	SET_BIT(UCSRC_REG,UCSZ0_Bit);*/

	/* select boudrate [9600] */
	UBRRL_REG =(( F_OSC/(16UL * UART_BAUD_RATE))-1) ;
	/*
	 *  select Parity Mood
	 */
#if (UART_PARITY_MOOD == PARITY_DISABLE)
	CLR_BIT(UCSRC_REG,UPM0_Bit);
	CLR_BIT(UCSRC_REG,UPM1_Bit);
#elif(UART_PARITY_MOOD == PARITY_ODD)
	CLR_BIT(UCSRC_REG,UPM0_Bit);
	SET_BIT(UCSRC_REG,UPM1_Bit);
#elif(UART_PARITY_MOOD == PARITY_EVEN)
	SET_BIT(UCSRC_REG,UPM0_Bit);
	SET_BIT(UCSRC_REG,UPM1_Bit);
#else
#error("error in UART PARITY MOOD")
#endif

	CLR_BIT(UCSRC_REG,USBS_Bit);
}

void M_UART_Void_UARTWrite(u8 Copy_UART_DataToSend)
{
	u32 Local_u32_Counter = 0 ;
	UDR_REG = Copy_UART_DataToSend ;

	while(Local_u32_Counter < UART_Polling_Time)
	{
		Local_u32_Counter++ ;
		if(GET_BIT(UCSRA_REG,TXC_Bit) == UART_Complete_Transmiting)
		{
			break;
		}
	}
}

u8 M_UART_u8_UARTRead(void)
{
	u8 return_value = 0 ;
	u32 Local_u32_Counter = 0 ;
	while(Local_u32_Counter < UART_Polling_Time)
	{
		Local_u32_Counter++ ;
		if(GET_BIT(UCSRA_REG,RXC_Bit) == UART_Complete_Transmiting)
		{
			break;
		}
	}
	return_value = UDR_REG  ;
	return  return_value;
}

void  M_UART_u8_UARTReadStr(u8 *Copy_U8_Str)
{
	u8  Local_U8_StrCounter=0;
	u32 Local_u32_Counter = 0 ;
	Copy_U8_Str[0] = '\0' ;
	Copy_U8_Str[1] =  '\0';

	while(Local_u32_Counter < UART_Polling_Time)
	{
		Local_u32_Counter++ ;
		if(GET_BIT(UCSRA_REG,RXC_Bit) == UART_Complete_Transmiting)
		{
			break;
		}
	}
	while(GET_BIT(UCSRA_REG,RXC_Bit) != UART_still_data)
	{
		Copy_U8_Str[Local_U8_StrCounter]= UDR_REG  ;
		_delay_ms(100) ;
		Local_U8_StrCounter++ ;
	}
	Copy_U8_Str[2]= '\0'  ;
}
