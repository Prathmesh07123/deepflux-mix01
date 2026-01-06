//--------------------- Ganpati Bappa Morya ------------------


#include <stdint.h>
#include <stdio.h>
#include <stm32f1xx.h>
#include "rcc.h"
#include "gpio.h"
#include "timer.h"
#include "button.h"
#include "Printf_debug.h"

#define DEBUG

volatile int16_t encoder_last = 0;

int main(void)
{
	RCC_72_Init();
	GPIO_Init();
	USART2_INIT();
	Button_Init();

	TIM2_Encoder_Init();
	TIM3_Button_Init();
#ifdef DEBUG
	printf("Debugging Start...\n");
	fflush(stdout);
#endif

	button_event_t evt;

	while(1){

		if(Button_GetEvent(&evt)){

			if(evt.type == BUTTON_EVENT_PRESSED){
				switch(evt.button){
					case BTN_ENCODER:
						printf("Encode Button pressed\n");
						fflush(stdout);
						break;
					case BTN_CUE:
						printf("CUE pressed\n");
						fflush(stdout);
						break;
					case BTN_PLAY:
						printf("Play pressed\n");
						fflush(stdout);
						break;
					case BTN_COUNT:
						break;
				}
			}

		}
		int16_t pos = (int16_t)TIM2->CNT;

		int16_t delta = pos - encoder_last;

		if(delta >= 2){
			printf("Encoder +1\n");
			fflush(stdout);
			encoder_last += 2;
		}
		else{
			if(delta <= -2){
				printf("Encoder -1\n");
				fflush(stdout);
				encoder_last -= 2;
			}
		}

	}

}

//================== ISR ==================

void TIM3_IRQHandler(void){

    if (TIM3->SR & TIM3_SR_UIF){

        TIM3->SR &= ~TIM3_SR_UIF;
        Button_Scan_1ms();
    }
}
