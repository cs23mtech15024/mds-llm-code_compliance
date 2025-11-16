// Context: Cryptomining rig thermal throttle header

// seed_095_NC.h
#pragma once
int seed095_throttle_temp = 92;
bool seed095_should_throttle(int t) {
    return t >= seed095_throttle_temp;
}
