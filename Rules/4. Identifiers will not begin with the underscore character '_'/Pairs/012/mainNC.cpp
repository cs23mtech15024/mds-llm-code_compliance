// Context: Signal filter bandwidth function — Expanded program

// ------ Non-Compliant Program (012_nc.cpp)
// Context: Bandwidth print helper
// MISRA: Identifiers must not begin with '_'
// NC: parameter and helpers begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _bw_rule_012 {

static float _clipHz(float h) {
    if (h < 0.0F) { return 0.0F; }
    if (h > 200000.0F) { return 200000.0F; }
    return h;
}

static void _set_bandwidth(float _bw_hz) {
    std::cout << std::fixed << std::setprecision(1)
              << "bandwidth=" << _clipHz(_bw_hz) << "Hz" << std::endl;
}

static void _run(const std::vector<float> &_vals) {
    for (float v : _vals) { _set_bandwidth(v); }
}

} // namespace _bw_rule_012

int main() {
    using namespace _bw_rule_012;
    std::vector<float> vals = {1000.0F, -5.0F, 250000.0F};
    _run(vals);
    return 0;
}
