// Context: Quality factor (Q) for resonance — Expanded program

// ------ Compliant Program (073_c.cpp)
// Context: Print Q factor
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace q_rule_073 {

static float clipQ(float q) {
    if (q < 0.1F) { return 0.1F; }
    if (q > 20.0F) { return 20.0F; }
    return q;
}

static void emit(float q_factor) {
    std::cout << std::fixed << std::setprecision(2)
              << "Q=" << clipQ(q_factor) << std::endl;
}

static void scan(const std::vector<float>& v) {
    for (float q : v) { emit(q); }
}

} // namespace q_rule_073

int main() {
    using namespace q_rule_073;
    std::vector<float> vals = {2.5F, 0.01F, 30.0F};
    scan(vals);
    return 0;
}
