// Context: Amplitude envelope detector — Expanded program

// ------ Compliant Program (045_c.cpp)
// Context: Peak absolute value
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace peak_rule_045 {

static float absf(float v) { return (v >= 0.0F) ? v : -v; }

static float detect_peak(float sample) {
    return absf(sample);
}

static void scan(const std::vector<float> &v) {
    for (float s : v) {
        std::cout << std::fixed << std::setprecision(3)
                  << "in=" << s << " peak=" << detect_peak(s) << std::endl;
    }
}

} // namespace peak_rule_045

int main() {
    using namespace peak_rule_045;
    std::vector<float> v = {-0.85F, 0.12F, -1.23F};
    scan(v);
    return 0;
}
