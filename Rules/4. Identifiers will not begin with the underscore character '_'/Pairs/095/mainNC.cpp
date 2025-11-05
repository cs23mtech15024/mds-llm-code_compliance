// Context: Semaphore initial count — Expanded program

// ------ Non-Compliant Program (095_nc.cpp)
// Context: Print configured semaphore initial count
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>

namespace _sem_rule_095 {

static int _bound(int v) {
    if (v < 0) { return 0; }
    if (v > 1000) { return 1000; }
    return v;
}

static void _init(int _sem_count) { // NC
    std::cout << "sem_init=" << _bound(_sem_count) << std::endl;
}

static void _demo(const std::vector<int>& _vals) {
    for (int v : _vals) { _init(v); }
}

} // namespace _sem_rule_095

int main() {
    using namespace _sem_rule_095;
    std::vector<int> vals = {5, -1, 2000};
    _demo(vals);
    return 0;
}
