//---------------------------- Ganpati Bappa Morya -------------------------

#include "adc.h"
#include <stm32f1xx.h>

//------------------------ CONFIG -----------------------

#define ADC_DEADBAND		12
#define ADC_FILTER_SHIFT 	3
#define EVENT_QUEUE_SIZE 	8

//=======================================================

//-------------------- Internal State -------------------

static uint16_t adc_raw[ADC_CH_COUNT];
static uint16_t adc_filtered[ADC_CH_COUNT];
static uint16_t adc_last_sent[ADC_CH_COUNT];

static volatile adc_event_t event_queue[EVENT_QUEUE_SIZE];
static volatile uint8_t evt_head = 0;
static volatile uint8_t evt_tail = 0;

static uint8_t current_channel = 0;

//=======================================================

//-------------------- Internal Helper ------------------

static void ADC_PushEvent(adc_channel_t ch, uint16_t value){

	uint8_t next = (evt_head + 1) % EVENT_QUEUE_SIZE;

	if(next == evt_tail){
		return;
	}

	event_queue[evt_head].channel = ch;
	event_queue[evt_head].value   = value;
	evt_head = next;

}

//=======================================================

//---------------------- Public API ---------------------

void ADC_Init(void){

	RCC->CFGR &= ~(0b11 << 14);
	RCC->CFGR |= RCC_CFGR_ADCPRE6;

	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

	ADC1->CR1 = 0;	// Reset ADC Reg
	ADC1->CR2 = 0;

	ADC1->SMPR2 &= ~(0b111 << 15);
	ADC1->SMPR2 |= ADC1_SMPR2_SMP5_55;

	ADC1->SQR1 &= ~ADC1_SQR1_L1;
	ADC1->SQR3 &= ~(0x1F << 0);
	ADC1->SQR3 |= ADC1_SQR3_SQ1;

	ADC1->CR2 &= ~(0b111 << 17);
	ADC1->CR2 |= ADC1_CR2_TIM3_TRGO;
	ADC1->CR2 |= ADC1_CR2_EXTTRIG;

	ADC1->CR2 |= ADC1_CR2_ADON;
	for(volatile int i = 0; i < 1000; i++);

	//---------- ADC Calibration ------------

	ADC1->CR2 |= ADC1_CR2_RSTCAL;
	while(ADC1->CR2 & ADC1_CR2_RSTCAL);

	ADC1->CR2 |= ADC1_CR2_CAL;
	while(ADC1->CR2 & ADC1_CR2_CAL);

	//=======================================

	ADC1->CR1 |= ADC1_CR1_EOCIE;
	NVIC_SetPriority(ADC1_2_IRQn, 2);
	NVIC_EnableIRQ(ADC1_2_IRQn);

	ADC1->CR2 |= ADC1_CR2_ADON;

}

void ADC_Scan_ISR(void){

	uint16_t raw = ADC1->DR;

	adc_raw[current_channel] = raw;

	/* IIR filtering */
	adc_filtered[current_channel] +=
			(raw - adc_filtered[current_channel]) >> ADC_FILTER_SHIFT;


	/* Deadband check */
	int16_t diff =
	        (int16_t)adc_filtered[current_channel] -
	        (int16_t)adc_last_sent[current_channel];

	if(diff >= ADC_DEADBAND || diff <= -ADC_DEADBAND){

		adc_last_sent[current_channel] = adc_filtered[current_channel];

		ADC_PushEvent((adc_channel_t)current_channel,
					adc_filtered[current_channel]);
	}


}

uint8_t ADC_GetEvent(adc_event_t *evt){

	if(evt_head == evt_tail){
		return 0;
	}

	*evt = event_queue[evt_tail];
	evt_tail = (evt_tail + 1) % EVENT_QUEUE_SIZE;
	return 1;
}

