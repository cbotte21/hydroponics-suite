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
  controllers.emplace_back(static_cast<int>(controllers.size()), new Plant("Tomato", 24));
  controllers.emplace_back(static_cast<int>(controllers.size()), new Plant("Onion", 24*2));
  controllers.emplace_back(static_cast<int>(controllers.size()), new Plant("Cucumber", 24*3));

  this->cycleCalculator = new CycleCalculator(secondsForQuart, quartsUsedHourly());
  for (ValveController& controller : controllers) {
    controller.setDuration(cycleCalculator->wateringIntervalSeconds(controller.getPlant()));
  }
}

double IrrigationManager::quartsUsedHourly() const {
  double sum = 0;
  for (const auto& controller : controllers) {
    sum += controller.getPlant().getQuartsDaily()/24;
  }
  return sum;
}

void IrrigationManager::cycle() {
  ValveController controller = controllers[currController++];
  if (currController >= static_cast<uint>(controllers.size())) {
    currController = 0;
  }

  // Debug console log
  printf("--- Water cycle started ---\n");
  printf("Plant: %s (%s)\n", controller.getPlant().getName().c_str(), controller.getPlant().getId().c_str());
  printf("Quarts per hour: %lfs\n", controller.getPlant().getQuartsDaily()/24.0);
  printf("Water time: %lfs\n", cycleCalculator->wateringIntervalSeconds(controller.getPlant()));
  printf("Sleep time: %lfs\n", cycleCalculator->delayIntervalSeconds(controller.getPlant()));
  printf("--- Water cycle ended ---\n\n");

  // TODO: All sleeps are not accurate! double to long lost precision
  controller.cycle();
  sleep_ms((uint32_t)cycleCalculator->delayIntervalSeconds(controller.getPlant()) * SECONDS_TO_MS);
}

#pragma clang diagnostic pop