// Context: Gyroscope angular rate buffer

// ------ Compliant Program (023_c.cpp)
// Context: Convert deg/s to rad/s for the X axis
// Status: COMPLIANT (array by reference)
#include <iostream>
#include <iomanip>

namespace gyro_023_c {

static void dps_to_rads(float (&r)[3]) { // C helper
    r[0] *= 0.01745329252F; // pi/180
}

void process_gyro_data(float (&rates)[3]) { // C API
    dps_to_rads(rates);
    std::cout << std::fixed << std::setprecision(6)
              << "rate_x=" << rates[0] << "\n";
}

} // namespace gyro_023_c

int main() {
    using namespace gyro_023_c;
    float gyro_rates[3] = {10.5F, 12.0F, 8.5F};
    process_gyro_data(gyro_rates);
    return 0;
}
