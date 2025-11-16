// Context: Airport runway visibility threshold header

// seed_092_NC.h
#pragma once
double seed092_visibility_limit = 1.2;
bool seed092_is_low(double km) {
    return km < seed092_visibility_limit;
}
