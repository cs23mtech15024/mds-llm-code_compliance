// Context: Memory pool block size — Expanded program

// ------ Compliant Program (089_c.cpp)
// Context: Display chosen block size
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>

namespace blk_rule_089 {

static int sanitize(int v) {
    if (v < 16) { return 16; }
    if (v > 4096) { return 4096; }
    return v;
}

static void print(int block_size) {
    std::cout << "block=" << sanitize(block_size) << " bytes" << std::endl;
}

static void demo(const std::vector<int>& vals) {
    for (int v : vals) { print(v); }
}

} // namespace blk_rule_089

int main() {
    using namespace blk_rule_089;
    std::vector<int> v = {256, 8, 10000};
    demo(v);
    return 0;
}
