// Context: Hydraulic press pressure-limit header

// seed_096_NC.h
#pragma once
double seed096_pressure_cap = 15000.0;
bool seed096_exceeds(double psi) {
    return psi > seed096_pressure_cap;
}
