#pragma once

#include <Arduino.h>
#include "../L298/L298.hpp"

enum flavour
{
    tomato,
    barbeque,
    mustard
};

struct sauces
{
    L298 tomato;
    L298 barbeque;
    L298 mustard;
};

void sauce_init(int pins[], int retract);
void sauce_dispense(flavour sauce, int rate);
void halt();
