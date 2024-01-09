#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <chrono>
#include <atomic>
#include <thread>
#include <math.h>

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include "ui.h"
#include "ui_events.h"

#include "common_devices.h"
#include "pwm.h"

std::atomic<bool> is_shutdown(false);
void sigint_handler(int signum) {
    is_shutdown.store(true);
}

void lv_ticking_func() {
    while (!is_shutdown.load()) {
        lv_tick_inc(1);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

GPIOController gpio;
LCDController lcd(23, 24, 26, 1, 240, 320);
Touchpad touchpad(27, 22, 0x38, 240, 320);
PWMController lcd_backlight(26, 1000, 1000);
LEDMatrix led_matrix;

bool is_sleeping = false;

void btn_sleep_defocused(lv_event_t* e) {
    if (is_sleeping) {
        is_sleeping = false;
        for (int i = 0; i <= 100; i++) {
            lcd_backlight.set_duty_cycle(i * 10);
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
}

void btn_sleep_clicked(lv_event_t* e) {
    if (is_sleeping) {
        btn_sleep_defocused(e);
    } else {
        is_sleeping = true;
        for (int i = 0; i <= 100; i++) {
            lcd_backlight.set_duty_cycle(1000 - i * 10);
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
}

void btn_light_clicked(lv_event_t* e) {
    led_matrix.toggle();
}

void movexy_up_clicked(lv_event_t* e) {
    if (led_matrix.get_source_y() < 1.0) {
        led_matrix.set_source_y(led_matrix.get_source_y() + 0.25);
    }
}

void movexy_down_clicked(lv_event_t* e) {
    if (led_matrix.get_source_y() > -1.0) {
        led_matrix.set_source_y(led_matrix.get_source_y() - 0.25);
    }
}

void movexy_left_clicked(lv_event_t* e) {
    if (led_matrix.get_source_x() > -1.0) {
        led_matrix.set_source_x(led_matrix.get_source_x() - 0.25);
    }
}

void movexy_right_clicked(lv_event_t* e) {
    if (led_matrix.get_source_x() < 1.0) {
        led_matrix.set_source_x(led_matrix.get_source_x() + 0.25);
    }
}

int main(int argc, char** argv) {
    signal(SIGINT, sigint_handler);

    lcd.init();
    touchpad.init();
    lcd_backlight.launch();

    float decay_coefficient = 0.667;
    led_matrix.add_light(12, -1.0, 1.0, decay_coefficient);
    led_matrix.add_light(16, -1.0, -1.0, decay_coefficient);
    led_matrix.add_light(20, 1.0, -1.0, decay_coefficient);
    led_matrix.add_light(21, 1.0, 1.0, decay_coefficient);
    led_matrix.set_source(0.0, 0.0);
    // PWMController pwm(16, 100, 1000);
    // pwm.set_duty_cycle(20);
    // pwm.launch();
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // pwm.stop();
    
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    std::thread lv_ticking_thread(lv_ticking_func);
    lv_ticking_thread.detach();

    ui_init();

    while (!is_shutdown.load()) {
        lv_timer_handler();

        lv_obj_set_pos(ui_Point, (int) round(led_matrix.get_source_x() * 50), (int) round((-led_matrix.get_source_y()) * 50));
    }

    return 0;
}
