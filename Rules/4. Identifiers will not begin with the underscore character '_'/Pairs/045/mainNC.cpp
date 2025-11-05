// Context: Amplitude envelope detector — Expanded program

// ------ Non-Compliant Program (045_nc.cpp)
// Context: Peak absolute value
// MISRA: Identifiers must not begin with '_'
// NC: function begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _peak_rule_045 {

static float _absf(float v) { return (v >= 0.0F) ? v : -v; }

static float _detect_peak(float sample) { // NC
    return _absf(sample);
}

static void _scan(const std::vector<float> &_v) {
    for (float s : _v) {
        std::cout << std::fixed << std::setprecision(3)
                  << "in=" << s << " peak=" << _detect_peak(s) << std::endl;
    }
}

} // namespace _peak_rule_045

int main() {
    using namespace _peak_rule_045;
    std::vector<float> v = {-0.85F, 0.12F, -1.23F};
    _scan(v);
    return 0;
}
