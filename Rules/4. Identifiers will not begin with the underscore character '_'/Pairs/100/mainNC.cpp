// Context: Heartbeat interval checker — Expanded program

// ------ Non-Compliant Program (100_nc.cpp)
// Context: Validate heartbeat interval
// MISRA: Identifiers must not begin with '_'
// NC: function and parameter begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _hb_rule_100 {

static bool _check_heartbeat(int _interval) { // NC
    return (_interval > 0) && (_interval < 10000);
}

static void _scan(const std::vector<int>& _vals) {
    for (int v : _vals) {
        std::cout << "valid=" << _check_heartbeat(v) << std::endl;
    }
}

} // namespace _hb_rule_100

int main() {
    using namespace _hb_rule_100;
    std::vector<int> vals = {1000, 0, 20000};
    _scan(vals);
    return 0;
}
