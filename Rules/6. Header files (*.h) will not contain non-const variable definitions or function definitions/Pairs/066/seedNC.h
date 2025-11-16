// Context: Display refresh compensation factor

// seed_066_NC.h
#pragma once
float seed066_refresh_factor = 1.05F;
float seed066_apply(float hz) {
    return hz * seed066_refresh_factor;
}
