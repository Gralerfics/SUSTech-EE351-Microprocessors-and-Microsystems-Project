#ifndef SPI_HARDWARE_H
#define SPI_HARDWARE_H

#include <stdint.h>

class SPIController {
public:
    SPIController(int channel);
    ~SPIController();

    void send_byte(uint8_t byte);
    uint8_t receive_byte();
    void send_word(uint16_t word);
    uint16_t receive_word();
    void send_data(uint8_t* data, int length);
    void receive_data(uint8_t* data, int length);

private:
    int channel;
};

#endif