// Context: Phase shift calculator — Expanded program

// ------ Non-Compliant Program (050_nc.cpp)
// Context: Print phase in degrees
// MISRA: Identifiers must not begin with '_'
// NC: variable and helpers begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _ph_rule_050 {

static float _wrap(float d) {
    while (d >= 360.0F) { d -= 360.0F; }
    while (d < 0.0F) { d += 360.0F; }
    return d;
}

static void _print(float _phase_deg) { // NC
    std::cout << std::fixed << std::setprecision(1)
              << "phase=" << _wrap(_phase_deg) << " degrees" << std::endl;
}

static void _run(const std::vector<float> &_vals) {
    for (float v : _vals) { _print(v); }
}

} // namespace _ph_rule_050

int main() {
    using namespace _ph_rule_050;
    std::vector<float> vals = {45.0F, -30.0F, 765.0F};
    _run(vals);
    return 0;
}
