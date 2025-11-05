// Context: Output clamp min value — Expanded program

// ------ Non-Compliant Program (084_nc.cpp)
// Context: Enforce minimum actuator command magnitude
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _omin_rule_084 {

static float _lift(float v, float _output_min) { // NC
    if (v == 0.0F) { return 0.0F; }
    float s = (v > 0.0F) ? 1.0F : -1.0F;
    float a = (v > 0.0F) ? v : -v;
    if (a < _output_min) { a = _output_min; }
    return s * a;
}

static void _scan(const std::vector<float>& _vals, float _output_min) {
    for (float v : _vals) {
        std::cout << std::fixed << std::setprecision(2)
                  << "in=" << v << " out=" << _lift(v, _output_min) << std::endl;
    }
}

} // namespace _omin_rule_084

int main() {
    using namespace _omin_rule_084;
    std::vector<float> vals = {0.0F, 0.5F, -0.2F, 10.0F};
    _scan(vals, 1.0F);
    return 0;
}
