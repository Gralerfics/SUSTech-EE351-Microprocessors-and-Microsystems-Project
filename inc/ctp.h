#ifndef CTP_H
#define CTP_H

#include <memory>

#include "i2c.h"

class Touchpad {
public:
    Touchpad(int io_int, int io_rst, int dev_addr, int canonical_width, int canonical_height);
    ~Touchpad();

    void set_rst();
    void reset_rst();
    
    void reset();
    void init();

    void set_direction(bool mx, bool my, bool mv);
    void redirect_xy(int &x, int &y);

    bool is_point1_pressed(bool update = true);
    bool is_point2_pressed(bool update = true);
    void get_point1_xy(int &x, int &y, bool update = true);
    void get_point2_xy(int &x, int &y, bool update = true);

    void update_point1();
    void update_point2();
    void update_points();

private:
    int io_int, io_rst;
    std::unique_ptr<I2CController> i2c = nullptr;

    int canonical_width, canonical_height;
    int width, height;
    bool mx, my, mv;

    int e1_7 = 0, e1_6 = 0, e2_7 = 0, e2_6 = 0;
    int id1 = 0, id2 = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    /*
        Notes:
            e1_7:6 = 01 when released, 10 when pressed;
            e2_7:6 = 11 when released, 10 when point 2 is pressed (sometimes not true when two points are on the same column (row)?);
            id2 = 15 when point 2 is not pressed;
            something uncertain.
    */
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