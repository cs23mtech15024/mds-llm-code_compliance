// Context: Circular buffer write pointer — Expanded program

// ------ Non-Compliant Program (062_nc.cpp)
// Context: Advance circular buffer write pointer
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>

namespace _cb_rule_062 {

static int _wrap(int idx, int size) {
    if (size <= 0) { return 0; }
    int m = idx % size;
    return (m < 0) ? (m + size) : m;
}

static void _advance(int &_write_ptr, int size) { // NC
    _write_ptr = _wrap(_write_ptr + 1, size);
}

static void _simulate(int size) {
    int _write_ptr = 0; // NC
    for (int i = 0; i < size * 3; ++i) {
        _advance(_write_ptr, size);
        std::cout << "wr_ptr=" << _write_ptr << std::endl;
    }
}

} // namespace _cb_rule_062

int main() {
    using namespace _cb_rule_062;
    _simulate(10);
    return 0;
}
