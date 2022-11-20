/*
 * ADC_prg.c
 *
 *  Created on: Oct 16, 2022
 *      Author: aya_enan
 */
#include "STD.h"
#include "BitMath.h"
#include "ADC_priv.h"
#include "ADC_config.h"
#include "ADC_int.h"

void M_ADC_void_Init(u8 copy_u8presclaer, u8 copy_vref)
{
  // step 1 : choose prescaler
   ADCSRA_REG &= ADC_PRESCALER_MASK;
   ADCSRA_REG |= copy_u8presclaer;

  // step 2 : Disable Interrupt
   CLR_BIT( ADCSRA_REG,ADIE_BIT);
  // step 3 : right adjust
   CLR_BIT(ADMUX_REG,ADLAR_BIT);
  // step 4 : disable auto trigger
   CLR_BIT(ADCSRA_REG,ADATE_BIT);
	// step 5 : choose vref
   ADMUX_REG &= ADC_VREF_MASK;
   ADMUX_REG |= (copy_vref << 6);
	// step 6 : Enable ADC
   SET_BIT(ADCSRA_REG , ADEN_BIT);
}
u16 M_ADC_u16_adcRead(u8 copy_u8Channel )
{
   // step 1 : choose channel
	ADMUX_REG &= ADC_CHANNEL_MASK;
	ADMUX_REG |= copy_u8Channel;
	// step 2 : Enable (start Conversion )
    SET_BIT(ADCSRA_REG,ADSC_BIT);
	// step 3 : wait until conversion is done
     while(GET_BIT(ADCSRA_REG,ADIF_BIT)== 0);
	//step 4 : return value
     return ADC_REG;
}
