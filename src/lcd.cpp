#include "lcd.h"

#include <cstring>
#include <chrono>
#include <thread>

#include "common_devices.h"

LCDController::LCDController(int io_rs, int io_rst, int io_led, int spi_channel, int canonical_width, int canonical_height) {
    this->io_rs = io_rs;
    this->io_rst = io_rst;
	this->io_led = io_led;
    this->spi = std::make_unique<SPIController>(spi_channel);

    this->canonical_width = canonical_width;
    this->canonical_height = canonical_height;
    this->width = canonical_width;
    this->height = canonical_height;

	gpio.set_pin_mode(this->io_rs, gpio.MODE_OUT);
	gpio.set_pin_mode(this->io_rst, gpio.MODE_OUT);
	gpio.set_pin_mode(this->io_led, gpio.MODE_OUT);

	this->set_brightness(100);
}

LCDController::~LCDController() {
    // GPIO::cleanup(this->io_rs);
    // GPIO::cleanup(this->io_rst);
}

void LCDController::set_rs() {
	gpio.write_pin(this->io_rs, gpio.STATE_HIGH);
}

void LCDController::reset_rs() {
	gpio.write_pin(this->io_rs, gpio.STATE_LOW);
}

void LCDController::set_rst() {
	gpio.write_pin(this->io_rst, gpio.STATE_HIGH);
}

void LCDController::reset_rst() {
	gpio.write_pin(this->io_rst, gpio.STATE_LOW);
}

void LCDController::reset() {
    this->set_rst();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    this->reset_rst();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    this->set_rst();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void LCDController::init() {
    this->reset();

	this->send_command(0xCF);
	this->send_data(0x00);
	this->send_data(0xC1);
	this->send_data(0x30);

	this->send_command(0xED);
	this->send_data(0x64);
	this->send_data(0x03);
	this->send_data(0X12);
	this->send_data(0X81);

	this->send_command(0xE8);
	this->send_data(0x85);
	this->send_data(0x00);
	this->send_data(0x78);

	this->send_command(0xCB);
	this->send_data(0x39);
	this->send_data(0x2C);
	this->send_data(0x00);
	this->send_data(0x34);
	this->send_data(0x02);

	this->send_command(0xF7);
	this->send_data(0x20);

	this->send_command(0xEA);
	this->send_data(0x00);
	this->send_data(0x00);

	this->send_command(0xC0);
	this->send_data(0x13);

	this->send_command(0xC1);
	this->send_data(0x13);

	this->send_command(0xC5);
	this->send_data(0x22);
	this->send_data(0x35);

	this->send_command(0xC7);
	this->send_data(0xBD);

	this->send_command(0x21);

	this->send_command(0x36);
	this->send_data(0x08);

	this->send_command(0xB6);
	this->send_data(0x0A);
	this->send_data(0xA2);

	this->send_command(0x3A);
	this->send_data(0x55);

	this->send_command(0xF6);
	this->send_data(0x01);
	this->send_data(0x30);

	this->send_command(0xB1);
	this->send_data(0x00);
	this->send_data(0x1B);

	this->send_command(0xF2);
	this->send_data(0x00);

	this->send_command(0x26);
	this->send_data(0x01);

	this->send_command(0xE0);
	this->send_data(0x0F);
	this->send_data(0x35);
	this->send_data(0x31);
	this->send_data(0x0B);
	this->send_data(0x0E);
	this->send_data(0x06);
	this->send_data(0x49);
	this->send_data(0xA7);
	this->send_data(0x33);
	this->send_data(0x07);
	this->send_data(0x0F);
	this->send_data(0x03);
	this->send_data(0x0C);
	this->send_data(0x0A);
	this->send_data(0x00);

	this->send_command(0XE1);
	this->send_data(0x00);
	this->send_data(0x0A);
	this->send_data(0x0F);
	this->send_data(0x04);
	this->send_data(0x11);
	this->send_data(0x08);
	this->send_data(0x36);
	this->send_data(0x58);
	this->send_data(0x4D);
	this->send_data(0x07);
	this->send_data(0x10);
	this->send_data(0x0C);
	this->send_data(0x32);
	this->send_data(0x34);
	this->send_data(0x0F);

    this->send_command(0x11);
    std::this_thread::sleep_for(std::chrono::milliseconds(120));
    this->send_command(0x29);

    this->set_direction(1, 0, 1);

    this->canvas_clear(this->color_from_rgb(255, 255, 255));
}

void LCDController::set_brightness(int brightness) {
	this->brightness = brightness;
	// TODO
}

void LCDController::send_command(uint8_t command) {
    this->reset_rs();
    this->spi->send_byte(command);
}

void LCDController::send_data(uint8_t data) {
    this->set_rs();
    this->spi->send_byte(data);
}

uint8_t LCDController::receive_data() {
    this->set_rs();
    uint8_t data = this->spi->receive_byte();
    return data;
}

void LCDController::write_register(uint8_t address, uint8_t data) {
    this->send_command(address);
    this->send_data(data);
}

uint8_t LCDController::read_register(uint8_t address) {
    this->send_command(address);
    return this->receive_data();
}

void LCDController::set_direction(bool mx, bool my, bool mv) {
	if (!mv) {
        this->width = this->canonical_width;
        this->height = this->canonical_height;
	} else {
		this->width = this->canonical_height;
		this->height = this->canonical_width;
	}
	this->write_register(this->CMD_MEMORY_ACCESS_CONTROL, (mx << 6) | (my << 7) | (mv << 5) | 0x08);
}

void LCDController::enable_ram_write() {
    this->send_command(this->CMD_MEMORY_WRITE);
}

void LCDController::enable_ram_read() {
    this->send_command(this->CMD_MEMORY_READ);
}

void LCDController::set_window(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
    this->send_command(this->CMD_COLUMN_ADDRESS_SET);
    this->send_data(x0 >> 8);
    this->send_data(x0 & 0xFF);
    this->send_data(x1 >> 8);
    this->send_data(x1 & 0xFF);

    this->send_command(this->CMD_PAGE_ADDRESS_SET);
    this->send_data(y0 >> 8);
    this->send_data(y0 & 0xFF);
    this->send_data(y1 >> 8);
    this->send_data(y1 & 0xFF);

    this->enable_ram_write();
}

void LCDController::set_cursor(uint16_t x, uint16_t y) {
    this->set_window(x, y, x, y);
}

uint16_t LCDController::color_from_rgb(uint8_t r, uint8_t g, uint8_t b, bool little_endian) {
    uint16_t color = (r << 11) | (g << 5) | b;
    if (little_endian) color = ((color & 0xFF) << 8) | ((color & 0xFF00) >> 8);
    return color;
}

void LCDController::canvas_fill(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t* colors) {
    this->set_window(x0, y0, x1, y1);
    this->set_rs();
    uint32_t area = (x1 - x0 + 1) * (y1 - y0 + 1);
    this->spi->send_data(reinterpret_cast<uint8_t*>(colors), area * 2);
}

void LCDController::canvas_clear(uint16_t color) {
    uint32_t area = this->width * this->height;
    uint16_t data[area];
    std::fill(data, data + area, color);
    this->canvas_fill(0, 0, this->width - 1, this->height - 1, data);
}
