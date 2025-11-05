// Context: Attack time envelope parameter — Expanded program

// ------ Compliant Program (070_c.cpp)
// Context: Attack time in ms
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace atk_rule_070 {

static float clip(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 10000.0F) { return 10000.0F; }
    return v;
}

static void emit(float attack_ms) {
    std::cout << std::fixed << std::setprecision(1)
              << "attack=" << clip(attack_ms) << "ms" << std::endl;
}

static void run(const std::vector<float>& vals) {
    for (float v : vals) { emit(v); }
}

} // namespace atk_rule_070

int main() {
    using namespace atk_rule_070;
    std::vector<float> vals = {10.0F, -5.0F, 20000.0F};
    run(vals);
    return 0;
}
