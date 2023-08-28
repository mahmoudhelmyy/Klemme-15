/********************************************************************/
/*      SWC     : atmega32_mapping.h                                */
/*      Date    : 8/26/2023                                         */
/*      Authors : MetaWare LLC                                      */
/*		  Mahmoud Sayed Mahmoud Helmy (1285)                */
/*		  Mohamed Mahmoud Masoud (200)                      */
/*		  Mark Ehab Tawfik (201)                            */
/*		  Hazzem Mohamed Ezzeldin (1297)                    */
/*		  Yousef Khaled Ahmed (558)                         */
/********************************************************************/
/* =============================================================
 * 							File Guard
 * =============================================================*/
#ifndef ATMEGA32_MAPPING_H_
#define ATMEGA32_MAPPING_H_
/* =============================================================
 * 							Includes
 * =============================================================*/

#include "std_types.h"

/* =============================================================
 * 							Definitions
 * =============================================================*/
/*
	REGISTER FOR PORTA, DDRA, PINA
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTA *((volatile uint8 *)0x3B)
#define DDRA *((volatile uint8 *)0x3A)
#define PINA *((volatile uint8 *)0x39)


/*
	REGISTER FOR PORTB, DDRB, PINB
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTB *((volatile uint8 *)0x38)
#define DDRB *((volatile uint8 *)0x37)
#define PINB *((volatile uint8 *)0x36)


/*
	REGISTER FOR PORTC, DDRC, PINC
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTC *((volatile uint8 *)0x35)
#define DDRC *((volatile uint8 *)0x34)
#define PINC *((volatile uint8 *)0x33)


/*
	REGISTER FOR PORTD, DDRD, PIND
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTD *((volatile uint8 *)0x32)
#define DDRD *((volatile uint8 *)0x31)
#define PIND *((volatile uint8 *)0x30)


/* =============================================================
 * 							Interrupts
 * =============================================================*/

/* Concatenation Function */
#define VECTOR(x) __vector_##x

/* ISR Body */
#define ISR(vector) \
void vector (void) __attribute__ ((signal,used, externally_visible)) ; \
void vector (void)

/* =============================================================
 * 							Shared
 * =============================================================*/

#define SREG   *((volatile uint8*) 0x5F)
#define MCUCR  *((volatile uint8*) 0x55)
#define MCUCSR *((volatile uint8*) 0x54)
#define GICR   *((volatile uint8*) 0x5B)
#define GIFR   *((volatile uint8*) 0x5A)
#define SFIOR  *((volatile uint8*) 0x50)
#define ADTS2           7
#define ADTS1			6
#define ADTS0			5
#define ACME			3
#define PUD				2
#define PSR2			1
#define PSR10			0

/* =============================================================
 * 				  Analog to Digital Converter
 * =============================================================*/
#define ACSR   *((volatile uint8*) 0x28)

#define ADMUX  *((volatile uint8*) 0x27)
#define REFS1				7
#define REFS0				6
#define ADLAR				5
#define MUX4				4
#define MUX3				3
#define MUX2				2
#define MUX1				1
#define MUX0				0

#define ADCSRA *((volatile uint8*) 0x26)
#define ADEN				7
#define ADSC				6
#define ADATE				5
#define ADIF				4
#define ADIE				3
#define ADPS2				2
#define ADPS1				1
#define ADPS0				0

#define ADCH   *((volatile uint8*) 0x25)
#define ADCL   *((volatile uint8*) 0x24)
#define ADC	   *((volatile uint16*)0x24)


/* =============================================================
 * 							Timers
 * =============================================================*/


#define OCR0  *((volatile uint8*) 0x5C)
#define TCCR0  *((volatile uint8*) 0x53)
#define FOC0            7
#define WGM00			6
#define COM01			5
#define COM00			4
#define WGM01			3
#define	CS02			2
#define	CS01			1
#define	CS00			0
	    
#define TCNT0 *((volatile uint8*) 0x52)
#define TIMSK *((volatile uint8*) 0x59)

#define OCIE2			7
#define TOIE2			6
#define TICIE1			5
#define OCIE1A			4
#define OCIE1B			3
#define TOIE1			2
#define OCIE0			1
#define TOIE0			0
	
#define TIFR *((volatile uint8*) 0x58)
						
#define OCF2			7 
#define TOV2			6
#define ICF1			5
#define OCF1A			4
#define OCF1B			3
#define TOV1			2
#define OCF0			1
#define TOV0            0 
						
						
						
#endif /* ATMEGA32_MAPPING_H_ */
						
						
						
