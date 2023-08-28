/********************************************************************/
/*      SWC     : Application.h                                     */
/*      Date    : 8/26/2023                                         */
/*      Authors : MetaWare LLC                                      */
/*		  Mahmoud Sayed Mahmoud Helmy (1285)                */
/*		  Mohamed Mahmoud Masoud (200)                      */
/*		  Mark Ehab Tawfik (201)                            */
/*		  Hazzem Mohamed Ezzeldin (1297)                    */
/*		  Yousef Khaled Ahmed (558)                         */
/********************************************************************/
#include "../MCAL/ADC/Adc.h"
#include "../HAL/LCD/AVR_LCD.h"
#include "../MCAL/Timer0/Timer.h"
#include "../HAL/LED/LED.h"
#include "../MCAL/Interrupt/atmega32_Interrupts.h"
#include "../Commons/atmega32_mapping.h"
#include "Application_Cfg.h"
void offMode(void);
void readyMode(void);
void alertMode(void);
void ignitionMode(void);
void systemInit(void);
void App(void);
void welcomeScreen(void);
typedef enum
{
	OFF,
	READY,
	IGNITION
}KLEMMA_STATE_t;
