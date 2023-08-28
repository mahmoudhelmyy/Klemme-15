/*
 * Application.c
 *
 * Created: 8/28/2023 1:48:29 AM
 * Author: HELMY-PC
 */ 

#include "Application.h"
#include <avr/interrupt.h>
/*==================== Global Variables ====================*/

volatile int g_tick = 0;
volatile uint8 g_ready_cnt = 0;
volatile uint8 g_Timer0_start_once = 0;
volatile KLEMMA_STATE_t g_KLEMMA_STATE ;
static void (*TIMER0_OverflowCallbackFunc)(void);


/*==================== Mode Handling Functions ====================*/

// Function to handle the OFF mode
void offMode() {
    g_KLEMMA_STATE = OFF;
    g_ready_cnt = 0;
    g_Timer0_start_once = 0;
    LCD_moveCursor(0, 0);
    LCD_displayString("OFF    ");
    LED_Off(LED_GREEN);
    LED_Off(LED_RED);
}

// Function to handle the READY mode
void readyMode() {
    g_KLEMMA_STATE = READY;
    LCD_moveCursor(0, 0);
    LCD_displayString("READY   ");
    if (g_ready_cnt == 0) {
//        g_tick = 0;
        LED_on(LED_RED);
        LED_Off(LED_GREEN);
        if(g_Timer0_start_once == 0)
        {
        	TIMER0_vidStart();
        	g_Timer0_start_once = 1;
        }
    }
}

// Function to handle the IGNITION mode
void ignitionMode() {
    g_KLEMMA_STATE = IGNITION;
    g_ready_cnt = 0;
    g_Timer0_start_once = 0;
    LCD_moveCursor(0, 0);
    LCD_displayString("IGNITION");
    LED_Off(LED_GREEN);
    LED_Off(LED_RED);
}

/*==================== System Initialization ====================*/

void systemInit() {
    ADC_ConfigType ADC1 = {ADC_PRESCALER_128, ADC_REFERENCE_AVCC};
    LED_Init_All();
    ADC_Init(&ADC1);
    LCD_init();
}

/*==================== Main Application Function ====================*/

void App() {
    uint16_t readBuffer = 0;
    
    /*==================== System Initialization ====================*/
	
    systemInit();
    TIMER0_vidInit();
    TIMER0_OverflowCallbackFunc = alertMode;
    TIMER0_u8SetOverflowCallback(alertMode);
    TIMER0_vidSetPreloadValue(27);
    TIMER0_vidEnableOverflowInterrupt();
    GlobalInterrupt_enable();
    /*==================================================================*/
    
    LCD_moveCursor(1, 0);
    LCD_displayString("ADC = ");
    
    while (1) {
        // Read ADC value
        ADC_readChannel_interrupt(ADC_CHANNEL_0, &readBuffer);
        LCD_moveCursor(1, 7);
        LCD_integerToString(readBuffer);
        LCD_displayString("  ");
        
        // Determine mode based on ADC value
        if (readBuffer < 50) {
            offMode();
        } else if (readBuffer < 100) {
            readyMode();
        } else {
            ignitionMode();
        }
    }
}

// Function to handle the ALERT mode
void alertMode() {
   if(g_KLEMMA_STATE == READY)
   {
	    g_tick++;
	    if (g_tick == 184) // 184 overflows correspond to 3 seconds with prescaler 1024
	    {
		TIMER0_vidStop();
		g_ready_cnt = 1;
		g_tick = 0;
		LED_Off(LED_RED);
		LED_on(LED_GREEN);
		g_Timer0_start_once = 0;
	    }
   }
   else
   {
	   TIMER0_vidStop();
   }

   TIFR |= (1 << TOV0); // Clear Timer 0 overflow flag
}

void welcomeScreen() {
	_delay_ms(1000);
	// Initialize LCD
	LCD_clearScreen();
	LCD_init();
	
	// Display Team Information
	LCD_moveCursor(0, 0);
	LCD_displayString(TEAM);
	LCD_clearScreen();
	LCD_moveCursor(0, 0);
	LCD_displayString(NAME_1);
	LCD_moveCursor(1, 0);
	LCD_displayString(NAME_2);
	LCD_moveCursor(2, 0);
	LCD_displayString(NAME_3);
	LCD_moveCursor(3, 0);
	LCD_displayString(NAME_4);
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_moveCursor(1, 0);
	LCD_displayString(NAME_5);
	_delay_ms(3000); // Delay for 3 seconds
	
	// Clear the screen
	LCD_clearScreen();
	
	// Display Welcome Message
	LCD_moveCursor(1, 3);
	LCD_displayString(WELCOME);
	_delay_ms(2000); // Delay for 2 seconds
	
	// Clear the screen
	LCD_clearScreen();
	
	// Display Start Engine Message
	LCD_moveCursor(1, 2);
	LCD_displayString(START_CAR);
	_delay_ms(1000);
	
}
