#include "../ui.hpp"

lv_obj_t *jobScreen;
lv_obj_t *detailStatusLabel;
lv_obj_t *statusLabel;
lv_obj_t *loadButtonLabel;

void event_loadButtonLabel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_CLICKED)
    {
        lv_screen_load_anim(sauceScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false);
    }
}

void jobScreen_create(void)
{
    jobScreen = lv_obj_create(NULL);
    lv_obj_remove_flag(jobScreen, (lv_obj_flag_t)(LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN)); 
    lv_obj_set_style_bg_image_src(jobScreen, &bg, LV_PART_MAIN | LV_STATE_DEFAULT);

    detailStatusLabel = lv_label_create(jobScreen);
    lv_obj_set_width(detailStatusLabel, 460);
    lv_obj_set_height(detailStatusLabel, LV_SIZE_CONTENT); 
    lv_obj_set_x(detailStatusLabel, 10);
    lv_obj_set_y(detailStatusLabel, 60);
    lv_label_set_text(detailStatusLabel, "The user info and status of the machine goes here. Wrapping text appears to work - yay!");
    lv_obj_remove_flag(detailStatusLabel, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE)); 
    lv_obj_set_style_text_color(detailStatusLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(detailStatusLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(detailStatusLabel, &FugazOne30, LV_PART_MAIN | LV_STATE_DEFAULT);

    statusLabel = lv_label_create(jobScreen);
    lv_obj_set_width(statusLabel, LV_SIZE_CONTENT);  
    lv_obj_set_height(statusLabel, LV_SIZE_CONTENT); 
    lv_obj_set_x(statusLabel, 10);
    lv_obj_set_y(statusLabel, 10);
    lv_label_set_text(statusLabel, "Working...");
    lv_obj_remove_flag(statusLabel, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN)); 
    lv_obj_set_style_text_color(statusLabel, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(statusLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(statusLabel, &FugazOne36, LV_PART_MAIN | LV_STATE_DEFAULT);

    loadButtonLabel = lv_label_create(jobScreen);
    lv_obj_set_width(loadButtonLabel, 460);
    lv_obj_set_height(loadButtonLabel, 26);
    lv_obj_set_x(loadButtonLabel, 1);
    lv_obj_set_y(loadButtonLabel, -10);
    lv_obj_set_align(loadButtonLabel, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(loadButtonLabel, "Load another sausage?");
    lv_obj_add_flag(loadButtonLabel, LV_OBJ_FLAG_CLICKABLE); 
    lv_obj_remove_flag(loadButtonLabel, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN)); 
    lv_obj_set_style_text_color(loadButtonLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(loadButtonLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(loadButtonLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(loadButtonLabel, &FugazOne24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(loadButtonLabel, 13, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(loadButtonLabel, lv_color_hex(0x0099FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(loadButtonLabel, 127, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(loadButtonLabel, event_loadButtonLabel, LV_EVENT_ALL, NULL);
}
