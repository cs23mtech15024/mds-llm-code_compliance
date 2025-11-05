// Context: Load cell calibration value — Expanded program

// ------ Compliant Program (054_c.cpp)
// Context: Weight = raw * calibration
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace cal_rule_054 {

static float limit(float x, float lo, float hi) {
    if (x < lo) { return lo; }
    if (x > hi) { return hi; }
    return x;
}

static float weight(float raw, float calibration) {
    return raw * limit(calibration, 0.0F, 10.0F);
}

static void table(const std::vector<float>& raws, float calibration) {
    for (float r : raws) {
        std::cout << std::fixed << std::setprecision(2)
                  << "w=" << weight(r, calibration) << std::endl;
    }
}

} // namespace cal_rule_054

int main() {
    using namespace cal_rule_054;
    std::vector<float> raws = {1023.0F, 800.0F, 512.0F};
    table(raws, 0.5F);
    return 0;
}
