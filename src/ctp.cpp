#include "ctp.h"

#include <cstring>
#include <chrono>
#include <thread>

#include "common_devices.h"

Touchpad::Touchpad(int io_int, int io_rst, int dev_addr) {
    this->io_int = io_int;
    this->io_rst = io_rst;
    this->i2c = std::make_unique<I2CController>(dev_addr);

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

bool Touchpad::is_pressed() {
    return gpio.read_pin(this->io_int) == gpio.STATE_LOW;
}
#include "stdio.h"
void Touchpad::update_points() {
    uint8_t buf[16];
    uint8_t xh1 = this->i2c->read_register_8(this->REG_P1_XH);
    uint8_t xl1 = this->i2c->read_register_8(this->REG_P1_XL);
    uint8_t yh1 = this->i2c->read_register_8(this->REG_P1_YH);
    uint8_t yl1 = this->i2c->read_register_8(this->REG_P1_YL);
    uint8_t xh2 = this->i2c->read_register_8(this->REG_P2_XH);
    uint8_t xl2 = this->i2c->read_register_8(this->REG_P2_XL);
    uint8_t yh2 = this->i2c->read_register_8(this->REG_P2_YH);
    uint8_t yl2 = this->i2c->read_register_8(this->REG_P2_YL);
    
    this->e1_7 = (xh1 & 0x80) >> 7;
    this->e1_6 = (xh1 & 0x40) >> 6;
    this->e2_7 = (xh2 & 0x80) >> 7;
    this->e2_6 = (xh2 & 0x40) >> 6;

    this->id1 = (yh1 & 0xF0) >> 4;
    this->id2 = (yh2 & 0xF0) >> 4;

    this->x1 = ((xh1 & 0x0F) << 8) | xl1;
    this->y1 = ((yh1 & 0x0F) << 8) | yl1;
    this->x2 = ((xh2 & 0x0F) << 8) | xl2;
    this->y2 = ((yh2 & 0x0F) << 8) | yl2;

    this->weight1 = this->i2c->read_register_8(this->REG_P1_WEIGHT);
    this->weight2 = this->i2c->read_register_8(this->REG_P2_WEIGHT);

    this->misc1 = this->i2c->read_register_8(this->REG_P1_MISC);
    this->misc2 = this->i2c->read_register_8(this->REG_P2_MISC);

    printf("e1_7: %d, e1_6: %d, e2_7: %d, e2_6: %d\n", this->e1_7, this->e1_6, this->e2_7, this->e2_6);
    printf("id1: %d, id2: %d\n", this->id1, this->id2);
    printf("x1: %d, y1: %d, x2: %d, y2: %d\n", this->x1, this->y1, this->x2, this->y2);
    printf("weight1: %d, weight2: %d\n", this->weight1, this->weight2);
    printf("misc1: %d, misc2: %d\n", this->misc1, this->misc2);
    printf("=======================================\n");
}

// void Touchpad::get_position(int* x, int* y) {
//     uint8_t xh = this->i2c->read_register_8(this->REG_P1_XH);
//     uint8_t xl = this->i2c->read_register_8(this->REG_P1_XL);
//     uint8_t yh = this->i2c->read_register_8(this->REG_P1_YH);
//     uint8_t yl = this->i2c->read_register_8(this->REG_P1_YL);

//     *x = ((xh & 0x0F) << 8) | xl;
//     *y = ((yh & 0x0F) << 8) | yl;
// }
