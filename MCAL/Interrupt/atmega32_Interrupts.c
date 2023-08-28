/********************************************************************/
/*      SWC     : atmega32_Interrupts.c	                            */
/*      Date    : 8/26/2023                                         */
/*      Date    : 8/26/2023                                         */
/*      Authors : MetaWare LLC                                      */
/*				  Mahmoud Sayed Mahmoud Helmy (1285)                */
/*		          Mohamed Mahmoud Masoud (200)                      */
/*		          Mark Ehab Tawfik (201)                            */
/*		          Hazzem Mohamed Ezzeldin (1297)                    */
/*		          Yousef Khaled Ahmed (558)                         */
/********************************************************************/

#include "atmega32_Interrupts.h"

/*
Enabling Global Interrupt Bit, it is necessary for the initialization for each maskable Interrupts
Arguments:			void
Return:				void
*/
void GlobalInterrupt_enable(void){
	SET_BIT(SREG , GLOBAL_INTERRUPT_BIT);
}

/*
Enable for INT0 External Interrupt
Arguments:			The interrupt sense control Mode.
Return:				void
*/

void Ext_Int0_Enable(uint8 Mode){
	DIO_setupPinDirection(PORTD, PIN2_ID, PIN_INPUT);
	GICR|=INT0_ENABLE;
	MCUCR = ((MCUCR & 0xFC) | Mode);
}

 /*Disable for INT0 External Interrupt*/
void Ext_Int0_Disable(){
	GICR&=~INT0_ENABLE;
}

/*
Enable for INT1 External Interrupt
Arguments:			The interrupt sense control Mode.
Return:				void
*/
void Ext_Int1_Enable(uint8 Mode){
	DIO_setupPinDirection(PORTD, PIN3_ID, PIN_INPUT);
	GICR|=INT1_ENABLE;
	MCUCR = ((MCUCR & 0xF3) | (Mode<<2));
}

 /*Disable for INT1 External Interrupt*/
void Ext_Int1_Disable(){
	GICR&=~INT1_ENABLE;
}

/*
Enable for INT2 External Interrupt
Arguments:			The interrupt sense control Mode.
Return:				void
*/
void Ext_Int2_Enable(uint8 Mode){
	DIO_setupPinDirection(PORTB, PIN2_ID, PIN_INPUT);
	GICR|=INT2_ENABLE;
	SET_BIT(MCUCSR,Mode);
}
 /*Disable for INT0 External Interrupt*/
void Ext_Int2_Disable(){
	GICR&=~INT2_ENABLE;
}
