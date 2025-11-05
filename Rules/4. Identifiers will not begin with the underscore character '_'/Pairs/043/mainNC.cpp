// Context: Frequency response analyzer — Expanded program

// ------ Non-Compliant Program (043_nc.cpp)
// Context: Compute period from Hz
// MISRA: Identifiers must not begin with '_'
// NC: function and parameter begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _freq_rule_043 {

static float _protect(float v) {
    if (v <= 0.0F) { return 1.0F; }
    return v;
}

static float _analyze_freq(float _hz) { // NC
    float hz = _protect(_hz);
    return 1.0F / hz;
}

static void _table(const std::vector<float> &_hzs) {
    for (float h : _hzs) {
        std::cout << std::fixed << std::setprecision(6)
                  << "Hz=" << h << " period=" << _analyze_freq(h) << "s" << std::endl;
    }
}

} // namespace _freq_rule_043

int main() {
    using namespace _freq_rule_043;
    std::vector<float> hz = {0.0F, 1.0F, 1000.0F};
    _table(hz);
    return 0;
}
