#include "i2c.h"

#include <chrono>
#include <thread>

#include "common_devices.h"

I2CController::I2CController(int io_sda, int io_scl, int slave_addr) {
    this->io_sda = io_sda;
    this->io_scl = io_scl;
    this->slave_addr = slave_addr;
    this->slave_addr_w = (slave_addr << 1) | 0x00;
    this->slave_addr_r = (slave_addr << 1) | 0x01;

    gpio.set_pin_mode(this->io_sda, gpio.MODE_OUT);
    gpio.set_pin_mode(this->io_scl, gpio.MODE_OUT);
    this->set_scl();
    this->set_sda();
}

I2CController::~I2CController() {
    // GPIO::cleanup(this->io_sda);
    // GPIO::cleanup(this->io_scl);
}

void I2CController::set_sda_input() {
    gpio.set_pin_mode(this->io_sda, gpio.MODE_IN);
}

void I2CController::set_sda_output() {
    gpio.set_pin_mode(this->io_sda, gpio.MODE_OUT);
}

void I2CController::set_sda() {
    gpio.write_pin(this->io_sda, gpio.STATE_HIGH);
}

void I2CController::reset_sda() {
    gpio.write_pin(this->io_sda, gpio.STATE_LOW);
}

bool I2CController::read_sda() {
    return gpio.read_pin(this->io_sda) == gpio.STATE_HIGH;
}

void I2CController::set_scl() {
    gpio.write_pin(this->io_scl, gpio.STATE_HIGH);
}

void I2CController::reset_scl() {
    gpio.write_pin(this->io_scl, gpio.STATE_LOW);
}

void I2CController::delay_tick() {
    std::this_thread::sleep_for(std::chrono::microseconds(1));
}

void I2CController::start() {
    this->set_sda_output();
    this->set_sda();
    this->set_scl();
    this->delay_tick();
    this->reset_sda();
    this->delay_tick();
    this->reset_scl();
    this->delay_tick();
}

void I2CController::stop() {
    this->set_sda_output();
    this->reset_scl();
    this->reset_sda();
    this->delay_tick();
    this->set_scl();
    this->delay_tick();
    this->set_sda();
    this->delay_tick();
}

bool I2CController::wait_ack() {
    this->set_sda_input();
    this->set_sda();
    this->delay_tick();
    this->set_scl();
    this->delay_tick();
    int trial_count = 0;
    while (this->read_sda()) {
        trial_count++;
        if (trial_count > 1000) {
            this->stop();
            return false;
        }
    }
    this->reset_scl();
    return true;
}

void I2CController::send_ack() {
    this->set_sda_output();
    this->reset_scl();
    this->reset_sda();
    this->delay_tick();
    this->set_scl();
    this->delay_tick();
    this->reset_scl();
}

void I2CController::send_nack() {
    this->set_sda_output();
    this->reset_scl();
    this->set_sda();
    this->delay_tick();
    this->set_scl();
    this->delay_tick();
    this->reset_scl();
}

void I2CController::write_byte(uint8_t data) {
    this->set_sda_output();
    this->reset_scl();
    for (int i = 0; i < 8; i++) {
        if (data & 0x80) {
            this->set_sda();
        } else {
            this->reset_sda();
        }
        data <<= 1;
        this->delay_tick();
        this->set_scl();
        this->delay_tick();
        this->reset_scl();
        this->delay_tick();
    }
    // this->reset_scl();
}

int I2CController::read_byte(bool ack) {
    this->set_sda_input();
    int data = 0;
    for (int i = 0; i < 8; i++) {
        this->reset_scl();
        this->delay_tick();
        this->set_scl();
        data <<= 1;
        if (this->read_sda()) data |= 0x01;
        this->delay_tick();
    }
    if (ack) {
        this->send_ack();
    } else {
        this->send_nack();
    }
    return data;
}
#include "stdio.h"
bool I2CController::write_register_8(uint8_t reg, uint8_t data) {
    this->start();
    this->write_byte(this->slave_addr_w);
    if (!this->wait_ack()) return false;
    this->write_byte(reg);
    if (!this->wait_ack()) return false;
    this->write_byte(data);
    if (!this->wait_ack()) return false;
    this->stop();
    return true;
}

uint8_t I2CController::read_register_8(uint8_t reg) {
    this->start();
    this->write_byte(this->slave_addr_w);
    this->wait_ack();
    if (!this->wait_ack()) return false;
    this->write_byte(reg);
    this->wait_ack();
    if (!this->wait_ack()) return false;
    this->start();
    this->write_byte(this->slave_addr_r);
    this->wait_ack();
    if (!this->wait_ack()) return false;
    uint8_t data = this->read_byte(false);
    this->stop();
    return data;
}
