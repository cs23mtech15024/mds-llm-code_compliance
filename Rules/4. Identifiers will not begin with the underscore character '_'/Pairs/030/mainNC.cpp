// Context: Gain coefficient adjuster — Expanded program

// ------ Non-Compliant Program (030_nc.cpp)
// Context: Multiply signal with gain
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _gain_rule_030 {

static float _apply(float s, float g) { return s * g; }

static void _print(float signal, float _gain) { // NC
    std::cout << std::fixed << std::setprecision(2)
              << "output=" << _apply(signal, _gain) << std::endl;
}

static void _sweep(const std::vector<float> &_gains) {
    float signal = 100.0F;
    for (float g : _gains) { _print(signal, g); }
}

} // namespace _gain_rule_030

int main() {
    using namespace _gain_rule_030;
    std::vector<float> gains = {0.5F, 1.5F, 2.0F};
    _sweep(gains);
    return 0;
}
