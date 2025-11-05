// Context: Gain coefficient adjuster — Expanded program

// ------ Compliant Program (030_c.cpp)
// Context: Multiply signal with gain
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace gain_rule_030 {

static float apply(float s, float g) { return s * g; }

static void print(float signal, float gain) {
    std::cout << std::fixed << std::setprecision(2)
              << "output=" << apply(signal, gain) << std::endl;
}

static void sweep(const std::vector<float> &gains) {
    float signal = 100.0F;
    for (float g : gains) { print(signal, g); }
}

} // namespace gain_rule_030

int main() {
    using namespace gain_rule_030;
    std::vector<float> gains = {0.5F, 1.5F, 2.0F};
    sweep(gains);
    return 0;
}
