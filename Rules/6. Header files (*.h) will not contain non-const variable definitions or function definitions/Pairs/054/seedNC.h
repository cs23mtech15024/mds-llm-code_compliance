// Context: Smart grid load shedding threshold header

// seed_054_NC.h
#pragma once
double seed054_shed_threshold_kw = 500.0;
double seed054_margin(double load) {
    return seed054_shed_threshold_kw - load;
}
