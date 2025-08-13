#include "Arduino.h"
#include <SPI.h>

#include <conf.h>

void touch_begin(uint8_t cs, uint8_t rotation);
void touch_point(int16_t *x, int16_t *y, uint8_t *z);
