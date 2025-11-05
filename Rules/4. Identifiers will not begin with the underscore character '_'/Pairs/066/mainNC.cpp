// Context: Smoothing filter alpha value — Expanded program

// ------ Non-Compliant Program (066_nc.cpp)
// Context: Show smoothing factor alpha
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _alpha_rule_066 {

static float _clip01(float a) {
    if (a < 0.0F) { return 0.0F; }
    if (a > 1.0F) { return 1.0F; }
    return a;
}

static void _show(float _alpha) { // NC
    std::cout << std::fixed << std::setprecision(2)
              << "alpha=" << _clip01(_alpha) << std::endl;
}

static void _scan(const std::vector<float>& _vals) {
    for (float v : _vals) { _show(v); }
}

} // namespace _alpha_rule_066

int main() {
    using namespace _alpha_rule_066;
    std::vector<float> vals = {-0.2F, 0.3F, 1.7F};
    _scan(vals);
    return 0;
}
