// Context: Robotic arm kinematics parameters

// -------- Compliant Program (prog_002_c.cpp)
// Context: Robotic arm kinematics
// COMPLIANT: Only includes declarations. Definitions placed in this TU.
#include <iostream>
#include <cmath>
#include "seedC.h"  // extern seed002_link1, seed002_link2, seed002_calc_reach()

// Provide definitions
double seed002_link1 = 0.55;
double seed002_link2 = 0.40;
double seed002_calc_reach() { return seed002_link1 + seed002_link2; }

namespace kinematics_c {

template <typename T>
T compute_joint_extension(T theta) {
    double r = seed002_calc_reach();
    return r * std::cos(theta);
}

template <typename T>
T compute_projection(T theta) {
    return seed002_link1 * std::sin(theta) + seed002_link2 * std::cos(theta);
}

template <std::size_t N>
void simulate(const double (&angles)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        double a = angles[i];
        std::cout << "theta=" << a
                  << " proj=" << compute_projection(a)
                  << " ext=" << compute_joint_extension(a) << "\n";
    }
}

} // namespace kinematics_c

int main() {
    using namespace kinematics_c;
    const double thetas[4] = {0.0, 0.25, 0.5, 0.75};
    simulate(thetas);
    return 0;
}
