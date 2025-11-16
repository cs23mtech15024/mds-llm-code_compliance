// Context: Drone propeller pitch lookup header

// seed_067_NC.h
#pragma once
float seed067_pitch_values[3] = {3.1F, 4.5F, 5.2F};
float seed067_get_pitch(int i) {
    return seed067_pitch_values[i];
}
