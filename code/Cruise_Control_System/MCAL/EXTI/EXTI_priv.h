/*
 * EXTI_priv.h
 *
 *  Created on: Oct 12, 2022
 *      Author: aya_enan
 */

#ifndef EXTI_EXTI_PRIV_H_
#define EXTI_EXTI_PRIV_H_


#define MCUCR_REG   (*((volatile u8 *) 0x55))
#define MCUCSR_REG  (*((volatile u8 *) 0x54))
#define GICR_REG    (*((volatile u8 *) 0x5B)) // control register contains IEs
#define GIFR_REG    (*((volatile u8 *) 0x5A)) // flag register contains IFs


//GICR
#define INT1_BIT   7  // IE of EXTI1
#define INT0_BIT   6  // IE of EXTI0
#define INT2_BIT   5  // IE of EXTI2


//GIFR
#define INTF1_BIT   7  // IF of EXTI1
#define INTF0_BIT   6  // IF of EXTI0
#define INTF2_BIT   5  // IF of EXTI2

//MCUCR
#define ISC00_BIT  0   // INT0 sense control 0
#define ISC01_BIT  1   // INT0 sense control 1

#define ISC10_BIT  2   // INT1 sense control 0
#define ISC11_BIT  3   // INT1 sense control 1

//MCUCSR
#define ISC2_BIT    6   // INT2 sense control


#define EXTI_INT0_MASK    0b11111100 // 0xFC
#define EXTI_INT1_MASK    0b11110011 // 0xF3
#endif /* EXTI_EXTI_PRIV_H_ */
