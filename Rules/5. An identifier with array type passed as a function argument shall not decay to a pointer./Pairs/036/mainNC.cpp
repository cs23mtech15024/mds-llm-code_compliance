// Context: Infrared sensor zone detection

// ------ Non-Compliant Program (036_nc.cpp)
// Context: Check if first IR zone shows activity
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <cstdint>
#include <iomanip>

namespace ir_036_nc {

static std::size_t count_active(const std::uint8_t *zones, std::size_t n) {
    std::size_t c = 0U; for (std::size_t i = 0; i < n; ++i) if (zones[i] != 0U) ++c; return c;
}

bool check_zones(std::uint8_t zones[]) { // NC API
    const std::size_t N = 8U; // not enforced by the signature
    const auto active = count_active(zones, N);
    std::cout << "active_total=" << active << "\n";
    return zones[0] > 0U;
}

} // namespace ir_036_nc

int main() {
    using namespace ir_036_nc;
    std::uint8_t ir_zones[8] = {1, 0, 1, 0, 0, 1, 0, 0};
    std::cout << std::boolalpha << "zone0_active=" << check_zones(ir_zones) << "\n";
    return 0;
}
