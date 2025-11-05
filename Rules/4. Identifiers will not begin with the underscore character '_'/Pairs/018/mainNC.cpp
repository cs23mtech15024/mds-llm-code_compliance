// Context: PWM duty cycle calculator — Expanded program

// ------ Non-Compliant Program (018_nc.cpp)
// Context: Map percentage to 8-bit PWM
// MISRA: Identifiers must not begin with '_'
// NC: function begins with '_'
#include <iostream>
#include <cstdint>
#include <vector>

namespace _pwm_rule_018 {

static std::uint8_t _clip8(int v) {
    if (v < 0) { return 0U; }
    if (v > 255) { return 255U; }
    return static_cast<std::uint8_t>(v);
}

static int _calc_duty_cycle(float percent) {
    int x = static_cast<int>(percent * 255.0F / 100.0F);
    return static_cast<int>(_clip8(x));
}

static void _show(const std::vector<float> &_p) {
    for (float v : _p) { std::cout << "duty=" << _calc_duty_cycle(v) << std::endl; }
}

} // namespace _pwm_rule_018

int main() {
    using namespace _pwm_rule_018;
    std::vector<float> p = {0.0F, 50.0F, 75.0F, 100.0F};
    _show(p);
    return 0;
}
