// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: ee351_ui

#include "../ui.h"

void ui_Date_screen_init(void)
{
    ui_Date = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Date, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Date, &ui_img_bkg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Date_Header = lv_obj_create(ui_Date);
    lv_obj_set_width(ui_Date_Header, 291);
    lv_obj_set_height(ui_Date_Header, 40);
    lv_obj_set_x(ui_Date_Header, 0);
    lv_obj_set_y(ui_Date_Header, -20);
    lv_obj_set_align(ui_Date_Header, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Date_Header, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Date_Header, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Date_Header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Date_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Date_Header, lv_color_hex(0x414B62), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Date_Header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Date_Header, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Date_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Date_Header_Label = lv_label_create(ui_Date_Header);
    lv_obj_set_width(ui_Date_Header_Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Date_Header_Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Date_Header_Label, 0);
    lv_obj_set_y(ui_Date_Header_Label, 10);
    lv_obj_set_align(ui_Date_Header_Label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Date_Header_Label, "Calendar");
    lv_obj_set_style_text_color(ui_Date_Header_Label, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Date_Header_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Date_Header_Label, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Calendar = lv_calendar_create(ui_Date);
    lv_calendar_set_today_date(ui_Calendar, 2024, 1, 8);
    lv_calendar_set_showed_date(ui_Calendar, 2024, 1);
    lv_obj_t * ui_Calendar_header = lv_calendar_header_arrow_create(ui_Calendar);
    lv_obj_set_width(ui_Calendar, lv_pct(89));
    lv_obj_set_height(ui_Calendar, lv_pct(80));
    lv_obj_set_x(ui_Calendar, 0);
    lv_obj_set_y(ui_Calendar, 10);
    lv_obj_set_align(ui_Calendar, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Date, ui_event_Date, LV_EVENT_ALL, NULL);

}
