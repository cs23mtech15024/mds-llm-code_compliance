// Context: Quality factor (Q) for resonance — Expanded program

// ------ Non-Compliant Program (073_nc.cpp)
// Context: Print Q factor
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _q_rule_073 {

static float _clipQ(float q) {
    if (q < 0.1F) { return 0.1F; }
    if (q > 20.0F) { return 20.0F; }
    return q;
}

static void _emit(float _q_factor) { // NC
    std::cout << std::fixed << std::setprecision(2)
              << "Q=" << _clipQ(_q_factor) << std::endl;
}

static void _scan(const std::vector<float>& _v) {
    for (float q : _v) { _emit(q); }
}

} // namespace _q_rule_073

int main() {
    using namespace _q_rule_073;
    std::vector<float> vals = {2.5F, 0.01F, 30.0F};
    _scan(vals);
    return 0;
}
