// Context: Pressure sensor scaling function — Expanded program

// ------ Non-Compliant Program (015_nc.cpp)
// Context: Scale raw ADC to pressure
// MISRA: Identifiers must not begin with '_'
// NC: function and args begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _prs_rule_015 {

static float _mul(float a, float b) { return a * b; }

static float _scale_pressure(float _raw, float _factor) {
    return _mul(_raw, _factor);
}

static void _show(const std::vector<float> &_raws, float _factor) {
    for (float r : _raws) {
        std::cout << std::fixed << std::setprecision(3)
                  << _scale_pressure(r, _factor) << std::endl;
    }
}

} // namespace _prs_rule_015

int main() {
    using namespace _prs_rule_015;
    std::vector<float> raws = {1023.0F, 512.0F, 256.0F};
    _show(raws, 0.1F);
    return 0;
}
