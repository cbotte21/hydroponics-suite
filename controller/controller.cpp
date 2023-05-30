#include "controller.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
/*
 * Author: Cody Botte
 *
 * TODO:
 *  - Light controller should be on a separate thread
 *  - Connect to a wireless programmer
 *
 * Notes:
 *  - Program will depend on water restriction for calculating water output.
 *  - Can OR all valve controller output for a water pump enable.
 *
 *  main() Explanation:
 *      - Save external plantdata to file if present
 *      - Load plantdata from file
 *      - Register LAMP/LIGHT output: HIGH time intervals
 *      - Register ValveControllers with plants
 *      - Set valve open intervals
 *      - Endless loop
 *          - Cycle all plant's valves
 *          - Check light state (tick())
 *          - Sleep
 */

const double quartsPerHour = 8;
const double minutesForQuart = 60 / quartsPerHour;
const double secondsForQuart = 60 * minutesForQuart;

const uint LIGHTS_HOURS_HIGH = 12;

void lightManagerCore() {
    LightController lightController;
    while (true) {
      lightController.cycle(LIGHTS_HOURS_HIGH);
    }
}

int main() {
    stdio_init_all();

    // Initialize LightManager core
    multicore_launch_core1(lightManagerCore);

    // Initialize I/O controllers
    IrrigationManager irrigationManager(secondsForQuart);

    // Main Loop
    while (true) {
        //Handle irrigation
        irrigationManager.cycle();
    }
}
#pragma clang diagnostic pop