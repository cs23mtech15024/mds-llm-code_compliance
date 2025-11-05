// Context: Deadband region width — Expanded program

// ------ Compliant Program (074_c.cpp)
// Context: Deadband width around zero
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace db_rule_074 {

static float clip01(float x) {
    if (x < 0.0F) { return 0.0F; }
    if (x > 1.0F) { return 1.0F; }
    return x;
}

static float apply(float v, float deadband) {
    float d = clip01(deadband);
    if (v > d) { return v - d; }
    if (v < -d) { return v + d; }
    return 0.0F;
}

static void scan(const std::vector<float>& vals, float deadband) {
    for (float x : vals) {
        std::cout << std::fixed << std::setprecision(3)
                  << "in=" << x << " out=" << apply(x, deadband) << std::endl;
    }
}

} // namespace db_rule_074

int main() {
    using namespace db_rule_074;
    std::vector<float> vals = {-0.2F, -0.05F, 0.0F, 0.07F, 0.4F};
    scan(vals, 0.05F);
    return 0;
}
