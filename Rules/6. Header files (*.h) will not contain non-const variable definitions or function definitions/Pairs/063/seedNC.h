// Context: Weather station rainfall calibration header

// seed_063_NC.h
#pragma once
double seed063_rain_factor = 0.87;
double seed063_calibrate(double mm) {
    return mm * seed063_rain_factor;
}
