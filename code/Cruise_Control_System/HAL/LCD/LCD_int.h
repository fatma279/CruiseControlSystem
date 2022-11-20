/*
 * LCD_int.h
 *
 *  Created on: Oct 10, 2022
 *      Author: aya_enan
 */

#ifndef LCD_LCD_INT_H_
#define LCD_LCD_INT_H_

void H_LCD_void_Init(void);
void H_LCD_void_sendData(u8 copy_u8Data);
void H_LCD_void_sendCommand(u8 copy_u8Command);
void H_LCD_void_sendString(u8 *str);
void H_LCD_void_sendIntNum(s32  copy_s32Num);
void H_LCD_void_gotoXY(u8 copy_u8row, u8 copy_u8col);
void H_LCD_void_ClearDisplay(void);
#endif /* LCD_LCD_INT_H_ */
