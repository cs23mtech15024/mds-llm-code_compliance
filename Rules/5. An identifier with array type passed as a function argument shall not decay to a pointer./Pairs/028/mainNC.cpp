// Context: Thermocouple lookup table

// ------ Non-Compliant Program (028_nc.cpp)
// Context: Return the first LUT entry (placeholder)
// Status: VIOLATED (array decays)
#include <iostream>
#include <iomanip>

namespace tclut_028_nc {

float lookup_temperature(float table[]) { // NC API
    return table[0];
}

} // namespace tclut_028_nc

int main() {
    using namespace tclut_028_nc;
    float thermocouple_lut[256] = {25.0F};
    std::cout << std::fixed << std::setprecision(1)
              << "temp=" << lookup_temperature(thermocouple_lut) << "\n";
    return 0;
}
