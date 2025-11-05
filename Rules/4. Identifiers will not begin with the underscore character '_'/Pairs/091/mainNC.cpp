// Context: Resource usage counter — Expanded program

// ------ Non-Compliant Program (091_nc.cpp)
// Context: Track current resource usage count
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _res_rule_091 {

static int _sanitize(int v) {
    if (v < 0) { return 0; }
    if (v > 100000) { return 100000; }
    return v;
}

static void _accumulate(int &_resource_count, const std::vector<int>& deltas) { // NC
    for (int d : deltas) {
        int tmp = _resource_count + d;
        _resource_count = _sanitize(tmp);
        std::cout << "resources=" << _resource_count << std::endl;
    }
}

} // namespace _res_rule_091

int main() {
    using namespace _res_rule_091;
    int _resource_count = 10; // NC
    std::vector<int> deltas = {+5, -3, +1000000, -50};
    _accumulate(_resource_count, deltas);
    return 0;
}
