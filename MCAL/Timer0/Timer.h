/********************************************************************/
/*      SWC     : Timer.h	                                        */
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
 * 			File Guard
 * =============================================================*/
#ifndef MCAL_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_INTERFACE_H_

#include "../../Commons/Macros.h"
#include "../../Commons/std_types.h"
#include "../../Commons/atmega32_mapping.h"
#include "Timer_Cfg.h"
#include "Timer_Private.h"

/*-----------------------------------------------------------------------------------*/
/*                                                                                   */
/*                           	 FUNCTIONS PROTOTYPES				     */
/*                                                                                   */
/*-----------------------------------------------------------------------------------*/

/**********************************************************************************/
/* Description     : Initialize Timer0 based on selected configurations from      */
/* 		     config file						  */
/* Input Arguments : void						          */
/* Return          : void						          */
/**********************************************************************************/
void TIMER0_vidInit(void);
/**********************************************************************************/
/* Description     : Start Timer0 by setting Timer0 prescaler selected from       */
/* 		     config file					          */
/* Input Arguments : void						          */
/* Return          : void						          */
/**********************************************************************************/
void TIMER0_vidStart(void);
/**********************************************************************************/
/* Description     : Stop Timer0  					          */
/* Input Arguments : void						          */
/* Return          : void						          */
/**********************************************************************************/
void TIMER0_vidStop(void);
/**********************************************************************************/
/* Description     : Set preload value					          */
/* Input Arguments : u8 Copy_u8PreloadValue                                       */
/* Return          : void                                		          */
/**********************************************************************************/
void TIMER0_vidSetPreloadValue(uint8 Copy_u8PreloadValue);
/**********************************************************************************/
/* Description     : Set compare match value				          */
/* Input Arguments : u8 Copy_u8CompareMatchValue                                  */
/* Return          : void                                		          */
/**********************************************************************************/
void TIMER0_vidSetCompareMatchValue(uint8 Copy_u8CompareMatchValue);
/**********************************************************************************/
/* Description     : Read Timer/Counter0 Value				          */
/* Input Arguments : void                                                         */
/* Return          : u8	                                		          */
/**********************************************************************************/
uint8 TIMER0_u8ReadTimerValue(void);
/**********************************************************************************/
/* Description     : Enable Timer0 Overflow Interrupt			          */
/* Input Arguments : void                                                         */
/* Return          : void                                		          */
/**********************************************************************************/
void TIMER0_vidEnableOverflowInterrupt(void);
/**********************************************************************************/
/* Description     : Disable Timer0 Overflow Interrupt			          */
/* Input Arguments : void                        			          */
/* Return          : void                               	                  */
/**********************************************************************************/
void TIMER0_vidDisableOverflowInterrupt(void);
/**********************************************************************************/
/* Description     : Enable Timer0 Compare Match Interrupt		          */
/* Input Arguments : void                            		    	          */
/* Return          : void                       		                  */
/**********************************************************************************/
void TIMER0_vidEnableCompareMatchInterrupt(void);
/**********************************************************************************/
/* Description     : Disable Timer0 Compare Match Interrupt		          */
/* Input Arguments : void                       				  */
/* Return          : void                    			                  */
/**********************************************************************************/
void TIMER0_vidDisableCompareMatchInterrupt(void);
/**********************************************************************************/
/* Description     : Register application callback function that will be called   */
/*		     immediately once Timer0 overflow ISR is triggered		  */
/* Input Arguments : void(*Copy_pvTIMER0OverflowFunc)(void)		          */
/* Return          : u8						                  */
/**********************************************************************************/
uint8 TIMER0_u8SetOverflowCallback(void(*Copy_pvTIMER0OverflowFunc)(void));
/**********************************************************************************/
/* Description     : Register application callback function that will be called   */
/*		     immediately once Timer0 compare match ISR is triggered	  */
/* Input Arguments : void(*Copy_pvTIMER0CompareMatchFunc)(void)		          */
/* Return          : u8						                  */
/**********************************************************************************/
uint8 TIMER0_u8SetCompareMatchCallback(void(*Copy_pvTIMER0CompareMatchFunc)(void));
/**********************************************************************************/
/* Description     : A function used to delay the processor for some time in      */
/*		     milli-second based on passed value of time in milli-second   */
/* Input Arguments : u32 Copy_u32DelayTime_ms				          */
/* Return          : u8                                                	          */
/**********************************************************************************/
uint8 TIMER0_u8SetBusyWait_ms(uint32 Copy_u32DelayTime_ms);
/**********************************************************************************/
/* Description     : Start to generate PWM from Timer0			          */
/* Input Arguments : u8 Copy_u8DutyCyclePercentage				  */
/* Return          : void						          */
/**********************************************************************************/
uint8 TIMER0_u8StartPWM(uint8 Copy_u8DutyCyclePercentage);
/**********************************************************************************/
/* Description     : Clear Timer0 overflow flag				          */
/* Input Arguments : void							  */
/* Return          : void						          */
/**********************************************************************************/
void TIMER0_vidClearOvfFlag(void);

#endif /* MCAL_TIMER0_INTERFACE_H_ */
