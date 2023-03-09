//
// Created by cbotte21 on 3/9/23.
//

#include "CycleCalculator.h"

double CycleCalculator::cycleActiveMinutesHourly() {
    return quartsHourly/flowrateHourly*60;
}

double CycleCalculator::cycleLowMinutesHourly() {
    return 60 - cycleActiveMinutesHourly();
}

double CycleCalculator::wateringLengthSeconds(Plant plant) {
    double plantQuartsHourly = plant.water_quarts_daily/24.0;
    double minutesPlantActiveHour = cycleActiveMinutesHourly()*plantQuartsHourly/quartsHourly;
    double cycleTimeMinutes = minutesPlantActiveHour/cyclesHourly;
    return cycleTimeMinutes/flowrateHourly; //*60/60 cancels
}

double CycleCalculator::delayIntervalSeconds() {
    return 0;
}
