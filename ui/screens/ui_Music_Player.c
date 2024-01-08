// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: Smart_Gadget

#include "../ui.h"

void ui_Music_Player_screen_init(void)
{
    ui_Music_Player = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Music_Player, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Music_Player, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Music_Player, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Music_Player, &ui_img_pattern_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_tiled(ui_Music_Player, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Music_Title = ui_Small_Label_create(ui_Music_Player);
    lv_obj_set_x(ui_Music_Title, 0);
    lv_obj_set_y(ui_Music_Title, 0);
    lv_obj_set_align(ui_Music_Title, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Music_Title, "Wood and forest");
    lv_obj_set_style_text_color(ui_Music_Title, lv_color_hex(0x000746), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Music_Title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Author = ui_Small_Label_create(ui_Music_Player);
    lv_obj_set_x(ui_Author, 0);
    lv_obj_set_y(ui_Author, 25);
    lv_obj_set_align(ui_Author, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Author, "Alan Smith");
    lv_obj_set_style_text_color(ui_Author, lv_color_hex(0x9C9CD9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Author, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Play_btn = lv_obj_create(ui_Music_Player);
    lv_obj_set_width(ui_Play_btn, 60);
    lv_obj_set_height(ui_Play_btn, 60);
    lv_obj_set_x(ui_Play_btn, 0);
    lv_obj_set_y(ui_Play_btn, -42);
    lv_obj_set_align(ui_Play_btn, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_Play_btn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Play_btn, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Play_btn, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Play_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Play_btn, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Play_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Play_btn, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Play_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Play_btn, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Play_btn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Play_btn, lv_color_hex(0x515EB5), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Play_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Play = lv_img_create(ui_Play_btn);
    lv_img_set_src(ui_Play, &ui_img_play_png);
    lv_obj_set_width(ui_Play, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Play, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Play, 2);
    lv_obj_set_y(ui_Play, 0);
    lv_obj_set_align(ui_Play, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Play, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Play, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Album = lv_img_create(ui_Music_Player);
    lv_img_set_src(ui_Album, &ui_img_album_png);
    lv_obj_set_width(ui_Album, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Album, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Album, 0);
    lv_obj_set_y(ui_Album, 20);
    lv_obj_set_align(ui_Album, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_Album, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Album, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Album, 300, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Backward = lv_img_create(ui_Music_Player);
    lv_img_set_src(ui_Backward, &ui_img_backward_png);
    lv_obj_set_width(ui_Backward, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Backward, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Backward, 30);
    lv_obj_set_y(ui_Backward, -60);
    lv_obj_set_align(ui_Backward, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_Backward, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Backward, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Backward, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Backward, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_Backward, lv_color_hex(0x515EB5), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(ui_Backward, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Forward = lv_img_create(ui_Music_Player);
    lv_img_set_src(ui_Forward, &ui_img_forward_png);
    lv_obj_set_width(ui_Forward, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Forward, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Forward, -30);
    lv_obj_set_y(ui_Forward, -60);
    lv_obj_set_align(ui_Forward, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_Forward, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Forward, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Forward, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Forward, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_Forward, lv_color_hex(0x515EB5), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(ui_Forward, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Scrolldots3 = ui_Scrolldots_create(ui_Music_Player);
    lv_obj_set_x(ui_Scrolldots3, 0);
    lv_obj_set_y(ui_Scrolldots3, -8);

    lv_obj_set_width(ui_comp_get_child(ui_Scrolldots3, UI_COMP_SCROLLDOTS_D1), 4);
    lv_obj_set_height(ui_comp_get_child(ui_Scrolldots3, UI_COMP_SCROLLDOTS_D1), 4);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots3, UI_COMP_SCROLLDOTS_D2), 10);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots3, UI_COMP_SCROLLDOTS_D2), 0);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots3, UI_COMP_SCROLLDOTS_D3), 20);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots3, UI_COMP_SCROLLDOTS_D3), 0);

    lv_obj_set_width(ui_comp_get_child(ui_Scrolldots3, UI_COMP_SCROLLDOTS_D4), 8);
    lv_obj_set_height(ui_comp_get_child(ui_Scrolldots3, UI_COMP_SCROLLDOTS_D4), 8);
    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots3, UI_COMP_SCROLLDOTS_D4), 31);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots3, UI_COMP_SCROLLDOTS_D4), 0);
    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Scrolldots3, UI_COMP_SCROLLDOTS_D4), lv_color_hex(0x101C52),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Scrolldots3, UI_COMP_SCROLLDOTS_D4), 255, LV_PART_MAIN | LV_STATE_DEFAULT);




    lv_obj_add_event_cb(ui_Music_Player, ui_event_Music_Player, LV_EVENT_ALL, NULL);

}
