// Context: Infrared sensor zone detection

// ------ Compliant Program (036_c.cpp)
// Context: Check if first IR zone shows activity
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <cstdint>
#include <iomanip>

namespace ir_036_c {

static std::size_t count_active(const std::uint8_t (&zones)[8]) {
    std::size_t c = 0U; for (std::size_t i = 0; i < 8U; ++i) if (zones[i] != 0U) ++c; return c;
}

bool check_zones(std::uint8_t (&zones)[8]) { // C API
    const auto active = count_active(zones);
    std::cout << "active_total=" << active << "\n";
    return zones[0] > 0U;
}

} // namespace ir_036_c

int main() {
    using namespace ir_036_c;
    std::uint8_t ir_zones[8] = {1, 0, 1, 0, 0, 1, 0, 0};
    std::cout << std::boolalpha << "zone0_active=" << check_zones(ir_zones) << "\n";
    return 0;
}
