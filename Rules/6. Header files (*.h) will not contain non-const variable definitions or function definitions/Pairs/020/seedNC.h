// Context: Energy meter sample buffer parameters

// seed_020_NC.h
#pragma once
// NC: sample buffer length and inline helper implemented
#include <cstddef>
std::size_t seed020_samples = 1024; // NC

std::size_t seed020_half() { // NC
    return seed020_samples / 2;
}
