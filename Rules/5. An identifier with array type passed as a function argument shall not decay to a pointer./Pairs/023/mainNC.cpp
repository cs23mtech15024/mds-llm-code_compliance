// Context: Gyroscope angular rate buffer

// ------ Non-Compliant Program (023_nc.cpp)
// Context: Convert deg/s to rad/s for the X axis
// Status: VIOLATED (array decays to pointer)
#include <iostream>
#include <iomanip>

namespace gyro_023_nc {

static void dps_to_rads(float *r) { // NC helper
    r[0] *= 0.01745329252F; // pi/180
}

void process_gyro_data(float rates[]) { // NC API
    dps_to_rads(rates);
    std::cout << std::fixed << std::setprecision(6)
              << "rate_x=" << rates[0] << "\n";
}

} // namespace gyro_023_nc

int main() {
    using namespace gyro_023_nc;
    float gyro_rates[3] = {10.5F, 12.0F, 8.5F};
    process_gyro_data(gyro_rates);
    return 0;
}
