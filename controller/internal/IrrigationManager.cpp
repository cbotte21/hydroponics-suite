//
// Created by cbotte21 on 3/9/23.
//

#include "IrrigationManager.h"
#include <chrono>

using std::chrono::milliseconds;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "NullDereference"

const uint SECONDS_TO_MS = 1000;

IrrigationManager::IrrigationManager(double secondsForQuart) {
  //TODO: Write data from programming if could connect.
  //TODO: Populate data from files, if exists.
  controllers.emplace_back(static_cast<int>(controllers.size()), new PlantCluster(2));
  //controllers.emplace_back(static_cast<int>(controllers.size()), new PlantCluster(4));

  this->cycleCalculator = new CycleCalculator(secondsForQuart, quartsUsedHourly());
  for (ValveController& controller : controllers) {
    controller.setDuration(cycleCalculator->wateringIntervalSeconds(controller.getPlantCluster()));
  }
}

double IrrigationManager::quartsUsedHourly() const {
  double sum = 0;
  for (const auto& controller : controllers) {
    sum += controller.getPlantCluster().getQuartsDaily()/24;
  }
  return sum;
}

void IrrigationManager::cycle() {
  ValveController controller = controllers[currController++];
  if (currController >= static_cast<uint>(controllers.size())) {
    currController = 0;
  }

  // TODO: When not feeling lazy, turn printfs to extraction operator overloading for or toString functions.
  // Debug console log
  printf("--- Water cycle started ---\n");
  printf("PlantCluster: %s (%s)\n", currController);
  printf("Quarts per hour: %lfs\n", controller.getPlantCluster().getQuartsDaily()/24);
  printf("Water time: %lfs\n", cycleCalculator->wateringIntervalSeconds(controller.getPlantCluster()));
  printf("Sleep time: %lfs\n", cycleCalculator->delayIntervalSeconds(controller.getPlantCluster()));
  printf("--- Water cycle ended ---\n\n");

  // TODO: All sleeps are not accurate! double to long lost precision
  controller.cycle();
  sleep_ms((uint32_t)cycleCalculator->delayIntervalSeconds(controller.getPlantCluster()) * SECONDS_TO_MS);
}

#pragma clang diagnostic pop