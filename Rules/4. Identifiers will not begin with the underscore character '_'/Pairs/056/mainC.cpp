// Context: Jitter measurement accumulator — Expanded program

// ------ Compliant Program (056_c.cpp)
// Context: Track and print jitter ms
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace jit_rule_056 {

static float clip(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 1000.0F) { return 1000.0F; }
    return v;
}

static void emit(float jitter_ms) {
    std::cout << std::fixed << std::setprecision(2)
              << "jitter=" << clip(jitter_ms) << "ms" << std::endl;
}

static void run(const std::vector<float>& vals) {
    for (float v : vals) { emit(v); }
}

} // namespace jit_rule_056

int main() {
    using namespace jit_rule_056;
    std::vector<float> vals = {2.5F, -1.0F, 5000.0F};
    run(vals);
    return 0;
}
