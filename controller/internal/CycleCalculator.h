//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_CYCLECALCULATOR_H
#define HYDROPONIC_SUITE_CYCLECALCULATOR_H

#include "PlantCluster.h"

/*
 *  At the current state, plants will water once per hour,
 *  Should eventually involve a predefined amount of cycles per hour.
 */

class CycleCalculator {
    double secondsForQuart;
    double quartsUsedHourly;

    [[nodiscard]] inline double percentageOfWaterflow(const PlantCluster& plant) const {
      return plant.getQuartsDaily()/24/quartsUsedHourly;
    }

public:
    CycleCalculator(double secondsForQuart, double quartsUsedHourly) {
        this->secondsForQuart = secondsForQuart;
        this->quartsUsedHourly = quartsUsedHourly;
    }

    [[nodiscard]] double wateringIntervalSeconds(const PlantCluster& plant) const;
    [[nodiscard]] double delayIntervalSeconds(const PlantCluster& plant) const;
};

#endif //HYDROPONIC_SUITE_CYCLECALCULATOR_H
