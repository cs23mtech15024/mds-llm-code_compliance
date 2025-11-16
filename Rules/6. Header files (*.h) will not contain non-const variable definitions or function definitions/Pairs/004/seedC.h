// Context: Network packet parser configuration

// seed_004_C.h
#pragma once
#include <cstdint>
extern std::uint8_t seed004_magic_header[4];
bool seed004_is_valid(std::uint8_t b);
