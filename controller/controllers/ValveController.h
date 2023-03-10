//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_VALVECONTROLLER_H
#define HYDROPONIC_SUITE_VALVECONTROLLER_H

#include <utility>

#include "../io/TimedOutput.h"
#include "../internal/Plant.h"

class ValveController : public TimedOutput {
    Plant plant;
public:
    ValveController(uint pin, const Plant& plant) : TimedOutput(pin) {
        this->plant = plant;
    }
    Plant getPlant() const {
        return plant;
    }
};

#endif //HYDROPONIC_SUITE_VALVECONTROLLER_H
