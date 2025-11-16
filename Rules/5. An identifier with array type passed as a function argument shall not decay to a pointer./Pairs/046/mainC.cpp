// Context: Laser distance sensor array

// ------ Compliant Program (046_c.cpp)
// Context: Report first measured distance with a simple echo
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace lzr_046_c {

static void echo2(const float (&x)[16]) {
    std::cout << "x0=" << x[0] << ", x1=" << x[1] << "\n";
}

float find_closest_distance(float (&distances)[16]) { // C API
    echo2(distances);
    return distances[0];
}

} // namespace lzr_046_c

int main() {
    using namespace lzr_046_c;
    float laser_readings[16] = {2.5F, 3.0F, 2.8F};
    std::cout << std::fixed << std::setprecision(2) << "min=" << find_closest_distance(laser_readings) << "\n";
    return 0;
}
