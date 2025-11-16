// Context: Torque sensor linearization table

// ------ Compliant Program (043_c.cpp)
// Context: Lookup linearized torque using LUT head (toy)
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace tq_043_c {

static float head_or_zero(const float (&lut)[128]) {
    return lut[0];
}

float linearize_torque(float (&lut)[128]) { // C API
    return head_or_zero(lut);
}

} // namespace tq_043_c

int main() {
    using namespace tq_043_c;
    float torque_lut[128] = {0.5F};
    std::cout << std::fixed << std::setprecision(3) << "torque=" << linearize_torque(torque_lut) << "\n";
    return 0;
}
