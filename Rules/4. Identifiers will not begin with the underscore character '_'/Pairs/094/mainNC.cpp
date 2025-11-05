// Context: Mutex lock timeout value — Expanded program

// ------ Non-Compliant Program (094_nc.cpp)
// Context: Configure and print mutex lock timeout
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _mtx_rule_094 {

static int _sanitize(int t) {
    if (t < 0) { return 0; }
    if (t > 60000) { return 60000; }
    return t;
}

static void _show(int _lock_timeout) { // NC
    std::cout << "timeout=" << _sanitize(_lock_timeout) << "ms" << std::endl;
}

static void _scan(const std::vector<int>& _vals) {
    for (int v : _vals) { _show(v); }
}

} // namespace _mtx_rule_094

int main() {
    using namespace _mtx_rule_094;
    std::vector<int> vals = {1000, -5, 999999};
    _scan(vals);
    return 0;
}
