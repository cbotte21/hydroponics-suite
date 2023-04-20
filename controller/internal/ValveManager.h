//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_VALVEMANAGER_H
#define HYDROPONIC_SUITE_VALVEMANAGER_H

#include <vector>
#include "../controllers/ValveController.h"
#include "CycleCalculator.h"

// TODO: Should be renamed to IrrigationManager

class ValveManager {
    CycleCalculator* cycleCalculator = nullptr;  // Pointer to lazily-lazy init.... Eventually make setters and a default constructor
    double flowrateQuartsHourly = 0;
    uint cyclesHourly = 0;
    std::vector<ValveController> controllers;
    double getTotalQuartsDaily();  // Statistics needed for watering interval calculation
public:
    ValveManager(double flowrateHourly, uint cyclesHourly);
    void cycle();
    inline uint32_t getSleepSeconds() {
        return (uint32_t)cycleCalculator->delayIntervalSeconds();
    }
    friend std::istream& operator >> (std::istream& in, ValveManager& valveManager);
};

#endif  // HYDROPONIC_SUITE_VALVEMANAGER_H