#pragma once

#include <Arduino.h>
#include <lvgl.h>
#include "../display/display.hpp"

#include <conf.h>

#define DISPLAY_WIDTH 480
#define DISPLAY_HEIGHT 320

#define BLACK lv_color_hex(0x000000)
#define WHITE lv_color_hex(0xFFFFFF)
#define RED   lv_color_hex(0xFF0000)
#define GREEN lv_color_hex(0x00FF00)
#define BLUE  lv_color_hex(0x0000FF)

extern lv_obj_t *mainScreen;
extern lv_obj_t *sauce;
extern lv_obj_t *pattern;
extern lv_obj_t *start;

void ui_init();
void ui_create();
void ui_changeScreen(lv_obj_t *thisScreen);
void ui_update();
