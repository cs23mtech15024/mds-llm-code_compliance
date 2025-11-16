// Context: Smart grid load balancing threshold header

// seed_076_NC.h
#pragma once
int seed076_load_limit = 3500;
bool seed076_overload(int watts) {
    return watts > seed076_load_limit;
}
