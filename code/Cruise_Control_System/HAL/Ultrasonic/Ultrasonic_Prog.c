/*
 * Ultrasonic_Prog.c
 *
 *  Created on: Oct 27, 2022
 *      Author: TECH VALLEY
 */

#include "STD.h"
#include "BitMath.h"

#include "Ultrasonic_Private.h"
#include "Ultrasonic_Config.h"
#include "Ultrasonic_Interface.h"

#include "DIO_Interface.h"
#include "TIMER1_int.h"

#include <avr/delay.h>
#include <math.h>


static u16  g_Reading1 = 0;
static u16  g_Reading2 = 0;

static u8 g_StateCounter  = 0;

void H_Ultrasonic_void_Init(void)
{
	// Init Timer 1
		// step 1 : Init Timer 1 in Normal mode
		M_TIMER1_void_Init();

		// step 2 : Init ICU
		M_TIMER1_ICU_void_Init();

		// step 3 : set cal back
		M_TIMER1_ICU_void_setCallBack(A_ICU_HW);

		// step 4 : Enable ICU Interrupt
		M_TIMER1_ICU_void_EnableInt();

		// step 5 : config ICP direction (input capture pin) as input
		M_DIO_Void_SetPinDirection(PD6_PIN, INPUT);

		// config ULTRASONIC_TRIGGER_PIN  as output (Trigger to ultraSonic)
		M_DIO_Void_SetPinDirection(ULTRASONIC_TRIGGER_PIN ,OUTPUT);
}


u16 H_Ultrasonic_u16_Read(void)
{
	 u32 PeriodTicks;
	 f32 time;
	 u16 Local_Distance;

	 M_DIO_Void_SetPinValue(ULTRASONIC_TRIGGER_PIN, HIGH);
	    _delay_us(10);
	   M_DIO_Void_SetPinValue(ULTRASONIC_TRIGGER_PIN, LOW);

		while(g_StateCounter < 2); // CPU is waiting for readings
		g_StateCounter=0;
		 PeriodTicks =g_Reading2 - g_Reading1;
	     time = (PeriodTicks * 16 )/1000000.0;
	     Local_Distance = ceil((time/2) * 34300);


	     return Local_Distance;
}

void H_Ultrasonic_void_ReStart(void)
{
	M_TIMER1_ICU_void_setTrigger(TIMER1_ICU_RAISING_TRIGG);
	//Enable ICU Interrupt
	M_TIMER1_ICU_void_EnableInt();

}


void A_ICU_HW(void)
{
	if(g_StateCounter == 0)
	{
		// take reading at 1st rising edge
		g_Reading1 = M_TIMER1_ICU_u16_readInput();
		// change trigger to be falling
		M_TIMER1_ICU_void_setTrigger(TIMER1_ICU_FALLING_TRIGG);
	}
	else if(g_StateCounter == 1)
	{
		// take reading at falling edge
		g_Reading2 = M_TIMER1_ICU_u16_readInput();
		// disable ICU interrupt
		M_TIMER1_ICU_void_DisableInt();
	}

	g_StateCounter++;
}
