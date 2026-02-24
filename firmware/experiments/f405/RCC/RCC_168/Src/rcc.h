//---------------------------- Ganpati Bappa Morya --------------------------------

#ifndef CORE_RCC_H_
#define CORE_RCC_H_

#include <stdint.h>
#include <stm32f4xx.h>


//********************************* POWER REG DEFINE **********************************
#define RCC_APB1ENR_PWREN 	(1 << 28)	//Enable Power Controller Reg
#define PWR_CR_VOS			(1 << 14)	//VOS = Scale 1 Mode
//*************************************************************************************

//********************************** RCC REG DEFINE ***********************************
#define RCC_CR_HSEON		(1 << 16)		//RCC HSE Clock Enable
#define RCC_CR_HSERDY		(1 << 17)		//RCC HSE clock ready flag
#define FLASH_ACR_LATENCY5	(5 << 0)		//168MHz Requires 5WS
#define FLASH_ACR_ICEN		(1 << 9)		//Instruction cache enable
#define FLASH_ACR_DCEN		(1 << 10)		//Data cache enable
#define FLASH_ACR_PRFTEN	(1 << 8)		//Prefetch enable
#define RCC_CFGR_HPRE_1		(0b000 << 4)	//system clock not divided (AHB prescaler)
#define RCC_CFGR_PPRE1_4	(0b101 << 10)	//AHB clock divided by 4 (APB1 prescaler)
#define RCC_CFGR_PPRE2_2	(0b100 << 13)	//AHB clock divided by 2 (APB2 prescaler)
#define RCC_PLLCFGR_PLLM8	(8 << 0)		//HSE = 8MHZ / M = 8 = 1MHz
#define RCC_PLLCFGR_PLLN336 (336 << 6)		//1MHz * 336 = 336MHz
#define RCC_PLLCFGR_PLLP2	(0b00 << 16)	//336MHz / 2 = 168MHz
#define RCC_PLLCFGR_PLLQ4	(4 << 24)		//PLLQ Prescaler 4
#define RCC_PLLCFGR_PLLSRC	(1 << 22)		//HSE As PLL Source
#define RCC_CR_PLLON		(1 << 24)		//Main PLL (PLL) enable
#define RCC_CR_PLLRDY		(1 << 25)		//Main PLL (PLL) clock ready flag
#define RCC_CFGR_SW_PLL		(0b10 << 0)		//PLL selected as system clock
#define RCC_CFGR_SWS		(0b11 << 2)		//Scan SWS Bits
#define RCC_CFGR_SWS_PLL	(0b10 << 2)		//PLL used as the system clock
//*************************************************************************************


void clock_168_Init(void);

#endif
