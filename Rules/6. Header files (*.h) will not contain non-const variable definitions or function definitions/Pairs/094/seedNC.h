// Context: Radiation sensor dose alarm header

// seed_094_NC.h
#pragma once
float seed094_dose_limit = 0.75F;
bool seed094_alarm(float dose) {
    return dose > seed094_dose_limit;
}
