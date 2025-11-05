// Context: Retry attempt counter — Expanded program

// ------ Non-Compliant Program (027_nc.cpp)
// Context: Retry counter increment
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>

namespace _ret_rule_027 {

static int _add(int a, int b) { return a + b; }

static void _bump(int &_retry_count) { // NC
    _retry_count = _add(_retry_count, 1);
}

static void _run(std::vector<int> &_ops) {
    int _retry_count = 0;
    for (int op : _ops) {
        if ((op % 2) != 0) { _bump(_retry_count); }
    }
    std::cout << "retries=" << _retry_count << std::endl;
}

} // namespace _ret_rule_027

int main() {
    using namespace _ret_rule_027;
    std::vector<int> ops = {0,1,2,3,4,5};
    _run(ops);
    return 0;
}
