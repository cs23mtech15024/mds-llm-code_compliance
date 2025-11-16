// Context: Network packet parser configuration

// seed_004_NC.h
#pragma once
// NC: global buffer + function definition
#include <cstdint>
std::uint8_t seed004_magic_header[4] = {0xDE,0xAD,0xBE,0xEF}; // NC

bool seed004_is_valid(std::uint8_t b) { // NC
    return b == seed004_magic_header[0];
}
