//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_LIGHTCONTROLLER_H
#define HYDROPONIC_SUITE_LIGHTCONTROLLER_H

#include "AnalogOutput.h"

#include <vector>

const uint SECONDS_TO_MS = 1000;
const uint MINUTES_TO_MS = 60 * SECONDS_TO_MS;
const uint HOURS_TO_MS = 60 * MINUTES_TO_MS;

const uint LIGHT_PIN = 16;

class LightController : public AnalogOutput {
  AnalogOutput light = AnalogOutput(LIGHT_PIN);
  public:
    explicit LightController() : AnalogOutput() {}
    void cycle(int hoursHigh);
};

#endif //HYDROPONIC_SUITE_LIGHTCONTROLLER_H
