// Context: Agricultural soil nutrient factor header

// seed_075_NC.h
#pragma once
float seed075_nutrient_factor = 0.72F;
float seed075_adjust(float base) {
    return base * seed075_nutrient_factor;
}
