// Context: Actuator feedback position array

// ------ Compliant Program (054_c.cpp)
// Context: Actuator feedback positions (6 DOF)
// Rule: Preserve array extent (COMPLIANT)
// C: get_actuator_position takes a reference to array[6]
#include <iostream>
#include <iomanip>

namespace act_054_c {

float get_actuator_position(float (&positions)[6]) { // C API exact bound
    return positions[0];
}

} // namespace act_054_c

int main() {
    using namespace act_054_c;
    float actuator_pos[6] = {45.5F, 0, 0, 0, 0, 0};
    std::cout << std::fixed << std::setprecision(1)
              << "pos0=" << get_actuator_position(actuator_pos) << "\n";
    return 0;
}
