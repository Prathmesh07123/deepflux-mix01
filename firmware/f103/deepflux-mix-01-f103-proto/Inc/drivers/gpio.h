/*
 * gpio.h
 *
 *  Created on: Jan 6, 2026
 *      Author: prath
 */

#ifndef DRIVERS_GPIO_H_
#define DRIVERS_GPIO_H_

#include <stdint.h>
#include <stm32f1xx.h>

//----------------- GPIO INITILIZATION MACRO ---------------------
#define RCC_APB2ENR_IOPAEN	(1 << 2)	//Enable CLK for GPIOA
#define RCC_APB2ENR_IOPCEN	(1 << 4)	//Enable CLK for GPIOC
#define GPIOA_CRL_PA0_IF	(0x4 << 0)	//Input Floating (CNF = 01, MODE = 00)
#define GPIOA_CRL_PA1_IF	(0x4 << 4)	//Input Floating (CNF = 01, MODE = 00)
#define GPIO_CRL_PA2_AF 	(0xB << 8)	// CNF2 = 10 , MODE2 = 11 Alternate Function (UART2 TX)
#define GPIOA_CRL_PA5_IPU	(0x8 << 20)	//PA5 = Input Internal Pull UP
#define GPIOA_CRL_PA6_IPU 	(0x8 << 24)	//PA6 = Input Internal Pull UP
#define GPIOA_CRL_PA7_IPU	(0x8 << 28)	//PA7 = Input Internal Pull UP
#define GPIOA_ODR_PA5		(1 << 5)	//Enable Pull-up
#define GPIOA_ODR_PA6 		(1 << 6)	//Enable Pull-up
#define GPIOA_ODR_PA7		(1 << 7)	//Enable Pull-up



void GPIO_Init(void);

#endif /* DRIVERS_GPIO_H_ */
