/*
 * ADC_priv.h
 *
 *  Created on: Oct 16, 2022
 *      Author: aya_enan
 */

#ifndef ADC_ADC_PRIV_H_
#define ADC_ADC_PRIV_H_

#define ADC_REG    *((volatile u16*)0x24) // this is a pinter that points to both ADCH and ADCL
#define ADMUX_REG  *((volatile u8*)0x27) // channel selection
#define ADCSRA_REG  *((volatile u8*)0x26) // Control register
#define SFIOR_REG   *((volatile u8*)0x50) // special function register

//ADCSRA_REG

#define  ADEN_BIT   7   // ADC Enable ON/OFF
#define  ADSC_BIT   6   // ADC start Conversion
#define  ADATE_BIT  5   // auto trigger
#define  ADIF_BIT   4  // Interrupt flag
#define  ADIE_BIT   3  // Interrupt Enable
#define  ADPS2_BIT  2  // prescaler 2
#define  ADPS1_BIT  1  // prescaler 1
#define  ADPS0_BIT  0  // prescaler 0

// SFIOR_REG
#define ADTS2_BIT   7
#define ADTS1_BIT  6
#define ADTS0_BIT   5

//ADMUX_REG

#define REFS1_BIT   7  // v reference 1
#define REFS0_BIT   6  // v reference 0
#define ADLAR_BIT   5  // left or right adjust

#define ADC_PRESCALER_MASK 0b11111000

#define ADC_VREF_MASK   0b00111111

#define ADC_CHANNEL_MASK 0b11100000
#endif /* ADC_ADC_PRIV_H_ */
