//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_VALVECONTROLLER_H
#define HYDROPONIC_SUITE_VALVECONTROLLER_H

#include <utility>

#include "../io/TimedOutput.h"
#include "../internal/Plant.h"

class ValveController : public TimedOutput {
public:
    ValveController(uint pin, const Plant& plant) : TimedOutput(pin, plant.watering_duration) {}
};


#endif //HYDROPONIC_SUITE_VALVECONTROLLER_H
