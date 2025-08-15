#include <Arduino.h>
#include <indev/ui/ui.hpp>
#include <motion/motion.hpp>
#include <debug/debug.hpp>

#include <conf.h>

static volatile uint32_t t = 0;

static leds led_map;

void setup()
{
    display_init();
    display_setBacklight(BL_ON);

    debug_init();

    ui_init();
    ui_create();

    motion_init();

    led_map.stat1 = 255;
    led_map.stat2 = 63;
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
    t = ui_update();
    
    if (t > 30000)
    {
        display_setBacklight(BL_OFF);
    }
    else if (t > 10000)
    {
        display_setBacklight(BL_LOW);
    }
    else
    {
        display_setBacklight(BL_ON);
    }
}
