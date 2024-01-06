#ifndef SPI_H
#define SPI_H

#include <stdint.h>

class SPIController {
public:
    SPIController(int io_sck, int io_mosi, int io_miso);
    ~SPIController();

    void set_sck();
    void reset_sck();
    void set_mosi();
    void reset_mosi();
    bool get_miso();

    void send_byte(uint8_t byte);
    uint8_t receive_byte();
    void send_word(uint16_t word);
    uint16_t receive_word();

private:
    int io_sck, io_mosi, io_miso;
};

#endif