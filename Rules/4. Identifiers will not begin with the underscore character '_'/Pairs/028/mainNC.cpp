// Context: Angle conversion degrees to radians — Expanded program

// ------ Non-Compliant Program (028_nc.cpp)
// Context: Degrees -> radians converter
// MISRA: Identifiers must not begin with '_'
// NC: function and parameter begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _ang_rule_028 {

static float _k() { return 0.0174533F; }

static float _deg_to_rad(float _degrees) { // NC
    return _degrees * _k();
}

static void _table(const std::vector<float> &_d) {
    for (float v : _d) {
        std::cout << std::fixed << std::setprecision(6)
                  << v << "deg -> " << _deg_to_rad(v) << "rad" << std::endl;
    }
}

} // namespace _ang_rule_028

int main() {
    using namespace _ang_rule_028;
    std::vector<float> d = {0.0F, 90.0F, 180.0F};
    _table(d);
    return 0;
}
