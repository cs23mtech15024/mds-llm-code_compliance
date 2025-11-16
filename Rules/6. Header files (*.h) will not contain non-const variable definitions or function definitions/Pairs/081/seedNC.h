// Context: Drone altitude safety floor header

// seed_081_NC.h
#pragma once
float seed081_min_altitude = 15.0F;
bool seed081_is_too_low(float alt) {
    return alt < seed081_min_altitude;
}
