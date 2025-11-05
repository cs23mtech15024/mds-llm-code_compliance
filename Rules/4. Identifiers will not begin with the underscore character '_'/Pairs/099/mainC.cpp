// Context: Watchdog timer period — Expanded program

// ------ Compliant Program (099_c.cpp)
// Context: Show watchdog period in ms
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace wd_rule_099 {

static int limit(int ms) {
    if (ms < 1) { return 1; }
    if (ms > 3600000) { return 3600000; }
    return ms;
}

static void emit(int watchdog_ms) {
    std::cout << "watchdog=" << limit(watchdog_ms) << "ms" << std::endl;
}

static void scan(const std::vector<int>& vals) {
    for (int v : vals) { emit(v); }
}

} // namespace wd_rule_099

int main() {
    using namespace wd_rule_099;
    std::vector<int> vals = {5000, -20, 99999999};
    scan(vals);
    return 0;
}
