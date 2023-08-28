/********************************************************************/
/*      SWC     : Button.h	                                    */
/*      Date    : 8/26/2023                                         */
/*      Authors : MetaWare LLC                                      */
/*		  Mahmoud Sayed Mahmoud Helmy (1285)                */
/*		  Mohamed Mahmoud Masoud (200)                      */
/*		  Mark Ehab Tawfik (201)                            */
/*		  Hazzem Mohamed Ezzeldin (1297)                    */
/*		  Yousef Khaled Ahmed (558)                         */
/********************************************************************/
#include "Button.h"

void Button_init(void)
{ 
	DIO_setupPinDirection(PORTD_ID,PIN7_ID,PIN_INPUT); 
	DIO_setupPinDirection(PORTD_ID,PIN6_ID,PIN_INPUT);
	DIO_setupPinDirection(PORTD_ID,PIN5_ID,PIN_INPUT);
	DIO_setupPinDirection(PORTD_ID,PIN4_ID,PIN_INPUT);
	DIO_setupPinDirection(PORTD_ID,PIN3_ID,PIN_INPUT);
	DIO_setupPortDirection(PORTC_ID,PIN_INPUT);
	
}

uint8_t Button_Read(uint8_t ButtonPinColumn, uint8_t ButtonPinRow){

	uint8_t ButtonStatus;

	DIO_setupPinDirection(BUTTON_PORT_ROW_OUT,ButtonPinRow,PIN_OUTPUT);
	DIO_writePin(BUTTON_PORT_ROW_OUT,ButtonPinRow,LOGIC_LOW);
	
	_delay_ms(20);
	
	ButtonStatus = GET_BIT(BUTTON_PORT_COLUMN_IN,(ButtonPinColumn));
	
	return ButtonStatus;
	
	_delay_ms(20);
	
}
	
	
