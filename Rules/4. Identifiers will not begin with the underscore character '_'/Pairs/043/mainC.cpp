// Context: Frequency response analyzer — Expanded program

// ------ Compliant Program (043_c.cpp)
// Context: Compute period from Hz
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace freq_rule_043 {

static float protect(float v) {
    if (v <= 0.0F) { return 1.0F; }
    return v;
}

static float analyze_freq(float hz) {
    float h = protect(hz);
    return 1.0F / h;
}

static void table(const std::vector<float> &hzs) {
    for (float h : hzs) {
        std::cout << std::fixed << std::setprecision(6)
                  << "Hz=" << h << " period=" << analyze_freq(h) << "s" << std::endl;
    }
}

} // namespace freq_rule_043

int main() {
    using namespace freq_rule_043;
    std::vector<float> hz = {0.0F, 1.0F, 1000.0F};
    table(hz);
    return 0;
}
