// Context: Barometric pressure trend analysis

// ------ Non-Compliant Program (051_nc.cpp)
// Context: Barometric pressure trend analysis over 24 hours
// Rule: Identifier with array type shall not decay to a pointer (VIOLATED)
// NC: analyze_trend and helpers accept decayed arrays/pointers
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace pressure_051_nc {

static float first(const float *p, std::size_t n) { // NC
    return (n > 0U) ? p[0] : 0.0F;
}

static float delta01(const float *p, std::size_t n) { // NC
    return (n > 1U) ? (p[1] - p[0]) : 0.0F;
}

float analyze_trend(float pressures[]) { // NC API
    const std::size_t N = 24U;
    float start = first(pressures, N);
    float d01   = delta01(pressures, N);
    (void)start; // pretend we use it elsewhere
    return d01;
}

} // namespace pressure_051_nc

int main() {
    using namespace pressure_051_nc;
    float pressure_trend[24] = {1013.0F, 1015.0F};
    std::cout << std::fixed << std::setprecision(1)
              << "delta=" << analyze_trend(pressure_trend) << "\n";
    return 0;
}
