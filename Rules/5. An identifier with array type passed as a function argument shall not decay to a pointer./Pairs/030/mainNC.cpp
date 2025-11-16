// Context: Humidity sensor moving average

// ------ Non-Compliant Program (030_nc.cpp)
// Context: Smooth humidity with 2-sample average (demo)
// Status: VIOLATED (array decays)
#include <iostream>
#include <iomanip>

namespace humid_030_nc {

static float avg2(const float *r) { // NC helper
    return (r[0] + r[1]) / 2.0F;
}

float smooth_humidity(float readings[]) { // NC API
    return avg2(readings);
}

} // namespace humid_030_nc

int main() {
    using namespace humid_030_nc;
    float humidity_buffer[10] = {65.5F, 66.0F};
    std::cout << std::fixed << std::setprecision(1)
              << "humidity=" << smooth_humidity(humidity_buffer) << "\n";
    return 0;
}
