// Context: Proportional gain parameter — Expanded program

// ------ Non-Compliant Program (079_nc.cpp)
// Context: Proportional gain Kp
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _kp_rule_079 {

static float _limit(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 1000.0F) { return 1000.0F; }
    return v;
}

static void _show(float _kp) { // NC
    std::cout << std::fixed << std::setprecision(2)
              << "Kp=" << _limit(_kp) << std::endl;
}

static void _scan(const std::vector<float>& _vals) {
    for (float v : _vals) { _show(v); }
}

} // namespace _kp_rule_079

int main() {
    using namespace _kp_rule_079;
    std::vector<float> vals = {1.0F, -5.0F, 5000.0F};
    _scan(vals);
    return 0;
}
