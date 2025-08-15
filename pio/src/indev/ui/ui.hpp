#pragma once

#include <Arduino.h>
#include <lvgl.h>
#include "../display/display.hpp"

#include <indev/buttons/buttons.hpp>

#include "screens/sauceScreen.hpp"
#include "screens/patternScreen.hpp"
#include "screens/jobScreen.hpp"

#include <conf.h>

#define DISPLAY_WIDTH 480
#define DISPLAY_HEIGHT 320

LV_IMG_DECLARE(bg);
LV_IMG_DECLARE(doubleLine);
LV_IMG_DECLARE(line);
LV_IMG_DECLARE(loops);
LV_IMG_DECLARE(thick);
LV_IMG_DECLARE(tick);
LV_IMG_DECLARE(wave);
LV_IMG_DECLARE(zigzag);

LV_FONT_DECLARE(FugazOne24);
LV_FONT_DECLARE(FugazOne30);
LV_FONT_DECLARE(FugazOne36);
LV_FONT_DECLARE(FugazOne48);

struct buttonsState
{
    bool tomato;
    bool barbeque;
    bool mustard;
    bool start;
};

static buttonsState buttons;

void ui_init();
void ui_create();
void ui_changeScreen(lv_obj_t *thisScreen);
lv_obj_t *ui_getScreen(void);
uint32_t ui_update();
