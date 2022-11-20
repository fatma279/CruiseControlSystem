/*
 * EXTI_int.h
 *
 *  Created on: Oct 12, 2022
 *      Author: aya_enan
 */

#ifndef EXTI_EXTI_INT_H_
#define EXTI_EXTI_INT_H_

#define EXTI_TRIG_LOW_LEVEL       0 // 0 0
#define EXTI_TRIG_ANY_CHANGE      1 // 0 1
#define EXTI_TRIG_FALLING_EDGE    2 // 1 0
#define EXTI_TRIG_RAISING_EDGE    3 // 1 1

#define EXTI_INT0_ID   6   // IE
#define EXTI_INT1_ID   7
#define EXTI_INT2_ID   5


void M_EXTI_void_EnableInt(u8 copy_u8IntID, u8 copy_u8Trigg);

void M_EXTI_void_DisableInt(u8 copy_u8IntID);

void M_EXTI_void_setCallBackfn(void (*ptrfn)(void),u8 copy_u8IntID);
#endif /* EXTI_EXTI_INT_H_ */
