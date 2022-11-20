/*
 * TIMER0_int.h
 *
 *  Created on: Oct 17, 2022
 *      Author: aya_enan
 */

#ifndef TIMER0_TIMER0_INT_H_
#define TIMER0_TIMER0_INT_H_

#define TIMER0_OVF_INT_ID   0
#define TIMER0_COMP_INT_ID  1

void M_TIMER0_void_Init(void);
void M_TIMER0_void_setTimeMS(u32 copy_u32TimeMS );
void M_TIMER0_void_setCallBack(void (*ptrfn)(void),u8 copy_u8IntID);
void M_TIMER0_void_EnableInt(u8 copy_u8IntID);
void M_TIMER0_void_DisableInt(u8 copy_u8IntID);
void M_TIMER0_void_startTimer(void);
void M_TIMER0_void_stopTimer(void);
void M_TIMER0_void_setFastPWM(u8 copy_u8Duty);
void M_TIMER0_void_setPhaseCorrectPWM(u8 copy_u8Duty);
#endif /* TIMER0_TIMER0_INT_H_ */
