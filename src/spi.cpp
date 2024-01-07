#include "spi.h"

#include <algorithm>

#include "wiringPi.h"
#include "wiringPiSPI.h"

SPIController::SPIController(int channel) {
    this->channel = channel;

    wiringPiSPISetup(this->channel, 80000000);
}

SPIController::~SPIController() {
    // GPIO::cleanup(this->io_sck);
    // GPIO::cleanup(this->io_mosi);
    // GPIO::cleanup(this->io_miso);
}

void SPIController::send_byte(uint8_t byte) {
    this->send_data(&byte, 1);
}

uint8_t SPIController::receive_byte() {
    uint8_t byte = 0;
    this->receive_data(&byte, 1);
    return byte;
}

void SPIController::send_word(uint16_t word) {
    this->send_data((uint8_t*) &word, 2);
}

uint16_t SPIController::receive_word() {
    uint16_t word = 0;
    this->receive_data((uint8_t*) &word, 2);
    return word;
}

void SPIController::send_data(uint8_t* data, int length) {
    int ptr = 0;
    while (ptr < length) {
        int chunk = std::min(4096, length - ptr);
        wiringPiSPIDataRW(this->channel, data + ptr, chunk);
        ptr += chunk;
    }
}

void SPIController::receive_data(uint8_t* data, int length) {
    // TODO
    wiringPiSPIDataRW(this->channel, data, length);
}
