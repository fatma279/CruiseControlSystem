/*
 * EXTI_prg.c
 *
 *  Created on: Oct 12, 2022
 *      Author: aya_enan
 */
#include "STD.h"
#include "BitMath.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "EXTI_int.h"
#include <avr/interrupt.h>

void (*EXTI_CallBackArr[3])(void) = {NULL,NULL,NULL};


void M_EXTI_void_EnableInt(u8 copy_u8IntID, u8 copy_u8Trigg)
{
	//step 1 : Enable IE
	// method 1
	/*	switch(copy_u8IntID)
	{
	case EXTI_INT0_ID:
		SET_BIT(GICR_REG,INT0_BIT);
		break;
	case EXTI_INT1_ID:
		SET_BIT(GICR_REG,INT1_BIT);
		break;
	case EXTI_INT2_ID:
		SET_BIT(GICR_REG,INT2_BIT);
		break;
	}*/
	// method 2
	SET_BIT(GICR_REG,copy_u8IntID);

	// step 2 : choose trigger
	/*	switch(copy_u8IntID)
	{
	case EXTI_INT0_ID:
		switch(copy_u8Trigg)
		{
		case EXTI_TRIG_LOW_LEVEL:
			CLR_BIT(MCUCR_REG, ISC00_BIT);
			CLR_BIT(MCUCR_REG, ISC01_BIT);
			break;
		case EXTI_TRIG_ANY_CHANGE :
			SET_BIT(MCUCR_REG, ISC00_BIT);
			CLR_BIT(MCUCR_REG, ISC01_BIT);
			break;
		case EXTI_TRIG_FALLING_EDGE:
			CLR_BIT(MCUCR_REG, ISC00_BIT);
			SET_BIT(MCUCR_REG, ISC01_BIT);
			break;
		case EXTI_TRIG_RAISING_EDGE:
			SET_BIT(MCUCR_REG, ISC00_BIT);
			SET_BIT(MCUCR_REG, ISC01_BIT);
			break;
		}
		break;
	case EXTI_INT1_ID:
		break;
	case EXTI_INT2_ID:
		break;
	}*/
	switch(copy_u8IntID)
	{
	case EXTI_INT0_ID:
		// step 1 : clear bits using mask
		MCUCR_REG &= EXTI_INT0_MASK;
		// step 2 : insert value of bits
		MCUCR_REG |=  copy_u8Trigg;
		break;
	case EXTI_INT1_ID:
		// step 1 : clear bits using mask
		MCUCR_REG &= EXTI_INT1_MASK;
		// step 2 : insert value of bits
		MCUCR_REG |=  copy_u8Trigg << 2;
		break;
	case EXTI_INT2_ID:
		// step 1 : clear bit
        CLR_BIT(MCUCSR_REG,ISC2_BIT);
        //step 2 : insert value
        // method 1
     //   MCUCSR_REG |= (GET_BIT(copy_u8Trigg , 0))<<  ISC2_BIT;

        // method 2
        MCUCSR_REG |=  ((copy_u8Trigg & 1)) <<  ISC2_BIT;
		break;
	}
}

void M_EXTI_void_DisableInt(u8 copy_u8IntID)
{
	CLR_BIT(GICR_REG,copy_u8IntID);
}

void M_EXTI_void_setCallBackfn(void (*ptrfn)(void),u8 copy_u8IntID)
{
    switch(copy_u8IntID)
    {
    case EXTI_INT0_ID:
    	EXTI_CallBackArr[0] = ptrfn;
    	break;
    case EXTI_INT1_ID:
    	EXTI_CallBackArr[1] = ptrfn;
    	break;
    case EXTI_INT2_ID:
    	EXTI_CallBackArr[2] = ptrfn;
    	break;
    }
}
ISR(INT0_vect )
{

	if(EXTI_CallBackArr[0] != NULL)
	{
		EXTI_CallBackArr[0]();
	}
}
ISR(INT1_vect)
{
	if(EXTI_CallBackArr[1] != NULL)
		{
			EXTI_CallBackArr[1]();
		}
}
ISR(INT2_vect)
{
	if(EXTI_CallBackArr[2] != NULL)
		{
			EXTI_CallBackArr[2]();
		}
}
