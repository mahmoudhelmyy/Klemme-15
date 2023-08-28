/********************************************************************/
/*      SWC     : Adc.c		                                    */
/*      Date    : 8/26/2023                                         */
/*      Authors : MetaWare LLC                                      */
/*		  Mahmoud Sayed Mahmoud Helmy (1285)                */
/*		  Mohamed Mahmoud Masoud (200)                      */
/*		  Mark Ehab Tawfik (201)                            */
/*		  Hazzem Mohamed Ezzeldin (1297)                    */
/*		  Yousef Khaled Ahmed (558)                         */
/********************************************************************/

#include "Adc.h"

/* pointer to char that holds the address of the buffer -that is sent to  *
 * the read function- where the ADC value should be saved.                */
volatile uint16 * g_ADCBuffer;

/* Interrupt service routine where the value of the ADC is saved in the    *
 * ADCBuffer variable.                                                     */
ISR(__vector_16){
    *g_ADCBuffer = ADC;
}



Std_ReturnType ADC_Init(const ADC_ConfigType *ConfigPtr) {
	/* Configure ADC settings */
	uint8 reference = ConfigPtr->reference;
	uint8 prescaler = ConfigPtr->prescaler;
	
	SET_BIT(ADCSRA, ADEN); /* Enable the ADC */
	CLEAR_BIT(ADCSRA, ADIE); /* Disable the ADC interrupt */
	ADMUX = (ADMUX & 0x3F) | (reference << 6); /* Set reference input */
	
	/* Set pre-scaler */
	switch (prescaler) {
		case ADC_PRESCALER_2:
		case ADC_PRESCALER_4:
		case ADC_PRESCALER_8:
		case ADC_PRESCALER_16:
		case ADC_PRESCALER_32:
		case ADC_PRESCALER_64:
		case ADC_PRESCALER_128:
		ADCSRA = (ADCSRA & 0xF8) | prescaler;
		break;
		default:
		return E_NOT_OK;
	}
	
	return E_OK;
}

Std_ReturnType ADC_readChannel_polling(uint8 channelNum , uint16 * read_buffer){
	ADMUX = (ADMUX & 0xE0) | channelNum; /* channel number that I want to read from */
	SET_BIT(ADCSRA , ADSC);/* ADC start conversion */
	while(!(GET_BIT(ADCSRA , ADIF)));
	SET_BIT(ADCSRA , ADIF);
	*read_buffer = 0xFF & ADCL;
	*read_buffer = ((*read_buffer & 0xFF) | (ADCH<<8));
	return E_OK;
}


Std_ReturnType ADC_readChannel_interrupt(uint8 channelNum, uint16 *read_buffer){
	g_ADCBuffer = read_buffer;
	ADMUX = (ADMUX & 0xE0) | channelNum; /* channel number that I want to read from */
	SET_BIT(ADCSRA , ADIE); /* enabling ADC interrupt */
    SET_BIT(SREG , GLOBAL_INTERRUPT_BIT); /* enabling the global interrupt */
	SET_BIT(ADCSRA , ADSC); /* ADC start conversion */
	return E_OK;
}

/* Deinitialize the ADC module */
Std_ReturnType ADC_DeInit(void) {
	/* Disable the ADC */
	CLEAR_BIT(ADCSRA, ADEN);
	
	/* Disable the ADC interrupt */
	CLEAR_BIT(ADCSRA, ADIE);
	
	/* Clear reference and prescaler settings */
	ADMUX = 0x00;
	ADCSRA &= 0xF8;
	return E_OK;
}
