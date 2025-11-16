// Context: Wind speed measurement samples

// ------ Non-Compliant Program (022_nc.cpp)
// Context: Compute average of first two wind-speed samples
// Status: VIOLATED (array decays to pointer)
#include <iostream>
#include <iomanip>

namespace wind_022_nc {

static float avg2(const float *a) { // NC helper
    return (a[0] + a[1]) / 2.0F;
}

float compute_wind_average(float speeds[]) { // NC API
    return avg2(speeds);
}

} // namespace wind_022_nc

int main() {
    using namespace wind_022_nc;
    float wind_samples[100] = {5.5F, 6.0F};
    std::cout << std::fixed << std::setprecision(2)
              << "avg_speed=" << compute_wind_average(wind_samples) << "\n";
    return 0;
}
