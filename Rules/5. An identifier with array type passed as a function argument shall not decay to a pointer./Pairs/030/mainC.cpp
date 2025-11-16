// Context: Humidity sensor moving average

// ------ Compliant Program (030_c.cpp)
// Context: Smooth humidity with 2-sample average (demo)
// Status: COMPLIANT (array by reference)
#include <iostream>
#include <iomanip>

namespace humid_030_c {

static float avg2(const float (&r)[10]) { // C helper
    return (r[0] + r[1]) / 2.0F;
}

float smooth_humidity(float (&readings)[10]) { // C API
    return avg2(readings);
}

} // namespace humid_030_c

int main() {
    using namespace humid_030_c;
    float humidity_buffer[10] = {65.5F, 66.0F};
    std::cout << std::fixed << std::setprecision(1)
              << "humidity=" << smooth_humidity(humidity_buffer) << "\n";
    return 0;
}
