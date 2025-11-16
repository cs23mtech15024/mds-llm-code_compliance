// Context: HVAC fan speed parameters header

// seed_069_NC.h
#pragma once
int seed069_max_fan_speed = 5;
int seed069_limit(int s) {
    return (s > seed069_max_fan_speed) ? seed069_max_fan_speed : s;
}
