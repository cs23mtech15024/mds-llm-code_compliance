// Context: Timestamp delta calculator — Expanded program

// ------ Compliant Program (038_c.cpp)
// Context: t2 - t1 with range checks
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <limits>

namespace ts_rule_038 {

static long clipLong(long v) {
    const long LIM = 100000000L;
    if (v < -LIM) { return -LIM; }
    if (v > LIM) { return LIM; }
    return v;
}

static long calc_delta(long t1, long t2) {
    long a = clipLong(t1);
    long b = clipLong(t2);
    return b - a;
}

static void test(const std::vector<std::pair<long,long>> &cases) {
    for (const auto &pr : cases) {
        std::cout << "delta=" << calc_delta(pr.first, pr.second) << std::endl;
    }
}

} // namespace ts_rule_038

int main() {
    using namespace ts_rule_038;
    std::vector<std::pair<long,long>> cases = {{1000L, 5000L}, {-9e11, 0L}, {0L, 9e11}};
    test(cases);
    return 0;
}
