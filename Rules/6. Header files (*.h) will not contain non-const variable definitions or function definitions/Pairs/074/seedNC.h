// Context: Electric scooter speed governor

// seed_074_NC.h
#pragma once
int seed074_speed_cap = 25;
int seed074_limit_speed(int s) {
    return (s > seed074_speed_cap) ? seed074_speed_cap : s;
}
