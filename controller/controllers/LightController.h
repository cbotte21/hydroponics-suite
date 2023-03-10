//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_LIGHTCONTROLLER_H
#define HYDROPONIC_SUITE_LIGHTCONTROLLER_H

#include "../io/AnalogOutput.h"

class LightController : public AnalogOutput {
    std::vector<std::pair<uint, uint>> light_high_intervals;
public:
    explicit LightController() : AnalogOutput() {}
    void tick();
    friend std::istream& operator >> (std::istream& in, LightController& lightController); //Load time intervals and pin
};

#endif //HYDROPONIC_SUITE_LIGHTCONTROLLER_H
