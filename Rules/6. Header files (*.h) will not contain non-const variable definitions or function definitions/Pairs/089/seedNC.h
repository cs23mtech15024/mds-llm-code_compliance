// Context: Pipeline pressure regulation header

// seed_089_NC.h
#pragma once
float seed089_max_pressure = 275.0F;
bool seed089_pressure_ok(float p) {
    return p <= seed089_max_pressure;
}
