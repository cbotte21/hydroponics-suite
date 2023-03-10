//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_VALVEMANAGER_H
#define HYDROPONIC_SUITE_VALVEMANAGER_H

#include <vector>
#include "../controllers/ValveController.h"
#include "CycleCalculator.h"

class ValveManager {
    CycleCalculator* cycleCalculator = nullptr;
    double flowrateHourly = 0;
    uint cyclesHourly = 0;
    std::vector<ValveController> controllers;
    double getTotalQuartsDaily(); //Statistics needed for watering interval calculation
public:
    ValveManager(double flowrateHourly, uint cyclesHourly);
    void cycle();
    inline uint32_t getSleepSeconds() {
        return (uint32_t)cycleCalculator->delayIntervalSeconds();
    }
    friend std::istream& operator >> (std::istream& in, ValveManager& valveManager);
};

#endif //HYDROPONIC_SUITE_VALVEMANAGER_H