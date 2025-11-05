// Context: Altitude compensation factor — Expanded program

// ------ Compliant Program (022_c.cpp)
// Context: Linear altitude compensation demo
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace alt_rule_022 {

static float limit(float v, float lo, float hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static float comp(float altitude_m) {
    float k = 1.0F - (altitude_m / 10000.0F);
    return limit(k, 0.5F, 1.0F);
}

static void report(const std::vector<float> &alts) {
    for (float a : alts) {
        std::cout << std::fixed << std::setprecision(3)
                  << "alt=" << a << "m comp=" << comp(a) << std::endl;
    }
}

} // namespace alt_rule_022

int main() {
    using namespace alt_rule_022;
    std::vector<float> alts = {0.0F, 1500.0F, 8000.0F, 12000.0F};
    report(alts);
    return 0;
}
