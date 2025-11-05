// Context: Setpoint value holder — Expanded program

// ------ Non-Compliant Program (080_nc.cpp)
// Context: Store and print setpoint
// MISRA: Identifiers must not begin with '_'
// NC: variable and funcs begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _sp_rule_080 {

static float _clip(float sp) {
    if (sp < -1000.0F) { return -1000.0F; }
    if (sp > 1000.0F) { return 1000.0F; }
    return sp;
}

static void _set(float &_setpoint, float v) { // NC
    _setpoint = _clip(v);
}

static void _print(float _setpoint) { // NC
    std::cout << std::fixed << std::setprecision(2)
              << "sp=" << _setpoint << std::endl;
}

static void _demo(const std::vector<float>& _vals) {
    float _setpoint = 25.0F; // NC
    for (float v : _vals) { _set(_setpoint, v); _print(_setpoint); }
}

} // namespace _sp_rule_080

int main() {
    using namespace _sp_rule_080;
    std::vector<float> vals = {25.0F, -1200.0F, 555.5F};
    _demo(vals);
    return 0;
}
