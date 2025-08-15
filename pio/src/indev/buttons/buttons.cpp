#include "buttons.hpp"

void tomatoCB(void);
void barbequeCB(void);
void mustardCB(void);
void startCB(void);

static ButtonCallback _cb;

void buttons_init(void)
{
    pinMode(TOMATO_BTN,   BUTTON_PULL);
    pinMode(BARBEQUE_BTN, BUTTON_PULL);
    pinMode(MUSTARD_BTN,  BUTTON_PULL);
    pinMode(START_BTN,    BUTTON_PULL);

    pinMode(TOMATO_LED,   OUTPUT);
    pinMode(BARBEQUE_LED, OUTPUT);
    pinMode(MUSTARD_LED,  OUTPUT);
    pinMode(START_LED,    OUTPUT);

    attachInterrupt(digitalPinToInterrupt(TOMATO_BTN),   tomatoCB,   RISING);
    attachInterrupt(digitalPinToInterrupt(BARBEQUE_BTN), barbequeCB, RISING);
    attachInterrupt(digitalPinToInterrupt(MUSTARD_BTN),  mustardCB,  RISING);
    attachInterrupt(digitalPinToInterrupt(START_BTN),    startCB,    RISING);
}

void buttons_setCB(ButtonCallback cb)
{
    _cb = cb;
}

void buttons_setLEDs(ButtonLEDs leds)
{
    analogWrite(TOMATO_LED,   leds.tomato);
    analogWrite(BARBEQUE_LED, leds.barbeque);
    analogWrite(MUSTARD_LED,  leds.mustard);
    analogWrite(START_LED,    leds.start);
}

void tomatoCB(void)
{
    _cb(TOMATO_BTN);
}

void barbequeCB(void)
{
    _cb(BARBEQUE_BTN);
}

void mustardCB(void)
{
    _cb(MUSTARD_BTN);
}

void startCB(void)
{
    _cb(START_BTN);
}
