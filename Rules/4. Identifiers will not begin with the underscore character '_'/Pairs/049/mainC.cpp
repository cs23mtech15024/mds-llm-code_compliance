// Context: Saturation limit enforcer — Expanded program

// ------ Compliant Program (049_c.cpp)
// Context: Clamp value to limit
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace sat_rule_049 {

static int clamp(int v, int lo, int hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static int saturate(int value, int limit) {
    return clamp(value, -limit, limit);
}

static void scan(const std::vector<std::pair<int,int>> &v) {
    for (const auto &p : v) {
        std::cout << "val=" << p.first << " lim=" << p.second
                  << " out=" << saturate(p.first, p.second) << std::endl;
    }
}

} // namespace sat_rule_049

int main() {
    using namespace sat_rule_049;
    std::vector<std::pair<int,int>> v = {{150,100},{-250,200},{10,100}};
    scan(v);
    return 0;
}
