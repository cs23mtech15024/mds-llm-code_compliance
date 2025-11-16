// Context: Substation transformer thermal threshold header

// seed_082_NC.h
#pragma once
double seed082_temp_threshold = 85.0;
bool seed082_overtemp(double t) {
    return t > seed082_temp_threshold;
}
