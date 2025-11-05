// Context: Message queue capacity — Expanded program

// ------ Non-Compliant Program (097_nc.cpp)
// Context: Configure and print queue capacity
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>

namespace _mq_rule_097 {

static int _limit(int v) {
    if (v < 1) { return 1; }
    if (v > 10000) { return 10000; }
    return v;
}

static void _set(int &_queue_capacity, int v) { // NC
    _queue_capacity = _limit(v);
    std::cout << "capacity=" << _queue_capacity << std::endl;
}

static void _sweep(int &_queue_capacity, const std::vector<int>& vals) {
    for (int x : vals) { _set(_queue_capacity, x); }
}

} // namespace _mq_rule_097

int main() {
    using namespace _mq_rule_097;
    int _queue_capacity = 50; // NC
    std::vector<int> vals = {50, 0, 500000, 128};
    _sweep(_queue_capacity, vals);
    return 0;
}
