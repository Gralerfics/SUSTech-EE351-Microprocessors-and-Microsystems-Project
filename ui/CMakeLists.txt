SET(SOURCES screens/ui_Home.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_bkg_png.c
    images/ui_img_btn_print_down_png.c
    images/ui_img_btn_print_top_off_png.c
    images/ui_img_icn_stop_png.c
    images/ui_img_icn_time_1_png.c
    images/ui_img_icn_time_2_png.c
    fonts/ui_font_Small_Font.c)

add_library(ui ${SOURCES})
