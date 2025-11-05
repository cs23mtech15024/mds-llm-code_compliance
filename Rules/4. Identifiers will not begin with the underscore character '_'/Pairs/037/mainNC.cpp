// Context: Range boundary checker — Expanded program

// ------ Non-Compliant Program (037_nc.cpp)
// Context: Check val in [min,max]
// MISRA: Identifiers must not begin with '_'
// NC: function and parameters begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _rng_rule_037 {

static int _sanitize(int v) {
    if (v < -1000) { return -1000; }
    if (v > 1000) { return 1000; }
    return v;
}

static bool _in_range(int _val, int _min, int _max) { // NC
    int v = _sanitize(_val);
    int lo = (_min <= _max) ? _min : _max;
    int hi = (_min <= _max) ? _max : _min;
    return (v >= lo) && (v <= hi);
}

static void _report(const std::vector<int> &_vals, int _min, int _max) {
    for (int v : _vals) {
        std::cout << "v=" << v << " ok=" << _in_range(v, _min, _max) << std::endl;
    }
}

} // namespace _rng_rule_037

int main() {
    using namespace _rng_rule_037;
    std::vector<int> vals = {-1500, -10, 0, 999, 2000};
    _report(vals, 0, 100);
    return 0;
}
