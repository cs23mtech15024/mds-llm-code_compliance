// Context: Wind speed measurement samples

// ------ Compliant Program (022_c.cpp)
// Context: Compute average of first two wind-speed samples
// Status: COMPLIANT (array by reference)
#include <iostream>
#include <iomanip>

namespace wind_022_c {

static float avg2(const float (&a)[100]) { // C helper
    return (a[0] + a[1]) / 2.0F;
}

float compute_wind_average(float (&speeds)[100]) { // C API
    return avg2(speeds);
}

} // namespace wind_022_c

int main() {
    using namespace wind_022_c;
    float wind_samples[100] = {5.5F, 6.0F};
    std::cout << std::fixed << std::setprecision(2)
              << "avg_speed=" << compute_wind_average(wind_samples) << "\n";
    return 0;
}
