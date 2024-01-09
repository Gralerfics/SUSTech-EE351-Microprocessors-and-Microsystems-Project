#include "pwm.h"

#include <chrono>
#include <future>

#include "common_devices.h"

void pwm_thread_func(PWMController* pwm_controller) {
    while (!is_shutdown.load() and pwm_controller->is_running()) {
        int duty_cycle = pwm_controller->get_duty_cycle();
        
        gpio.write_pin(pwm_controller->get_pin(), gpio.STATE_HIGH);
        std::this_thread::sleep_for(std::chrono::microseconds(duty_cycle));
        gpio.write_pin(pwm_controller->get_pin(), gpio.STATE_LOW);
        std::this_thread::sleep_for(std::chrono::microseconds(pwm_controller->get_max_duty_cycle() - duty_cycle));
    }
}

PWMController::PWMController(int pin, int max_duty_cycle, int initial_duty_cycle) {
    this->pin = pin;
    this->max_duty_cycle = max_duty_cycle;
    this->duty_cycle = initial_duty_cycle;

    this->running.store(false);
}

PWMController::~PWMController() {
    // GPIO::cleanup(this->pin);
}

int PWMController::get_pin() {
    return this->pin;
}

int PWMController::get_duty_cycle() {
    return this->duty_cycle.load();
}

int PWMController::get_max_duty_cycle() {
    return this->max_duty_cycle;
}

void PWMController::launch() {
    this->running.store(true);
    std::thread pwm_thread(pwm_thread_func, this);
    pwm_thread.detach();
}

void PWMController::stop() {
    this->running.store(false);
}

bool PWMController::is_running() {
    return this->running.load();
}

void PWMController::set_duty_cycle(int duty_cycle) {
    this->duty_cycle.store(duty_cycle);
}
