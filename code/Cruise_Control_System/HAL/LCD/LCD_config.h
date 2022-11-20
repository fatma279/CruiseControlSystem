/*
 * LCD_config.h
 *
 *  Created on: Oct 10, 2022
 *      Author: aya_enan
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

/*
 *  choose LCD mode :
 *  LCD_4BIT
 *  LCD_8BIT
 */
#define LCD_MODE  LCD_4BIT
/*
 *  control pins
 */
#define LCD_RS_PIN   PA1_PIN
//#define LCD_RW_PIN   PB0_PIN
#define LCD_EN_PIN   PA2_PIN

/*
 *  data pins
 */
#define LCD_D7_PIN  PA6_PIN
#define LCD_D6_PIN  PA5_PIN
#define LCD_D5_PIN  PA4_PIN
#define LCD_D4_PIN  PA3_PIN

#define LCD_D3_PIN  PB2_PIN
#define LCD_D2_PIN  PA2_PIN
#define LCD_D1_PIN  PA1_PIN
#define LCD_D0_PIN  PA0_PIN

#endif /* LCD_LCD_CONFIG_H_ */
