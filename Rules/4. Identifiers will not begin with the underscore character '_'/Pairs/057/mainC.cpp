// Context: Coordinate transform X-axis — Expanded program

// ------ Compliant Program (057_c.cpp)
// Context: Translate x by offset
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace tx_rule_057 {

static float clipOff(float o) {
    if (o < -1000.0F) { return -1000.0F; }
    if (o > 1000.0F) { return 1000.0F; }
    return o;
}

static float transform_x(float x, float offset) {
    return x + clipOff(offset);
}

static void apply(const std::vector<float>& xs, float off) {
    for (float x : xs) {
        std::cout << std::fixed << std::setprecision(2)
                  << "x'=" << transform_x(x, off) << std::endl;
    }
}

} // namespace tx_rule_057

int main() {
    using namespace tx_rule_057;
    std::vector<float> xs = {10.0F, -5.0F, 100.0F};
    apply(xs, 5.0F);
    return 0;
}
