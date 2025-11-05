// Context: Deadband region width — Expanded program

// ------ Non-Compliant Program (074_nc.cpp)
// Context: Deadband width around zero
// MISRA: Identifiers must not begin with '_'
// NC: variable and helpers begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _db_rule_074 {

static float _clip01(float x) {
    if (x < 0.0F) { return 0.0F; }
    if (x > 1.0F) { return 1.0F; }
    return x;
}

static float _apply(float v, float _deadband) { // NC
    float d = _clip01(_deadband);
    if (v > d) { return v - d; }
    if (v < -d) { return v + d; }
    return 0.0F;
}

static void _scan(const std::vector<float>& _vals, float _deadband) {
    for (float x : _vals) {
        std::cout << std::fixed << std::setprecision(3)
                  << "in=" << x << " out=" << _apply(x, _deadband) << std::endl;
    }
}

} // namespace _db_rule_074

int main() {
    using namespace _db_rule_074;
    std::vector<float> vals = {-0.2F, -0.05F, 0.0F, 0.07F, 0.4F};
    _scan(vals, 0.05F);
    return 0;
}
