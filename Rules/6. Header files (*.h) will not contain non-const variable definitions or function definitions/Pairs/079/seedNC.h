// Context: Satellite power budget margin header

// seed_079_NC.h
#pragma once
double seed079_margin = 12.5;
bool seed079_within_margin(double usage) {
    return usage < seed079_margin;
}
