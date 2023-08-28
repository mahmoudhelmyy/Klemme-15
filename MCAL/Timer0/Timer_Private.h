/********************************************************************/
/*      SWC     : Timer_Private.c	                            */
/*      Date    : 8/26/2023                                         */
/*      Authors : MetaWare LLC                                      */
/*		  Mahmoud Sayed Mahmoud Helmy (1285)                */
/*		  Mohamed Mahmoud Masoud (200)                      */
/*		  Mark Ehab Tawfik (201)                            */
/*		  Hazzem Mohamed Ezzeldin (1297)                    */
/*		  Yousef Khaled Ahmed (558)                         */
/********************************************************************/

#ifndef MCAL_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_PRIVATE_H_

/* ============================================================================================================= 
/*                           	               PRIVATE MACROS				     
/* =============================================================================================================*/    
/* Define Timer0 Overflow Ticks */
#define TIMER0_OVERFLOW_TICKS		                                 255 /* Maximum Number of Timer Ticks to Reach Overflow and Calculated Based on Timer Resolution (8 bits in case of Timer0) */


/* Mask of Timer0 Waveform Generation Bits */
#define TIMER0_WAVEFORM_GENERATION_MASK                                  0b10110111


/* Define Timer0 Operating Modes */
#define TIMER0_OVERFLOW_MODE				                 0b00000000 /* Normal (Overflow) Mode */
#define TIMER0_PHASE_CORRECT_PWM_MODE                                    0b01000000 /* PWM, Phase Correct Mode */
#define TIMER0_CTC_MODE		                                         0b00001000 /* CTC (Clear Timer on Compare Match) Mode */
#define TIMER0_FAST_PWM_MODE                                             0b01001000 /* Fast PWM Mode */


/* Mask of Timer0 Output Compare Match Pin Mode Bits */
#define TIMER0_OUTPUT_COMPARE_PIN_MODE_MASK                              0b11001111


/* Define Timer0 Output Compare Match Pin Modes (Non PWM) */
#define TIMER0_NON_PWM_OUTPUT_COMPARE_PIN_DISCONNECTED                   0b00000000 /* Timer0 Output Compare Match Pin is Disconnect */
#define TIMER0_NON_PWM_OUTPUT_COMPARE_PIN_TOGGLE                         0b00010000 /* Timer0 Output Compare Match Pin is Toggled */
#define TIMER0_NON_PWM_OUTPUT_COMPARE_PIN_CLEAR                          0b00100000 /* Timer0 Output Compare Match Pin is Cleared */
#define TIMER0_NON_PWM_OUTPUT_COMPARE_PIN_SET                            0b00110000 /* Timer0 Output Compare Match Pin is Set */


/* Define Timer0 Output Compare Match Pin Modes (Fast PWM) */
#define TIMER0_FAST_PWM_OUTPUT_COMPARE_PIN_DISCONNECTED		         0b00000000 /* Timer0 Output Compare Match Pin is Disconnect */
#define TIMER0_FAST_PWM_OUTPUT_COMPARE_PIN_NON_INVERTED_MODE             0b00100000 /* Clear OC0 on compare match, set OC0 at TOP */
#define TIMER0_FAST_PWM_OUTPUT_COMPARE_PIN_INVERTED_MODE                 0b00110000 /* Set OC0 on compare match, clear OC0 at TOP */


/* Define Timer0 Output Compare Match Pin Modes (Phase-Correct PWM) */
#define TIMER0_PHASE_CORRECT_PWM_OUTPUT_COMPARE_PIN_DISCONNECTED         0b00000000 /* Timer0 Output Compare Match Pin is Disconnect */
#define TIMER0_PHASE_CORRECT_PWM_OUTPUT_COMPARE_PIN_NON_INVERTED_MODE    0b00100000 /* Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting */
#define TIMER0_PHASE_CORRECT_PWM_OUTPUT_COMPARE_PIN_INVERTED_MODE        0b00110000 /* Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting */


/* Mask of Timer0 Clock Selection Bits */
#define TIMER0_CLK_MASK							 0xF8


/* Timer0 Prescaler Selections */
#define TIMER0_CLK_DIV_BY_NO_PRESCALER				         1 /* clkI/O/(No prescaling) */
#define TIMER0_CLK_DIV_BY_8						 2 /* clkI/O/8 (From prescaler) */
#define TIMER0_CLK_DIV_BY_64						 3 /* clkI/O/64 (From prescaler) */
#define TIMER0_CLK_DIV_BY_256						 4 /* clkI/O/256 (From prescaler) */
#define TIMER0_CLK_DIV_BY_1024						 5 /* clkI/O/1024 (From prescaler) */
#define TIMER0_EXT_CLK_FALLING_EDGE					 6 /* External clock source on T0 pin. Clock on falling edge */
#define TIMER0_EXT_CLK_RISING_EDGE			       	         7 /* External clock source on T0 pin. Clock on rising edge */


/*-----------------------------------------------------------------------------------*/
/*                                                                                   */
/*                           CONFIGURATION OPTIONS VALUES		             */
/*                                                                                   */
/*-----------------------------------------------------------------------------------*/

/* Timer0 Operating Modes Options */
#define OVERFLOW_MODE							 1
#define PHASE_CORRECT_PWM_MODE                                           2
#define CTC_MODE							 3
#define FAST_PWM_MODE                                                    4


/* Output Compare Match Pin Modes Options (Non PWM) */
#define DISCONNECTED							 0
#define TOGGLE	                                                         1
#define CLEAR	                                                         2
#define SET																 3


/* Output Compare Match Pin Modes Options (Phase Correct & Fast PWM) */
#define NON_INVERTED_MODE                                                1
#define INVERTED_MODE                                                    2


/* Enable/Disable signals for both Overflow and Compare Match Interrupts of Timer0 */
#define ENABLE                                                           1
#define DISABLE                                                          2


/* Timer0 Pre-scaler Options */
#define CLK_DIV_BY_NO_PRESCALER	                                         1
#define CLK_DIV_BY_8	                                                 8
#define CLK_DIV_BY_64							 64
#define CLK_DIV_BY_256      	                                         256
#define CLK_DIV_BY_1024                                                  1024
#define EXT_CLK_FALLING_EDGE	                                         2
#define EXT_CLK_RISING_EDGE						 3

/**********************************************************************************/
/* Description     : Function to get ceil of the result of two dividend numbers   */
/* Input Arguments : f32 Copy_f32Num1 , f32 Copy_f32Num2		          */
/* Return          : u32  	        	      			          */
/**********************************************************************************/
/*
uint32 SERV_u32CeilDev(float32 Copy_f32Num1 , float32 Copy_f32Num2)
{
	/ * Local Variables Definitions * /
	uint32 Local_u32Result;			/ * A variable to hold result after ceiling * /

	/ * Calculate result then ceil it * /
	Local_u32Result = (uint32)(Copy_f32Num1/Copy_f32Num2) + (SERV_f32Mod(Copy_f32Num1,Copy_f32Num2)!= 0);

	return Local_u32Result;
}
*/

#endif /* MCAL_TIMER0_PRIVATE_H_ */
