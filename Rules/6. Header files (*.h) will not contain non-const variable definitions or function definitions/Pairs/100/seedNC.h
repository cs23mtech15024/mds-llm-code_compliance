// Context: Deep-sea probe hull stress limit header

// seed_100_NC.h
#pragma once
double seed100_stress_limit = 18.7;
bool seed100_warn(double stress) {
    return stress > seed100_stress_limit;
}
