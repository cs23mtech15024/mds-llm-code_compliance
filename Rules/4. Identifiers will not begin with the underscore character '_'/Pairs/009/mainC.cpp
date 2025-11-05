// Context: Array size calculation helper — Expanded program

// ------ Compliant Program (009_c.cpp)
// Context: Compute byte size of an int array
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>

namespace arr_rule_009 {

static int get_array_size(int count) {
    return static_cast<int>(count * static_cast<int>(sizeof(int)));
}

static void demo(const std::vector<int> &v) {
    int n = static_cast<int>(v.size());
    std::cout << "size=" << get_array_size(n) << std::endl;
}

} // namespace arr_rule_009

int main() {
    using namespace arr_rule_009;
    std::vector<int> v = {1,2,3,4,5};
    demo(v);
    return 0;
}
