/*
 * main.c
 *
 *  Created on: Oct 19, 2022
 *      Author: aya_enan
 */
#include "STD.h"
#include"LED_Interface.h"
#include "TIMER0_int.h"
#include "TIMER1_int.h"
#include "DIO_Interface.h"
#include "LCD_int.h"
#include "GIE_int.h"
#include "Ultrasonic_Interface.h"
#include "RELAY_Interface.h"
#include <util/delay.h>
#include "BLUETOOTH_Int.h"



void main()
{
	//Init Ultrasonic
	H_Ultrasonic_void_Init();

	//Init LCD
	H_LCD_void_Init();

	// step 6 : Enable GIE
	M_GIE_void_Enable();

	u16 Distance;
	u8 mode='D';
	u8 flag=0; /*the flag will Guard the car from turning left or right while moving forward right or forward left*/


	H_LCD_void_gotoXY(0, 2);
	H_LCD_void_sendString("MODE: ");

	H_LCD_void_gotoXY(0, 7);
	H_LCD_void_sendData(mode);

	H_LCD_void_gotoXY(1,4);
	H_LCD_void_sendString("CC: ");
    /* init leds*/
	H_LED_Void_LEDInit(LED_RED);
	H_LED_Void_LEDInit(LED_GRN);
	H_LED_Void_LEDInit(LED_BLU);
    /* init relay*/
	H_RELAY_Void_RELAYInit(RELAY1);
    /* init bluetooth*/
	H_BLUETOOTH_Void_BLUETOOTHInit();

	u8 Local_u8_str[3];

	while(1)
	{

		H_LCD_void_gotoXY(1,7);
		H_LCD_void_sendString("OFF");
		H_BLUETOOTH_u8_BLUETOOTHReadStr(Local_u8_str);
		switch(Local_u8_str[0])
		{
		case 'G':
			/* case the car is moving using fuel button */
			if(Local_u8_str[1] == '\0')
			{
				H_LED_Void_LEDOn(LED_GRN);
				H_LED_Void_LEDOff(LED_BLU);
				H_LED_Void_LEDOff(LED_RED);
				flag=0;
			}
			/* case the car is moving using fuel button and turning left */
			else if(Local_u8_str[1] == 'L')
			{
				H_LED_Void_LEDOn(LED_BLU);
				H_LED_Void_LEDOn(LED_GRN);
				H_LED_Void_LEDOff(LED_RED);
				flag=1;
			}
			/* case the car is moving using fuel button and turning right */
			else if(Local_u8_str[1] == 'R')
			{
				H_LED_Void_LEDOn(LED_RED);
				H_LED_Void_LEDOn(LED_GRN);
				H_LED_Void_LEDOff(LED_BLU);
				flag=1;

			}
			break;

		case 'R':
			/* case the car is turning right only */
			if(flag == 0)
			{
				H_LED_Void_LEDOn(LED_RED);
				H_LED_Void_LEDOff(LED_BLU);
				H_LED_Void_LEDOff(LED_GRN);
			}
			break;

		case 'L':
			/* case the car is turning left only */
			if ( flag == 0)
			{
				H_LED_Void_LEDOn(LED_BLU);
				H_LED_Void_LEDOff(LED_RED);
				H_LED_Void_LEDOff(LED_GRN);
			}
			break;

		case 'B':
			/* case the car is in backward mode  .. it will display on lcd char R */
			if(flag == 0)
			{
				H_LCD_void_gotoXY(0, 7);
				H_LCD_void_sendData(' ');
				H_LCD_void_sendData('R');
				H_LED_Void_LEDOff(LED_RED);
				H_LED_Void_LEDOff(LED_GRN);
				H_LED_Void_LEDOff(LED_BLU);
			}
			break;

		case 'F':
			/* case the car is in forward mode  .. it will display on lcd char D */
			if(flag == 0)
			{
				H_LCD_void_gotoXY(0, 7);
				H_LCD_void_sendData(' ');
				H_LCD_void_sendData('D');
				H_LED_Void_LEDOff(LED_RED);
				H_LED_Void_LEDOff(LED_GRN);
				H_LED_Void_LEDOff(LED_BLU);
			}
			break;

		case 'W' :
			if(flag == 0)
			{   /* it will be waiting state until user push w button again */
				do{
					H_RELAY_Void_RELAYOn(RELAY1);
					_delay_ms(1000);
					H_RELAY_Void_RELAYOff(RELAY1);
					_delay_ms(1000);
					/*to read the updated value inside the loop*/
					H_BLUETOOTH_u8_BLUETOOTHReadStr(Local_u8_str);
				}while(Local_u8_str[0]!='W');
			}
			break;

		case 'C':
			H_LCD_void_gotoXY(1,7);
			H_LCD_void_sendString("   ");
			H_LCD_void_gotoXY(1,7);
			H_LCD_void_sendString("ON");

			do{
				/* the value of distance in proutes must be mapped before testing */
				Distance = H_Ultrasonic_u16_Read();

				/*
				 * Will keep the distance equal 20cm
                  If it is greater than 20 he will move the car automatically to keep the distance =20cm
                  (fuel button will be on (middle led is on) and back to off if the distance =20).
				 */

				if (Distance > 20)
				{
					H_LED_Void_LEDOn(LED_GRN);//CAR IS Moving

				}
				else if (Distance <= 20 )
				{
					H_LED_Void_LEDOff(LED_GRN); //CAR IS Stopped

				}

				/* TO TAKE THE NEXT READ :
				 * change trigger to rising edge and enable int
				 */

				H_Ultrasonic_void_ReStart();

				H_BLUETOOTH_u8_BLUETOOTHReadStr(Local_u8_str);

				/*If i was in forward state and pressed backward the cruise control will stop.
				  If it is on and I pressed fuel button the cruise control will stop.*/

			}while ((Local_u8_str[0] !='B') && (Local_u8_str[0] != 'G') );
			break ;

		  default:                    break;


		}


	}

}



