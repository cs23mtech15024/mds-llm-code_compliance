// Context: Derivative gain parameter — Expanded program

// ------ Non-Compliant Program (077_nc.cpp)
// Context: Derivative gain Kd
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _kd_rule_077 {

static float _clip(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 10.0F) { return 10.0F; }
    return v;
}

static void _show(float _kd) { // NC
    std::cout << std::fixed << std::setprecision(3)
              << "Kd=" << _clip(_kd) << std::endl;
}

static void _scan(const std::vector<float>& _vals) {
    for (float v : _vals) { _show(v); }
}

} // namespace _kd_rule_077

int main() {
    using namespace _kd_rule_077;
    std::vector<float> vals = {0.01F, -0.5F, 50.0F};
    _scan(vals);
    return 0;
}
