// Context: Output clamp min value — Expanded program

// ------ Compliant Program (084_c.cpp)
// Context: Enforce minimum actuator command magnitude
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace omin_rule_084 {

static float lift(float v, float output_min) {
    if (v == 0.0F) { return 0.0F; }
    float s = (v > 0.0F) ? 1.0F : -1.0F;
    float a = (v > 0.0F) ? v : -v;
    if (a < output_min) { a = output_min; }
    return s * a;
}

static void scan(const std::vector<float>& vals, float output_min) {
    for (float v : vals) {
        std::cout << std::fixed << std::setprecision(2)
                  << "in=" << v << " out=" << lift(v, output_min) << std::endl;
    }
}

} // namespace omin_rule_084

int main() {
    using namespace omin_rule_084;
    std::vector<float> vals = {0.0F, 0.5F, -0.2F, 10.0F};
    scan(vals, 1.0F);
    return 0;
}
