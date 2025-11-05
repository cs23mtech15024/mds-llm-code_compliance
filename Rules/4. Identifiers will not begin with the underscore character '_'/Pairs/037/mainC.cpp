// Context: Range boundary checker — Expanded program

// ------ Compliant Program (037_c.cpp)
// Context: Check val in [min,max]
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace rng_rule_037 {

static int sanitize(int v) {
    if (v < -1000) { return -1000; }
    if (v > 1000) { return 1000; }
    return v;
}

static bool in_range(int val, int min, int max) {
    int v = sanitize(val);
    int lo = (min <= max) ? min : max;
    int hi = (min <= max) ? max : min;
    return (v >= lo) && (v <= hi);
}

static void report(const std::vector<int> &vals, int min, int max) {
    for (int v : vals) {
        std::cout << "v=" << v << " ok=" << in_range(v, min, max) << std::endl;
    }
}

} // namespace rng_rule_037

int main() {
    using namespace rng_rule_037;
    std::vector<int> vals = {-1500, -10, 0, 999, 2000};
    report(vals, 0, 100);
    return 0;
}
