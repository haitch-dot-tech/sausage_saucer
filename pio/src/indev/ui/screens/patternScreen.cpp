#include "../ui.hpp"

lv_obj_t *patternScreen;
lv_obj_t *patternTitleLabel;
lv_obj_t *skipLabel;
lv_obj_t *thickButton;
lv_obj_t *lineButton;
lv_obj_t *zigzagButton;
lv_obj_t *doubleButton;
lv_obj_t *waveButton;
lv_obj_t *loopsButton;
lv_obj_t *infoLabel;

void event_skipLabel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_CLICKED)
    {
        lv_screen_load_anim(jobScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false);
    }
}

void patternScreen_create(void)
{
    patternScreen = lv_obj_create(NULL);
    lv_obj_remove_flag(patternScreen, (lv_obj_flag_t)(LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN));
    lv_obj_set_style_bg_image_src(patternScreen, &bg, LV_PART_MAIN | LV_STATE_DEFAULT);

    patternTitleLabel = lv_label_create(patternScreen);
    lv_obj_set_width(patternTitleLabel, LV_SIZE_CONTENT);  
    lv_obj_set_height(patternTitleLabel, LV_SIZE_CONTENT); 
    lv_obj_set_x(patternTitleLabel, 10);
    lv_obj_set_y(patternTitleLabel, 10);
    lv_label_set_text(patternTitleLabel, "Pattern:");
    lv_obj_remove_flag(patternTitleLabel, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN));
    lv_obj_set_style_text_color(patternTitleLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(patternTitleLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(patternTitleLabel, &FugazOne36, LV_PART_MAIN | LV_STATE_DEFAULT);

    skipLabel = lv_label_create(patternScreen);
    lv_obj_set_width(skipLabel, LV_SIZE_CONTENT);  
    lv_obj_set_height(skipLabel, LV_SIZE_CONTENT); 
    lv_obj_set_x(skipLabel, -10);
    lv_obj_set_y(skipLabel, 0);
    lv_obj_set_align(skipLabel, LV_ALIGN_BOTTOM_RIGHT);
    lv_label_set_text(skipLabel, "Tap this text to begin!");
    lv_obj_add_flag(skipLabel, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(skipLabel, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN));
    lv_obj_set_style_text_color(skipLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(skipLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(skipLabel, &FugazOne30, LV_PART_MAIN | LV_STATE_DEFAULT);

    thickButton = lv_imagebutton_create(patternScreen);
    lv_imagebutton_set_src(thickButton, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &thick, NULL);
    lv_imagebutton_set_src(thickButton, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &thick, NULL);
    lv_imagebutton_set_src(thickButton, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, NULL, &tick, NULL);
    lv_imagebutton_set_src(thickButton, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, NULL, &tick, NULL);
    lv_obj_set_width(thickButton, 100);
    lv_obj_set_height(thickButton, 100);
    lv_obj_set_x(thickButton, 0);
    lv_obj_set_y(thickButton, -55);
    lv_obj_set_align(thickButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(thickButton, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_remove_flag(thickButton, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN));

    lineButton = lv_imagebutton_create(patternScreen);
    lv_imagebutton_set_src(lineButton, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &line, NULL);
    lv_imagebutton_set_src(lineButton, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &line, NULL);
    lv_imagebutton_set_src(lineButton, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, NULL, &tick, NULL);
    lv_imagebutton_set_src(lineButton, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, NULL, &tick, NULL);
    lv_obj_set_width(lineButton, 100);
    lv_obj_set_height(lineButton, 100);
    lv_obj_set_x(lineButton, -145);
    lv_obj_set_y(lineButton, -55);
    lv_obj_set_align(lineButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(lineButton, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_remove_flag(lineButton, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN));

    zigzagButton = lv_imagebutton_create(patternScreen);
    lv_imagebutton_set_src(zigzagButton, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &zigzag, NULL);
    lv_imagebutton_set_src(zigzagButton, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &zigzag, NULL);
    lv_imagebutton_set_src(zigzagButton, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, NULL, &tick, NULL);
    lv_imagebutton_set_src(zigzagButton, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, NULL, &tick, NULL);
    lv_obj_set_width(zigzagButton, 100);
    lv_obj_set_height(zigzagButton, 100);
    lv_obj_set_x(zigzagButton, 145);
    lv_obj_set_y(zigzagButton, -55);
    lv_obj_set_align(zigzagButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(zigzagButton, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_remove_flag(zigzagButton, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN));

    doubleButton = lv_imagebutton_create(patternScreen);
    lv_imagebutton_set_src(doubleButton, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &doubleLine, NULL);
    lv_imagebutton_set_src(doubleButton, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &doubleLine, NULL);
    lv_imagebutton_set_src(doubleButton, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, NULL, &tick, NULL);
    lv_imagebutton_set_src(doubleButton, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, NULL, &tick, NULL);
    lv_obj_set_width(doubleButton, 100);
    lv_obj_set_height(doubleButton, 100);
    lv_obj_set_x(doubleButton, -145);
    lv_obj_set_y(doubleButton, 55);
    lv_obj_set_align(doubleButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(doubleButton, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_remove_flag(doubleButton, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN));

    waveButton = lv_imagebutton_create(patternScreen);
    lv_imagebutton_set_src(waveButton, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &wave, NULL);
    lv_imagebutton_set_src(waveButton, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &wave, NULL);
    lv_imagebutton_set_src(waveButton, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, NULL, &tick, NULL);
    lv_imagebutton_set_src(waveButton, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, NULL, &tick, NULL);
    lv_obj_set_width(waveButton, 100);
    lv_obj_set_height(waveButton, 100);
    lv_obj_set_x(waveButton, 0);
    lv_obj_set_y(waveButton, 55);
    lv_obj_set_align(waveButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(waveButton, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_remove_flag(waveButton, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN));

    loopsButton = lv_imagebutton_create(patternScreen);
    lv_imagebutton_set_src(loopsButton, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &loops, NULL);
    lv_imagebutton_set_src(loopsButton, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &loops, NULL);
    lv_imagebutton_set_src(loopsButton, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, NULL, &tick, NULL);
    lv_imagebutton_set_src(loopsButton, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, NULL, &tick, NULL);
    lv_obj_set_width(loopsButton, 100);
    lv_obj_set_height(loopsButton, 100);
    lv_obj_set_x(loopsButton, 145);
    lv_obj_set_y(loopsButton, 55);
    lv_obj_set_align(loopsButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(loopsButton, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_remove_flag(loopsButton, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN));

    infoLabel = lv_label_create(patternScreen);
    lv_obj_set_width(infoLabel, LV_SIZE_CONTENT);  
    lv_obj_set_height(infoLabel, LV_SIZE_CONTENT); 
    lv_obj_set_x(infoLabel, -10);
    lv_obj_set_y(infoLabel, 10);
    lv_obj_set_align(infoLabel, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(infoLabel, "Press START to run.\nDefault is Line if none are selected.");
    lv_obj_remove_flag(infoLabel, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN));
    lv_obj_set_style_text_color(infoLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(infoLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(infoLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(infoLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(skipLabel, event_skipLabel, LV_EVENT_ALL, NULL);
}
