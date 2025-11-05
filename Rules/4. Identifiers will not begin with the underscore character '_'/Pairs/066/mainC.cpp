// Context: Smoothing filter alpha value — Expanded program

// ------ Compliant Program (066_c.cpp)
// Context: Show smoothing factor alpha
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace alpha_rule_066 {

static float clip01(float a) {
    if (a < 0.0F) { return 0.0F; }
    if (a > 1.0F) { return 1.0F; }
    return a;
}

static void show(float alpha) {
    std::cout << std::fixed << std::setprecision(2)
              << "alpha=" << clip01(alpha) << std::endl;
}

static void scan(const std::vector<float>& vals) {
    for (float v : vals) { show(v); }
}

} // namespace alpha_rule_066

int main() {
    using namespace alpha_rule_066;
    std::vector<float> vals = {-0.2F, 0.3F, 1.7F};
    scan(vals);
    return 0;
}
