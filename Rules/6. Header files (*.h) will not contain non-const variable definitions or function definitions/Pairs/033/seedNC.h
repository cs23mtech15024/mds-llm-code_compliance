// Context: Robotics wheel encoder conversion factors

// seed_033_NC.h
#pragma once
double seed033_ticks_per_rev = 2048.0;
double seed033_to_radians(int ticks) {
    return (ticks * 3.14159 * 2) / seed033_ticks_per_rev;
}
