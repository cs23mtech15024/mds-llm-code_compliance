// Context: Spacecraft fuel consumption estimator header

// seed_090_NC.h
#pragma once
float seed090_fuel_rate = 0.0025F;
float seed090_estimate(float sec) {
    return sec * seed090_fuel_rate;
}
