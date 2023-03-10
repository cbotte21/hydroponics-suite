//
// Created by cbotte21 on 3/9/23.
//

#include "ValveManager.h"

double ValveManager::getTotalQuartsDaily() {
    double sum = 0;
    for (auto controller : controllers) {
        sum += controller.getPlant().water_quarts_daily;
    }
    return sum;
}

void ValveManager::cycle() {

}

std::istream& operator >> (std::istream& in, ValveManager& valveManager) {
/*
    for (int i = 0; i < VALVE_COUNT; i++) { //TODO: Check for blacklisted pins
        Plant plant;
        controllers.emplace_back(i, plant);
        valveManager.quartsDaily += plant.water_quarts_daily;
    }

    for (int i = 0; i < VALVE_COUNT; i++) {
        controllers[i].setDuration(cycleCalculator.wateringLengthSeconds(controllers[i].getPlant()));
    }
 */
    valveManager.cycleCalculator = new CycleCalculator(valveManager.flowrateHourly, valveManager.getTotalQuartsDaily(), valveManager.cyclesHourly);
}

ValveManager::ValveManager(double flowrateHourly, uint cyclesHourly) {
    this->flowrateHourly = flowrateHourly;
    this->cyclesHourly = cyclesHourly;
}
