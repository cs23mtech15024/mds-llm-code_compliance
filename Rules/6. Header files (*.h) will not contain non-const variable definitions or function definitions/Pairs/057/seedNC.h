// Context: Environmental sensor sampling interval header

// seed_057_NC.h
#pragma once
unsigned long seed057_sample_interval_ms = 1000UL;
unsigned long seed057_half_interval() {
    return seed057_sample_interval_ms / 2UL;
}
