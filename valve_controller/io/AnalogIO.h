//
// Created by cbotte21 on 2/23/23.
//

#ifndef HYDROPONIC_SUITE_ANALOGIO_H
#define HYDROPONIC_SUITE_ANALOGIO_H

#include "../valve_controller.h"
#include "IO.h"

//TODO: Change to AnalogOutput

class AnalogIO : public IO {
public:
    //Constructors
    explicit AnalogIO(uint pin);
    AnalogIO(uint pin, bool state);

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


#endif //HYDROPONIC_SUITE_ANALOGIO_H
