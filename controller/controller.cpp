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

const uint SECONDS_TO_MS = 1000;
const double secondsForQuart = 20;

void lightManagerCore() {
    LightController lightController;
    while (true) {
      lightController.tick();
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