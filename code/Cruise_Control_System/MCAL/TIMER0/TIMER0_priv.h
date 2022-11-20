/*
 * TIMER0_priv.h
 *
 *  Created on: Oct 17, 2022
 *      Author: aya_enan
 */

#ifndef TIMER0_TIMER0_PRIV_H_
#define TIMER0_TIMER0_PRIV_H_

#define TCNT0_REG   (*((volatile u8*)0x52))  // counter register
#define OCR0_REG    (*((volatile u8*)0x5C))  // compare match register
#define TCCR0_REG   (*((volatile u8*)0x53))  // control register
#define TIMSK_REG   (*((volatile u8*)0x59))  // IEs
#define TIFR_REG    (*((volatile u8*)0x58))  // IFs

//TCCR0_REG
#define FOC0_BIT   7    // force compare match
#define WGM00_BIT  6   // mode select 0
#define COM01_BIT  5   // OC0 pin mode select 1
#define COM00_BIT  4   // OC0 pin mode select 0
#define WGM01_BIT  3  // mode select 1
#define CS02_BIT   2  // prescaler 2
#define CS01_BIT   1  // prescaler 1
#define CS00_BIT   0  // prescaler 0

//TIMSK_REG
#define OCIE0_BIT   1  // Output Compare Interrupt Enable
#define TOIE0_BIT   0  // Overflow Interrupt Enable


//TIFR_REG

#define  OCF0_BIT  1  // Output Compare flag
#define  TOV0_BIT  0  // Overflow flag

#define TIMER0_PRESCALER_MASK    0b11111000  // 0xF8
#define TIMER0_OC0_MODE_MASK     0b11001111  // 0xCF

//prescaler
#define    TIMER0_PRESCALER_NO_CLOCK              0
#define    TIMER0_PRESCALER_1                     1
#define    TIMER0_PRESCALER_8                     2
#define    TIMER0_PRESCALER_64                    3
#define    TIMER0_PRESCALER_256                   4
#define    TIMER0_PRESCALER_1024                  5
#define    TIMER0_PRESCALER_EXT_FALLING_EDGE      6
#define    TIMER0_PRESCALER_EXT_RAISING_EDGE      7

// Timer mode
#define   TIMER0_MODE_NORMAL             0
#define   TIMER0_MODE_CTC                1
#define   TIMER0_MODE_FAST_PWM           2
#define   TIMER0_MODE_PHASE_CORRECT_PWM  3

//OC0 pin Mode
// NON PWM modes
#define  TIMER0_OC0_MODE_DISCONNECTED    0
#define  TIMER0_OC0_MODE_TOGGLE          1
#define  TIMER0_OC0_MODE_CLEAR           2
#define  TIMER0_OC0_MODE_SET             3

// PWM modes
#define TIMER0_OC0_MODE_PWM_DISCONNECTED    0
#define TIMER0_OC0_MODE_PWM_NON_INVERTING   0b00100000 // 0x20 = 32
#define TIMER0_OC0_MODE_PWM_INVERTING       0b00110000 // 0x30 = 48

#endif /* TIMER0_TIMER0_PRIV_H_ */
