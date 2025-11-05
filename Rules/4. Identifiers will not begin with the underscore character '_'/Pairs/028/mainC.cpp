// Context: Angle conversion degrees to radians — Expanded program

// ------ Compliant Program (028_c.cpp)
// Context: Degrees -> radians converter
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace ang_rule_028 {

static float k() { return 0.0174533F; }

static float deg_to_rad(float degrees) {
    return degrees * k();
}

static void table(const std::vector<float> &d) {
    for (float v : d) {
        std::cout << std::fixed << std::setprecision(6)
                  << v << "deg -> " << deg_to_rad(v) << "rad" << std::endl;
    }
}

} // namespace ang_rule_028

int main() {
    using namespace ang_rule_028;
    std::vector<float> d = {0.0F, 90.0F, 180.0F};
    table(d);
    return 0;
}
