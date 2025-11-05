// Context: Watchdog timer period — Expanded program

// ------ Non-Compliant Program (099_nc.cpp)
// Context: Show watchdog period in ms
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _wd_rule_099 {

static int _limit(int ms) {
    if (ms < 1) { return 1; }
    if (ms > 3600000) { return 3600000; }
    return ms;
}

static void _emit(int _watchdog_ms) { // NC
    std::cout << "watchdog=" << _limit(_watchdog_ms) << "ms" << std::endl;
}

static void _scan(const std::vector<int>& _vals) {
    for (int v : _vals) { _emit(v); }
}

} // namespace _wd_rule_099

int main() {
    using namespace _wd_rule_099;
    std::vector<int> vals = {5000, -20, 99999999};
    _scan(vals);
    return 0;
}
