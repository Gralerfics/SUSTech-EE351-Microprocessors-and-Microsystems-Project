#ifndef LED_MATRIX_H
#define LED_MATRIX_H

#include <vector>
#include <memory>

#include "pwm.h"

class LEDMatrix {
public:
    LEDMatrix();
    ~LEDMatrix();

    float get_source_x();
    float get_source_y();

    void update();
    void set_source(float x, float y);
    void set_source_x(float x);
    void set_source_y(float y);

    void add_light(int pin, float x, float y, float decay_coefficient);

    void launch();
    void stop();
    void toggle();
    bool is_running();

private:
    float source_x = 0.0, source_y = 0.0;

    int num_lights = 0;
    std::vector<float> xs, ys;
    std::vector<float> decay_coefficients;
    std::vector<std::shared_ptr<PWMController>> pwms;

    bool running = false;
};

#endif