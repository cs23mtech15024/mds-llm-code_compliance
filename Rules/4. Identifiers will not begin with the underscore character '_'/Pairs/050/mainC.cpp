// Context: Phase shift calculator — Expanded program

// ------ Compliant Program (050_c.cpp)
// Context: Print phase in degrees
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace ph_rule_050 {

static float wrap(float d) {
    while (d >= 360.0F) { d -= 360.0F; }
    while (d < 0.0F) { d += 360.0F; }
    return d;
}

static void print(float phase_deg) {
    std::cout << std::fixed << std::setprecision(1)
              << "phase=" << wrap(phase_deg) << " degrees" << std::endl;
}

static void run(const std::vector<float> &vals) {
    for (float v : vals) { print(v); }
}

} // namespace ph_rule_050

int main() {
    using namespace ph_rule_050;
    std::vector<float> vals = {45.0F, -30.0F, 765.0F};
    run(vals);
    return 0;
}
