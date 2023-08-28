/********************************************************************/
/*      SWC     : Timer_Cfg.h	                                    */
/*      Date    : 8/26/2023                                         */
/*      Authors : MetaWare LLC                                      */
/*				  Mahmoud Sayed Mahmoud Helmy (1285)                */
/*		          Mohamed Mahmoud Masoud (200)                      */
/*		          Mark Ehab Tawfik (201)                            */
/*		          Hazzem Mohamed Ezzeldin (1297)                    */
/*		          Yousef Khaled Ahmed (558)                         */
/********************************************************************/

#ifndef MCAL_TIMER0_CONFIG_H_
#define MCAL_TIMER0_CONFIG_H_

/* =============================================================================================================
	                                   Set AVR ATmega32 Clock Frequency
 =============================================================================================================*/
#define TIMER0_MCU_CLK_FREQ 16000000UL /* Default: 8000000UL */

/* =============================================================================================================*/


/* =============================================================================================================
		                             Set Timer0 Operating Mode
 =============================================================================================================*/                         
/* Options : - OVERFLOW_MODE			         
 	     - PHASE_CORRECT_PWM_MODE
 	     - CTC_MODE
 	     - FAST_PWM_MODE
 =============================================================================================================*/
#define TIMER0_MODE OVERFLOW_MODE /* Default: OVERFLOW_MODE */

/* =============================================================================================================
                             Set Mode of Timer0 Output Compare Match Pin (Non-PWM)
 =============================================================================================================*/                       
/* Options : - DISCONNECTED				 
	     - TOGGLE
	     - CLEAR
		 - SET
=============================================================================================================*/
#define TIMER0_NON_PWM_OUTPUT_COMPARE_PIN_MODE DISCONNECTED /* Default : DISCONNECTED */

/* =============================================================================================================
				Set Mode of Timer0 Output Compare Match Pin (FastPWM)
 =============================================================================================================
 Options : - DISCONNECTED				
 	     - NON_INVERTED_MODE
 	     - INVERTED_MODE
	Note    : Only Selected When Fast PWM Mode is Enabled 
 =============================================================================================================*/
#define TIMER0_FAST_PWM_OUTPUT_COMPARE_PIN_MODE DISCONNECTED /* Default : DISCONNECTED */

/* =============================================================================================================
			  Set Mode of Timer0 Output Compare Match Pin (Phase-correct PWM)
 =============================================================================================================*/					      	                         
/* Options : - DISCONNECTED				 
 	     - NON_INVERTED_MODE
 	     - INVERTED_MODE
 Note    : Only Selected When Phase Correct PWM Mode is Enabled				         			
 =============================================================================================================*/
#define TIMER0_PHASE_CORRECT_PWM_OUTPUT_COMPARE_PIN_MODE DISCONNECTED /* Default : DISCONNECTED */

/* =============================================================================================================
 Enable/Disable Timer/Counter0 Overflow Interrupt :- 	 
 =============================================================================================================
 Options : - ENABLE                                    
 	     - DISABLE
 =============================================================================================================*/
#define TIMER0_OVERFLOW_INTERRUPT_ENABLE ENABLE /* Default : DISABLE */

/* =============================================================================================================
 					Enable/Disable Timer/Counter0 Compare Match
 =============================================================================================================
 Options : - ENABLE
           - DISABLE
 =============================================================================================================*/
#define TIMER0_COMPARE_MATCH_INTERRUPT_ENABLE DISABLE /* Default : DISABLE */

/* =============================================================================================================
 						Set Timer0 Prescaler
 =============================================================================================================
 Options : - CLK_DIV_BY_NO_PRESCALER	   	       
 	     - CLK_DIV_BY_8
 	     - CLK_DIV_BY_64
 	     - CLK_DIV_BY_256
 	     - CLK_DIV_BY_1024
	     - EXT_CLK_FALLING_EDGE
	     - EXT_CLK_RISING_EDGE
 Note    : Last two options are selected only if used	Timer0 as counter				
 =============================================================================================================*/
#define TIMER0_PRESCALER CLK_DIV_BY_1024 /* Default: CLK_DIV_BY_8 */

#endif /* MCAL_TIMER0_CONFIG_H_ */
