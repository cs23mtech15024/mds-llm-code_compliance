// Context: Thermal printer heat pulse configuration

// seed_042_NC.h
#pragma once
int seed042_pulse_width_us = 220;
int seed042_calc_total(int pulses) {
    return pulses * seed042_pulse_width_us;
}
