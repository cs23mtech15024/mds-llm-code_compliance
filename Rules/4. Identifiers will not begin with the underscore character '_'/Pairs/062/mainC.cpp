// Context: Circular buffer write pointer — Expanded program

// ------ Compliant Program (062_c.cpp)
// Context: Advance circular buffer write pointer
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>

namespace cb_rule_062 {

static int wrap(int idx, int size) {
    if (size <= 0) { return 0; }
    int m = idx % size;
    return (m < 0) ? (m + size) : m;
}

static void advance(int &write_ptr, int size) {
    write_ptr = wrap(write_ptr + 1, size);
}

static void simulate(int size) {
    int write_ptr = 0;
    for (int i = 0; i < size * 3; ++i) {
        advance(write_ptr, size);
        std::cout << "wr_ptr=" << write_ptr << std::endl;
    }
}

} // namespace cb_rule_062

int main() {
    using namespace cb_rule_062;
    simulate(10);
    return 0;
}
