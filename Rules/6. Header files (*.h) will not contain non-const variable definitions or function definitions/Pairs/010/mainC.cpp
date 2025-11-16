// Context: Autonomous vehicle lane model parameters

// -------- Compliant Program (prog_010_c.cpp)
// Context: Autonomous vehicle lane curvature model — COMPLIANT
#include <iostream>
#include <iomanip>
#include <cstddef>
#include "seedC.h"

// Definitions
float seed010_lane_width = 3.7F;
float seed010_curvature(float r) { return 1.0F / (r + seed010_lane_width); }

namespace lane_c {

template <std::size_t N>
void scan(const float (&radii)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        float c = seed010_curvature(radii[i]) * 100.0F;
        std::cout << "r=" << radii[i] << " curv=" << c << "\n";
    }
}

template <std::size_t N>
float sum(const float (&vals)[N]) {
    float s = 0.0F;
    for (float v : vals) s += v;
    return s;
}

} // namespace lane_c

int main() {
    using namespace lane_c;
    const float r[5] = {5.0F,10.0F,15.0F,20.0F,25.0F};
    scan(r);
    std::cout << "sum=" << sum(r) << "\n";
    return 0;
}
