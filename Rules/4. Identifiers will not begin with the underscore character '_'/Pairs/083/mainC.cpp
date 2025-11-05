// Context: Output clamp max value — Expanded program

// ------ Compliant Program (083_c.cpp)
// Context: Enforce maximum actuator command
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace omax_rule_083 {

static float limit(float v, float output_max) {
    if (v > output_max) { return output_max; }
    if (v < -output_max) { return -output_max; }
    return v;
}

static void scan(const std::vector<float>& vals, float output_max) {
    for (float v : vals) {
        std::cout << std::fixed << std::setprecision(2)
                  << "in=" << v << " out=" << limit(v, output_max) << std::endl;
    }
}

} // namespace omax_rule_083

int main() {
    using namespace omax_rule_083;
    std::vector<float> vals = {50.0F, 120.0F, -200.0F};
    scan(vals, 100.0F);
    return 0;
}
