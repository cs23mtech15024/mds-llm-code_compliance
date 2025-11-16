// Context: Laser distance sensor array

// ------ Non-Compliant Program (046_nc.cpp)
// Context: Report first measured distance with a simple echo
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace lzr_046_nc {

// NC helper: pointer + length for display
static void echo2(const float *x, std::size_t n) {
    if (n > 0U) std::cout << "x0=" << x[0]; if (n > 1U) std::cout << ", x1=" << x[1]; std::cout << "\n";
}

float find_closest_distance(float distances[]) { // NC API
    echo2(distances, 16U);
    return distances[0];
}

} // namespace lzr_046_nc

int main() {
    using namespace lzr_046_nc;
    float laser_readings[16] = {2.5F, 3.0F, 2.8F};
    std::cout << std::fixed << std::setprecision(2) << "min=" << find_closest_distance(laser_readings) << "\n";
    return 0;
}
