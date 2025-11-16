// Context: Robotic joint angle commands

// ------ Compliant Program (061_c.cpp)
// Context: Robotic joint angle commands
// Rule: Preserve array type via reference (COMPLIANT)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace robot_061_c {

constexpr std::size_t kJoints = 6U;

static void clamp_deg(float &v, float lo, float hi) {
    if (v < lo) v = lo; else if (v > hi) v = hi;
}

template <std::size_t N>
static void set_first_joint(float (&angles)[N], float deg) {
    static_assert(N == 6U, "require 6 joints");
    angles[0] = deg;
    clamp_deg(angles[0], -180.0F, 180.0F);
}

template <std::size_t N>
static void dump_head(const float (&angles)[N], std::size_t count) {
    for (std::size_t i = 0; i < count && i < N; ++i) {
        std::cout << (i?" ":"") << std::fixed << std::setprecision(1) << angles[i];
    }
    std::cout << "\n";
}

void set_joint_angles(float (&angles)[kJoints]) { // C API
    angles[1] = 10.0F;
    set_first_joint(angles, 30.0F);
    std::cout << "joint0=" << angles[0] << " joint1=" << angles[1] << "\n";
    dump_head(angles, 3U);
}

} // namespace robot_061_c

int main() {
    using namespace robot_061_c;
    float robot_joints[kJoints] = {0,0,0,0,0,0};
    set_joint_angles(robot_joints);
    return 0;
}
