#include "valve_controller.h"

/*
 * TODO:
 *  - Connect pico_w to wireless programmer
 *
 */

//If WATERING_INTERVAL < (WATERING_LENGTH*VALVE_COUNT) -> INFINITE WATERING LOOP
const int VALVE_CONT = 2;
const int WATERING_INTERVAL = 1; //Minutes between water cycle
const int WATERING_LENGTH = 20;

int main() {
    stdio_init_all();

    std::vector<AnalogOutput> controllers;
    //Initialize I/O
    for (int i = 0; i < VALVE_CONT; i++) {
        controllers.emplace_back(i, false);
    }

    //Main Loop
    while (true) {
        printf("Water cycle started!\n");
        for (auto controller : controllers) {
            controller.toggle();
            sleep_ms(WATERING_LENGTH*1000);
            controller.toggle();
        }
        printf("Water cycle ended!\n");
        sleep_ms(WATERING_INTERVAL*1000*60);
    }
    return 0;
}
