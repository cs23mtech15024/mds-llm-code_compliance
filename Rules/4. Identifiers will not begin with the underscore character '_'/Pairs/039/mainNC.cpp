// Context: Priority level selector — Expanded program

// ------ Non-Compliant Program (039_nc.cpp)
// Context: Select priority in [0..10]
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _prio_rule_039 {

static int _clipPri(int p) {
    if (p < 0) { return 0; }
    if (p > 10) { return 10; }
    return p;
}

static void _set(int &_priority, int v) { // NC
    _priority = _clipPri(v);
}

static void _demo(const std::vector<int> &_vals) {
    int _priority = 5;
    for (int v : _vals) {
        _set(_priority, v);
        std::cout << "prio=" << _priority << std::endl;
    }
}

} // namespace _prio_rule_039

int main() {
    using namespace _prio_rule_039;
    std::vector<int> vals = {-1, 0, 3, 11};
    _demo(vals);
    return 0;
}
