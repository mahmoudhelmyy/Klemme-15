/********************************************************************/
/*      SWC     : LED.h		                                        */
/*      Date    : 8/26/2023                                         */
/*      Authors : MetaWare LLC                                      */
/*				  Mahmoud Sayed Mahmoud Helmy (1285)                */
/*		          Mohamed Mahmoud Masoud (200)                      */
/*		          Mark Ehab Tawfik (201)                            */
/*		          Hazzem Mohamed Ezzeldin (1297)                    */
/*		          Yousef Khaled Ahmed (558)                         */
/********************************************************************/
/* =============================================================
 * 							File Guard
 * =============================================================*/

#ifndef LED_H_
#define LED_H_

/* =============================================================
 * 							Includes
 * =============================================================*/

#include "../../MCAL/DIO/atmega32_DIO.h"
#include "../../Commons/std_types.h"

#define LED_BLUE			0   
#define LED_RED				1
#define LED_YELLOW			2
#define LED_GREEN			3

#define LED_RED_PORT		PORTB_ID
#define LED_RED_PIN			PIN7_ID

#define LED_GREEN_PORT		PORTA_ID
#define LED_GREEN_PIN		PIN4_ID

#define LED_BLUE_PORT		PORTA_ID
#define LED_BLUE_PIN		PIN5_ID

#define LED_YELLOW_PORT		PORTA_ID
#define LED_YELLOW_PIN		PIN6_ID

#define LED_OFF				0
#define LED_ON				1

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/* =============================================================
 * 							Function Prototypes
 * =============================================================*/

void LED_Init(uint8 Led_Color);
void LED_Init_All(void);
void LED_on(uint8 Led_Color);
void LED_Off(uint8 Led_Color);
void LED_Toggle(uint8 Led_Color);
uint8 LED_Check(uint8 Led_Color);
void LED_All_Off();

#endif /* LED_H_ */
