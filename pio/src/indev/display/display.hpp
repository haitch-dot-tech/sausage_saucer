#include <Arduino.h>
#include <TFT_eSPI.h>
#include "touch/touch.hpp"

#include <conf.h>

void display_init(uint8_t bl_state = HIGH);
void display_getTouch(int16_t *x, int16_t *y, uint8_t *z);
void display_write(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint16_t *px);
