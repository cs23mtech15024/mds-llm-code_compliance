// Context: Greenhouse CO₂ regulation threshold header

// seed_071_NC.h
#pragma once
int seed071_co2_limit = 900;
bool seed071_exceeds(int ppm) {
    return ppm > seed071_co2_limit;
}
