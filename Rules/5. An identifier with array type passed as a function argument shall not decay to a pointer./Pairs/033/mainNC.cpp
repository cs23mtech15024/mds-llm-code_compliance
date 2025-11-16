// Context: Strain gauge bridge readings

// ------ Non-Compliant Program (033_nc.cpp)
// Context: Convert first bridge value to microstrain (toy)
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace strain_033_nc {

static float to_microstrain(float v) { return v * 0.001F; }

float calculate_strain(float bridge_values[]) { // NC API
    const std::size_t N = 4U; (void)N;
    const float ms = to_microstrain(bridge_values[0]);
    std::cout << "first_raw=" << bridge_values[0] << "\n";
    return ms;
}

} // namespace strain_033_nc

int main() {
    using namespace strain_033_nc;
    float strain_data[4] = {1500.0F, 0.0F, 0.0F, 0.0F};
    std::cout << std::fixed << std::setprecision(3) << "strain=" << calculate_strain(strain_data) << "\n";
    return 0;
}
