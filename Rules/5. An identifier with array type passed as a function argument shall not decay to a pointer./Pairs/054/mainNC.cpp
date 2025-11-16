// Context: Actuator feedback position array

// ------ Non-Compliant Program (054_nc.cpp)
// Context: Actuator feedback positions (6 DOF)
// Rule: Array decays to pointer (VIOLATED)
// NC: get_actuator_position returns element 0 via pointer
#include <iostream>
#include <iomanip>

namespace act_054_nc {

float get_actuator_position(float positions[]) { // NC API
    return positions[0];
}

} // namespace act_054_nc

int main() {
    using namespace act_054_nc;
    float actuator_pos[6] = {45.5F, 0, 0, 0, 0, 0};
    std::cout << std::fixed << std::setprecision(1)
              << "pos0=" << get_actuator_position(actuator_pos) << "\n";
    return 0;
}
