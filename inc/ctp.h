#ifndef CTP_H
#define CTP_H

#include <memory>

#include "i2c.h"

class Touchpad {
public:
    Touchpad(int io_sda, int io_scl, int io_int, int io_rst, int dev_addr);
    ~Touchpad();
    
    void reset();
    void init();

    bool is_pressed();
    void update_points();
    // void get_position(int* x, int* y);

private:
    void set_rst();
    void reset_rst();

    int io_sda, io_scl, io_int, io_rst;
    std::unique_ptr<I2CController> i2c = nullptr;

    int e1_7 = 0, e1_6 = 0, e2_7 = 0, e2_6 = 0;
    int id1 = 0, id2 = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    int weight1 = 0, weight2 = 0;
    int misc1 = 0, misc2 = 0;

    const uint8_t REG_P1_XH = 0x03; // bit 7:6 = event flag, bit 3:0 = x position high
    const uint8_t REG_P1_XL = 0x04;
    const uint8_t REG_P1_YH = 0x05; // bit 7:4 = point 1 id, bit 3:0 = y position high
    const uint8_t REG_P1_YL = 0x06;
    const uint8_t REG_P1_WEIGHT = 0x07;
    const uint8_t REG_P1_MISC = 0x08;
    const uint8_t REG_P2_XH = 0x09;
    const uint8_t REG_P2_XL = 0x0A;
    const uint8_t REG_P2_YH = 0x0B;
    const uint8_t REG_P2_YL = 0x0C;
    const uint8_t REG_P2_WEIGHT = 0x0D;
    const uint8_t REG_P2_MISC = 0x0E;
};

#endif