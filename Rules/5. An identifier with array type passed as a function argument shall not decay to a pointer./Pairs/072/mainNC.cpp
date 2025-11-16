// Context: Thermal camera pixel matrix

// ------ Non-Compliant Program (072_nc.cpp)
// Context: Thermal camera pixel matrix
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace therm_072_nc {

static float max2(const float *p, std::size_t n) { // NC helper
    float m = (n>0U)? p[0] : 0.0F; if (n>1U && p[1] > m) m = p[1]; return m;
}

float get_max_temperature(float pixels[]) { // NC API
    const std::size_t N = 4096U; (void)N;
    return max2(pixels, 8U);
}

static void print_head(const float *p) {
    std::cout << std::fixed << std::setprecision(1)
              << "p0=" << p[0] << " p1=" << p[1] << "\n";
}

} // namespace therm_072_nc

int main() {
    using namespace therm_072_nc;
    float thermal_image[4096] = {25.5F, 26.1F, 24.8F};
    float mx = get_max_temperature(thermal_image);
    print_head(thermal_image);
    std::cout << "max_temp=" << std::fixed << std::setprecision(1) << mx << "\n";
    return 0;
}
