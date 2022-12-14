/*
 * TIMER0_config.h
 *
 *  Created on: Oct 17, 2022
 *      Author: aya_enan
 */

#ifndef TIMER0_TIMER0_CONFIG_H_
#define TIMER0_TIMER0_CONFIG_H_

/*
 *   choose from :
 *    TIMER0_PRESCALER_NO_CLOCK
 *    TIMER0_PRESCALER_1
 *    TIMER0_PRESCALER_8
 *    TIMER0_PRESCALER_64
 *    TIMER0_PRESCALER_256
 *    TIMER0_PRESCALER_1024
 *    TIMER0_PRESCALER_EXT_FALLING_EDGE
 *    TIMER0_PRESCALER_EXT_RAISING_EDGE
 */
#define TIMER0_PRESCALER  TIMER0_PRESCALER_1024
/*
 *   choose from :
 *   TIMER0_MODE_NORMAL
 *   TIMER0_MODE_CTC
 *   TIMER0_MODE_FAST_PWM
 *   TIMER0_MODE_PHASE_CORRECT_PWM
 */
#define TIMER0_MODE     TIMER0_MODE_FAST_PWM
/*
 * choose from :
 * for Non PWM(Normal mode or CTC mode):
 * TIMER0_OC0_MODE_DISCONNECTED
 * TIMER0_OC0_MODE_TOGGLE
 * TIMER0_OC0_MODE_CLEAR
 * TIMER0_OC0_MODE_SET
 *
 * PWM :
  TIMER0_OC0_MODE_PWM_DISCONNECTED
  TIMER0_OC0_MODE_PWM_NON_INVERTING
  TIMER0_OC0_MODE_PWM_INVERTING
 *
 */
#define TIMER0_OC0_MODE TIMER0_OC0_MODE_PWM_NON_INVERTING

#define FCPU   16

#endif /* TIMER0_TIMER0_CONFIG_H_ */
