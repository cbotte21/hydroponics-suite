//
// Created by cbotte21 on 2/23/23.
//

#ifndef HYDROPONIC_SUITE_IO_H
#define HYDROPONIC_SUITE_IO_H


#include "hardware/pio.h"
#include "valve_controller.pio.h"

#include "../valve_controller.h"

class IO {
    uint pin;
public:
    //Constructors
    explicit IO(uint pin) {
        gpio_init(pin);
        this->pin = pin;
    }

    uint getPin() const {
        return pin;
    }
};


#endif //HYDROPONIC_SUITE_IO_H
