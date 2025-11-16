// Context: Bluetooth device pairing table header

// seed_014_NC.h
#pragma once
// NC: pairing table and helper defined in header
#include <cstdint>
std::uint64_t seed014_paired[4] = {0}; // NC

bool seed014_is_paired(std::uint64_t id) { // NC
    return seed014_paired[0] == id;
}
