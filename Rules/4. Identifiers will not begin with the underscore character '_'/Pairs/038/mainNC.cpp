// Context: Timestamp delta calculator — Expanded program

// ------ Non-Compliant Program (038_nc.cpp)
// Context: t2 - t1 with range checks
// MISRA: Identifiers must not begin with '_'
// NC: function begins with '_'
#include <iostream>
#include <vector>
#include <limits>

namespace _ts_rule_038 {

static long _clipLong(long v) {
    const long LIM = 100000000L;
    if (v < -LIM) { return -LIM; }
    if (v > LIM) { return LIM; }
    return v;
}

static long _calc_delta(long t1, long t2) { // NC
    long a = _clipLong(t1);
    long b = _clipLong(t2);
    return b - a;
}

static void _test(const std::vector<std::pair<long,long>> &_cases) {
    for (const auto &pr : _cases) {
        std::cout << "delta=" << _calc_delta(pr.first, pr.second) << std::endl;
    }
}

} // namespace _ts_rule_038

int main() {
    using namespace _ts_rule_038;
    std::vector<std::pair<long,long>> cases = {{1000L, 5000L}, {-9e11, 0L}, {0L, 9e11}};
    _test(cases);
    return 0;
}
