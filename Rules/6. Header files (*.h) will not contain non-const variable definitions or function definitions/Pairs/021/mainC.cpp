// Context: Thermostat setpoint header with mutable setpoint

// -------- Compliant Program (prog_021_c.cpp)
// Context: Thermostat control — COMPLIANT
#include <iostream>
#include <iomanip>
#include "seedC.h" // extern seed021_thermostat_setpoint, seed021_get_setpoint()

// Definitions
float seed021_thermostat_setpoint = 22.5F;
float seed021_get_setpoint() { return seed021_thermostat_setpoint; }

namespace thermo_c {

float adjust(float current, float offset) {
    return current + offset;
}

template <std::size_t N>
void run(const float (&temps)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        float target = seed021_get_setpoint();
        float corrected = adjust(temps[i], target - temps[i]);
        std::cout << "temp=" << temps[i]
                  << " target=" << target
                  << " corrected=" << corrected << "\n";
    }
}

template <std::size_t N>
float avg(const float (&arr)[N]) {
    float s = 0;
    for (auto v : arr) s += v;
    return (N>0)? s/N:0;
}

} // namespace thermo_c

int main() {
    using namespace thermo_c;
    const float readings[5] = {20.5F,21.0F,22.0F,23.5F,24.0F};
    run(readings);
    std::cout << "avg=" << avg(readings) << "\n";
    return 0;
}
