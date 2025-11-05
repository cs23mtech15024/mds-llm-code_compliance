// Context: Buffer allocation size — Expanded program

// ------ Compliant Program (024_c.cpp)
// Context: Allocation size reporter
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace buf_rule_024 {

static int sanitize(int n) {
    if (n < 0) { return 0; }
    if (n > 4096) { return 4096; }
    return n;
}

static void printAlloc(int buffer_size) {
    int s = sanitize(buffer_size);
    std::cout << "alloc=" << s << " bytes" << std::endl;
}

static void batch(const std::vector<int> &sizes) {
    for (int n : sizes) { printAlloc(n); }
}

} // namespace buf_rule_024

int main() {
    using namespace buf_rule_024;
    std::vector<int> sizes = {128, 512, 8192};
    batch(sizes);
    return 0;
}
