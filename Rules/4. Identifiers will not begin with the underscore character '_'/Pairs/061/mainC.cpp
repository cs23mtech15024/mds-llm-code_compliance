// Context: Hysteresis threshold value — Expanded program

// ------ Compliant Program (061_c.cpp)
// Context: Apply simple hysteresis to a signal
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace hyst_rule_061 {

static float apply(float v, float center, float hysteresis) {
    float hi = center + hysteresis;
    float lo = center - hysteresis;
    if (v > hi) { return 1.0F; }
    if (v < lo) { return 0.0F; }
    return 0.5F;
}

static void scan(const std::vector<float>& vals, float center, float hysteresis) {
    for (float x : vals) {
        std::cout << std::fixed << std::setprecision(2)
                  << "x=" << x << " y=" << apply(x, center, hysteresis) << std::endl;
    }
}

} // namespace hyst_rule_061

int main() {
    using namespace hyst_rule_061;
    std::vector<float> vals = {0.0F, 0.08F, 0.1F, 0.12F, -0.1F};
    scan(vals, 0.0F, 0.1F);
    return 0;
}
