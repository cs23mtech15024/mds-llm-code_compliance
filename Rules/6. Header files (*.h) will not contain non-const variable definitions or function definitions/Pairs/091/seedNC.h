// Context: Smart irrigation soil-moisture cutoff header

// seed_091_NC.h
#pragma once
float seed091_moisture_cutoff = 18.5F;
bool seed091_should_irrigate(float moisture) {
    return moisture < seed091_moisture_cutoff;
}
