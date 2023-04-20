//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_CYCLECALCULATOR_H
#define HYDROPONIC_SUITE_CYCLECALCULATOR_H

#include "../controller.h"

class CycleCalculator {
    double flowrateHourly;
    double quartsUsedHourly;
    uint cyclesHourly;

    double cycleActiveMinutesHourly();
    double cycleLowMinutesHourly();
public:
    CycleCalculator() {}
    CycleCalculator(double flowrateHourly, uint quartsUsedHourly, uint cyclesHourly) {
        this->flowrateHourly = flowrateHourly;
        this->quartsUsedHourly = quartsUsedHourly;
        this->cyclesHourly = cyclesHourly;
    }

    double wateringLengthSeconds(Plant plant);
    double delayIntervalSeconds();
};


#endif //HYDROPONIC_SUITE_CYCLECALCULATOR_H
