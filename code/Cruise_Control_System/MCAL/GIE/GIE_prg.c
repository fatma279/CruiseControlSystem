/*
 * GIE_prg.c
 *
 *  Created on: Oct 12, 2022
 *      Author: aya_enan
 */

#include  "STD.h"
#include  "BitMath.h"
#include  "GIE_priv.h"
#include  "GIE_config.h"
#include  "GIE_int.h"

void M_GIE_void_Enable(void)
{
  // Method 1 : using C
//	SET_BIT(SREG_REG,I_BIT);

  //Method 2 : Assembly
	asm("SEI");
}
void M_GIE_void_Diasble(void)
{
	// Method 1 : using C

	//CLR_BIT(SREG_REG,I_BIT);

	 //Method 2 : Assembly
	asm("CLI");

}
