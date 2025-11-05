// Context: Slew rate limit calculator — Expanded program

// ------ Non-Compliant Program (064_nc.cpp)
// Context: slew = delta/time
// MISRA: Identifiers must not begin with '_'
// NC: function begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _slew_rule_064 {

static float _safeTime(float t) {
    return (t <= 0.0F) ? 1.0F : t;
}

static float _calc_slew_rate(float delta, float time) { // NC
    return delta / _safeTime(time);
}

static void _table(const std::vector<std::pair<float,float>>& _cases) {
    for (const auto &p : _cases) {
        std::cout << std::fixed << std::setprecision(2)
                  << "slew=" << _calc_slew_rate(p.first, p.second) << std::endl;
    }
}

} // namespace _slew_rule_064

int main() {
    using namespace _slew_rule_064;
    std::vector<std::pair<float,float>> cases = {{10.0F,0.1F},{-5.0F,0.0F}};
    _table(cases);
    return 0;
}
