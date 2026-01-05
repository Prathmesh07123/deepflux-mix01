//------------------------------- Ganpati Bappa Morya ---------------------------

#include <stdint.h>
#include <stdio.h>
#include <stm32f1xx.h>
#include "rcc.h"
#include "Printf_debug.h"

//-------------------- ADC Initialization Macro -----------------
#define RCC_CFGR_ADCPRE6 	(0b10 << 14)	// 72/6 = 12MHz
#define RCC_APB2ENR_GPIOA 	(1 << 2)		// Clock Enable For GPIOA
#define GPIOA_CRL_ANALOG5	(0xF << 20)		// For Analog CNF5 = 00, MODE5 = 00;
#define RCC_APB2ENR_ADC1EN 	(1 << 9)		// Clock Enable For ADC1
#define ADC1_SMPR2_SMP5_55	(0b101 << 15)	// Sampling Time = 55.5
#define ADC1_SQR1_L1		(0xF << 20)		// Regular Channel Sequence length = 1 Conversion
#define ADC1_SQR3_SQ1		(5 << 0)		// SQ5 = 1
#define ADC1_CR2_ADON 		(1 << 0)		// Turn ONN ADC1
#define ADC1_CR2_RSTCAL 	(1 << 3)		// Reset Calibration
#define ADC1_CR2_CAL		(1 << 2)		// ADC Calibration
#define ADC1_CR2_EXTSEL_SW	(0b111 << 17)	// SWSTART as External Event
#define ADC1_CR2_EXTTRIG	(1 << 20)		// Enable External Trigger
#define ADC1_CR2_CONT		(1 << 1)		// Continuous Conversion
#define ADC1_CR2_SWSTART	(1 << 22)		// Start Conversion
#define ADC1_SR_EOC 		(1 << 1)		// End Of Conversion



void ADC_Init(void);

void ADC_Init(void){

	RCC->CFGR &= ~(0b11 << 14);
	RCC->CFGR |= RCC_CFGR_ADCPRE6;
	RCC->APB2ENR |= RCC_APB2ENR_GPIOA;

	GPIOA->CRL &= ~GPIOA_CRL_ANALOG5;

	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

	ADC1->CR1 = 0;	// Reset ADC Reg
	ADC1->CR2 = 0;

	ADC1->SMPR2 &= ~(0b111 << 15);
	ADC1->SMPR2 |= ADC1_SMPR2_SMP5_55;

	ADC1->SQR1 &= ~ADC1_SQR1_L1;
	ADC1->SQR3 &= ~(0x1F << 0);
	ADC1->SQR3 |= ADC1_SQR3_SQ1;

	ADC1->CR2 |= ADC1_CR2_ADON;
	for(volatile int i = 0; i < 1000; i++);

	//---------- ADC Calibration ------------
	ADC1->CR2 |= ADC1_CR2_RSTCAL;
	while(ADC1->CR2 & ADC1_CR2_RSTCAL);

	ADC1->CR2 |= ADC1_CR2_CAL;
	while(ADC1->CR2 & ADC1_CR2_CAL);
	//---------------------------------------

	ADC1->CR2 |= ADC1_CR2_EXTSEL_SW;
	ADC1->CR2 |= ADC1_CR2_EXTTRIG;
	ADC1->CR2 |= ADC1_CR2_CONT;

	ADC1->CR2 |= ADC1_CR2_SWSTART;
}


int main(void)
{

	RCC_72_Init();
	USART2_INIT();
	ADC_Init();

	while(1){
		while(!(ADC1->SR & ADC1_SR_EOC));
		uint16_t adc_val = ADC1->DR;
		ADC1->SR &= ~ADC1_SR_EOC;

		printf("ADC Val : %u\r\n", adc_val);
		fflush(stdout);

		for(volatile uint32_t i = 0; i < 100000; i++);
	}

}
