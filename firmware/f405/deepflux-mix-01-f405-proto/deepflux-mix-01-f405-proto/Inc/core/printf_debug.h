//--------------------- Ganpati Bappa Morya ----------------------

#ifndef CORE_PRINTF_DEBUG_H_
#define CORE_PRINTF_DEBUG_H_

#include <stdint.h>
#include <stm32f4xx.h>

#define RCC_APB1ENR_UART2EN (1 << 17)
#define USART2_CR1_TE (1 << 3)
#define USART2_CR1_UE (1 << 13)
#define USART2_SR_TXE (1 << 7)

void USART2_INIT(void);
void Uart_Write(int ch);
int __io_putchar(int ch);

#endif /* CORE_PRINTF_DEBUG_H_ */
