// Context: CAN bus message identifier table

// ------ Non-Compliant Program (012_nc.cpp)
// Context: Validate standard 11-bit CAN IDs (< 0x800)
// Rule: Array shall not decay — VIOLATED (ids[] decays)
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace can_012_nc {

static bool is_std_id(std::uint32_t id) { return id < 0x800U; }

static unsigned count_valid(const std::uint32_t *ids, std::size_t n) { // NC helper
    unsigned ok = 0U;
    for (std::size_t i = 0; i < n; ++i) { if (is_std_id(ids[i])) { ++ok; } }
    return ok;
}

bool is_valid_id(std::uint32_t ids[]) { // NC API
    const std::size_t N = 16U; // intended bound ignored by type
    std::cout << "first=0x" << std::hex << ids[0] << std::dec << "\n";
    std::cout << "valid_count=" << count_valid(ids, N) << "\n";
    return is_std_id(ids[0]);
}

} // namespace can_012_nc

int main() {
    using namespace can_012_nc;
    std::uint32_t can_ids[16] = {0x123U, 0x7FFU, 0x800U, 0x1FFFFFFFU};
    const bool ok = is_valid_id(can_ids);
    std::cout << std::boolalpha << "first_valid=" << ok << "\n";
    return 0;
}
