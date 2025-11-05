// Context: Jitter measurement accumulator — Expanded program

// ------ Non-Compliant Program (056_nc.cpp)
// Context: Track and print jitter ms
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _jit_rule_056 {

static float _clip(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 1000.0F) { return 1000.0F; }
    return v;
}

static void _emit(float _jitter_ms) { // NC
    std::cout << std::fixed << std::setprecision(2)
              << "jitter=" << _clip(_jitter_ms) << "ms" << std::endl;
}

static void _run(const std::vector<float>& _vals) {
    for (float v : _vals) { _emit(v); }
}

} // namespace _jit_rule_056

int main() {
    using namespace _jit_rule_056;
    std::vector<float> vals = {2.5F, -1.0F, 5000.0F};
    _run(vals);
    return 0;
}
