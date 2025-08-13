#include "L298.hpp"

L298::L298() {}

void L298::init(uint8_t high, uint8_t low)
{
    hi = high;
    lo = low;

    pinMode(hi, OUTPUT);
    pinMode(lo, OUTPUT);
}

void L298::setMotor(uint8_t speed, direction direction)
{
    if (direction == FORWARD)
    {
        analogWrite(hi, speed);
        digitalWrite(lo, LOW);
    }
    else
    {
        analogWrite(lo, speed);
        digitalWrite(hi, LOW);
    }
}