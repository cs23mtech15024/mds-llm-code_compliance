// Context: Gas sensor PPM measurements

// ------ Non-Compliant Program (045_nc.cpp)
// Context: Average first two gas PPM readings and print formatted
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace gas_045_nc {

static float avg2(const float *x, std::size_t n) { return (n > 1U) ? (x[0] + x[1]) / 2.0F : (n ? x[0] : 0.0F); }

float get_average_ppm(float ppm_values[]) { // NC API
    return avg2(ppm_values, 20U);
}

} // namespace gas_045_nc

int main() {
    using namespace gas_045_nc;
    float gas_ppm[20] = {150.0F, 155.0F};
    std::cout << std::fixed << std::setprecision(1) << "avg_ppm=" << get_average_ppm(gas_ppm) << "\n";
    return 0;
}
