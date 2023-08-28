/********************************************************************/
/*      SWC     : Application.c                                     */
/*      Date    : 8/26/2023                                         */
/*      Authors : MetaWare LLC                                      */
/*				  Mahmoud Sayed Mahmoud Helmy (1285)                */
/*		          Mohamed Mahmoud Masoud (200)                      */
/*		          Mark Ehab Tawfik (201)                            */
/*		          Hazzem Mohamed Ezzeldin (1297)                    */
/*		          Yousef Khaled Ahmed (558)                         */
/********************************************************************/

 /* =============================================================
 * 							Includes
 * =============================================================*/
  
#include "Application.h"

 /* =============================================================
 * 						Global Variables
 * =============================================================*/
  
volatile int g_tick = 0;				/* Variable to hold Timer0 Ticks */
volatile uint8 g_ready_cnt = 0;				/* Variable to indicate status of OVF interrupt return */
volatile uint8 g_Timer0_start_once = 0;			/* Variable to indicated if Timer0 has started only once or not while in ready state */
volatile KLEMMA_STATE_t g_KLEMMA_STATE ;		/* Variable to hold current state of KLEMME 15 */
static void (*TIMER0_OverflowCallbackFunc)(void);	/* Variable to hold pointer to OVF callback function */


/*==================== Mode Handling Functions ====================*/

/* Function to handle the OFF mode */
void offMode()
{
    /* Set klemma state to off */
    g_KLEMMA_STATE = OFF;

    /* Reset g_ready_cnt flag */
    g_ready_cnt = 0;

    /* Reset  g_Timer0_start_once Flag */
    g_Timer0_start_once = 0;

    /* Info to be displayed on lcd while on klemma off state */
    LCD_moveCursor(1, 0);
    LCD_displayString("OFF    ");

    /* Turn off both RED and GREEN LEDs */
    LED_Off(LED_GREEN);
    LED_Off(LED_RED);
    LCD_moveCursor(3,0);
    LCD_displayString("RED OFF GREEN OFF");
}

/* Function to handle the READY mode */
void readyMode()
{
    /* Set klemma state to ready */
    g_KLEMMA_STATE = READY;

    /* Info to be displayed on lcd while on klemma ready state */
    LCD_moveCursor(1, 0);
    LCD_displayString("READY   ");

    /* Check if OVF Interrupt was entered or not */
    if (g_ready_cnt == 0) {

	/* OVF Interrupt was not entered */

	/* Turn on RED LED and Turn off GREEN LED */
        LED_on(LED_RED);
        LED_Off(LED_GREEN);
	LCD_moveCursor(3,0);
        LCD_displayString("RED ON GREEN OFF ");

        /* Check if Timer0 started or not */
        if(g_Timer0_start_once == 0)
        {
        	/* Timer0 has not started */

        	/* Start Timer0 */
        	TIMER0_vidStart();

        	/* Set g_Timer0_start_once Flag */
        	g_Timer0_start_once = 1;
        }
    }
    else
    {
	    /* OVF Interrupt was entered */

	    /* Turn off RED LED and Turn on GREEN LED */
	    LCD_moveCursor(3,0);
	    LCD_displayString("RED OFF GREEN ON ");
    }
}

/* Function to handle the IGNITION mode */
void ignitionMode()
{
    /* Set klemma state to ready */
    g_KLEMMA_STATE = IGNITION;

    /* Reset g_ready_cnt flag */
    g_ready_cnt = 0;

    /* Reset  g_Timer0_start_once Flag */
    g_Timer0_start_once = 0;

    /* Info to be displayed on lcd while on klemma ready state */
    LCD_moveCursor(1,0);
    LCD_displayString("IGNITION");

    /* Turn off both RED and GREEN LEDs */
    LED_Off(LED_GREEN);
    LED_Off(LED_RED);
    LCD_moveCursor(3,0);
    LCD_displayString("RED OFF GREEN OFF");
}

/*==================== System Initialization ====================*/
void systemInit()
{
    /* Set ADC pre-configurations */
    ADC_ConfigType ADC1 = {ADC_PRESCALER_128, ADC_REFERENCE_AVCC};

    /* Initialize LED system in the app */
    LED_Init_All();

    /* Initialize ADC */
    ADC_Init(&ADC1);

    /* Initialize Character LCD */
    LCD_init();
}

/*==================== Main Application Function ====================*/
void App()
{
    /* Local Variables Definitions */
    uint16 readBuffer = 0;
    
    /*==================== System Initialization ====================*/
    /* Display APP Welcome Screen  */
    welcomeScreen();

    /* Initialize System */
    systemInit();

    /* Initialize Timer0 */
    TIMER0_vidInit();

    /* Register OVF Callback Function */
    TIMER0_OverflowCallbackFunc = alertMode;
    TIMER0_u8SetOverflowCallback(alertMode);

    /* Set Preload Value */
    TIMER0_vidSetPreloadValue(27);

    /* Enable OVF Interrupt */
    TIMER0_vidEnableOverflowInterrupt();

    /* Enable Global Interrupt Enable */
    GlobalInterrupt_enable();

    /*================================Begin APP==================================*/
    LCD_moveCursor(0, 0);
    LCD_displayString("KLEMME STATE ");
    LCD_moveCursor(2, 0);
    LCD_displayString("KLEMME RANGE = ");
    
    while (1)
    {
        /* Read ADC value */
        ADC_readChannel_interrupt(ADC_CHANNEL_0, &readBuffer);

        /* Print ADC value on LCD */
        LCD_moveCursor(2, 15);
        LCD_integerToString(readBuffer);
        LCD_displayString("  ");
        
        /* Determine mode based on ADC value */
        if (readBuffer < 50)
        {
        	/* Enter off mode */
                offMode();
        }
        else if (readBuffer < 100)
        {
        	/* Enter ready mode */
                readyMode();
        }
	else
        {
		/* Enter ignition mode */
		ignitionMode();
        }
    }
}

/* Function to handle the ALERT mode (Overflow Callback Function) */
void alertMode()
{
   /* Check if Klemma is in ready state */
   if(g_KLEMMA_STATE == READY)
   {
	   /* Klemma is in ready state */

	   /* Increase OVFs Counter */
	    g_tick++;

	    /* Check if OVFs Counter reached required OVFs number required to achieve 3 seconds */
	    if (g_tick == 184) /* 184 overflows correspond to 3 seconds with prescaler 1024 */
	    {
		/* 3 seconds Passed */

		/* Stop Timer0 */
		TIMER0_vidStop();

		/* Set g_ready_cnt Flag */
		g_ready_cnt = 1;

		/* Reset g_Timer0_start_once Flag */
		g_Timer0_start_once = 0;

		/* Reset OVFs Counter */
		g_tick = 0;

		/* Turn off RED LED and Turn on GREEN LED */
		LED_Off(LED_RED);
		LED_on(LED_GREEN);
	    }
   }
   else
   {
	   /* Klemma is not in ready state */

	   /* Stop Timer0 */
	   TIMER0_vidStop();
   }

   /* Clear Timer0 OVF Flag */
   TIMER0_vidClearOvfFlag();
}

void welcomeScreen() {
	_delay_ms(1000);		/* Delay for 1 second */

	/* Initialize LCD */
	LCD_clearScreen();
	LCD_init();
	
	/* Display Team Information */
	LCD_moveCursor(1, 0);
	LCD_displayString(TEAM);
	_delay_ms(50);			/* Delay for 50 milli seconds */
	LCD_clearScreen();
	LCD_moveCursor(1, 0);
	LCD_displayString(TEAM_REVERSE);
	_delay_ms(50);			/* Delay for 50 milli seconds */
	LCD_clearScreen();
	LCD_moveCursor(1, 0);
	LCD_displayString(TEAM);
	_delay_ms(2000);		/* Delay for 2 seconds */
	LCD_clearScreen();
	LCD_moveCursor(0, 0);
	LCD_displayString(NAME_1);
	LCD_moveCursor(1, 0);
	LCD_displayString(NAME_2);
	LCD_moveCursor(2, 0);
	LCD_displayString(NAME_3);
	LCD_moveCursor(3, 0);
	LCD_displayString(NAME_4);
	_delay_ms(1000);		/* Delay for 1 second */
	LCD_clearScreen();
	LCD_moveCursor(1, 0);
	LCD_displayString(NAME_5);
	_delay_ms(3000); 		/* Delay for 3 seconds */
	
	/* Display class and company info */
	LCD_clearScreen();
	LCD_moveCursor(0,0);
	LCD_displayString(COMPANY);
	LCD_moveCursor(1,0);
	LCD_displayString(CLASS);
	_delay_ms(3000);		/* Delay for 3 seconds */
	
	/* Display Welcome Message */
	LCD_clearScreen();
	LCD_moveCursor(1, 3);
	LCD_displayString(WELCOME);
	_delay_ms(2000); 		/* Delay for 2 seconds */
	

	/* Display Start Engine Message */
	LCD_clearScreen();
	LCD_moveCursor(1, 2);
	LCD_displayString(START_CAR);
	_delay_ms(1000);		/* Delay for 2 seconds */
	
}
