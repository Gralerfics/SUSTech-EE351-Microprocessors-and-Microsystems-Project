#include "i2c.h"

#include "wiringPiI2C.h"

I2CController::I2CController(int slave_addr) {
    this->slave_addr = slave_addr;

    this->fd = wiringPiI2CSetup(this->slave_addr);
}

I2CController::~I2CController() {
    // GPIO::cleanup();
}

void I2CController::write_byte(uint8_t data) {
    wiringPiI2CWrite(this->fd, data);
}

int I2CController::read_byte() {
    return wiringPiI2CRead(this->fd);
}

void I2CController::write_register_8(uint8_t reg, uint8_t data) {
    wiringPiI2CWriteReg8(this->fd, reg, data);
}

uint8_t I2CController::read_register_8(uint8_t reg) {
    return wiringPiI2CReadReg8(this->fd, reg);
}

void I2CController::write_register_16(uint8_t reg, uint16_t data) {
    wiringPiI2CWriteReg16(this->fd, reg, data);
}

uint16_t I2CController::read_register_16(uint8_t reg) {
    return wiringPiI2CReadReg16(this->fd, reg);
}
