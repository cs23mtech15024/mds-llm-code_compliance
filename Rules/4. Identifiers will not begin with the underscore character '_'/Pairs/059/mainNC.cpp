// Context: Moving average buffer index — Expanded program

// ------ Non-Compliant Program (059_nc.cpp)
// Context: Circular index advance
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _idx_rule_059 {

static int _wrap(int idx, int size) {
    if (size <= 0) { return 0; }
    int m = idx % size;
    return (m < 0) ? (m + size) : m;
}

static void _advance(int &_buffer_index, int size) { // NC
    _buffer_index = _wrap(_buffer_index + 1, size);
}

static void _demo(int _size) {
    int _buffer_index = 0;
    for (int i = 0; i < _size * 2; ++i) {
        _advance(_buffer_index, _size);
        std::cout << "idx=" << _buffer_index << std::endl;
    }
}

} // namespace _idx_rule_059

int main() {
    using namespace _idx_rule_059;
    _demo(10);
    return 0;
}
