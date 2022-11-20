/*
 * UART_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define UCSRA_REG	(*(volatile u8*)0x2B)
#define UCSRB_REG	(*(volatile u8*)0x2A)
#define UCSRC_REG	(*(volatile u8*)0x40)

#define UDR_REG		(*(volatile u8*)0x2C)

#define UBRRL_REG	(*(volatile u8*)0x29)

#define RXC_Bit		7
#define TXC_Bit		6
#define UDRE_Bit	5
#define FE_Bit		4
#define DOR_Bit		3
#define PE_Bit		2
#define U2X_Bit		1
#define MPCM_Bit	0

#define RXCIE_Bit	7
#define TXCIE_Bit	6
#define UDRIE_Bit	5
#define RXEN_Bit	4
#define TXEN_Bit	3
#define UCSZ2_Bit	2
#define RXB8_Bit	1
#define TXB8_Bit	0

#define URSEL_Bit	7
#define UMSEL_Bit	6
#define UPM1_Bit	5
#define UPM0_Bit	4
#define USBS_Bit	3
#define UCSZ1_Bit	2
#define UCSZ0_Bit	1
#define UCPOL_Bit	0

#define PARITY_DISABLE	 0
#define PARITY_ODD		 2
#define PARITY_EVEN		 3

#define BAUDRATE_4800  4800
#define BAUDRATE_9600  9600
#define BAUDRATE_14400  14400
#define BAUDRATE_38400  38400

#define UART_Complete_Transmiting 		1
#define UART_still_data 				0
#define UART_Complete_Reciveing			1
#define UART_Polling_Time				2000000


#endif /* MCAL_UART_UART_PRIVATE_H_ */
