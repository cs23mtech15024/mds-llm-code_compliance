// Context: Motor control speed helper function — Expanded program

// ------ Compliant Program (005_c.cpp)
// Context: RPM calculation utility
// C: compliant identifiers
#include <iostream>
#include <vector>

namespace mc_rule_005 {

static float mul60(float v) {
    return v * 60.0F;
}

static float calculate_rpm(float freq) {
    return mul60(freq);
}

static void report(const std::vector<float> &freqs) {
    for (float f : freqs) {
        std::cout << "rpm=" << calculate_rpm(f) << std::endl;
    }
}

} // namespace mc_rule_005

int main() {
    using namespace mc_rule_005;
    std::vector<float> freqs = {10.0F, 25.0F, 50.0F};
    report(freqs);
    return 0;
}
