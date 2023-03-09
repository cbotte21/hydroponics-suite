//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_TIMEDOUTPUT_H
#define HYDROPONIC_SUITE_TIMEDOUTPUT_H

#include "AnalogOutput.h"

class TimedOutput : public AnalogOutput {
    uint duration_seconds;
public:
    TimedOutput(uint pin, uint duration_seconds) : AnalogOutput(pin) {
        this->duration_seconds = duration_seconds;
    }

    //Cycle enables a positive output to a desired pin for a selected duration
    inline void cycle() {
        this->set(true);
        sleep_ms(duration_seconds*1000);
        this->set(false);
    }
};


#endif //HYDROPONIC_SUITE_TIMEDOUTPUT_H
