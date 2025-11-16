// Context: Robotic arm kinematics parameters

// -------- Non-Compliant Program (prog_002_nc.cpp)
// Context: Robotic arm kinematics
// Rule violated: Header defines variables + function bodies
#include <iostream>
#include <cmath>
#include "seedNC.h"  // seed002_link1, seed002_link2, seed002_calc_reach()

namespace kinematics_nc {

double compute_joint_extension(double theta) {
    double r = seed002_calc_reach(); // uses NC definition from header
    return r * std::cos(theta);
}

double compute_projection(double theta) {
    return seed002_link1 * std::sin(theta) + seed002_link2 * std::cos(theta);
}

void simulate(double angles[], std::size_t n) { // NC: decayed array
    for (std::size_t i = 0; i < n; ++i) {
        double a = angles[i];
        std::cout << "theta=" << a
                  << " proj=" << compute_projection(a)
                  << " ext=" << compute_joint_extension(a) << "\n";
    }
}

} // namespace kinematics_nc

int main() {
    using namespace kinematics_nc;
    double thetas[4] = {0.0, 0.25, 0.5, 0.75};
    simulate(thetas, 4);
    return 0;
}
