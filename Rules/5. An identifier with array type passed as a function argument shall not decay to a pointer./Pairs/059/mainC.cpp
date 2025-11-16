// Context: HVAC zone temperature setpoints

// ------ Compliant Program (059_c.cpp)
// Context: HVAC zone temperature setpoints (10 zones)
// Rule: Preserve array extent (COMPLIANT)
// C: configure_zones takes reference to array[10]
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace hvac_059_c {

template <std::size_t N>
static void set_first(float (&sp)[N], float v) { if (N > 0U) { sp[0] = v; } }

void configure_zones(float (&setpoints)[10]) { // C API exact bound
    set_first(setpoints, 22.0F);
    std::cout << "zone0_sp=" << setpoints[0] << "\n";
}

} // namespace hvac_059_c

int main() {
    using namespace hvac_059_c;
    float hvac_setpoints[10] = {0};
    configure_zones(hvac_setpoints);
    return 0;
}
