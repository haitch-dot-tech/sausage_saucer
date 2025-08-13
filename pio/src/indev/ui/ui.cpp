#include "ui.hpp"

#define TS_DEBUG

lv_obj_t *mainScreen;
lv_obj_t *sauce;
lv_obj_t *pattern;
lv_obj_t *start;

#ifdef TS_DEBUG
    lv_obj_t *touch_coords_debug;
#endif

bool left_calibrated = false;
bool right_calibrated = false;

/* Calibration */
#define X_NEG 226
#define Y_NEG 385
#define X_POS 3934
#define Y_POS 4095

LV_IMG_DECLARE(bg);

LV_FONT_DECLARE(FugazOne30);

static uint32_t PROGMEM draw_buf[(DISPLAY_WIDTH * DISPLAY_HEIGHT / 10 * (LV_COLOR_DEPTH / 8)) / 4];

static uint32_t lv_tick(void);
void touch_read(lv_indev_t *indev, lv_indev_data_t *data);
void flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);

void ui_init()
{
    lv_init();
    lv_tick_set_cb(lv_tick);
    lv_display_t *disp = lv_display_create(480, 320);
    lv_display_set_flush_cb(disp, flush_cb);
    lv_display_set_buffers(disp, (void *)draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
    lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_0);
    
    /* Touch init */
    lv_indev_t *touch = lv_indev_create();
    lv_indev_set_type(touch, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(touch, touch_read);
}

void ui_create()
{
    mainScreen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(mainScreen, BLACK, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_flag(mainScreen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_image_src(mainScreen, &bg, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_screen_load(mainScreen);

    sauce = lv_label_create(mainScreen);
    lv_obj_set_width(sauce, 130);
    lv_obj_set_height(sauce, 30);
    lv_obj_set_x(sauce, 10);
    lv_obj_set_y(sauce, 10);
    lv_label_set_text(sauce, "1. SAUCE");
    lv_obj_set_style_text_font(sauce, &FugazOne30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(sauce, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(sauce, lv_color_hex(0x26ABFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(sauce, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    pattern = lv_label_create(mainScreen);
    lv_obj_set_width(pattern, 175);
    lv_obj_set_height(pattern, 30);
    lv_obj_set_x(pattern, 150);
    lv_obj_set_y(pattern, 10);
    lv_label_set_text(pattern, "2. PATTERN");
    lv_obj_set_style_text_font(pattern, &FugazOne30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(pattern, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(pattern, lv_color_hex(0x26ABFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(pattern, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    start = lv_label_create(mainScreen);
    lv_obj_set_width(start, 135);
    lv_obj_set_height(start, 30);
    lv_obj_set_x(start, 335);
    lv_obj_set_y(start, 10);
    lv_label_set_text(start, "3. START");
    lv_obj_set_style_text_font(start, &FugazOne30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(start, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(start, lv_color_hex(0x26ABFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(start, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    #ifdef TS_DEBUG
        touch_coords_debug = lv_label_create(mainScreen);
        lv_obj_align(touch_coords_debug, LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_style_text_font(touch_coords_debug, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
    #endif
}

void ui_changeScreen(lv_obj_t *thisScreen)
{
    lv_screen_load_anim(thisScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false);
}

void ui_update()
{
    lv_timer_handler();
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

    SerialUSB.printf("X: %d, Y: %d, Z: %d\n", x, y, zraw);

    #ifdef TS_DEBUG
        lv_label_set_text_fmt(touch_coords_debug, "X: %d, Y: %d, Z: %d", x, y, zraw);
    #endif

    if (zraw != 0)
    {
        data->state = LV_INDEV_STATE_PRESSED;

        data->point.x = x;
        data->point.y = y;
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}
