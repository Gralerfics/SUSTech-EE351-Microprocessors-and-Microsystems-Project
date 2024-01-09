#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <chrono>
#include <atomic>
#include <thread>

#include "wiringPi.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include "ui.h"
#include "ui_events.h"

#include "common_devices.h"

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

int leds_x = 0, leds_y = 0;

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
    lcd_backlight.launch();
    
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    std::thread lv_ticking_thread(lv_ticking_func);
    lv_ticking_thread.detach();

    ui_init();

    int val = 0;
    while (!is_shutdown.load()) {
        lv_timer_handler();

        val += 10;
        lcd_backlight.set_duty_cycle(val % 1000);
        printf("PWM duty cycle: %d\n", lcd_backlight.get_duty_cycle());
        if (val >= 5000) {
            lcd_backlight.stop();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}
