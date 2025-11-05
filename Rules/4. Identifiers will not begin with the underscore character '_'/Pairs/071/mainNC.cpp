// Context: Release time envelope parameter — Expanded program

// ------ Non-Compliant Program (071_nc.cpp)
// Context: Release time in ms
// MISRA: Identifiers must not begin with '_'
// NC: variable and helpers begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _rel_rule_071 {

static float _clip(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 20000.0F) { return 20000.0F; }
    return v;
}

static void _emit(float _release_ms) { // NC
    std::cout << std::fixed << std::setprecision(1)
              << "release=" << _clip(_release_ms) << "ms" << std::endl;
}

static void _run(const std::vector<float>& _vals) {
    for (float v : _vals) { _emit(v); }
}

} // namespace _rel_rule_071

int main() {
    using namespace _rel_rule_071;
    std::vector<float> vals = {200.0F, -10.0F, 50000.0F};
    _run(vals);
    return 0;
}
