// Context: Release time envelope parameter — Expanded program

// ------ Compliant Program (071_c.cpp)
// Context: Release time in ms
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace rel_rule_071 {

static float clip(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 20000.0F) { return 20000.0F; }
    return v;
}

static void emit(float release_ms) {
    std::cout << std::fixed << std::setprecision(1)
              << "release=" << clip(release_ms) << "ms" << std::endl;
}

static void run(const std::vector<float>& vals) {
    for (float v : vals) { emit(v); }
}

} // namespace rel_rule_071

int main() {
    using namespace rel_rule_071;
    std::vector<float> vals = {200.0F, -10.0F, 50000.0F};
    run(vals);
    return 0;
}
