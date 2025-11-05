// Context: Stack size allocator — Expanded program

// ------ Non-Compliant Program (098_nc.cpp)
// Context: Configure stack size in kilobytes
// MISRA: Identifiers must not begin with '_'
// NC: function and parameter begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _stk_rule_098 {

static int _boundKB(int kb) {
    if (kb < 1) { return 1; }
    if (kb > 1048576) { return 1048576; }
    return kb;
}

static void _allocate_stack(int _size_kb) { // NC
    int s = _boundKB(_size_kb);
    std::cout << "stack=" << s << "KB" << std::endl;
}

static void _demo(const std::vector<int>& _vals) {
    for (int v : _vals) { _allocate_stack(v); }
}

} // namespace _stk_rule_098

int main() {
    using namespace _stk_rule_098;
    std::vector<int> vals = {64, 0, 2000000};
    _demo(vals);
    return 0;
}
