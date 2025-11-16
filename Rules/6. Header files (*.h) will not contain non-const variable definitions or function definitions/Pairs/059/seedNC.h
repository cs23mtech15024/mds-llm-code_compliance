// Context: Camera white-balance preset header

// seed_059_NC.h
#pragma once
int seed059_wb_temp = 5500;
int seed059_adjust(int ambient) {
    return seed059_wb_temp + (ambient / 100);
}
