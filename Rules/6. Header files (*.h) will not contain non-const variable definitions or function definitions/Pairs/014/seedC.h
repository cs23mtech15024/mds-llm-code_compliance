// Context: Bluetooth device pairing table header

// seed_014_C.h
#pragma once
#include <cstdint>
extern std::uint64_t seed014_paired[4];
bool seed014_is_paired(std::uint64_t id);
