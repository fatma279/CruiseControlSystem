/*
 * LCD_priv.h
 *
 *  Created on: Oct 10, 2022
 *      Author: aya_enan
 */

#ifndef LCD_LCD_PRIV_H_
#define LCD_LCD_PRIV_H_

#define LCD_4BIT  0
#define LCD_8BIT  1

#define LCD_FUNCTION_SET_8BIT_2LINES_5X7  0x38

#define LCD_FUNVTION_SET_4BIT_2LINES_5X7  0x28

#define LCD_CLEAR                         0x01

#define DISPLAY_ON_CURSOR_ON_BLINK_OFF    0x0E

#define ENTRY_MODE_SET                   0x06

#define SET_R0C0_                        0x80  // 0x80 (fixed for instruction) +  (0x00 1st address in R0 )

#define SET_R1C0_                        0xC0  // 0x80 (fixed for instruction) +  (0x40 1st address in R1 )

static void H_LCD_void_WriteNlatch(u8 copy_u8Data);
#endif /* LCD_LCD_PRIV_H_ */
