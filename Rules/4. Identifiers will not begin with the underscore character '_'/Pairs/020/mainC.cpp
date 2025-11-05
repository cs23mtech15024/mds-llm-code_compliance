// Context: Timer interval milliseconds — Expanded program

// ------ Compliant Program (020_c.cpp)
// Context: Interval print helper
// C: identifiers do not begin with '_'
#include <iostream>
#include <iomanip>

namespace tim_rule_020 {

static long sanitize(long v) {
    if (v < 0L) { return 0L; }
    if (v > 600000L) { return 600000L; }
    return v;
}

static void print_ms(long interval_ms) {
    std::cout << std::fixed << std::setprecision(0)
              << "timer=" << sanitize(interval_ms) << "ms" << std::endl;
}

} // namespace tim_rule_020

int main() {
    using namespace tim_rule_020;
    long interval_ms = 1000L;
    print_ms(interval_ms);
    print_ms(-50L);
    print_ms(700000L);
    return 0;
}
