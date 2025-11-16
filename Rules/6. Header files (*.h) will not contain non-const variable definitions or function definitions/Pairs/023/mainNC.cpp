// Context: Automotive CAN message table defined in header

// -------- Non-Compliant Program (prog_023_nc.cpp)
// Context: Automotive CAN message table
#include <iostream>
#include <cstdint>
#include "seedNC.h" // seed023_CAN_IDS[], seed023_valid_id()

namespace can_nc {

void print_ids() {
    std::cout << "CAN IDs:";
    for (int i = 0; i < 8; ++i) std::cout << ' ' << seed023_CAN_IDS[i];
    std::cout << "\n";
}

void check(std::uint32_t msgs[], std::size_t n) { // NC
    for (std::size_t i = 0; i < n; ++i) {
        bool ok = seed023_valid_id(msgs[i]); // header fn
        std::cout << "msg=" << msgs[i] << " valid=" << ok << "\n";
    }
}

} // namespace can_nc

int main() {
    using namespace can_nc;
    std::uint32_t msgs[4] = {0x100,0x200,0x100,0x123};
    print_ids();
    check(msgs,4);
    return 0;
}
