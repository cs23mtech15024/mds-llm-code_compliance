// Context: Motor control speed helper function — Expanded program

// ------ Non-Compliant Program (005_nc.cpp)
// Context: RPM calculation utility
// NC: function and helpers start with '_'
#include <iostream>
#include <vector>

namespace _mc_rule_005 {

static float _mul60(float v) {
    return v * 60.0F;
}

static float _calculate_rpm(float _freq) {
    return _mul60(_freq);
}

static void _report(const std::vector<float> &_freqs) {
    for (float f : _freqs) {
        std::cout << "rpm=" << _calculate_rpm(f) << std::endl;
    }
}

} // namespace _mc_rule_005

int main() {
    using namespace _mc_rule_005;
    std::vector<float> freqs = {10.0F, 25.0F, 50.0F};
    _report(freqs);
    return 0;
}
