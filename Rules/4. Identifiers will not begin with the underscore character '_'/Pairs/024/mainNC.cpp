// Context: Buffer allocation size — Expanded program

// ------ Non-Compliant Program (024_nc.cpp)
// Context: Allocation size reporter
// MISRA: Identifiers must not begin with '_'
// NC: variable name begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _buf_rule_024 {

static int _sanitize(int n) {
    if (n < 0) { return 0; }
    if (n > 4096) { return 4096; }
    return n;
}

static void _printAlloc(int _buffer_size) { // NC
    int s = _sanitize(_buffer_size);
    std::cout << "alloc=" << s << " bytes" << std::endl;
}

static void _batch(const std::vector<int> &_sizes) {
    for (int n : _sizes) { _printAlloc(n); }
}

} // namespace _buf_rule_024

int main() {
    using namespace _buf_rule_024;
    std::vector<int> sizes = {128, 512, 8192};
    _batch(sizes);
    return 0;
}
