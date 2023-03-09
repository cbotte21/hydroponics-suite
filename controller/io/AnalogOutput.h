//
// Created by cbotte21 on 2/23/23.
//

#ifndef HYDROPONIC_SUITE_ANALOGOUTPUT_H
#define HYDROPONIC_SUITE_ANALOGOUTPUT_H

#include "../controller.h"
#include "IO.h"

class AnalogOutput : public IO {
public:
    //Constructors
    explicit AnalogOutput(uint pin) : IO(pin) {}
    AnalogOutput(uint pin, bool state) : AnalogOutput(pin) {
        set(state);
    }

    //Accessors
    inline bool state() const {
        return gpio_is_pulled_up(getPin());
    }

    //Mutators
    inline void set(bool state) const {
        state ? gpio_pull_up(getPin()) : gpio_pull_down(getPin());
    }
    inline void toggle() const {
        set(!state());
    }
};


#endif //HYDROPONIC_SUITE_ANALOGOUTPUT_H
