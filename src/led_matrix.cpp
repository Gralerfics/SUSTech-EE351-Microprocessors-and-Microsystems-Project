#include "led_matrix.h"

#include <math.h>

LEDMatrix::LEDMatrix() {
}

LEDMatrix::~LEDMatrix() {
}

float LEDMatrix::get_source_x() {
    return source_x;
}

float LEDMatrix::get_source_y() {
    return source_y;
}

void LEDMatrix::update() {
    for (int i = 0; i < num_lights; i++) {
        float distance = sqrt(pow(xs[i] - source_x, 2) + pow(ys[i] - source_y, 2));
        float value = 1.0 - distance * decay_coefficients[i];
        float a = 100.0;
        value = (pow(a, value) - 1) / (a - 1);
        pwms[i]->set_duty_cycle((int) round(1000.0 * value));
    }
}

void LEDMatrix::set_source(float x, float y) {
    source_x = x;
    source_y = y;
    this->update();
}

void LEDMatrix::set_source_x(float x) {
    this->set_source(x, source_y);
}

void LEDMatrix::set_source_y(float y) {
    this->set_source(source_x, y);
}

void LEDMatrix::add_light(int pin, float x, float y, float decay_coefficient) {
    num_lights += 1;
    xs.push_back(x);
    ys.push_back(y);
    decay_coefficients.push_back(decay_coefficient);
    pwms.push_back(std::make_shared<PWMController>(pin, 1000, 10000));
}

void LEDMatrix::launch() {
    if (!running) {
        running = true;
        this->update();
        for (int i = 0; i < num_lights; i++) {
            pwms[i]->launch();
        }
    }
}

void LEDMatrix::stop() {
    if (running) {
        running = false;
        for (int i = 0; i < num_lights; i++) {
            pwms[i]->stop();
        }
    }
}

void LEDMatrix::toggle() {
    if (running) {
        this->stop();
    } else {
        this->launch();
    }
}

bool LEDMatrix::is_running() {
    return running;
}
