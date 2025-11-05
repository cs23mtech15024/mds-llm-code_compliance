// Context: Output clamp max value — Expanded program

// ------ Non-Compliant Program (083_nc.cpp)
// Context: Enforce maximum actuator command
// MISRA: Identifiers must not begin with '_'
// NC: variable and helpers begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _omax_rule_083 {

static float _limit(float v, float _output_max) { // NC
    if (v > _output_max) { return _output_max; }
    if (v < -_output_max) { return -_output_max; }
    return v;
}

static void _scan(const std::vector<float>& _vals, float _output_max) {
    for (float v : _vals) {
        std::cout << std::fixed << std::setprecision(2)
                  << "in=" << v << " out=" << _limit(v, _output_max) << std::endl;
    }
}

} // namespace _omax_rule_083

int main() {
    using namespace _omax_rule_083;
    std::vector<float> vals = {50.0F, 120.0F, -200.0F};
    _scan(vals, 100.0F);
    return 0;
}
