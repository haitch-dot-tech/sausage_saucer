#include <Arduino.h>

#include <conf.h>

#define TOMATO_BTN   BTN1
#define BARBEQUE_BTN BTN2
#define MUSTARD_BTN  BTN3
#define START_BTN    BTN4

#define TOMATO_LED   BLED1
#define BARBEQUE_LED BLED2
#define MUSTARD_LED  BLED3
#define START_LED    BLED4

#define BUTTON_ACTIVE LOW

#if BUTTON_ACTIVE == LOW
#define BUTTON_PULL INPUT_PULLUP
#else
#define BUTTON_PULL INPUT_PULLDOWN
#endif

typedef void (*ButtonCallback)(int btn);

struct ButtonLEDs
{
    uint8_t tomato;
    uint8_t barbeque;
    uint8_t mustard;
    uint8_t start;
};

void buttons_init(void);
void buttons_setCB(ButtonCallback cb);
void buttons_setLEDs(ButtonLEDs leds);
