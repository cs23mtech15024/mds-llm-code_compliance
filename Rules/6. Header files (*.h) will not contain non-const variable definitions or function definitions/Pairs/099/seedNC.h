// Context: Solar inverter voltage sag detector header

// seed_099_NC.h
#pragma once
float seed099_min_voltage = 210.0F;
bool seed099_sag(float v) {
    return v < seed099_min_voltage;
}
