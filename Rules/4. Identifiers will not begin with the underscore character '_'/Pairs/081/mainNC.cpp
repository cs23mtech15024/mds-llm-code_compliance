// Context: Error accumulator variable — Expanded program

// ------ Non-Compliant Program (081_nc.cpp)
// Context: Integrate error over time for a controller
// MISRA: Identifiers must not begin with '_'
// NC: variable and helpers begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _err_rule_081 {

static float _clamp(float v, float lo, float hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static void _accumulate(float &_error_sum, float sample, float dt) { // NC
    _error_sum += sample * dt;
    _error_sum = _clamp(_error_sum, -1000.0F, 1000.0F);
}

static void _run(const std::vector<float> &_samples, float dt) {
    float _error_sum = 0.0F; // NC
    for (float e : _samples) {
        _accumulate(_error_sum, e, dt);
        std::cout << std::fixed << std::setprecision(3)
                  << "err_sum=" << _error_sum << std::endl;
    }
}

} // namespace _err_rule_081

int main() {
    using namespace _err_rule_081;
    std::vector<float> s = {0.5F, -0.2F, 0.3F, 0.1F};
    _run(s, 0.5F);
    return 0;
}
