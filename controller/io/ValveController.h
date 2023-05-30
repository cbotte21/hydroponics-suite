//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_VALVECONTROLLER_H
#define HYDROPONIC_SUITE_VALVECONTROLLER_H

#include <utility>

#include "TimedOutput.h"
#include "../internal/PlantCluster.h"

class ValveController : public TimedOutput {
    const PlantCluster* plantCluster;
public:
    ValveController(uint pin, const PlantCluster* plantCluster) : TimedOutput(pin) {
        this->plantCluster = plantCluster;
    }
    [[nodiscard]] PlantCluster getPlantCluster() const {
        return *plantCluster;
    }
};

#endif //HYDROPONIC_SUITE_VALVECONTROLLER_H
