// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: ee351_ui

#include "../ui.h"

void ui_Home_screen_init(void)
{
    ui_Home = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Home, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Home, &ui_img_bkg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Home_Header = lv_obj_create(ui_Home);
    lv_obj_set_width(ui_Home_Header, 291);
    lv_obj_set_height(ui_Home_Header, 40);
    lv_obj_set_x(ui_Home_Header, 0);
    lv_obj_set_y(ui_Home_Header, -20);
    lv_obj_set_align(ui_Home_Header, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Home_Header, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Home_Header, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Home_Header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Home_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Home_Header, lv_color_hex(0x414B62), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Home_Header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Home_Header, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Home_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Home_Header_Label = lv_label_create(ui_Home_Header);
    lv_obj_set_width(ui_Home_Header_Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Home_Header_Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Home_Header_Label, 0);
    lv_obj_set_y(ui_Home_Header_Label, 10);
    lv_obj_set_align(ui_Home_Header_Label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Home_Header_Label, "Home");
    lv_obj_set_style_text_color(ui_Home_Header_Label, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Home_Header_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Home_Header_Label, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Time_Panel = lv_obj_create(ui_Home);
    lv_obj_set_width(ui_Time_Panel, 224);
    lv_obj_set_height(ui_Time_Panel, 78);
    lv_obj_set_x(ui_Time_Panel, 0);
    lv_obj_set_y(ui_Time_Panel, 50);
    lv_obj_set_align(ui_Time_Panel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Time_Panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Time_Panel, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Time_Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Time_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Time_Panel, lv_color_hex(0x414B62), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Time_Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Time_Panel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Time_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Time_Label = lv_label_create(ui_Time_Panel);
    lv_obj_set_width(ui_Time_Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Time_Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Time_Label, 0);
    lv_obj_set_y(ui_Time_Label, -10);
    lv_obj_set_align(ui_Time_Label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Time_Label, "19 : 56 : 23");
    lv_obj_set_style_text_color(ui_Time_Label, lv_color_hex(0xE1E5F0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Time_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Time_Label, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Time_Label1 = lv_label_create(ui_Time_Panel);
    lv_obj_set_width(ui_Time_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Time_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Time_Label1, 1);
    lv_obj_set_y(ui_Time_Label1, 12);
    lv_obj_set_align(ui_Time_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Time_Label1, "2024 / 1 / 8   Monday");
    lv_obj_set_style_text_color(ui_Time_Label1, lv_color_hex(0xC0C3C9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Time_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Time_Label1, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BTN_Sleep = lv_img_create(ui_Home);
    lv_img_set_src(ui_BTN_Sleep, &ui_img_btn_print_down_png);
    lv_obj_set_width(ui_BTN_Sleep, LV_SIZE_CONTENT);   /// 40
    lv_obj_set_height(ui_BTN_Sleep, LV_SIZE_CONTENT);    /// 132
    lv_obj_set_x(ui_BTN_Sleep, 0);
    lv_obj_set_y(ui_BTN_Sleep, 65);
    lv_obj_set_align(ui_BTN_Sleep, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BTN_Sleep, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BTN_Sleep, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_BTN_Sleep, 128);

    ui_BTN_Sleep_Top = lv_img_create(ui_BTN_Sleep);
    lv_img_set_src(ui_BTN_Sleep_Top, &ui_img_btn_print_top_off_png);
    lv_obj_set_width(ui_BTN_Sleep_Top, LV_SIZE_CONTENT);   /// 105
    lv_obj_set_height(ui_BTN_Sleep_Top, LV_SIZE_CONTENT);    /// 94
    lv_obj_set_align(ui_BTN_Sleep_Top, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BTN_Sleep_Top, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_img_set_zoom(ui_BTN_Sleep_Top, 128);
    lv_obj_set_style_radius(ui_BTN_Sleep_Top, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_BTN_Sleep_Top, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_BTN_Sleep_Top, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BTN_Sleep_Top, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_BTN_Sleep_Top, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor(ui_BTN_Sleep_Top, lv_color_hex(0x67799B), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(ui_BTN_Sleep_Top, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_BTN_Sleep_Icon = lv_img_create(ui_BTN_Sleep_Top);
    lv_img_set_src(ui_BTN_Sleep_Icon, &ui_img_icn_stop_png);
    lv_obj_set_width(ui_BTN_Sleep_Icon, LV_SIZE_CONTENT);   /// 40
    lv_obj_set_height(ui_BTN_Sleep_Icon, LV_SIZE_CONTENT);    /// 40
    lv_obj_set_align(ui_BTN_Sleep_Icon, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BTN_Sleep_Icon, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BTN_Sleep_Icon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_BTN_Sleep_Icon, 128);

    lv_obj_add_event_cb(ui_BTN_Sleep_Top, ui_event_BTN_Sleep_Top, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Home, ui_event_Home, LV_EVENT_ALL, NULL);

}
