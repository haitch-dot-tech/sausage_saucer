#include <Arduino.h>
#include <indev/ui/ui.hpp>
#include <debug/debug.hpp>

#include <conf.h>

leds led_map;

void setup()
{
    SerialUSB.begin(115200);
    display_init(HIGH);
    ui_init();
    debug_init();
    ui_create();

    led_map.stat1 = 0;
    led_map.stat2 = 127;
    led_map.stat3 = 255;

    pinMode(BTN, INPUT_PULLDOWN);

    pinMode(M4_HI, OUTPUT);
    pinMode(M4_LO, OUTPUT);

    digitalWrite(M4_HI, LOW);
    digitalWrite(M4_LO, LOW);

    debug_leds(led_map);
}

void loop()
{
    ui_update();
}
