#ifndef PWM_H
#define PWM_H

#include <atomic>

class PWMController {
public:
    PWMController(int pin, int max_duty_cycle = 1000, int initial_duty_cycle = 0);
    ~PWMController();

    int get_pin();
    int get_duty_cycle();
    int get_max_duty_cycle();

    void launch();
    void stop();
    bool is_running();

    void set_duty_cycle(int duty_cycle);

private:
    int pin;
    std::atomic<int> duty_cycle;
    int max_duty_cycle = 1000;

    std::atomic<bool> running;
};

#endif