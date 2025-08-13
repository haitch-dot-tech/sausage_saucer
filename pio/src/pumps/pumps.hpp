#include <Arduino.h>

#include "../conf.h"

enum pumps
{
    TOMATO,
    BARBEQUE,
    MUSTARD
};

void pumps_init();
void pump(pumps sauce, bool en);