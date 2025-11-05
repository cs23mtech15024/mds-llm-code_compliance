// Context: Velocity limit checker — Expanded program

// ------ Non-Compliant Program (023_nc.cpp)
// Context: Velocity <= limit check
// MISRA: Identifiers must not begin with '_'
// NC: function begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _vel_rule_023 {

static float _clip(float v, float lo, float hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static bool _check_velocity_limit(float vel, float limit) { // NC
    float v = _clip(vel, -1000.0F, 1000.0F);
    float L = _clip(limit, 0.0F, 1000.0F);
    return v <= L;
}

static void _scan(const std::vector<float> &_v, float _limit) {
    for (float x : _v) {
        std::cout << std::fixed << std::setprecision(2)
                  << "v=" << x << " ok=" << _check_velocity_limit(x, _limit) << std::endl;
    }
}

} // namespace _vel_rule_023

int main() {
    using namespace _vel_rule_023;
    std::vector<float> vel = {10.0F, 45.0F, 55.0F};
    _scan(vel, 50.0F);
    return 0;
}
