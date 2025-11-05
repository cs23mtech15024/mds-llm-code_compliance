// Context: Attack time envelope parameter — Expanded program

// ------ Non-Compliant Program (070_nc.cpp)
// Context: Attack time in ms
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _atk_rule_070 {

static float _clip(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 10000.0F) { return 10000.0F; }
    return v;
}

static void _emit(float _attack_ms) { // NC
    std::cout << std::fixed << std::setprecision(1)
              << "attack=" << _clip(_attack_ms) << "ms" << std::endl;
}

static void _run(const std::vector<float>& _vals) {
    for (float v : _vals) { _emit(v); }
}

} // namespace _atk_rule_070

int main() {
    using namespace _atk_rule_070;
    std::vector<float> vals = {10.0F, -5.0F, 20000.0F};
    _run(vals);
    return 0;
}
