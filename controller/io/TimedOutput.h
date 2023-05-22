//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_TIMEDOUTPUT_H
#define HYDROPONIC_SUITE_TIMEDOUTPUT_H

#include "AnalogOutput.h"
#include "pico/stdlib.h"

class TimedOutput : public AnalogOutput {
    double duration_seconds;
public:
    explicit TimedOutput(uint pin) : AnalogOutput(pin) {
        this->duration_seconds = 0;
    }
    TimedOutput(uint pin, double duration_seconds) : AnalogOutput(pin) {
        this->duration_seconds = duration_seconds;
    }

    //Cycle enables a positive output to a desired pin for a selected duration
    void cycle() {
        this->set(true);
        sleep_ms((uint32_t)duration_seconds*1000);
        this->set(false);
    }

    inline void setDuration(double seconds) {
        this->duration_seconds = seconds;
    }

    inline double getDuration() const {
        return duration_seconds;
    }
};


#endif //HYDROPONIC_SUITE_TIMEDOUTPUT_H
