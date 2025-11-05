// Context: Hysteresis threshold value — Expanded program

// ------ Non-Compliant Program (061_nc.cpp)
// Context: Apply simple hysteresis to a signal
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _hyst_rule_061 {

static float _apply(float v, float center, float _hysteresis) { // NC
    float hi = center + _hysteresis;
    float lo = center - _hysteresis;
    if (v > hi) { return 1.0F; }
    if (v < lo) { return 0.0F; }
    return 0.5F; // indeterminate zone
}

static void _scan(const std::vector<float>& _vals, float center, float _hysteresis) {
    for (float x : _vals) {
        std::cout << std::fixed << std::setprecision(2)
                  << "x=" << x << " y=" << _apply(x, center, _hysteresis) << std::endl;
    }
}

} // namespace _hyst_rule_061

int main() {
    using namespace _hyst_rule_061;
    std::vector<float> vals = {0.0F, 0.08F, 0.1F, 0.12F, -0.1F};
    _scan(vals, 0.0F, 0.1F);
    return 0;
}
