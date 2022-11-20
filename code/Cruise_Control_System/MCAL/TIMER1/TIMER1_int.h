/*
 * TIMER1_int.h
 *
 *  Created on: Oct 19, 2022
 *      Author: aya_enan
 */

#ifndef TIMER1_TIMER1_INT_H_
#define TIMER1_TIMER1_INT_H_

#define TIMER1_ICU_RAISING_TRIGG  1
#define TIMER1_ICU_FALLING_TRIGG  0

void M_TIMER1_void_Init(void);
void M_TIMER1_ICU_void_Init(void);
void M_TIMER1_ICU_void_setTrigger(u8 copy_u8Trigg);
void M_TIMER1_ICU_void_setCallBack(void (*ptrfn)(void));
u16  M_TIMER1_ICU_u16_readInput(void);
void M_TIMER1_ICU_void_EnableInt(void);
void M_TIMER1_ICU_void_DisableInt(void);

#endif /* TIMER1_TIMER1_INT_H_ */
