//
// Created by cbotte21 on 3/9/23.
//

#include "CycleCalculator.h"

const int SECONDS_PER_HOUR = 60*60;
const int CYCLES_PER_HOUR = 10;

double CycleCalculator::wateringIntervalSeconds(const PlantCluster& plant) const {
    double plantQuartsHourly = plant.getQuartsDaily() / 24.0;  // Quarts per hour needed for plant
    return plantQuartsHourly*  secondsForQuart / CYCLES_PER_HOUR;  // TODO: Should incorporate cycles per hour
}

double CycleCalculator::delayIntervalSeconds(const PlantCluster& plant) const {
    double totalActiveSecondsHourly = quartsUsedHourly * secondsForQuart;
    double totalLowSecondsHourly = SECONDS_PER_HOUR - totalActiveSecondsHourly;
    return totalLowSecondsHourly * percentageOfWaterflow(plant) / CYCLES_PER_HOUR;  // Should be a way to event distribute sleep time
}
