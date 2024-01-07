#ifndef GPIO_H
#define GPIO_H

class GPIOController {
public:
    GPIOController();
    ~GPIOController();

    void set_pin_mode(int pin, int mode);
    void write_pin(int pin, int value);
    int read_pin(int pin);

    const int MODE_OUT = 1;
    const int MODE_IN = 0;
    const int STATE_HIGH = 1;
    const int STATE_LOW = 0;

private:
    
};

#endif