#include "../ui.hpp"

lv_obj_t *sauceScreen;
lv_obj_t *selectTitleLabel;
lv_obj_t *proceedInfoLabel;

void event_proceedInfoLabel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_CLICKED)
    {
        lv_screen_load_anim(patternScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false);
    }
}

void sauceScreen_create(void)
{
    sauceScreen = lv_obj_create(NULL);
    lv_obj_remove_flag(sauceScreen, (lv_obj_flag_t)(LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN)); 
    lv_obj_set_style_bg_image_src(sauceScreen, &bg, LV_PART_MAIN | LV_STATE_DEFAULT);

    selectTitleLabel = lv_label_create(sauceScreen);
    lv_obj_set_width(selectTitleLabel, LV_SIZE_CONTENT);  
    lv_obj_set_height(selectTitleLabel, LV_SIZE_CONTENT); 
    lv_obj_set_x(selectTitleLabel, 0);
    lv_obj_set_y(selectTitleLabel, -20);
    lv_obj_set_align(selectTitleLabel, LV_ALIGN_CENTER);
    lv_label_set_text(selectTitleLabel, "Select your Sauces:");
    lv_obj_remove_flag(selectTitleLabel, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE));
    lv_obj_set_style_text_color(selectTitleLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(selectTitleLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(selectTitleLabel, &FugazOne48, LV_PART_MAIN | LV_STATE_DEFAULT);

    proceedInfoLabel = lv_label_create(sauceScreen);
    lv_obj_set_width(proceedInfoLabel, LV_SIZE_CONTENT);  
    lv_obj_set_height(proceedInfoLabel, LV_SIZE_CONTENT); 
    lv_obj_set_x(proceedInfoLabel, 0);
    lv_obj_set_y(proceedInfoLabel, 30);
    lv_obj_set_align(proceedInfoLabel, LV_ALIGN_CENTER);
    lv_label_set_text(proceedInfoLabel, "Press START to proceed");
    lv_obj_add_flag(proceedInfoLabel, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(proceedInfoLabel, (lv_obj_flag_t)(LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN));
    lv_obj_set_style_text_color(proceedInfoLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(proceedInfoLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(proceedInfoLabel, &FugazOne36, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(proceedInfoLabel, event_proceedInfoLabel, LV_EVENT_ALL, NULL);
}
