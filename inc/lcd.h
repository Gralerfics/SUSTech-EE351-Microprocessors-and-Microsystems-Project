#ifndef LCD_H
#define LCD_H

#include <memory>
#include <stdint.h>

#include "spi.h"

// ILI9341
class LCDController {
public:
    LCDController(int io_rs, int io_rst, int spi_channel, int canonical_width, int canonical_height);
    ~LCDController();

    void reset();
    void init();

    void send_command(uint8_t command);
    void send_data(uint8_t data);
    uint8_t receive_data();

    void write_register(uint8_t address, uint8_t data);
    uint8_t read_register(uint8_t address);

    void set_direction(bool mx, bool my, bool mv);
    void enable_ram_write();
    void enable_ram_read();
    void set_window(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
    void set_cursor(uint16_t x, uint16_t y);

    uint16_t color_from_rgb(uint8_t r, uint8_t g, uint8_t b, bool little_endian = true);
    void canvas_fill(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t* colors);
    void canvas_clear(uint16_t color);

private:
    void set_rs();
    void reset_rs();
    void set_rst();
    void reset_rst();

    int io_rs, io_rst;
    std::unique_ptr<SPIController> spi = nullptr;

    int canonical_width, canonical_height;
    int width, height;

    const uint8_t CMD_COLUMN_ADDRESS_SET = 0x2A;
    const uint8_t CMD_PAGE_ADDRESS_SET = 0x2B;
    const uint8_t CMD_MEMORY_WRITE = 0x2C;
    const uint8_t CMD_MEMORY_READ = 0x2E;
    const uint8_t CMD_MEMORY_ACCESS_CONTROL = 0x36;
};

#endif