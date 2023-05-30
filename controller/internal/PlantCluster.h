//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_PLANT_H
#define HYDROPONIC_SUITE_PLANT_H

#include "pico/stdlib.h"
#include <string>
#include <utility>
#include <vector>
#include <utility>

using std::string;

class PlantCluster {
  string uuid;
  uint started;  // Timestamp
  double quartsDaily;

 public:
  // Load plant
  PlantCluster(string uuid, uint started, double quartsDaily) : PlantCluster(quartsDaily) {
    this->uuid = std::move(uuid);
    this->started = started;
  }

  // Initialize plant
  explicit PlantCluster(double quartsDaily) {
    uuid = "random uuid";
    this->started = 100;  // TODO: Populate with current time
    this->quartsDaily = quartsDaily;
  }

  [[nodiscard]] inline double getQuartsDaily() const {
    return quartsDaily;
  }

  [[nodiscard]] inline string getId() const {
    return uuid;
  }
};

#endif //HYDROPONIC_SUITE_PLANT_H
