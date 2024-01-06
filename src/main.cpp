#include <iostream>
#include <signal.h>
#include <chrono>
#include <thread>

#include "JetsonGPIO.h"
#include "lcd.h"

static bool shutdown = false;

void sigint_handler(int signum) {
    shutdown = true;
}

int main(int argc, char** argv) {
    signal(SIGINT, sigint_handler);

    GPIO::setmode(GPIO::BOARD);
    
    LCDController lcd(16, 18, 23, 19, 21, 240, 320);
    lcd.init();
    std::cout << "Finished." << std::endl;
    // lcd.canvas_clear(lcd.color_from_rgb(128, 128, 128));

    return 0;
}
