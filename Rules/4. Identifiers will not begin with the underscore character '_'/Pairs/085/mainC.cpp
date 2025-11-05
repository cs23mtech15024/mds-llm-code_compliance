// Context: Sample time period — Expanded program

// ------ Compliant Program (085_c.cpp)
// Context: Sample period configuration
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace dt_rule_085 {

static float sanitize(float dt) {
    if (dt < 0.0001F) { return 0.0001F; }
    if (dt > 1.0F) { return 1.0F; }
    return dt;
}

static void apply(float sample_time) {
    std::cout << std::fixed << std::setprecision(5)
              << "dt=" << sanitize(sample_time) << "s" << std::endl;
}

static void scan(const std::vector<float>& vals) {
    for (float v : vals) { apply(v); }
}

} // namespace dt_rule_085

int main() {
    using namespace dt_rule_085;
    std::vector<float> vals = {0.01F, 0.0F, 2.0F};
    scan(vals);
    return 0;
}
