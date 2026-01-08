//----------------------- Ganpati Bappa Morya ----------------------

#ifndef DRIVERS_ADC_H_
#define DRIVERS_ADC_H_

#include <stdint.h>

//------------------- CONFIG --------------------

#define ADC_MAX_CHANNELS	22
#define ADC_RAW_MAX			4095

//===============================================

//-------------------- ADC Initialization Macro -----------------
#define RCC_CFGR_ADCPRE6 	(0b10 << 14)	// 72/6 = 12MHz
#define RCC_APB2ENR_ADC1EN 	(1 << 9)		// Clock Enable For ADC1
#define ADC1_SMPR2_SMP5_55	(0b101 << 15)	// Sampling Time = 55.5
#define ADC1_SQR1_L1		(0xF << 20)		// Regular Channel Sequence length = 1 Conversion
#define ADC1_SQR3_SQ1		(4 << 0)		// SQ5 = 1
#define ADC1_CR2_ADON 		(1 << 0)		// Turn ONN ADC1
#define ADC1_CR2_RSTCAL 	(1 << 3)		// Reset Calibration
#define ADC1_CR2_CAL		(1 << 2)		// ADC Calibration
#define ADC1_CR2_TIM3_TRGO	(0b100 << 17)	// Timer 3 TRGO event
#define ADC1_CR2_EXTTRIG	(1 << 20)		// Enable External Trigger
#define ADC1_CR1_EOCIE		(1 << 5)		// Interrupt enable for EOC
//#define ADC1_CR2_SWSTART	(1 << 22)		// Start Conversion
//#define ADC1_SR_EOC 		(1 << 1)		// End Of Conversion

//=================================================================

//------------------- Types ---------------------

typedef enum {

	ADC_CH_POT_0 = 0,
	ADC_CH_COUNT

} adc_channel_t;

typedef struct {

	adc_channel_t channel;
	uint16_t value;

} adc_event_t;

//===============================================

//----------------- Public API ------------------

void ADC_Init(void);

void ADC_Scan_ISR(void);

uint8_t ADC_GetEvent(adc_event_t *evt);

//===============================================



#endif /* DRIVERS_ADC_H_ */
