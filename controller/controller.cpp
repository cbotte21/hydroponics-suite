#include "controller.h"

/*
 * TODO:
 *  - Connect pico_w to wireless programmer
 *  - Abstract plant data
 *
 *
 */

//If WATERING_INTERVAL < (WATERING_LENGTH*VALVE_COUNT) -> INFINITE WATERING LOOP
const int VALVE_CONT = 2;
const int WATERING_INTERVAL = 60; //Seconds between water cycle
const int WATERING_LENGTH = 20;

int main() {
    stdio_init_all();

    std::vector<TimedOutput> controllers;
    //Initialize I/O
    for (int i = 0; i < VALVE_CONT; i++) {
        controllers.emplace_back(i, WATERING_LENGTH);
    }

    //Main Loop
    while (true) {
        printf("Water cycle started!\n");
        for (auto controller : controllers) {
            controller.cycle();
        }
        printf("Water cycle ended!\n");
        //TODO: Compare time with light timers
        sleep_ms(WATERING_INTERVAL*1000);
    }
    return 0;
}
