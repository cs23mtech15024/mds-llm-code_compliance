// Context: Graphics engine mipmap levels header

// seed_030_NC.h
#pragma once
int seed030_mip_levels = 8;
int seed030_best_mip(int size) {
    return (size <= 256) ? seed030_mip_levels : seed030_mip_levels - 2;
}
