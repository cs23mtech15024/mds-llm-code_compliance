// Context: Coordinate transform X-axis — Expanded program

// ------ Non-Compliant Program (057_nc.cpp)
// Context: Translate x by offset
// MISRA: Identifiers must not begin with '_'
// NC: function begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _tx_rule_057 {

static float _clipOff(float o) {
    if (o < -1000.0F) { return -1000.0F; }
    if (o > 1000.0F) { return 1000.0F; }
    return o;
}

static float _transform_x(float x, float offset) { // NC
    return x + _clipOff(offset);
}

static void _apply(const std::vector<float>& _xs, float _off) {
    for (float x : _xs) {
        std::cout << std::fixed << std::setprecision(2)
                  << "x'=" << _transform_x(x, _off) << std::endl;
    }
}

} // namespace _tx_rule_057

int main() {
    using namespace _tx_rule_057;
    std::vector<float> xs = {10.0F, -5.0F, 100.0F};
    _apply(xs, 5.0F);
    return 0;
}
