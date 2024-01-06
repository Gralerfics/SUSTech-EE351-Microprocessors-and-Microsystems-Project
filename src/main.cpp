#include <iostream>
#include <signal.h>
#include <chrono>
#include <thread>

#include "wiringPi.h"

#include "lcd.h"

static bool shutdown = false;

void sigint_handler(int signum) {
    shutdown = true;
}

int main(int argc, char** argv) {
    signal(SIGINT, sigint_handler);

    if (wiringPiSetupGpio() == -1) return -1;

    LCDController lcd(23, 24, 11, 10, 9, 240, 320);
    lcd.init();
    std::cout << "Finished." << std::endl;

    return 0;
}
