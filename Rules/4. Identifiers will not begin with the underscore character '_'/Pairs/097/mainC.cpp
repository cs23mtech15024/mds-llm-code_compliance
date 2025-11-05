// Context: Message queue capacity — Expanded program

// ------ Compliant Program (097_c.cpp)
// Context: Configure and print queue capacity
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>

namespace mq_rule_097 {

static int limit(int v) {
    if (v < 1) { return 1; }
    if (v > 10000) { return 10000; }
    return v;
}

static void set(int &queue_capacity, int v) {
    queue_capacity = limit(v);
    std::cout << "capacity=" << queue_capacity << std::endl;
}

static void sweep(int &queue_capacity, const std::vector<int>& vals) {
    for (int x : vals) { set(queue_capacity, x); }
}

} // namespace mq_rule_097

int main() {
    using namespace mq_rule_097;
    int queue_capacity = 50;
    std::vector<int> vals = {50, 0, 500000, 128};
    sweep(queue_capacity, vals);
    return 0;
}
