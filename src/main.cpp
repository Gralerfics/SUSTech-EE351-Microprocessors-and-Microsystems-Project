#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <chrono>
#include <future>
#include <thread>

#include "wiringPi.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include "ui.h"
#include "ui_events.h"

#include "common_devices.h"

static bool is_shutdown = false;
void sigint_handler(int signum) {
    is_shutdown = true;
}

void lv_ticking_func() {
    while (!is_shutdown) {
        lv_tick_inc(1);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

GPIOController gpio;
LCDController lcd(23, 24, 1, 240, 320);
Touchpad touchpad(27, 22, 0x38, 240, 320);

void btn_sleep_clicked(lv_event_t* e) {
    printf("Sleep button clicked\n");
}

void btn_light_clicked(lv_event_t* e) {
    printf("Light button clicked\n");
}

void movexy_up_clicked(lv_event_t* e) {
    printf("Up button clicked\n");
}

void movexy_down_clicked(lv_event_t* e) {
    printf("Down button clicked\n");
}

void movexy_left_clicked(lv_event_t* e) {
    printf("Left button clicked\n");
}

void movexy_right_clicked(lv_event_t* e) {
    printf("Right button clicked\n");
}

int main(int argc, char** argv) {
    signal(SIGINT, sigint_handler);

    lcd.init();
    touchpad.init();
    
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    auto lv_ticking_future = std::async(std::launch::async, lv_ticking_func);

    ui_init();

    while (!is_shutdown) {
        lv_timer_handler();

        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}
