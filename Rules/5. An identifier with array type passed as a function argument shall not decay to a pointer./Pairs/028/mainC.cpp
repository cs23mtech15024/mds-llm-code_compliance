// Context: Thermocouple lookup table

// ------ Compliant Program (028_c.cpp)
// Context: Return the first LUT entry (placeholder)
// Status: COMPLIANT (array by reference)
#include <iostream>
#include <iomanip>

namespace tclut_028_c {

float lookup_temperature(float (&table)[256]) { // C API
    return table[0];
}

} // namespace tclut_028_c

int main() {
    using namespace tclut_028_c;
    float thermocouple_lut[256] = {25.0F};
    std::cout << std::fixed << std::setprecision(1)
              << "temp=" << lookup_temperature(thermocouple_lut) << "\n";
    return 0;
}
