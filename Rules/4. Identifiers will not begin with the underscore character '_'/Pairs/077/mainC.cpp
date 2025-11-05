// Context: Derivative gain parameter — Expanded program

// ------ Compliant Program (077_c.cpp)
// Context: Derivative gain Kd
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace kd_rule_077 {

static float clip(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 10.0F) { return 10.0F; }
    return v;
}

static void show(float kd) {
    std::cout << std::fixed << std::setprecision(3)
              << "Kd=" << clip(kd) << std::endl;
}

static void scan(const std::vector<float>& vals) {
    for (float v : vals) { show(v); }
}

} // namespace kd_rule_077

int main() {
    using namespace kd_rule_077;
    std::vector<float> vals = {0.01F, -0.5F, 50.0F};
    scan(vals);
    return 0;
}
