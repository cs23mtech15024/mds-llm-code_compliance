// Context: Signal filter bandwidth function — Expanded program

// ------ Compliant Program (012_c.cpp)
// Context: Bandwidth print helper
// C: no leading '_' identifiers
#include <iostream>
#include <vector>
#include <iomanip>

namespace bw_rule_012 {

static float clipHz(float h) {
    if (h < 0.0F) { return 0.0F; }
    if (h > 200000.0F) { return 200000.0F; }
    return h;
}

static void set_bandwidth(float bw_hz) {
    std::cout << std::fixed << std::setprecision(1)
              << "bandwidth=" << clipHz(bw_hz) << "Hz" << std::endl;
}

static void run(const std::vector<float> &vals) {
    for (float v : vals) { set_bandwidth(v); }
}

} // namespace bw_rule_012

int main() {
    using namespace bw_rule_012;
    std::vector<float> vals = {1000.0F, -5.0F, 250000.0F};
    run(vals);
    return 0;
}
