#include "controller.h"

/*
 * TODO:
 *  - Plants should take in quarts_per_day. Then I should calculate based on other controllers and sleep interval how long to run them.
 *  - Maybe lights should be on a separate thread?
 *  - Connect pico_w to wireless programmer
 *  - Abstract plant data
 *  - gRPC to send data
 *
 * Notes:
 *  - Program will depend on water restriction for calculating water output.
 *  - Can OR all valve controller output for a water pump enable.
 */

const uint cyclesHourly = 20;
const double hourlyFlowrate = 10;

//If WATERING_INTERVAL < (WATERING_LENGTH*VALVE_COUNT) -> INFINITE WATERING LOOP
const int VALVE_COUNT = 2;

//Lighting Controls
const int LIGHT_PIN = 5;
std::vector<std::pair<uint, uint>> LIGHT_INTERVAL; //Interval to have lights on

int main() {
    stdio_init_all();

    //TODO: Populate data from files, if exists.
    //TODO: Write data from programming if could connect.
    //TODO: Use insertion operator for loading data.

    uint totalDailyQuarts = 0;

    //Initialize I/O
    std::vector<ValveController> controllers;
    LightController lightController(LIGHT_PIN, LIGHT_INTERVAL);
    for (int i = 0; i < VALVE_COUNT; i++) { //TODO: Implement data for blacklisted pins, if necessary.
        Plant plant;
        controllers.emplace_back(i, plant);
        totalDailyQuarts += plant.water_quarts_daily;
    }

    //Set duration times
    CycleCalculator cycleCalculator(hourlyFlowrate, totalDailyQuarts, cyclesHourly);
    for (int i = 0; i < VALVE_COUNT; i++) {
        controllers[i].setDuration(cycleCalculator.wateringLengthSeconds(controllers[i].getPlant()));
    }

    //Main Loop
    while (true) {
        //Handle controllers
        printf("Water cycle started!\n");
        for (auto controller : controllers) {
            controller.cycle();
        }
        printf("Water cycle ended!\n");

        //Handle lights
        lightController.tick();

        sleep_ms(cycleCalculator.delayIntervalSeconds()*1000);
    }
}