/********************************************************************/
/*      SWC     : atmega32_Interrupts.h	                            */
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

#ifndef ATMEGA32_INTERRUPTS_H
#define ATMEGA32_INTERRUPTS_H
/* =============================================================
 * 							Includes
 * =============================================================*/
#include "../../Commons/std_types.h"
#include "../../MCAL/DIO/atmega32_DIO.h"
#include "../../Commons/Macros.h"
#include "../../Commons/atmega32_mapping.h"

/* =============================================================
 * 							Definitions
 * =============================================================*/

/*MISRA C - 2012 Rule 7.2 All unsigned constants are followed by a U suffix to avoid ambiguity*/
#define GLOBAL_INTERRUPT_BIT        7
#define GLOBAL_INT_ENABLE   		1U
#define GLOBAL_INT_DISABLE        	0U
									 
#define INT1_LOW_LEVEL 				0U
#define INT1_ANY_CHANGE 			1U
#define INT1_FALLING_EDGE 			2U
#define INT1_RISING_EDGE 			3U
									 
#define INT0_LOW_LEVEL 				0U
#define INT0_ANY_CHANGE 			1U
#define INT0_FALLING_EDGE 			2U
#define INT0_RISING_EDGE 			3U
									 
#define INT2_FALLING_EDGE			0U
#define INT2_RISING_EDGE			1U

#define INT1_ENABLE					0x80U
#define INT0_ENABLE					0x40U
#define INT2_ENABLE					0x20U

#define INT0_Vector                VECTOR_1
#define INT1_Vector                VECTOR_2
/* =============================================================
 * 							Function Prototypes
 * =============================================================*/
/*
Enabling Global Interrupt Bit, it is necessary for the initialization for each maskable Interrupts
Arguments:			void
Return:				void
*/
void GlobalInterrupt_enable(void);
/*
Enable for INT0 External Interrupt
Arguments:			The interrupt sense control Mode.
Return:				void
*/
void Ext_Int0_Enable(uint8 Mode);

/*Disable for INT0 External Interrupt*/
void Ext_Int0_Disable();

/*
Enable for INT1 External Interrupt
Arguments:			The interrupt sense control Mode.
Return:				void
*/
void Ext_Int1_Enable(uint8 Mode);

/*Disable for INT1 External Interrupt*/
void Ext_Int1_Disable();

/*
Enable for INT2 External Interrupt
Arguments:			The interrupt sense control Mode.
Return:				void
*/
void Ext_Int2_Enable(uint8 Mode);

/*Disable for INT0 External Interrupt*/
void Ext_Int2_Disable();

/* =============================================================
 * 				Global Shared Variables and Pointers
 * =============================================================*/

extern void (*Callback_ptr)();

#define GLOBAL_INTERRUPT_ENABLE_BIT (0x80U)

#endif /* INTERRUPTS_ATMEGA32_H_ */
