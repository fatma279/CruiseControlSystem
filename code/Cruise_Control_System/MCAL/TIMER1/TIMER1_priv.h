/*
 * TIMER1_priv.h
 *
 *  Created on: Oct 19, 2022
 *      Author: aya_enan
 */

#ifndef TIMER1_TIMER1_PRIV_H_
#define TIMER1_TIMER1_PRIV_H_

#define TCCR1A_REG (*((volatile u8*)0x4F)) // control register A
#define TCCR1B_REG (*((volatile u8*)0x4E)) // control register B
#define TIMSK_REG  (*((volatile u8*)0x59)) // IEs
#define ICR_REG    (*((volatile u16*)0x46)) // Input Capture Register (L+H)

//TCCR1A_REG
#define WGM10_BIT   0  // Mode Select bit 0
#define WGM11_BIT   1  // Mode Select bit 1

//TCCR1B_REG
#define CS10_BIT    0  // clock select bit 0
#define CS11_BIT    1  // clock select bit 1
#define CS12_BIT    2  // clock select bit 2
#define WGM12_BIT   3   // Mode Select bit 2
#define WGM13_BIT   4   // Mode Select bit 3
#define ICES1_BIT   6   //ICU edge Select (RAIS = 1),(falling = 0)
//TIMSK_REG
#define TICIE1_BIT  5 // ICU interrupt Enable
#endif /* TIMER1_TIMER1_PRIV_H_ */
