// Context: Feedforward gain coefficient — Expanded program

// ------ Non-Compliant Program (075_nc.cpp)
// Context: Feedforward coefficient
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _ff_rule_075 {

static float _limit(float g) {
    if (g < 0.0F) { return 0.0F; }
    if (g > 10.0F) { return 10.0F; }
    return g;
}

static void _emit(float _ff_gain) { // NC
    std::cout << std::fixed << std::setprecision(2)
              << "ff=" << _limit(_ff_gain) << std::endl;
}

static void _scan(const std::vector<float>& _vals) {
    for (float g : _vals) { _emit(g); }
}

} // namespace _ff_rule_075

int main() {
    using namespace _ff_rule_075;
    std::vector<float> vals = {1.2F, -1.0F, 24.0F};
    _scan(vals);
    return 0;
}
