#include "AnalogIO.h"

AnalogIO::AnalogIO(uint pin) : IO(pin) {
    //TODO: Set pin function if applicable
}

AnalogIO::AnalogIO(uint pin, bool state) : AnalogIO(pin) {
    set(state);
};
