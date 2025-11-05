// Context: Event timestamp recorder — Expanded program

// ------ Non-Compliant Program (048_nc.cpp)
// Context: Store and print event time
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _evt_rule_048 {

static long _sanitize(long v) {
    if (v < 0L) { return 0L; }
    return v;
}

static void _record(long &_event_time, long now) { // NC
    _event_time = _sanitize(now);
}

static void _print(long _event_time) { // NC
    std::cout << "time=" << _event_time << std::endl;
}

} // namespace _evt_rule_048

int main() {
    using namespace _evt_rule_048;
    long _event_time = 0L;
    _record(_event_time, 123456789L);
    _print(_event_time);
    return 0;
}
