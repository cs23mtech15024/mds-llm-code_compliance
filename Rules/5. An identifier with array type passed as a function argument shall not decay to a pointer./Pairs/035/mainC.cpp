// Context: Solar panel current measurements

// ------ Compliant Program (035_c.cpp)
// Context: Sum current from first two panels (toy)
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace solar_035_c {

static float sum2(const float (&a)[6]) { return a[0] + a[1]; }

float sum_panel_currents(float (&currents)[6]) { // C API
    return sum2(currents);
}

} // namespace solar_035_c

int main() {
    using namespace solar_035_c;
    float panel_currents[6] = {5.2F, 5.5F, 0, 0, 0, 0};
    std::cout << std::fixed << std::setprecision(2) << "total_current=" << sum_panel_currents(panel_currents) << "\n";
    return 0;
}
