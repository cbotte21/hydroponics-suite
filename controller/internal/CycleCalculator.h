//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_CYCLECALCULATOR_H
#define HYDROPONIC_SUITE_CYCLECALCULATOR_H

#include "../controller.h"

class CycleCalculator {
    double flowrateHourly;
    double quartsHourly;
    uint cyclesHourly;

    double cycleActiveMinutesHourly();
    double cycleLowMinutesHourly();
public:
    CycleCalculator(double flowrateHourly, uint quartsDaily, uint cyclesHourly) {
        this->flowrateHourly = flowrateHourly;
        this->quartsHourly = quartsDaily/24.0;
        this->cyclesHourly = cyclesHourly;
    }

    double wateringLengthSeconds(Plant plant);
    double delayIntervalSeconds();
};


#endif //HYDROPONIC_SUITE_CYCLECALCULATOR_H
