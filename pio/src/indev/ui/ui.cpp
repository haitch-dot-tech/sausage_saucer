#include "ui.hpp"

/* Touch calibration data */
#define X_NEG 226
#define Y_NEG 385
#define X_POS 3934
#define Y_POS 4095

static uint32_t PROGMEM draw_buf[(DISPLAY_WIDTH * DISPLAY_HEIGHT / 10 * (LV_COLOR_DEPTH / 8)) / 4];

volatile uint32_t lastMillis = 0;

static uint32_t lv_tick(void);
void touch_read(lv_indev_t *indev, lv_indev_data_t *data);
void flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);
void buttonCB(int btn);

void ui_init()
{
    lv_init();
    lv_tick_set_cb(lv_tick);
    lv_display_t *disp = lv_display_create(480, 320);
    lv_display_set_flush_cb(disp, flush_cb);
    lv_display_set_buffers(disp, (void *)draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
    lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_0);
    
    /* Touch driver init */
    lv_indev_t *touch = lv_indev_create();
    lv_indev_set_type(touch, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(touch, touch_read);

    buttons_init();
    buttons_setCB(buttonCB);
}

void ui_create()
{
    sauceScreen_create();
    patternScreen_create();
    jobScreen_create();

    ui_changeScreen(sauceScreen);
}

void ui_changeScreen(lv_obj_t *thisScreen)
{
    lv_screen_load_anim(thisScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false);
}

lv_obj_t *ui_getScreen(void)
{
    return lv_screen_active();
}

uint32_t ui_update()
{
    lv_timer_handler();
    
    return millis() - lastMillis;
}

static uint32_t lv_tick(void)
{
    return millis();
}

void flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
    display_write(area->x1, area->y1, area->x2, area->y2, (uint16_t *)px_map);
    lv_display_flush_ready(disp);
}

void touch_read(lv_indev_t *indev, lv_indev_data_t *data)
{
    int16_t xraw = 0, yraw = 0;
    uint8_t zraw;

    display_getTouch(&xraw, &yraw, &zraw);

    constrain(xraw, X_NEG, X_POS);
    constrain(yraw, Y_NEG, Y_POS);

    uint16_t x = map(xraw, X_NEG, X_POS, 0, 479);
    uint16_t y = map(yraw, Y_NEG, Y_POS, 0, 319);

    if (zraw != 0)
    {
        data->state = LV_INDEV_STATE_PRESSED;

        data->point.x = x;
        data->point.y = y;

        lastMillis = millis();
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void buttonCB(int btn)
{
    switch (btn)
    {
    case TOMATO_BTN:
        buttons.tomato = true;
        break;
    case BARBEQUE_BTN:
        buttons.barbeque = true;
        break;
    case MUSTARD_BTN:
        buttons.mustard = true;
        break;
    case START_BTN:
        buttons.start = true;
        break;
    default:
        break;
    }
}
