// Context: Automated gate motor torque settings

// seed_064_NC.h
#pragma once
int seed064_torque_limit = 120;
bool seed064_overloaded(int t) {
    return t > seed064_torque_limit;
}
