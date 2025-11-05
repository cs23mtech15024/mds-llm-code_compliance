// Context: Event timestamp recorder — Expanded program

// ------ Compliant Program (048_c.cpp)
// Context: Store and print event time
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace evt_rule_048 {

static long sanitize(long v) {
    if (v < 0L) { return 0L; }
    return v;
}

static void record(long &event_time, long now) {
    event_time = sanitize(now);
}

static void print(long event_time) {
    std::cout << "time=" << event_time << std::endl;
}

} // namespace evt_rule_048

int main() {
    using namespace evt_rule_048;
    long event_time = 0L;
    record(event_time, 123456789L);
    print(event_time);
    return 0;
}
