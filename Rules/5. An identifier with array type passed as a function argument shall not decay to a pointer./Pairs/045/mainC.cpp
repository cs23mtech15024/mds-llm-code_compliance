// Context: Gas sensor PPM measurements

// ------ Compliant Program (045_c.cpp)
// Context: Average first two gas PPM readings and print formatted
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace gas_045_c {

static float avg2(const float (&x)[20]) { return (x[0] + x[1]) / 2.0F; }

float get_average_ppm(float (&ppm_values)[20]) { // C API
    return avg2(ppm_values);
}

} // namespace gas_045_c

int main() {
    using namespace gas_045_c;
    float gas_ppm[20] = {150.0F, 155.0F};
    std::cout << std::fixed << std::setprecision(1) << "avg_ppm=" << get_average_ppm(gas_ppm) << "\n";
    return 0;
}
