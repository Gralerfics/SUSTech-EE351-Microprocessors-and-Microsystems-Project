#ifndef I2C_H
#define I2C_H

#include <stdint.h>

class I2CController {
public:
    I2CController(int slave_addr);
    ~I2CController();

    void write_byte(uint8_t data);
    int read_byte();
    void write_register_8(uint8_t reg, uint8_t data);
    uint8_t read_register_8(uint8_t reg);
    void write_register_16(uint8_t reg, uint16_t data);
    uint16_t read_register_16(uint8_t reg);

private:
    uint8_t slave_addr;
    int fd;
};

#endif