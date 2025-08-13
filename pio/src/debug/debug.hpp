#include <Arduino.h>

#include <conf.h>

struct leds
{
    uint8_t stat1;
    uint8_t stat2;
    uint8_t stat3;
};

void debug_init();
void debug_buzz(bool state);
void debug_leds(leds led_map);
