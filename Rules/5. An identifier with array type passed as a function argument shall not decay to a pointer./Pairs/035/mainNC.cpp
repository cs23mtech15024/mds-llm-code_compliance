// Context: Solar panel current measurements

// ------ Non-Compliant Program (035_nc.cpp)
// Context: Sum current from first two panels (toy)
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace solar_035_nc {

static float sum2(const float *a, std::size_t n) { return (n > 1U) ? (a[0] + a[1]) : (n ? a[0] : 0.0F); }

float sum_panel_currents(float currents[]) { // NC API
    const std::size_t N = 6U; (void)N;
    return sum2(currents, 6U);
}

} // namespace solar_035_nc

int main() {
    using namespace solar_035_nc;
    float panel_currents[6] = {5.2F, 5.5F, 0, 0, 0, 0};
    std::cout << std::fixed << std::setprecision(2) << "total_current=" << sum_panel_currents(panel_currents) << "\n";
    return 0;
}
