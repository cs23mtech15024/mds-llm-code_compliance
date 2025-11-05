// Context: Event flag bit position — Expanded program

// ------ Non-Compliant Program (096_nc.cpp)
// Context: Print event bit index
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _evt_rule_096 {

static int _clip(int b) {
    if (b < 0) { return 0; }
    if (b > 31) { return 31; }
    return b;
}

static void _emit(int _event_bit) { // NC
    std::cout << "bit=" << _clip(_event_bit) << std::endl;
}

static void _scan(const std::vector<int>& _bits) {
    for (int b : _bits) { _emit(b); }
}

} // namespace _evt_rule_096

int main() {
    using namespace _evt_rule_096;
    std::vector<int> bits = {3, -7, 64};
    _scan(bits);
    return 0;
}
