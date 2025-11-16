// Context: Thermal camera pixel matrix

// ------ Compliant Program (072_c.cpp)
// Context: Thermal camera pixel matrix
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace therm_072_c {

static float max2(const float (&p)[4096]) { // C helper (use first two)
    float m = p[0]; if (p[1] > m) m = p[1]; return m;
}

float get_max_temperature(float (&pixels)[4096]) { // C API
    return max2(pixels);
}

static void print_head(const float (&p)[4096]) {
    std::cout << std::fixed << std::setprecision(1)
              << "p0=" << p[0] << " p1=" << p[1] << "\n";
}

} // namespace therm_072_c

int main() {
    using namespace therm_072_c;
    float thermal_image[4096] = {25.5F, 26.1F, 24.8F};
    float mx = get_max_temperature(thermal_image);
    print_head(thermal_image);
    std::cout << "max_temp=" << std::fixed << std::setprecision(1) << mx << "\n";
    return 0;
}
