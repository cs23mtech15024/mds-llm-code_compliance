// Context: Automotive CAN message table defined in header

// seed_023_NC.h
#pragma once
#include <cstdint>
std::uint32_t seed023_CAN_IDS[8] = {0x100};
bool seed023_valid_id(std::uint32_t id) {
    return id == seed023_CAN_IDS[0];
}
