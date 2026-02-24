//------------------------ Ganpati Bappa Morya ---------------------

#ifndef DRIVER_BUTTON_H_
#define DRIVER_BUTTON_H_

#include <stdint.h>

typedef enum {

	BTN_ENCODER = 0,
	BTN_CUE,
	BTN_PLAY,
	BTN_COUNT
} button_id_t;

typedef enum {

	BUTTON_EVENT_PRESSED = 0,
	BUTTON_EVENT_RELEASED
} button_event_type_t;

typedef struct {

	button_id_t button;
	button_event_type_t type;
} button_event_t;

void Button_Init(void);
void Button_Scan_1ms(void);
uint8_t Button_GetEvent(button_event_t *event);


#endif /* DRIVER_BUTTON_H_ */
