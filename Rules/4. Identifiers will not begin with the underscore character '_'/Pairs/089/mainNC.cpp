// Context: Memory pool block size — Expanded program

// ------ Non-Compliant Program (089_nc.cpp)
// Context: Display chosen block size
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>

namespace _blk_rule_089 {

static int _sanitize(int v) {
    if (v < 16) { return 16; }
    if (v > 4096) { return 4096; }
    return v;
}

static void _print(int _block_size) { // NC
    std::cout << "block=" << _sanitize(_block_size) << " bytes" << std::endl;
}

static void _demo(const std::vector<int>& _vals) {
    for (int v : _vals) { _print(v); }
}

} // namespace _blk_rule_089

int main() {
    using namespace _blk_rule_089;
    std::vector<int> v = {256, 8, 10000};
    _demo(v);
    return 0;
}
