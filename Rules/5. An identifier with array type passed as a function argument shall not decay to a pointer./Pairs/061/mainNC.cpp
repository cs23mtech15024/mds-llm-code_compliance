// Context: Robotic joint angle commands

// ------ Non-Compliant Program (061_nc.cpp)
// Context: Robotic joint angle commands
// Rule: Array parameter decays to pointer (VIOLATED)
// Note: helpers take pointers + explicit lengths
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace robot_061_nc {

constexpr std::size_t kJoints = 6U;

static void clamp_deg(float &v, float lo, float hi) {
    if (v < lo) v = lo; else if (v > hi) v = hi;
}

static void set_first_joint(float *angles, std::size_t n, float deg) { // NC
    if (n > 0U) {
        angles[0] = deg;
        clamp_deg(angles[0], -180.0F, 180.0F);
    }
}

static void dump_head(const float *angles, std::size_t n, std::size_t count) {
    for (std::size_t i = 0; i < count && i < n; ++i) {
        std::cout << (i?" ":"") << std::fixed << std::setprecision(1) << angles[i];
    }
    std::cout << "\n";
}

void set_joint_angles(float angles[]) { // NC API
    angles[1] = 10.0F;
    set_first_joint(angles, kJoints, 30.0F);
    std::cout << "joint0=" << angles[0] << " joint1=" << angles[1] << "\n";
    dump_head(angles, kJoints, 3U);
}

} // namespace robot_061_nc

int main() {
    using namespace robot_061_nc;
    float robot_joints[kJoints] = {0,0,0,0,0,0};
    set_joint_angles(robot_joints);
    return 0;
}
