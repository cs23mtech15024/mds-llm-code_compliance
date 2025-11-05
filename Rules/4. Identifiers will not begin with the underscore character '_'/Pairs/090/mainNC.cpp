// Context: Allocation request handler — Expanded program

// ------ Non-Compliant Program (090_nc.cpp)
// Context: Simulate allocation requests
// MISRA: Identifiers must not begin with '_'
// NC: function and parameter begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _alloc_rule_090 {

static void* _allocate_memory(int _size) { // NC
    if (_size <= 0) {
        std::cout << "alloc=0 bytes" << std::endl;
        return nullptr;
    }
    std::cout << "alloc=" << _size << " bytes" << std::endl;
    return nullptr;
}

static void _demo(const std::vector<int>& _sizes) {
    for (int s : _sizes) { (void)_allocate_memory(s); }
}

} // namespace _alloc_rule_090

int main() {
    using namespace _alloc_rule_090;
    std::vector<int> sizes = {1024, -5, 0, 4096};
    _demo(sizes);
    return 0;
}
