// Context: Telemetry frame ID list header

// seed_019_NC.h
#pragma once
// NC: telemetry IDs defined and helper defined
#include <cstdint>
std::uint16_t seed019_ids[3] = {0x01,0x02,0x03}; // NC

std::uint16_t seed019_first() { // NC
    return seed019_ids[0];
}
