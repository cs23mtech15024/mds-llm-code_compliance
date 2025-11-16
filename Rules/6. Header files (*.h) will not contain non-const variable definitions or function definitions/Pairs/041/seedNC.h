// Context: Wind turbine blade angle configuration

// seed_041_NC.h
#pragma once
float seed041_blade_angle = 12.5F;
bool seed041_is_safe(float a) {
    return a < seed041_blade_angle;
}
