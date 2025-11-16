// Context: Warehouse robot battery reserve threshold

// seed_065_NC.h
#pragma once
int seed065_reserve_pct = 15;
bool seed065_low_battery(int pct) {
    return pct < seed065_reserve_pct;
}
