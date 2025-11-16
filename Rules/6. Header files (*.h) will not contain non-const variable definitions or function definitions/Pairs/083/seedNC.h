// Context: Factory conveyor jam detection header

// seed_083_NC.h
#pragma once
int seed083_jam_limit = 3;
bool seed083_is_jammed(int stalls) {
    return stalls >= seed083_jam_limit;
}
