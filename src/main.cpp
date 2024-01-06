#include <iostream>
#include <signal.h>
#include <chrono>
#include <thread>

#include "JetsonGPIO.h"

static bool shutdown = false;

void sigint_handler(int signum) {
    shutdown = true;
}

int main(int argc, char** argv) {
    signal(SIGINT, sigint_handler);

    GPIO::setmode(GPIO::BOARD);
    
    

    return 0;
}
