/********************************************************************/
/*      SWC     : Adc.h                                             */
/*      Date    : 8/26/2023                                         */
/*      Authors : MetaWare LLC                                      */
/*				  Mahmoud Sayed Mahmoud Helmy (1285)                */
/*		          Mohamed Mahmoud Masoud (200)                      */
/*		          Mark Ehab Tawfik (201)                            */
/*		          Hazzem Mohamed Ezzeldin (1297)                    */
/*		          Yousef Khaled Ahmed (558)                         */
/********************************************************************/
/* =============================================================
 * 						Function Prototypes
 * =============================================================*/
#ifndef ADC_H_
#define ADC_H_
/* =============================================================
 * 						  Includes
 * =============================================================*/
#include "../../Commons/Macros.h"
#include "../../Commons/std_types.h"
#include "../../Commons/atmega32_mapping.h"
#include "ADC_Cfg.h"
/* =============================================================
 * 						    Types
 * =============================================================*/
typedef uint8 Adc_ChannelType;
typedef uint16 Adc_ValueGroupType;
typedef uint8 Std_ReturnType;

/* ADC prescaler values */
#define ADC_PRESCALER_2     0x01
#define ADC_PRESCALER_4     0x02
#define ADC_PRESCALER_8     0x03
#define ADC_PRESCALER_16    0x04
#define ADC_PRESCALER_32    0x05
#define ADC_PRESCALER_64    0x06
#define ADC_PRESCALER_128   0x07

/* ADC reference voltage sources */
#define ADC_REFERENCE_EXTERNAL 0x00
#define ADC_REFERENCE_AVCC     0x01
#define ADC_REFERENCE_INTERNAL 0x03

#define GLOBAL_INTERRUPT_BIT   7

/* ADC channel identifiers */
#define ADC_CHANNEL_0   0
#define ADC_CHANNEL_1   1

/* =============================================================
 * 						Return Values
 * =============================================================*/
#define E_OK            (Std_ReturnType)1U
#define E_NOT_OK        (Std_ReturnType)0U

typedef struct {
    uint8 prescaler;
    uint8 reference;
} ADC_ConfigType;

/* =============================================================
 * 						Function Prototypes
 * =============================================================*/
Std_ReturnType ADC_Init(const ADC_ConfigType * configuation);
Std_ReturnType ADC_readChannel_polling(uint8 channelNum , uint16 * read_buffer);
Std_ReturnType ADC_readChannel_interrupt(uint8 channelNum, uint16 *read_buffer);
Std_ReturnType ADC_DeInit(void);


#endif /* ADC_H_ */
