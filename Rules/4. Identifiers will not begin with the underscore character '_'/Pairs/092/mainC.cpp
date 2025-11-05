// Context: Thread pool worker count — Expanded program

// ------ Compliant Program (092_c.cpp)
// Context: Maintain configurable worker thread count
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>

namespace tp_rule_092 {

static int bound(int v) {
    if (v < 1) { return 1; }
    if (v > 128) { return 128; }
    return v;
}

static void set(int &worker_threads, int v) {
    worker_threads = bound(v);
    std::cout << "workers=" << worker_threads << std::endl;
}

static void sweep(int &worker_threads, const std::vector<int>& vals) {
    for (int x : vals) { set(worker_threads, x); }
}

} // namespace tp_rule_092

int main() {
    using namespace tp_rule_092;
    int worker_threads = 4;
    std::vector<int> tries = {4, 0, 999, 8};
    sweep(worker_threads, tries);
    return 0;
}
