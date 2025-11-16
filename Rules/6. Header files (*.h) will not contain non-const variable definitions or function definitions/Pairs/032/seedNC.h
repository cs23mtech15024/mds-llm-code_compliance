// Context: Navigation system compass calibration header

// seed_032_NC.h
#pragma once
double seed032_declination = -4.2;
double seed032_correct_heading(double h) {
    return h + seed032_declination;
}
