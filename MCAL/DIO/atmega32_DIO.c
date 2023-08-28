/********************************************************************/
/*      SWC     : atmega32_DIO.c	                                */
/*      Date    : 8/26/2023                                         */
/*      Authors : MetaWare LLC                                      */
/*				  Mahmoud Sayed Mahmoud Helmy (1285)                */
/*		          Mohamed Mahmoud Masoud (200)                      */
/*		          Mark Ehab Tawfik (201)                            */
/*		          Hazzem Mohamed Ezzeldin (1297)                    */
/*		          Yousef Khaled Ahmed (558)                         */
/********************************************************************/

#include "atmega32_DIO.h"

/* ==================================================================================================
 * 							Description
 * ==================================================================================================
 * Configuring the Pin:
 * --------------------------------------------------------------------------------------------------
 * DDxn |  PORTxn  | PUD (in SFIOR) | I/O  |   Pull-up | Comment
 * --------------------------------------------------------------------------------------------------
 *   0        0       X               Input      No      Tri-state (Hi-Z)
 * --------------------------------------------------------------------------------------------------
 *   0        1       0               Input      Yes     Pxn will source current if ext. pulled low.
 * --------------------------------------------------------------------------------------------------
 *   0        1       1               Input      No      Tri-state (Hi-Z)
 * --------------------------------------------------------------------------------------------------
 *   1        0       X               Output     No      Output Low (Sink)
 * --------------------------------------------------------------------------------------------------
 *   1        1       X               Output     No      Output High (Source)
 * --------------------------------------------------------------------------------------------------
 * */


/*
Configure the direction (input/output) of a specific pin.
Arguments:  port_number: The port number to which the pin belongs (PORTA_ID, PORTB_ID, etc.).
			pin_number: The pin number within the port.
			direction: The desired direction of the pin (PIN_INPUT or PIN_OUTPUT).
Return:		void
 */
void DIO_setupPinDirection(uint8 port_number, uint8 pin_number,DIO_PinDirectionType direction) {
	if ((port_number >= NUMBER_OF_PORTS) || (pin_number >= NUMBER_OF_PINS_PER_PORT)) {
	} else {
		switch (port_number) {
		case (PORTA_ID):
			if (direction == PIN_OUTPUT) {
				SET_BIT(DDRA, pin_number);
			} else {
				CLEAR_BIT(DDRA, pin_number);
			}
			break;
		case (PORTB_ID):
			if (direction == PIN_OUTPUT) {
				SET_BIT(DDRB, pin_number);
			} else {
				CLEAR_BIT(DDRB, pin_number);
			}
			break;
		case (PORTC_ID):
			if (direction == PIN_OUTPUT) {
				SET_BIT(DDRC, pin_number);
			} else {
				CLEAR_BIT(DDRC, pin_number);
			}
			break;
		case (PORTD_ID):
			if (direction == PIN_OUTPUT) {
				SET_BIT(DDRD, pin_number);
			} else {
				CLEAR_BIT(DDRD, pin_number);
			}
			break;
		}
	}
}

/*
Configure the direction (input/output) of an entire port.
Arguments:  port_number: The port number to configure (PORTA_ID, PORTB_ID, etc.).
			direction: The desired direction of the entire port (PORT_INPUT or PORT_OUTPUT).
Return:     void
 */
void DIO_setupPortDirection(uint8 port_number, DIO_PinDirectionType direction) {
	if ((port_number >= NUMBER_OF_PORTS)) {

	} else {
		switch (port_number) {
		case (PORTA_ID):
			DDRA = direction;
			break;
		case (PORTB_ID):
			DDRB = direction;
			break;
		case (PORTC_ID):
			DDRC = direction;
			break;
		case (PORTD_ID):
			DDRD = direction;
			break;
		}
	}
}

/*
 Write a logic value (high/low) to a specific pin.
 Arguments:  The port number to which the pin belongs (PORTA_ID, PORTB_ID, etc.).
 			The pin number within the port.
 			The value to write to the pin (LOGIC_HIGH or LOGIC_LOW).
Return:		void
*/
void DIO_writePin(uint8 port_number, uint8 pin_number, uint8 value) {
	if ((port_number >= NUMBER_OF_PORTS) || (pin_number >= NUMBER_OF_PINS_PER_PORT)) {

	} else {
		switch (port_number) {
		case (PORTA_ID):
			if (value == LOGIC_HIGH) {
				SET_BIT(PORTA, pin_number);
			} else {
				CLEAR_BIT(PORTA, pin_number);
			}
			break;
		case (PORTB_ID):
			if (value == LOGIC_HIGH) {
				SET_BIT(PORTB, pin_number);
			} else {
				CLEAR_BIT(PORTB, pin_number);
			}
			break;
		case (PORTC_ID):
			if (value == LOGIC_HIGH) {
				SET_BIT(PORTC, pin_number);
			} else {
				CLEAR_BIT(PORTC, pin_number);
			}
			break;
		case (PORTD_ID):
			if (value == LOGIC_HIGH) {
				SET_BIT(PORTD, pin_number);
			} else {
				CLEAR_BIT(PORTD, pin_number);
			}
			break;
		}

	}
}

/*
Read the logic value (high/low) of a specific pin.
Arguments:  The port number to which the pin belongs (PORTA_ID, PORTB_ID, etc.).
			The pin number within the port.
Return:		The logic value read from the pin (LOGIC_HIGH or LOGIC_LOW). 
*/
uint8 DIO_readPin(uint8 port_number, uint8 pin_number){
	uint8 pin_value = LOGIC_LOW;

	if ((port_number >= NUMBER_OF_PORTS) || (pin_number >= NUMBER_OF_PINS_PER_PORT)) {

	} else {
		switch (port_number) {
		case (PORTA_ID):
			if (GET_BIT(PINA, pin_number)) {
				pin_value = LOGIC_HIGH;
			} else {
				pin_value = LOGIC_LOW;
			}
			break;
		case (PORTB_ID):
			if (GET_BIT(PINB, pin_number)) {
				pin_value = LOGIC_HIGH;
			} else {
				pin_value = LOGIC_LOW;
			}
			break;
		case (PORTC_ID):
			if (GET_BIT(PINC, pin_number)) {
				pin_value = LOGIC_HIGH;
			} else {
				pin_value = LOGIC_LOW;
			}
			break;
		case (PORTD_ID):
			if (GET_BIT(PIND, pin_number)) {
				pin_value = LOGIC_HIGH;
			} else {
				pin_value = LOGIC_LOW;
			}
			break;
		}

	}
	return pin_value;
}

/*
Write a logic value (high/low) to an entire port.
Arguments:  The port number to write to (PORTA_ID, PORTB_ID, etc.).
			The value to write to the port.
Return:		void		
*/
void DIO_writePort(uint8 port_number, uint8 value) {
	if ((port_number >= NUMBER_OF_PORTS)) {

	} else {
		switch (port_number) {
		case (PORTA_ID):
			PORTA = value;
			break;
		case (PORTB_ID):
			PORTB = value;
			break;
		case (PORTC_ID):
			PORTC = value;
			break;
		case (PORTD_ID):
			PORTD = value;
			break;
		}

	}
}

/*
Read the logic value (high/low) of an entire port.
Arguments:			The port number to read from (PORTA_ID, PORTB_ID, etc.).
Return:				An 8 bit number containing values of the pins in the port specified
*/
uint8 DIO_readPort(uint8 port_number) {
	uint8 port_value = LOGIC_LOW;

	if ((port_number >= NUMBER_OF_PORTS)) {

	} else {
		switch (port_number) {
		case (PORTA_ID):
			port_value = PINA;
			break;
		case (PORTB_ID):
			port_value = PINB;
			break;
		case (PORTC_ID):
			port_value = PINC;
			break;
		case (PORTD_ID):
			port_value = PIND;
			break;
		}

	}
	return port_value;
}

/*
Writing alternating logic value (high&low) of a specified pin.
Arguments:			The port number to read from (PORTA_ID, PORTB_ID, etc.).
					An 8 bit number containing values of the pins in the port specified
Return:				void
*/
void DIO_TogglePin(uint8 Port,uint8 Pin){
	switch (Port) {
		case PORTA_ID:
		TOGGLE_BIT(PORTA,Pin);
		break;
		case PORTB_ID:
		TOGGLE_BIT(PORTB,Pin);
		break;
		case PORTC_ID:
		TOGGLE_BIT(PORTC,Pin);
		break;
		case PORTD_ID:
		TOGGLE_BIT(PORTD,Pin);
		break;

	}
}
