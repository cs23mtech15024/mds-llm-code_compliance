// Context: Data compression dictionary size header

// seed_044_NC.h
#pragma once
int seed044_dict_size = 4096;
int seed044_max_code() {
    return seed044_dict_size - 1;
}
