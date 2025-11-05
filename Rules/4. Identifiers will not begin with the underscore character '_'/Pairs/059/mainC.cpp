// Context: Moving average buffer index — Expanded program

// ------ Compliant Program (059_c.cpp)
// Context: Circular index advance
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace idx_rule_059 {

static int wrap(int idx, int size) {
    if (size <= 0) { return 0; }
    int m = idx % size;
    return (m < 0) ? (m + size) : m;
}

static void advance(int &buffer_index, int size) {
    buffer_index = wrap(buffer_index + 1, size);
}

static void demo(int size) {
    int buffer_index = 0;
    for (int i = 0; i < size * 2; ++i) {
        advance(buffer_index, size);
        std::cout << "idx=" << buffer_index << std::endl;
    }
}

} // namespace idx_rule_059

int main() {
    using namespace idx_rule_059;
    demo(10);
    return 0;
}
