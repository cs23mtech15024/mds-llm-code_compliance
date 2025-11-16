// Context: Wireless RSSI smoothing parameters header

// seed_027_NC.h
#pragma once
int seed027_window_size = 5;
float seed027_smooth(float vals[]) {
    return vals[0];
}
