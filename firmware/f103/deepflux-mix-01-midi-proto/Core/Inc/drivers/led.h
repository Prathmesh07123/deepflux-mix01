//------------------------ Ganpati Bappa Morya -------------------

#ifndef INC_DRIVERS_LED_H_
#define INC_DRIVERS_LED_H_

#include <stdint.h>

extern volatile uint8_t led_play_state;
extern volatile uint8_t led_cue_state;

typedef enum {
	LED_PLAY = 0,
	LED_CUE
}led_id_t;

typedef enum {
	LED_OFF = 0,
	LED_ON
} led_state_t;

void LED_Init(void);
void LED_Set(led_id_t led, led_state_t state);


#endif /* INC_DRIVERS_LED_H_ */
