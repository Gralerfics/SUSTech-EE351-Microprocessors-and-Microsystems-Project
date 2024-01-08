#include "ctp.h"

#include <stdio.h>
#include <cstring>
#include <chrono>
#include <thread>

#include "common_devices.h"

Touchpad::Touchpad(int io_int, int io_rst, int dev_addr, int canonical_width, int canonical_height) {
    this->io_int = io_int;
    this->io_rst = io_rst;
    this->i2c = std::make_unique<I2CController>(dev_addr);

    this->canonical_width = canonical_width;
    this->canonical_height = canonical_height;
    this->width = canonical_width;
    this->height = canonical_height;

    gpio.set_pin_mode(this->io_int, gpio.MODE_IN);
    gpio.set_pin_mode(this->io_rst, gpio.MODE_OUT);
}

Touchpad::~Touchpad() {
    // GPIO::cleanup();
}

void Touchpad::set_rst() {
    gpio.write_pin(this->io_rst, gpio.STATE_HIGH);
}

void Touchpad::reset_rst() {
    gpio.write_pin(this->io_rst, gpio.STATE_LOW);
}

void Touchpad::reset() {
    this->set_rst();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    this->reset_rst();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    this->set_rst();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void Touchpad::init() {
    this->reset();

    this->set_direction(1, 0, 1);
}

void Touchpad::set_direction(bool mx, bool my, bool mv) {
	if (!mv) {
        this->width = this->canonical_width;
        this->height = this->canonical_height;
	} else {
		this->width = this->canonical_height;
		this->height = this->canonical_width;
	}
    this->mx = mx;
    this->my = my;
    this->mv = mv;
}

void Touchpad::redirect_xy(int &x, int &y) {
    if (this->mx) x = this->canonical_width - x;
    if (this->my) y = this->canonical_height - y;
    if (this->mv) std::swap(x, y);
}

bool Touchpad::is_point1_pressed(bool update) {
    if (update) {
        uint8_t xh1 = this->i2c->read_register_8(this->REG_P1_XH);
        this->e1_7 = (xh1 & 0x80) >> 7;
    }
    return this->e1_7;
}

bool Touchpad::is_point2_pressed(bool update) {
    if (update) {
        uint8_t xh2 = this->i2c->read_register_8(this->REG_P2_XH);
        this->e2_7 = (xh2 & 0x80) >> 7;
    }
    return this->e2_7;
}

void Touchpad::get_point1_xy(int &x, int &y, bool update) {
    if (update) this->update_point1();
    x = this->x1;
    y = this->y1;
    this->redirect_xy(x, y);
}

void Touchpad::get_point2_xy(int &x, int &y, bool update) {
    if (update) this->update_point2();
    x = this->x2;
    y = this->y2;
    this->redirect_xy(x, y);
}

void Touchpad::update_point1() {
    uint8_t xh1 = this->i2c->read_register_8(this->REG_P1_XH);
    uint8_t xl1 = this->i2c->read_register_8(this->REG_P1_XL);
    uint8_t yh1 = this->i2c->read_register_8(this->REG_P1_YH);
    uint8_t yl1 = this->i2c->read_register_8(this->REG_P1_YL);
    
    this->e1_7 = (xh1 & 0x80) >> 7;
    this->e1_6 = (xh1 & 0x40) >> 6;
    this->x1 = ((xh1 & 0x0F) << 8) | xl1;
    this->y1 = ((yh1 & 0x0F) << 8) | yl1;

    this->id1 = (yh1 & 0xF0) >> 4;
}

void Touchpad::update_point2() {
    uint8_t xh2 = this->i2c->read_register_8(this->REG_P1_XH);
    uint8_t xl2 = this->i2c->read_register_8(this->REG_P1_XL);
    uint8_t yh2 = this->i2c->read_register_8(this->REG_P1_YH);
    uint8_t yl2 = this->i2c->read_register_8(this->REG_P1_YL);
    
    this->e2_7 = (xh2 & 0x80) >> 7;
    this->e2_6 = (xh2 & 0x40) >> 6;
    this->x2 = ((xh2 & 0x0F) << 8) | xl2;
    this->y2 = ((yh2 & 0x0F) << 8) | yl2;
    
    this->id2 = (yh2 & 0xF0) >> 4;
}

void Touchpad::update_points() {
    this->update_point1();
    this->update_point2();

    // printf("=======================================\n");
    // printf("e1_7: %d, e1_6: %d, e2_7: %d, e2_6: %d\n", this->e1_7, this->e1_6, this->e2_7, this->e2_6);
    // printf("id1: %d, id2: %d\n", this->id1, this->id2);
    // printf("x1: %d, y1: %d, x2: %d, y2: %d\n", this->x1, this->y1, this->x2, this->y2);
}
