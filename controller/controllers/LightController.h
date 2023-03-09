//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_LIGHTCONTROLLER_H
#define HYDROPONIC_SUITE_LIGHTCONTROLLER_H

#include "../io/AnalogOutput.h"

class LightController : public AnalogOutput {
    std::vector<std::pair<uint, uint>> light_high_intervals;
public:
    LightController(uint pin, std::vector<std::pair<uint, uint>> light_high_intervals) : AnalogOutput(pin) {
        this->light_high_intervals = light_high_intervals;
    }
    void tick();
};

#endif //HYDROPONIC_SUITE_LIGHTCONTROLLER_H
