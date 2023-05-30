//
// Created by cbotte21 on 3/9/23.
//

#include "LightController.h"
#include "pico/stdlib.h"

// Tick compares current time to time interval. If within interval, pin high, else low.
void LightController::cycle(int hoursHigh) {
  light.set(true);
  sleep_ms(hoursHigh*HOURS_TO_MS);
  light.set(false);
  sleep_ms((24-hoursHigh)*HOURS_TO_MS);
}