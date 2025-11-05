// Context: PWM duty cycle calculator — Expanded program

// ------ Compliant Program (018_c.cpp)
// Context: Map percentage to 8-bit PWM
// C: identifiers do not begin with '_'
#include <iostream>
#include <cstdint>
#include <vector>

namespace pwm_rule_018 {

static std::uint8_t clip8(int v) {
    if (v < 0) { return 0U; }
    if (v > 255) { return 255U; }
    return static_cast<std::uint8_t>(v);
}

static int calc_duty_cycle(float percent) {
    int x = static_cast<int>(percent * 255.0F / 100.0F);
    return static_cast<int>(clip8(x));
}

static void show(const std::vector<float> &p) {
    for (float v : p) { std::cout << "duty=" << calc_duty_cycle(v) << std::endl; }
}

} // namespace pwm_rule_018

int main() {
    using namespace pwm_rule_018;
    std::vector<float> p = {0.0F, 50.0F, 75.0F, 100.0F};
    show(p);
    return 0;
}
