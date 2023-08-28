/********************************************************************/
/*      SWC     : atmega_DIO.h	                                    */
/*      Date    : 8/26/2023                                         */
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
#ifndef ATMEGA32_DIO_H_
#define ATMEGA32_DIO_H_

/* =============================================================
 * 							Includes
 * =============================================================*/
#include "../../Commons/std_types.h"
#include "../../Commons/Macros.h"
#include "../../Commons/atmega32_mapping.h"
#include <util/delay.h>

/* =============================================================
 * 							Definitions
 * =============================================================*/
#define NUMBER_OF_PORTS          (uint8)4
#define NUMBER_OF_PINS_PER_PORT	 (uint8)8
								 
#define PORTA_ID				 (uint8)0
#define PORTB_ID				 (uint8)1
#define PORTC_ID			     (uint8)2
#define PORTD_ID				 (uint8)3
								 
#define PIN0_ID					 (uint8)0
#define PIN1_ID					 (uint8)1
#define PIN2_ID					 (uint8)2
#define PIN3_ID					 (uint8)3
#define PIN4_ID					 (uint8)4
#define PIN5_ID					 (uint8)5
#define PIN6_ID					 (uint8)6
#define PIN7_ID					 (uint8)7

/* =============================================================
 * 							Data Types
 * =============================================================*/
typedef enum {
	PIN_INPUT, PIN_OUTPUT
} DIO_PinDirectionType;

typedef enum {
	PORT_INPUT, PORT_OUTPUT = 0xFF
} DIO_PortDirectionType;

/* =============================================================
 * 						Function Prototypes
 * =============================================================*/

/*
Configure the direction (input/output) of a specific pin.
Arguments:  port_number: The port number to which the pin belongs (PORTA_ID, PORTB_ID, etc.).
			pin_number: The pin number within the port.
			direction: The desired direction of the pin (PIN_INPUT or PIN_OUTPUT).
Return:		void
 */
void DIO_setupPinDirection(uint8 port_number, uint8 pin_number,DIO_PinDirectionType direction);
/*
Configure the direction (input/output) of an entire port.
Arguments:  port_number: The port number to configure (PORTA_ID, PORTB_ID, etc.).
			direction: The desired direction of the entire port (PORT_INPUT or PORT_OUTPUT).
Return:     void
 */
void DIO_setupPortDirection(uint8 port_number, DIO_PinDirectionType direction);
/*
Read the logic value (high/low) of an entire port.
Arguments:			The port number to read from (PORTA_ID, PORTB_ID, etc.).
Return:				An 8 bit number containing values of the pins in the port specified
*/
uint8 DIO_readPort(uint8 port_number);
/*
Write a logic value (high/low) to an entire port.
Arguments:  The port number to write to (PORTA_ID, PORTB_ID, etc.).
			The value to write to the port.
Return:		void		
*/
void DIO_writePort(uint8 port_number, uint8 value);
/*
Read the logic value (high/low) of a specific pin.
Arguments:  The port number to which the pin belongs (PORTA_ID, PORTB_ID, etc.).
			The pin number within the port.
Return:		The logic value read from the pin (LOGIC_HIGH or LOGIC_LOW). 
*/
uint8 DIO_readPin(uint8 port_number, uint8 pin_number);
/*
 Write a logic value (high/low) to a specific pin.
 Arguments:  The port number to which the pin belongs (PORTA_ID, PORTB_ID, etc.).
 			The pin number within the port.
 			The value to write to the pin (LOGIC_HIGH or LOGIC_LOW).
Return:		void
*/
void DIO_writePin(uint8 port_number, uint8 pin_number, uint8 value);
/*
Writing alternating logic value (high&low) of a specified pin.
Arguments:			The port number to read from (PORTA_ID, PORTB_ID, etc.).
					An 8 bit number containing values of the pins in the port specified
Return:				void
*/
void DIO_TogglePin(uint8 Port,uint8 Pin);
#endif /* ATMEGA32_DIO_H_ */
