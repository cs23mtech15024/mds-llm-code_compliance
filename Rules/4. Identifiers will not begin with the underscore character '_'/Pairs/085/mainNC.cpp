// Context: Sample time period — Expanded program

// ------ Non-Compliant Program (085_nc.cpp)
// Context: Sample period configuration
// MISRA: Identifiers must not begin with '_'
// NC: variable and helper begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _dt_rule_085 {

static float _sanitize(float dt) {
    if (dt < 0.0001F) { return 0.0001F; }
    if (dt > 1.0F) { return 1.0F; }
    return dt;
}

static void _apply(float _sample_time) { // NC
    std::cout << std::fixed << std::setprecision(5)
              << "dt=" << _sanitize(_sample_time) << "s" << std::endl;
}

static void _scan(const std::vector<float>& _vals) {
    for (float v : _vals) { _apply(v); }
}

} // namespace _dt_rule_085

int main() {
    using namespace _dt_rule_085;
    std::vector<float> vals = {0.01F, 0.0F, 2.0F};
    _scan(vals);
    return 0;
}
