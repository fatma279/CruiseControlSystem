/*
 * TIMER0_prg.c
 *
 *  Created on: Oct 17, 2022
 *      Author: aya_enan
 */
#include "STD.h"
#include "BitMath.h"
#include "TIMER0_priv.h"
#include "TIMER0_config.h"
#include "TIMER0_int.h"
#include <avr/interrupt.h>
#include <stdlib.h>


void (*g_CallBackArr[2])(void) = {NULL,NULL};
static u32 NumOFOverflows = 0;
static u8 NumOFRemainingTicks  = 0;
static u32 NumOFCmpMatches = 0;
void M_TIMER0_void_Init(void)
{
	//step1 : config Timer Mode
#if(TIMER0_MODE   == TIMER0_MODE_NORMAL)  // 0
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	CLR_BIT(TCCR0_REG,WGM01_BIT);
	// step 2 : config OC0 pin mode
#if(TIMER0_OC0_MODE >=TIMER0_OC0_MODE_DISCONNECTED   && TIMER0_OC0_MODE<= TIMER0_OC0_MODE_SET)
	TCCR0_REG &= TIMER0_OC0_MODE_MASK;
	TCCR0_REG |= TIMER0_OC0_MODE << COM00_BIT;
#else
#error ("wrong OC0 mode")

#endif
#elif(TIMER0_MODE   == TIMER0_MODE_CTC)  // 2
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);
	// step 2 : config OC0 pin mode
#if(TIMER0_OC0_MODE >=TIMER0_OC0_MODE_DISCONNECTED   && TIMER0_OC0_MODE<= TIMER0_OC0_MODE_SET)
	TCCR0_REG &= TIMER0_OC0_MODE_MASK;
	TCCR0_REG |= TIMER0_OC0_MODE << COM00_BIT;
#else
#error ("wrong OC0 mode")

#endif
#elif(TIMER0_MODE   == TIMER0_MODE_FAST_PWM) //3
	SET_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);
#if(TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_NON_INVERTING || TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_INVERTING)
	// step 1 : apply mask
	TCCR0_REG &= TIMER0_OC0_MODE_MASK;
	// step 2 : insert value
	TCCR0_REG |= TIMER0_OC0_MODE;
#else
  #error("wrong OC0 mode")
#endif
#elif(TIMER0_MODE   == TIMER0_MODE_PHASE_CORRECT_PWM)//1
	SET_BIT(TCCR0_REG,WGM00_BIT);
	CLR_BIT(TCCR0_REG,WGM01_BIT);
#if(TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_NON_INVERTING || TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_INVERTING)
	// step 1 : apply mask
	TCCR0_REG &= TIMER0_OC0_MODE_MASK;
	// step 2 : insert value
	TCCR0_REG |= TIMER0_OC0_MODE;
#else
  #error("wrong OC0 mode")
#endif
#else
#error ("wrong Timer0 mode")
#endif
}
void M_TIMER0_void_setTimeMS(u32 copy_u32TimeMS )
{
	u16 prescaler_Arr[]= {1,8,64,256,1024};
    f32 TickTime =  (f32)prescaler_Arr[TIMER0_PRESCALER-1 ] / FCPU;
	u32 DesiredNumOfTicks = (copy_u32TimeMS * 1000)/ TickTime;
#if(TIMER0_MODE   == TIMER0_MODE_NORMAL)
	NumOFOverflows = DesiredNumOfTicks/256;
	NumOFRemainingTicks = DesiredNumOfTicks % 256;
	if(NumOFRemainingTicks != 0)
	{
		TCNT0_REG = 256 - NumOFRemainingTicks;
		NumOFOverflows++;
	}
#elif(TIMER0_MODE   == TIMER0_MODE_CTC)
     u8 OCR0_Value = 255;
     while((DesiredNumOfTicks % OCR0_Value) != 0 )
     {
    	 OCR0_Value--;
     }
     OCR0_REG = OCR0_Value ;
     NumOFCmpMatches = DesiredNumOfTicks / OCR0_Value;
#endif
}
void M_TIMER0_void_startTimer(void)
{
	// step 1 : apply Mask
	TCCR0_REG &= TIMER0_PRESCALER_MASK;
	// step 2 : insert value
	TCCR0_REG |= TIMER0_PRESCALER;
}
void M_TIMER0_void_stopTimer(void)
{
	// step 1 : apply Mask
	TCCR0_REG &= TIMER0_PRESCALER_MASK;
	// step 2 : insert value
	//	TCCR0_REG |= TIMER0_PRESCALER_NO_CLOCK;// why commented ? coz mask will clear bits
}
void M_TIMER0_void_setCallBack(void (*ptrfn)(void),u8 copy_u8IntID)
{
	// Method1
	/*switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID:
		g_CallBackArr[0] = ptrfn;
		break;
	case TIMER0_COMP_INT_ID :
		g_CallBackArr[1] = ptrfn;
		break;
	}*/
	// Method 2
	if(copy_u8IntID == TIMER0_OVF_INT_ID || copy_u8IntID ==TIMER0_COMP_INT_ID )
		g_CallBackArr[copy_u8IntID] = ptrfn;
}
void M_TIMER0_void_EnableInt(u8 copy_u8IntID)
{
	switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID:
		SET_BIT(TIMSK_REG,TOIE0_BIT);
		break;
	case TIMER0_COMP_INT_ID :
		SET_BIT(TIMSK_REG,OCIE0_BIT);
		break;
	}
}
void M_TIMER0_void_DisableInt(u8 copy_u8IntID)
{
	switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID:
		CLR_BIT(TIMSK_REG,TOIE0_BIT);
		break;
	case TIMER0_COMP_INT_ID :
		CLR_BIT(TIMSK_REG,OCIE0_BIT);
		break;
	}

}
void M_TIMER0_void_setFastPWM(u8 copy_u8Duty)
{
#if (TIMER0_MODE  ==   TIMER0_MODE_FAST_PWM)
	#if(TIMER0_OC0_MODE  == TIMER0_OC0_MODE_PWM_NON_INVERTING)
      OCR0_REG =  abs(((copy_u8Duty * 256)/100)-1);
	#elif(TIMER0_OC0_MODE  == TIMER0_OC0_MODE_PWM_INVERTING)
      OCR0_REG = abs(255- ((copy_u8Duty* 256)/100) );
	#endif
#endif
}
void M_TIMER0_void_setPhaseCorrectPWM(u8 copy_u8Duty)
{
#if (TIMER0_MODE  ==   TIMER0_MODE_PHASE_CORRECT_PWM)
	#if(TIMER0_OC0_MODE  == TIMER0_OC0_MODE_PWM_NON_INVERTING)
      OCR0_REG =  (copy_u8Duty * 255)/100;
	#elif(TIMER0_OC0_MODE  == TIMER0_OC0_MODE_PWM_INVERTING)
      OCR0_REG = 255 - ((copy_u8Duty * 255)/100);
	#endif
#endif
}
ISR(TIMER0_OVF_vect)
{
   static u32 OVFcounter = 0;
   OVFcounter++;
   if(OVFcounter == NumOFOverflows)
   {
	   if(NumOFRemainingTicks != 0)
	   {
		   TCNT0_REG = 256 - NumOFRemainingTicks;
	   }

      //take Action
	   if(g_CallBackArr[TIMER0_OVF_INT_ID] != NULL)
	   {
		   g_CallBackArr[TIMER0_OVF_INT_ID](); // call fn in APP layer
	   }
	   OVFcounter = 0;

   }
}
ISR(TIMER0_COMP_vect)
{
	static u32 CmpMatchcounter = 0;
	CmpMatchcounter++;
	if(CmpMatchcounter == NumOFCmpMatches)
	{
	      //take Action
		   if(g_CallBackArr[TIMER0_COMP_INT_ID] != NULL)
		   {
			   g_CallBackArr[TIMER0_COMP_INT_ID](); // call fn in APP layer
		   }
		   CmpMatchcounter = 0;

	}
}
