// Context: Allocation request handler — Expanded program

// ------ Compliant Program (090_c.cpp)
// Context: Simulate allocation requests
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace alloc_rule_090 {

static void* allocate_memory(int size) {
    if (size <= 0) {
        std::cout << "alloc=0 bytes" << std::endl;
        return nullptr;
    }
    std::cout << "alloc=" << size << " bytes" << std::endl;
    return nullptr;
}

static void demo(const std::vector<int>& sizes) {
    for (int s : sizes) { (void)allocate_memory(s); }
}

} // namespace alloc_rule_090

int main() {
    using namespace alloc_rule_090;
    std::vector<int> sizes = {1024, -5, 0, 4096};
    demo(sizes);
    return 0;
}
