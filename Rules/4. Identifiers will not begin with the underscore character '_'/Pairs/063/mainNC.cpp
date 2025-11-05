// Context: Peak detector hold time — Expanded program

// ------ Non-Compliant Program (063_nc.cpp)
// Context: Hold time in milliseconds for peak detector
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _hold_rule_063 {

static int _clip(int v, int lo, int hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static void _emit(int _hold_ms) { // NC
    std::cout << "hold=" << _clip(_hold_ms, 0, 10000) << "ms" << std::endl;
}

static void _demo(const std::vector<int>& _vals) {
    for (int v : _vals) { _emit(v); }
}

} // namespace _hold_rule_063

int main() {
    using namespace _hold_rule_063;
    std::vector<int> vals = {100, -50, 50000};
    _demo(vals);
    return 0;
}
