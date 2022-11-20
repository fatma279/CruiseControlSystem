/*
 * TIMER1_prg.c
 *
 *  Created on: Oct 19, 2022
 *      Author: aya_enan
 */
#include "STD.h"
#include "BitMath.h"
#include "TIMER1_priv.h"
#include "TIMER1_config.h"
#include "TIMER1_int.h"
#include <avr/interrupt.h>


void (*g_ICU_CallBackPtr)(void) = NULL;

void M_TIMER1_void_Init(void)
{
   // set Mode as Normal Mode
    CLR_BIT(TCCR1A_REG,WGM10_BIT );
    CLR_BIT(TCCR1A_REG,WGM11_BIT );

    CLR_BIT(TCCR1B_REG,WGM12_BIT );
    CLR_BIT(TCCR1B_REG,WGM13_BIT );
   // set prescaler = 256
    CLR_BIT(TCCR1B_REG,CS10_BIT);
	CLR_BIT(TCCR1B_REG,CS11_BIT);
	SET_BIT(TCCR1B_REG,CS12_BIT);

}
void M_TIMER1_ICU_void_Init(void)
{
	SET_BIT(TCCR1B_REG,ICES1_BIT);
}
void M_TIMER1_ICU_void_setTrigger(u8 copy_u8Trigg)
{
    switch( copy_u8Trigg)
    {
    case TIMER1_ICU_RAISING_TRIGG:
    	SET_BIT(TCCR1B_REG,ICES1_BIT);
    	break ;
    case TIMER1_ICU_FALLING_TRIGG:
    	CLR_BIT(TCCR1B_REG,ICES1_BIT);
    	break;
    }
}
void M_TIMER1_ICU_void_setCallBack(void (*ptrfn)(void))
{
	g_ICU_CallBackPtr = ptrfn;
}
u16  M_TIMER1_ICU_u16_readInput(void)
{
   return ICR_REG;
}
void M_TIMER1_ICU_void_EnableInt(void)
{
  SET_BIT(TIMSK_REG,TICIE1_BIT );
}
void M_TIMER1_ICU_void_DisableInt(void)
{
	CLR_BIT(TIMSK_REG,TICIE1_BIT );
}


ISR(TIMER1_CAPT_vect)
{
  if(g_ICU_CallBackPtr != NULL)
  {
	  g_ICU_CallBackPtr();
  }

}
