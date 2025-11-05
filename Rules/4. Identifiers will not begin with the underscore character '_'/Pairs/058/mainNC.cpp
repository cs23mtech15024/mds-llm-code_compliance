// Context: Debounce time constant — Expanded program

// ------ Non-Compliant Program (058_nc.cpp)
// Context: Debounce duration in ms
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _db_rule_058 {

static int _clip(int v) {
    if (v < 0) { return 0; }
    if (v > 1000) { return 1000; }
    return v;
}

static void _report(int _debounce_ms) { // NC
    std::cout << "debounce=" << _clip(_debounce_ms) << "ms" << std::endl;
}

static void _scan(const std::vector<int>& _vals) {
    for (int v : _vals) { _report(v); }
}

} // namespace _db_rule_058

int main() {
    using namespace _db_rule_058;
    std::vector<int> vals = {50, -5, 5000};
    _scan(vals);
    return 0;
}
