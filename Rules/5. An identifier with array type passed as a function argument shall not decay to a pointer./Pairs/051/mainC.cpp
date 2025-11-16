// Context: Barometric pressure trend analysis

// ------ Compliant Program (051_c.cpp)
// Context: Barometric pressure trend analysis over 24 hours
// Rule: Identifier with array type shall not decay to a pointer (COMPLIANT)
// C: All functions take array references with bounds preserved
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace pressure_051_c {

template <std::size_t N>
static float first(const float (&p)[N]) { return (N > 0U) ? p[0] : 0.0F; }

template <std::size_t N>
static float delta01(const float (&p)[N]) { return (N > 1U) ? (p[1] - p[0]) : 0.0F; }

float analyze_trend(float (&pressures)[24]) { // C API with exact bound
    float start = first(pressures);
    float d01   = delta01(pressures);
    (void)start;
    return d01;
}

} // namespace pressure_051_c

int main() {
    using namespace pressure_051_c;
    float pressure_trend[24] = {1013.0F, 1015.0F};
    std::cout << std::fixed << std::setprecision(1)
              << "delta=" << analyze_trend(pressure_trend) << "\n";
    return 0;
}
