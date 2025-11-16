// Context: Biometric fingerprint scanner quality threshold

// seed_080_NC.h
#pragma once
int seed080_quality_threshold = 72;
bool seed080_is_valid(int q) {
    return q >= seed080_quality_threshold;
}
