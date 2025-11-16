// Context: Autonomous vehicle lane model parameters

// -------- Non-Compliant Program (prog_010_nc.cpp)
// Context: Autonomous vehicle lane curvature model
#include <iostream>
#include <iomanip>
#include <cstddef>
#include "seedNC.h" // seed010_lane_width, seed010_curvature()

namespace lane_nc {

float estimate(float r) {
    return seed010_curvature(r) * 100.0F;
}

void scan(float radii[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        float c = estimate(radii[i]);
        std::cout << "r=" << radii[i] << " curv=" << c << "\n";
    }
}

float sum(float vals[], std::size_t n) { // NC
    float s = 0.0F;
    for (std::size_t i = 0; i < n; ++i) s += vals[i];
    return s;
}

} // namespace lane_nc

int main() {
    using namespace lane_nc;
    float r[5] = {5.0F,10.0F,15.0F,20.0F,25.0F};
    scan(r,5);
    std::cout << "sum=" << sum(r,5) << "\n";
    return 0;
}
