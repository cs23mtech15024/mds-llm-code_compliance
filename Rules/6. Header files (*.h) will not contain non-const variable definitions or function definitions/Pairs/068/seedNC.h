// Context: Smart irrigation moisture threshold header

// seed_068_NC.h
#pragma once
int seed068_moisture_threshold = 45;
bool seed068_needs_water(int v) {
    return v < seed068_moisture_threshold;
}
