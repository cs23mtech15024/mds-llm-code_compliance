// Context: Automotive CAN message table defined in header

// -------- Compliant Program (prog_023_c.cpp)
// Context: Automotive CAN message table — COMPLIANT
#include <iostream>
#include <cstdint>
#include "seedC.h" // extern seed023_CAN_IDS[], seed023_valid_id()

// Definitions
std::uint32_t seed023_CAN_IDS[8] = {0x100,0,0,0,0,0,0,0};
bool seed023_valid_id(std::uint32_t id) { return id == seed023_CAN_IDS[0]; }

namespace can_c {

template <std::size_t N>
void print_ids(const std::uint32_t (&ids)[N]) {
    std::cout << "CAN IDs:";
    for (std::size_t i = 0; i < N; ++i) std::cout << ' ' << ids[i];
    std::cout << "\n";
}

template <std::size_t N>
void check(const std::uint32_t (&msgs)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        bool ok = seed023_valid_id(msgs[i]);
        std::cout << "msg=" << msgs[i] << " valid=" << ok << "\n";
    }
}

} // namespace can_c

int main() {
    using namespace can_c;
    const std::uint32_t msgs[4] = {0x100,0x200,0x100,0x123};
    print_ids(seed023_CAN_IDS);
    check(msgs);
    return 0;
}
