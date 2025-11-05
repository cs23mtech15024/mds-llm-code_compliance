// Context: Proportional gain parameter — Expanded program

// ------ Compliant Program (079_c.cpp)
// Context: Proportional gain Kp
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace kp_rule_079 {

static float limit(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 1000.0F) { return 1000.0F; }
    return v;
}

static void show(float kp) {
    std::cout << std::fixed << std::setprecision(2)
              << "Kp=" << limit(kp) << std::endl;
}

static void scan(const std::vector<float>& vals) {
    for (float v : vals) { show(v); }
}

} // namespace kp_rule_079

int main() {
    using namespace kp_rule_079;
    std::vector<float> vals = {1.0F, -5.0F, 5000.0F};
    scan(vals);
    return 0;
}
