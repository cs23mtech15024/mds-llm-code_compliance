// Context: Altitude compensation factor — Expanded program

// ------ Non-Compliant Program (022_nc.cpp)
// Context: Linear altitude compensation demo
// MISRA: Identifiers must not begin with '_'
// NC: variable and helpers begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _alt_rule_022 {

static float _limit(float v, float lo, float hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static float _comp(float _altitude_m) { // NC
    float k = 1.0F - (_altitude_m / 10000.0F);
    return _limit(k, 0.5F, 1.0F);
}

static void _report(const std::vector<float> &_alts) {
    for (float a : _alts) {
        std::cout << std::fixed << std::setprecision(3)
                  << "alt=" << a << "m comp=" << _comp(a) << std::endl;
    }
}

} // namespace _alt_rule_022

int main() {
    using namespace _alt_rule_022;
    std::vector<float> alts = {0.0F, 1500.0F, 8000.0F, 12000.0F};
    _report(alts);
    return 0;
}
