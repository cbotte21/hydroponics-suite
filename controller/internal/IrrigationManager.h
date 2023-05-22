//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_VALVEMANAGER_H
#define HYDROPONIC_SUITE_VALVEMANAGER_H

#include <vector>
#include "CycleCalculator.h"
#include "../io/ValveController.h"

class IrrigationManager {
    CycleCalculator* cycleCalculator = nullptr;  // Pointer to lazily-lazy init.... Eventually make setters and a default constructor
    std::vector<ValveController> controllers;  // TODO: Should probably be a circular linked list
    uint currController = 0;

    [[nodiscard]] double quartsUsedHourly() const;

public:
    explicit IrrigationManager(double secondsForQuart);
    void cycle();
};

#endif  // HYDROPONIC_SUITE_VALVEMANAGER_H