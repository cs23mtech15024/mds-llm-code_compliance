// Context: CAN bus message identifier table

// ------ Compliant Program (012_c.cpp)
// Context: Validate standard 11-bit CAN IDs (< 0x800)
// Rule: COMPLIANT (ids passed by reference to exact bound)
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace can_012_c {

static bool is_std_id(std::uint32_t id) { return id < 0x800U; }

static unsigned count_valid(const std::uint32_t (&ids)[16]) { // C helper
    unsigned ok = 0U;
    for (std::size_t i = 0; i < 16U; ++i) { if (is_std_id(ids[i])) { ++ok; } }
    return ok;
}

bool is_valid_id(std::uint32_t (&ids)[16]) { // C API
    std::cout << "first=0x" << std::hex << ids[0] << std::dec << "\n";
    std::cout << "valid_count=" << count_valid(ids) << "\n";
    return is_std_id(ids[0]);
}

} // namespace can_012_c

int main() {
    using namespace can_012_c;
    std::uint32_t can_ids[16] = {0x123U, 0x7FFU, 0x800U, 0x1FFFFFFFU};
    std::cout << std::boolalpha << "first_valid=" << is_valid_id(can_ids) << "\n";
    return 0;
}
