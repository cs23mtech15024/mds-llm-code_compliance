// Context: Message queue depth monitor — Expanded program

// ------ Non-Compliant Program (029_nc.cpp)
// Context: Queue depth printing
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _q_rule_029 {

static int _clip(int v) {
    if (v < 0) { return 0; }
    if (v > 1000) { return 1000; }
    return v;
}

static void _printDepth(int _queue_depth) { // NC
    std::cout << "depth=" << _clip(_queue_depth) << std::endl;
}

static void _replay(const std::vector<int> &_depths) {
    for (int d : _depths) { _printDepth(d); }
}

} // namespace _q_rule_029

int main() {
    using namespace _q_rule_029;
    std::vector<int> depths = {25, -5, 1200};
    _replay(depths);
    return 0;
}
