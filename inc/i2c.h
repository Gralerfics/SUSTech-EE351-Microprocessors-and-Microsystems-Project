#ifndef I2C_H
#define I2C_H

#include <stdint.h>

class I2CController {
public:
    I2CController(int io_sda, int io_scl, int slave_addr);
    ~I2CController();

    void write_byte(uint8_t data);
    int read_byte(bool ack);
    bool write_register_8(uint8_t reg, uint8_t data);
    uint8_t read_register_8(uint8_t reg);

private:
    void set_sda_input();
    void set_sda_output();
    void set_sda();
    void reset_sda();
    bool read_sda();
    void set_scl();
    void reset_scl();

    void delay_tick();

    void start();
    void stop();
    bool wait_ack();
    void send_ack();
    void send_nack();

    int io_sda, io_scl;
    uint8_t slave_addr, slave_addr_w, slave_addr_r;
};

#endif