// Context: Timeout duration setter — Expanded program

// ------ Non-Compliant Program (035_nc.cpp)
// Context: Millisecond timeout printer
// MISRA: Identifiers must not begin with '_'
// NC: parameter begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _tmo_rule_035 {

static long _clip(long v, long lo, long hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static void _set_timeout(long _ms) { // NC
    long s = _clip(_ms, 0L, 600000L);
    std::cout << std::fixed << std::setprecision(0) << "timeout=" << s << "ms" << std::endl;
}

static void _batch(const std::vector<long> &_vals) {
    for (long v : _vals) { _set_timeout(v); }
}

} // namespace _tmo_rule_035

int main() {
    using namespace _tmo_rule_035;
    std::vector<long> vals = {5000L, -1L, 900000L};
    _batch(vals);
    return 0;
}
