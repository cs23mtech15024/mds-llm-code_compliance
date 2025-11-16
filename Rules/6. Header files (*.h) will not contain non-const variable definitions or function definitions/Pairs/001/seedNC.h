// Context: Battery management system threshold config header

// seed_001_NC.h
// NC: Non-const variable + function definition in header
#pragma once
float seed001_low_voltage = 3.2F; // NC
float seed001_high_voltage = 4.2F; // NC

float seed001_compute_range(float v) { // NC
    return (v - seed001_low_voltage) * 10.0F;
}
