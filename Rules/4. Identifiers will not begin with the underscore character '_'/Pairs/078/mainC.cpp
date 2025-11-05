// Context: Integral gain parameter — Expanded program

// ------ Compliant Program (078_c.cpp)
// Context: Integral gain Ki
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace ki_rule_078 {

static float bound(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 100.0F) { return 100.0F; }
    return v;
}

static void show(float ki) {
    std::cout << std::fixed << std::setprecision(2)
              << "Ki=" << bound(ki) << std::endl;
}

static void scan(const std::vector<float>& vals) {
    for (float v : vals) { show(v); }
}

} // namespace ki_rule_078

int main() {
    using namespace ki_rule_078;
    std::vector<float> vals = {0.1F, -3.0F, 500.0F};
    scan(vals);
    return 0;
}
