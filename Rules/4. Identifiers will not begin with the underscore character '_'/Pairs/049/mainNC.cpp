// Context: Saturation limit enforcer — Expanded program

// ------ Non-Compliant Program (049_nc.cpp)
// Context: Clamp value to limit
// MISRA: Identifiers must not begin with '_'
// NC: function begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _sat_rule_049 {

static int _clamp(int v, int lo, int hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static int _saturate(int value, int limit) { // NC
    return _clamp(value, -limit, limit);
}

static void _scan(const std::vector<std::pair<int,int>> &_v) {
    for (const auto &p : _v) {
        std::cout << "val=" << p.first << " lim=" << p.second
                  << " out=" << _saturate(p.first, p.second) << std::endl;
    }
}

} // namespace _sat_rule_049

int main() {
    using namespace _sat_rule_049;
    std::vector<std::pair<int,int>> v = {{150,100},{-250,200},{10,100}};
    _scan(v);
    return 0;
}
