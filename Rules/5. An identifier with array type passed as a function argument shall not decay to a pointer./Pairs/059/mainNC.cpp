// Context: HVAC zone temperature setpoints

// ------ Non-Compliant Program (059_nc.cpp)
// Context: HVAC zone temperature setpoints (10 zones)
// Rule: Array decays to pointer (VIOLATED)
// NC: configure_zones uses pointer and implicit length
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace hvac_059_nc {

static void set_first(float *sp, std::size_t n, float v) { // NC
    if (n > 0U) { sp[0] = v; }
}

void configure_zones(float setpoints[]) { // NC API
    const std::size_t N = 10U;
    set_first(setpoints, N, 22.0F);
    std::cout << "zone0_sp=" << setpoints[0] << "\n";
}

} // namespace hvac_059_nc

int main() {
    using namespace hvac_059_nc;
    float hvac_setpoints[10] = {0};
    configure_zones(hvac_setpoints);
    return 0;
}
