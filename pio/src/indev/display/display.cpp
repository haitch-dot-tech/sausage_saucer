#include "display.hpp"

TFT_eSPI tft = TFT_eSPI(480, 320);

void display_init(uint8_t bl_state)
{
    tft.begin();
    tft.setRotation(1);
    touch_begin(PB12, 3);
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, bl_state);
}

void display_getTouch(int16_t *x, int16_t *y, uint8_t *z)
{
    touch_point(x, y, z);
}

void display_write(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint16_t *px)
{
    uint32_t w = (x2 - x1 + 1);
    uint32_t h = (y2 - y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(x1, y1, w, h);
    tft.pushColors(px, w * h, true);
    tft.endWrite();
}
