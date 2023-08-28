/********************************************************************/
/*      SWC     : Button.h	                                        */
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

#ifndef BUTTON_H_
#define BUTTON_H_
/* =============================================================
 * 							Includes
 * =============================================================*/

#include "../../MCAL/DIO/atmega32_DIO.h"
  
 /* =============================================================
 * 							Definitions
 * =============================================================*/
  
/********************The Kit Used has a keypad that can work as a 4x4 matrix or a single row of buttons************/
  
/********Is the port of the first row that is constant*************/
#define BUTTON_PORT_ROW_OUT         PORTC_ID      
/********Is the pin of the Button desired in the first row that is constant*************/
#define BUTTON_PIN_ROW              PIN5_ID            
 /********Is the PIN reg in which we read status of the Button desired in one of four columns*************/
#define BUTTON_PORT_COLUMN_IN    PIND  
/********Is the pin of the Button desired in one of four columns*************/     
#define BUTTON_PIN_COLUMN        PIN3_ID         

/* =============================================================
 * 							Function Prototypes
 * =============================================================*/

/*
Initializing  the pin directions of the pins that are connected to the keypad on the avr kit (Fares ATMega32 Kit)
Arguments :			void
Return:				void
 */
void Button_init(void);
/*
Reading the logical value of a single button
Arguments:  ButtonPinColumn: The Column number of the button specified
			ButtonPinColumn: The Row number of the button specified
Return:		Logical value of the key specified
*/
uint8_t Button_Read(uint8_t ButtonPinColumn, uint8_t ButtonPinRow);

#endif /* BUTTON_H_ */
