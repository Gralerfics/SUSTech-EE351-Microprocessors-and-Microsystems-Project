#include "spi.h"

#include "wiringPi.h"

SPIController::SPIController(int io_sck, int io_mosi, int io_miso) {
    this->io_sck = io_sck;
    this->io_mosi = io_mosi;
    this->io_miso = io_miso;

    pinMode(this->io_sck, OUTPUT);
    pinMode(this->io_mosi, OUTPUT);
    pinMode(this->io_miso, INPUT);
}

SPIController::~SPIController() {
    // GPIO::cleanup(this->io_sck);
    // GPIO::cleanup(this->io_mosi);
    // GPIO::cleanup(this->io_miso);
}

void SPIController::set_sck() {
    digitalWrite(this->io_sck, HIGH);
}

void SPIController::reset_sck() {
    digitalWrite(this->io_sck, LOW);
}

void SPIController::set_mosi() {
    digitalWrite(this->io_mosi, HIGH);
}

void SPIController::reset_mosi() {
    digitalWrite(this->io_mosi, LOW);
}

bool SPIController::get_miso() {
    return digitalRead(this->io_miso);
}

void SPIController::send_byte(uint8_t byte) {
    for (int i = 0; i < 8; i++) {
        if (byte & 0x80) {
            this->set_mosi();
        } else {
            this->reset_mosi();
        }
        this->reset_sck();
        this->set_sck();
        byte <<= 1;
    }
}

uint8_t SPIController::receive_byte() {
    uint8_t value = 0;
    uint8_t byte = 0xFF;
    for (int i = 0; i < 8; i++) {
        value <<= 1;
        if (byte & 0x80) {
            this->set_mosi();
        } else {
            this->reset_mosi();
        }
        byte <<= 1;
        this->reset_sck();
        if (this->get_miso()) {
            value += 1;
        }
        this->set_sck();
    }
    return value;
}

void SPIController::send_word(uint16_t word) {
    this->send_byte(word >> 8);
    this->send_byte(word & 0xFF);
}

uint16_t SPIController::receive_word() {
    uint16_t value = 0;
    value += this->receive_byte() << 8;
    value += this->receive_byte();
    return value;
}
