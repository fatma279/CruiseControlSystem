/*
 * ADC_int.h
 *
 *  Created on: Oct 16, 2022
 *      Author: aya_enan
 */

#ifndef ADC_ADC_INT_H_
#define ADC_ADC_INT_H_

typedef enum{
	prescaler_2 = 1,
	prescaler_4,
	prescaler_8,
	prescaler_16,
	prescaler_32,
	prescaler_64,
	prescaler_128,

}prescaler_t;
typedef enum{
	vref_AREF,
	vref_AVCC,
	vref_Internal = 3,
}vref_t	;
typedef enum
{
	channel_0,
	channel_1,
	channel_2,
	channel_3,
	channel_4,
	channel_5,
	channel_6,
	channel_7,
}channel_t;
void M_ADC_void_Init(u8 copy_u8presclaer, u8 copy_vref);
u16 M_ADC_u16_adcRead(u8 copy_u8Channel );

#endif /* ADC_ADC_INT_H_ */
