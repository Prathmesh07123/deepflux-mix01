//---------------------------- Ganpati Bappa Morya --------------------------

#ifndef DRIVER_GPIO_BARE_H_
#define DRIVER_GPIO_BARE_H_

#include <stdint.h>
#include <stm32f4xx.h>

//********************************** GPIO REG DEFINE *********************************

#define RCC_AHB1ENR_GPIOB	(1 << 1)
#define GPIOB_MODER_B2		(0b01 << 4)

#define GPIOA_MODER_PA2_AF 	(0b10 << 4)
#define GPIOA_AFRL_PA2_AF7 	(0x7 << 8)

#define RCC_AHB1ENR_GPIOA	(1 << 0)		//Enable CLK for GPIOA
#define GPIOA_MODER_PA3_IP	(0b11 << 6)		//PA3 = Input
#define GPIOA_MODER_PA4_IP  (0b11 << 8)		//PA4 = Input
#define GPIOA_MODER_PA5_IP	(0b11 << 10)	//PA5 = Input
#define GPIOA_PUPDR_PA3_PU	(0b01 << 6)		//Enable Internal Pull Up for PA3
#define GPIOA_PUPDR_PA4_PU	(0b01 << 8)		//Enable Internal Pull Up for PA4
#define GPIOA_PUPDR_PA5_PU	(0b01 << 10)	//Enable Internal Pull Up for PA5

#define GPIOA_MODER_PA6_AF 	(0b10 << 12)	//Alternate Function PA6 => TIM3_CH1
#define GPIOA_MODER_PA7_AF 	(0b10 << 14)	//Alternate Function PA7 => TIM3_CH2
#define GPIOA_AFRL_PA6_AF2 	(0x2 << 24)		//PA6 => TIM3_CH1
#define GPIOA_AFRL_PA7_AF2 	(0x2 << 28)		//PA7 => TIM3_CH2

//************************************************************************************

void GPIO_Init(void);

#endif /* DRIVER_GPIO_BARE_H_ */
