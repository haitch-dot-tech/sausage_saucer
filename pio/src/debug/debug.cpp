#include "debug.hpp"

void debug_init()
{
    analogWriteFrequency(PWM_FREQUENCY);
    analogWriteResolution(8);

    pinMode(BUZZ, OUTPUT);

    pinMode(STAT1, OUTPUT);
    pinMode(STAT2, OUTPUT);
    pinMode(STAT3, OUTPUT);

    digitalWrite(BUZZ, LOW);

    digitalWrite(STAT1, LOW);
    digitalWrite(STAT2, LOW);
    digitalWrite(STAT3, LOW);
}

void debug_buzz(bool state)
{
    digitalWrite(BUZZ, (state) ? HIGH : LOW);
}

void debug_leds(leds led_map)
{
    analogWrite(STAT1, led_map.stat1);
    analogWrite(STAT2, led_map.stat2);
    analogWrite(STAT3, led_map.stat3);
}
