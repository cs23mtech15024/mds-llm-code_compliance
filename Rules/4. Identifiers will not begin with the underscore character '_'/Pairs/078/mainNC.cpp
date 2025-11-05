// Context: Integral gain parameter — Expanded program

// ------ Non-Compliant Program (078_nc.cpp)
// Context: Integral gain Ki
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _ki_rule_078 {

static float _bound(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 100.0F) { return 100.0F; }
    return v;
}

static void _show(float _ki) { // NC
    std::cout << std::fixed << std::setprecision(2)
              << "Ki=" << _bound(_ki) << std::endl;
}

static void _scan(const std::vector<float>& _vals) {
    for (float v : _vals) { _show(v); }
}

} // namespace _ki_rule_078

int main() {
    using namespace _ki_rule_078;
    std::vector<float> vals = {0.1F, -3.0F, 500.0F};
    _scan(vals);
    return 0;
}
