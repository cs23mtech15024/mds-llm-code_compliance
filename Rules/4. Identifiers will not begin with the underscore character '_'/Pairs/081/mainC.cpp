// Context: Error accumulator variable — Expanded program

// ------ Compliant Program (081_c.cpp)
// Context: Integrate error over time for a controller
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace err_rule_081 {

static float clamp(float v, float lo, float hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static void accumulate(float &error_sum, float sample, float dt) {
    error_sum += sample * dt;
    error_sum = clamp(error_sum, -1000.0F, 1000.0F);
}

static void run(const std::vector<float> &samples, float dt) {
    float error_sum = 0.0F;
    for (float e : samples) {
        accumulate(error_sum, e, dt);
        std::cout << std::fixed << std::setprecision(3)
                  << "err_sum=" << error_sum << std::endl;
    }
}

} // namespace err_rule_081

int main() {
    using namespace err_rule_081;
    std::vector<float> s = {0.5F, -0.2F, 0.3F, 0.1F};
    run(s, 0.5F);
    return 0;
}
