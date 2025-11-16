// Context: Strain gauge bridge readings

// ------ Compliant Program (033_c.cpp)
// Context: Convert first bridge value to microstrain (toy)
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace strain_033_c {

static float to_microstrain(float v) { return v * 0.001F; }

float calculate_strain(float (&bridge_values)[4]) { // C API
    const float ms = to_microstrain(bridge_values[0]);
    std::cout << "first_raw=" << bridge_values[0] << "\n";
    return ms;
}

} // namespace strain_033_c

int main() {
    using namespace strain_033_c;
    float strain_data[4] = {1500.0F, 0.0F, 0.0F, 0.0F};
    std::cout << std::fixed << std::setprecision(3) << "strain=" << calculate_strain(strain_data) << "\n";
    return 0;
}
