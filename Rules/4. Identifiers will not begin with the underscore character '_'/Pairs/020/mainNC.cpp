// Context: Timer interval milliseconds — Expanded program

// ------ Non-Compliant Program (020_nc.cpp)
// Context: Interval print helper
// MISRA: Identifiers must not begin with '_'
// NC: variable and functions begin with '_'
#include <iostream>
#include <iomanip>

namespace _tim_rule_020 {

static long _sanitize(long v) {
    if (v < 0L) { return 0L; }
    if (v > 600000L) { return 600000L; }
    return v;
}

static void _print_ms(long _interval_ms) {
    std::cout << std::fixed << std::setprecision(0)
              << "timer=" << _sanitize(_interval_ms) << "ms" << std::endl;
}

} // namespace _tim_rule_020

int main() {
    using namespace _tim_rule_020;
    long _interval_ms = 1000L;
    _print_ms(_interval_ms);
    _print_ms(-50L);
    _print_ms(700000L);
    return 0;
}
