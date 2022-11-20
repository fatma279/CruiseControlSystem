/*
 * LCD_prg.c
 *
 *  Created on: Oct 10, 2022
 *      Author: aya_enan
 */
#include "STD.h"
#include "DIO_Interface.h"
#include "LCD_priv.h"
#include "LCD_config.h"
#include "LCD_int.h"
#include <avr/delay.h>
void H_LCD_void_Init(void)
{
   // step 1 : config direction for Control pins
   M_DIO_Void_SetPinDirection(LCD_RS_PIN, OUTPUT);

   M_DIO_Void_SetPinDirection(LCD_EN_PIN, OUTPUT);
  // step 2 : config direction for data pins 	(D4 ...D7) both
   M_DIO_Void_SetPinDirection(LCD_D7_PIN, OUTPUT);
   M_DIO_Void_SetPinDirection(LCD_D6_PIN, OUTPUT);
   M_DIO_Void_SetPinDirection(LCD_D5_PIN, OUTPUT);
   M_DIO_Void_SetPinDirection(LCD_D4_PIN, OUTPUT);
#if(LCD_MODE == LCD_8BIT)
   // step 2 : config direction for data pins 	(D0 ...D3)
  // M_DIO_Void_SetPinDirection(LCD_RW_PIN, OUTPUT);

   M_DIO_Void_SetPinDirection(LCD_D3_PIN, OUTPUT);
   M_DIO_Void_SetPinDirection(LCD_D2_PIN, OUTPUT);
   M_DIO_Void_SetPinDirection(LCD_D1_PIN, OUTPUT);
   M_DIO_Void_SetPinDirection(LCD_D0_PIN, OUTPUT);

   _delay_ms(35);
   H_LCD_void_sendCommand(LCD_FUNCTION_SET_8BIT_2LINES_5X7);

#elif(LCD_MODE == LCD_4BIT)
   _delay_ms(35);
   // step 1 : select Rs-> 0 (send Command )
   	M_DIO_Void_SetPinValue(LCD_RS_PIN, LOW);
    // deactivate Enable
     	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);

     	// send sequence 0010 required to config 4 bit mode
     	M_DIO_Void_SetPinValue(LCD_D7_PIN,0 );
     	M_DIO_Void_SetPinValue(LCD_D6_PIN,0 );
     	M_DIO_Void_SetPinValue(LCD_D5_PIN,1 );
     	M_DIO_Void_SetPinValue(LCD_D4_PIN,0 );

     	// activate Enable
     M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
     // delay
     _delay_ms(1);
     // deactivate Enable
     M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
     _delay_ms(30);// allow LCD to process data
   H_LCD_void_sendCommand(LCD_FUNVTION_SET_4BIT_2LINES_5X7 );
#endif

   // display ON/OFF
   H_LCD_void_sendCommand(DISPLAY_ON_CURSOR_ON_BLINK_OFF);
   //display clear
   H_LCD_void_sendCommand(LCD_CLEAR);
   //entry mode set
   H_LCD_void_sendCommand(ENTRY_MODE_SET);
}
void H_LCD_void_sendData(u8 copy_u8Data)
{
   // step 1 : select Rs-> 1 (send data )
	M_DIO_Void_SetPinValue(LCD_RS_PIN, HIGH);
	//step 2 : send data
	H_LCD_void_WriteNlatch(copy_u8Data);

}
void H_LCD_void_sendCommand(u8 copy_u8Command)
{
  // step 1 : select Rs-> 0 (send Command )
	M_DIO_Void_SetPinValue(LCD_RS_PIN, LOW);
	//step 2 : send command
	H_LCD_void_WriteNlatch(copy_u8Command);
}
void H_LCD_void_sendString(u8 *str) // 0x50 H
{
	u32 i = 0;
  while(str[i] != '\0')
  {
	  H_LCD_void_sendData(str[i]);
	  i++;
  }

  // Methode 2
/*  while(*str)
  {
	  H_LCD_void_sendData(*str);
	  str++;
  }*/

}
void H_LCD_void_sendIntNum(s32  copy_s32Num)
{
   if(copy_s32Num == 0)
   {
	   H_LCD_void_sendData('0');
	   return;
   }
   else if(copy_s32Num < 0)
   {
	   H_LCD_void_sendData('-');
	   copy_s32Num *= -1;
   }
   s8 i = 0;
   u8 Arr[10] = {0};
   while(copy_s32Num > 0)
   {
	   Arr[i] = copy_s32Num % 10;
	   copy_s32Num /= 10; // copy_s32Num = copy_s32Num /10
	   i++;
   }
   i--;
   while(i>=0)
   {
	   H_LCD_void_sendData(Arr[i]+ '0');
	   i--;
   }
}
void H_LCD_void_ClearDisplay(void)
{
	H_LCD_void_sendCommand(LCD_CLEAR);
}
static void H_LCD_void_WriteNlatch(u8 copy_u8Data)
{
 #if(LCD_MODE == LCD_8BIT)
 // config RW  to be write
	//M_DIO_Void_SetPinValue(LCD_RW_PIN,LOW);
 // deactivate Enable
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
	// prepare data to be latched
  M_DIO_Void_SetPinValue(LCD_D7_PIN, GET_BIT(copy_u8Data,7));
  M_DIO_Void_SetPinValue(LCD_D6_PIN, GET_BIT(copy_u8Data,6));
  M_DIO_Void_SetPinValue(LCD_D5_PIN, GET_BIT(copy_u8Data,5));
  M_DIO_Void_SetPinValue(LCD_D4_PIN, GET_BIT(copy_u8Data,4));
  M_DIO_Void_SetPinValue(LCD_D3_PIN, GET_BIT(copy_u8Data,3));
  M_DIO_Void_SetPinValue(LCD_D2_PIN, GET_BIT(copy_u8Data,2));
  M_DIO_Void_SetPinValue(LCD_D1_PIN, GET_BIT(copy_u8Data,1));
  M_DIO_Void_SetPinValue(LCD_D0_PIN, GET_BIT(copy_u8Data,0));

  // activate Enable
  M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
  // delay
  _delay_ms(1);
  // deactivate Enable
  M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
  _delay_ms(30);// allow LCD to process data

#elif(LCD_MODE == LCD_4BIT)

  // deactivate Enable
  	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
    //break msg into 2 msgs
  	// 1st (high nibble)
  	M_DIO_Void_SetPinValue(LCD_D7_PIN, GET_BIT(copy_u8Data,7));
  	M_DIO_Void_SetPinValue(LCD_D6_PIN, GET_BIT(copy_u8Data,6));
  	M_DIO_Void_SetPinValue(LCD_D5_PIN, GET_BIT(copy_u8Data,5));
  	M_DIO_Void_SetPinValue(LCD_D4_PIN, GET_BIT(copy_u8Data,4));

  	// activate Enable
  M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
  // delay
  _delay_ms(1);
  // deactivate Enable
  M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
  _delay_ms(30);// allow LCD to process data

  // 2nd (low nibble)
  M_DIO_Void_SetPinValue(LCD_D7_PIN, GET_BIT(copy_u8Data,3));
  M_DIO_Void_SetPinValue(LCD_D6_PIN, GET_BIT(copy_u8Data,2));
  M_DIO_Void_SetPinValue(LCD_D5_PIN, GET_BIT(copy_u8Data,1));
  M_DIO_Void_SetPinValue(LCD_D4_PIN, GET_BIT(copy_u8Data,0));

   // activate Enable
    M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
    // delay
    _delay_ms(1);
    // deactivate Enable
    M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
    _delay_ms(30);// allow LCD to process data

#endif
}

void H_LCD_void_gotoXY(u8 copy_u8row, u8 copy_u8col)
{
	if(copy_u8col >= 0 && copy_u8col <= 15)
	{
	  if(copy_u8row == 0) // first row
		  {
		    H_LCD_void_sendCommand(SET_R0C0_ + copy_u8col);
		  }
		  else if (copy_u8row == 1)// 2nd row
		  {
			H_LCD_void_sendCommand(SET_R1C0_ + copy_u8col);
		  }
	}

}
