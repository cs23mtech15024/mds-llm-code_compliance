// Context: Step counter accumulator — Expanded program

// ------ Non-Compliant Program (042_nc.cpp)
// Context: Increment steps with bounds
// MISRA: Identifiers must not begin with '_'
// NC: variable and helpers begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _step_rule_042 {

static int _clip(int v, int lo, int hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static void _add(int &_step_count, int d) { // NC
    int temp = _clip(_step_count + d, 0, 1000000);
    _step_count = temp;
}

static void _run(const std::vector<int> &_deltas) {
    int _step_count = 5000;
    for (int d : _deltas) {
        _add(_step_count, d);
        std::cout << std::fixed << std::setprecision(0)
                  << "steps=" << _step_count << std::endl;
    }
}

} // namespace _step_rule_042

int main() {
    using namespace _step_rule_042;
    std::vector<int> deltas = {100, 250, -50, 10000000};
    _run(deltas);
    return 0;
}
