// Context: Pressure sensor scaling function — Expanded program

// ------ Compliant Program (015_c.cpp)
// Context: Scale raw ADC to pressure
// C: no leading '_' identifiers
#include <iostream>
#include <vector>
#include <iomanip>

namespace prs_rule_015 {

static float mul(float a, float b) { return a * b; }

static float scale_pressure(float raw, float factor) {
    return mul(raw, factor);
}

static void show(const std::vector<float> &raws, float factor) {
    for (float r : raws) {
        std::cout << std::fixed << std::setprecision(3)
                  << scale_pressure(r, factor) << std::endl;
    }
}

} // namespace prs_rule_015

int main() {
    using namespace prs_rule_015;
    std::vector<float> raws = {1023.0F, 512.0F, 256.0F};
    show(raws, 0.1F);
    return 0;
}
