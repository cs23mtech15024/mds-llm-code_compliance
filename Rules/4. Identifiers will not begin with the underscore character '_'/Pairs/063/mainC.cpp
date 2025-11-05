// Context: Peak detector hold time — Expanded program

// ------ Compliant Program (063_c.cpp)
// Context: Hold time in milliseconds for peak detector
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace hold_rule_063 {

static int clip(int v, int lo, int hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static void emit(int hold_ms) {
    std::cout << "hold=" << clip(hold_ms, 0, 10000) << "ms" << std::endl;
}

static void demo(const std::vector<int>& vals) {
    for (int v : vals) { emit(v); }
}

} // namespace hold_rule_063

int main() {
    using namespace hold_rule_063;
    std::vector<int> vals = {100, -50, 50000};
    demo(vals);
    return 0;
}
