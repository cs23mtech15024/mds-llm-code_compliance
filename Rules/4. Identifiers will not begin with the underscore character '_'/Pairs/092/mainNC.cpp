// Context: Thread pool worker count — Expanded program

// ------ Non-Compliant Program (092_nc.cpp)
// Context: Maintain configurable worker thread count
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>

namespace _tp_rule_092 {

static int _bound(int v) {
    if (v < 1) { return 1; }
    if (v > 128) { return 128; }
    return v;
}

static void _set(int &_worker_threads, int v) { // NC
    _worker_threads = _bound(v);
    std::cout << "workers=" << _worker_threads << std::endl;
}

static void _sweep(int &_worker_threads, const std::vector<int>& vals) {
    for (int x : vals) { _set(_worker_threads, x); }
}

} // namespace _tp_rule_092

int main() {
    using namespace _tp_rule_092;
    int _worker_threads = 4; // NC
    std::vector<int> tries = {4, 0, 999, 8};
    _sweep(_worker_threads, tries);
    return 0;
}
