#ifndef COMMON_DEVICES_H
#define COMMON_DEVICES_H

#include <atomic>

extern std::atomic<bool> is_shutdown;

#include "gpio.h"
extern GPIOController gpio;

#include "lcd.h"
extern LCDController lcd;

#include "ctp.h"
extern Touchpad touchpad;

#include "pwm.h"
extern PWMController lcd_backlight;

#endif