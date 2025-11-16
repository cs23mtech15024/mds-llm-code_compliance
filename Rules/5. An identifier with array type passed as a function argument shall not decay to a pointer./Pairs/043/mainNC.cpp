// Context: Torque sensor linearization table

// ------ Non-Compliant Program (043_nc.cpp)
// Context: Lookup linearized torque using LUT head (toy)
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace tq_043_nc {

// NC helper: takes pointer and runtime count; no bound guarantee
static float head_or_zero(const float *lut, std::size_t n) {
    return (n > 0U) ? lut[0] : 0.0F;
}

float linearize_torque(float lut[]) { // NC API
    return head_or_zero(lut, 128U);
}

} // namespace tq_043_nc

int main() {
    using namespace tq_043_nc;
    float torque_lut[128] = {0.5F};
    std::cout << std::fixed << std::setprecision(3) << "torque=" << linearize_torque(torque_lut) << "\n";
    return 0;
}
