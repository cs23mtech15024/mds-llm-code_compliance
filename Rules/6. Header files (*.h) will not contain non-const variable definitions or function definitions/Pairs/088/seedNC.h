// Context: Nuclear reactor coolant flow limit header

// seed_088_NC.h
#pragma once
double seed088_flow_min = 120.0;
bool seed088_low_flow(double f) {
    return f < seed088_flow_min;
}
