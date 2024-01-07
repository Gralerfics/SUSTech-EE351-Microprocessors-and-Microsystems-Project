#include "gpio.h"

#include "wiringPi.h"

GPIOController::GPIOController() {
    wiringPiSetupGpio();
}

GPIOController::~GPIOController() {
    // GPIO::cleanup();
}

void GPIOController::set_pin_mode(int pin, int mode) {
    pinMode(pin, mode);
}

void GPIOController::write_pin(int pin, int value) {
    digitalWrite(pin, value);
}

int GPIOController::read_pin(int pin) {
    return digitalRead(pin);
}
