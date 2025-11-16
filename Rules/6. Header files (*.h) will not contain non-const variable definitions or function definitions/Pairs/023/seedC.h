// Context: Automotive CAN message table defined in header

// seed_023_C.h
#pragma once
#include <cstdint>
extern std::uint32_t seed023_CAN_IDS[8];
bool seed023_valid_id(std::uint32_t id);
