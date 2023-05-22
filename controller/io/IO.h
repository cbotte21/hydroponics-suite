//
// Created by cbotte21 on 2/23/23.
//

#ifndef HYDROPONIC_SUITE_IO_H
#define HYDROPONIC_SUITE_IO_H


#include "hardware/pio.h"
#include "controller.pio.h"

class IO {
    uint pin{};
public:
    //Constructors
    explicit IO(uint pin) {
        gpio_init(pin);
        this->pin = pin;
    }

    IO() = default;

    uint getPin() const {
        return pin;
    }

    inline void setPin(uint p) {
        gpio_init(p);
        pin = p;
    }
};


#endif //HYDROPONIC_SUITE_IO_H
