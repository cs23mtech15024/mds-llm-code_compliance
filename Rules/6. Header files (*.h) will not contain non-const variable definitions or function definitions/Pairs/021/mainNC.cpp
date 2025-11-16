// Context: Thermostat setpoint header with mutable setpoint

// -------- Non-Compliant Program (prog_021_nc.cpp)
// Context: Thermostat control
#include <iostream>
#include <iomanip>
#include "seedNC.h" // seed021_thermostat_setpoint, seed021_get_setpoint()

namespace thermo_nc {

float adjust(float current, float offset) {
    return current + offset;
}

void run(float temps[], std::size_t n) { // NC: decayed array
    for (std::size_t i = 0; i < n; ++i) {
        float target = seed021_get_setpoint();
        float corrected = adjust(temps[i], target - temps[i]);
        std::cout << "temp=" << temps[i]
                  << " target=" << target
                  << " corrected=" << corrected << "\n";
    }
}

float avg(float arr[], std::size_t n) { // NC
    float s = 0;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return (n>0)? s/n:0;
}

} // namespace thermo_nc

int main() {
    using namespace thermo_nc;
    float readings[5] = {20.5F, 21.0F, 22.0F, 23.5F, 24.0F};
    run(readings,5);
    std::cout << "avg=" << avg(readings,5) << "\n";
    return 0;
}
