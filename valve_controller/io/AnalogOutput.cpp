#include "AnalogOutput.h"

AnalogOutput::AnalogOutput(uint pin) : IO(pin) {
    //TODO: Set pin function if applicable
}

AnalogOutput::AnalogOutput(uint pin, bool state) : AnalogOutput(pin) {
    set(state);
};
