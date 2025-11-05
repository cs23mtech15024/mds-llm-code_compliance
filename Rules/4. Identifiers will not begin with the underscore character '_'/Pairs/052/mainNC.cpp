// Context: Exponential moving average — Expanded program

// ------ Non-Compliant Program (052_nc.cpp)
// Context: EMA update stream
// MISRA: Identifiers must not begin with '_'
// NC: function and parameters begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _ema_rule_052 {

static float _clamp01(float x) {
    if (x < 0.0F) { return 0.0F; }
    if (x > 1.0F) { return 1.0F; }
    return x;
}

static float _ema_update(float _prev, float _new_val, float _alpha) { // NC
    float a = _clamp01(_alpha);
    return a * _new_val + (1.0F - a) * _prev;
}

static void _process(const std::vector<float>& _vals, float _alpha) {
    float y = 0.0F;
    for (float v : _vals) {
        y = _ema_update(y, v, _alpha);
        std::cout << std::fixed << std::setprecision(3)
                  << "in=" << v << " ema=" << y << std::endl;
    }
}

} // namespace _ema_rule_052

int main() {
    using namespace _ema_rule_052;
    std::vector<float> v = {100.0F, 105.0F, 103.0F, 110.0F};
    _process(v, 0.2F);
    return 0;
}
