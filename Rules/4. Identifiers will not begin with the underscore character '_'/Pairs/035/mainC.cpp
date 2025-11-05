// Context: Timeout duration setter — Expanded program

// ------ Compliant Program (035_c.cpp)
// Context: Millisecond timeout printer
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace tmo_rule_035 {

static long clip(long v, long lo, long hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static void set_timeout(long ms) {
    long s = clip(ms, 0L, 600000L);
    std::cout << std::fixed << std::setprecision(0) << "timeout=" << s << "ms" << std::endl;
}

static void batch(const std::vector<long> &vals) {
    for (long v : vals) { set_timeout(v); }
}

} // namespace tmo_rule_035

int main() {
    using namespace tmo_rule_035;
    std::vector<long> vals = {5000L, -1L, 900000L};
    batch(vals);
    return 0;
}
