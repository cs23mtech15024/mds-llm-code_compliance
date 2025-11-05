// Context: Array size calculation helper — Expanded program

// ------ Non-Compliant Program (009_nc.cpp)
// Context: Compute byte size of an int array
// NC: function begins with '_'
#include <iostream>
#include <vector>

namespace _arr_rule_009 {

static int _get_array_size(int count) {
    return static_cast<int>(count * static_cast<int>(sizeof(int)));
}

static void _demo(const std::vector<int> &_v) {
    int n = static_cast<int>(_v.size());
    std::cout << "size=" << _get_array_size(n) << std::endl;
}

} // namespace _arr_rule_009

int main() {
    using namespace _arr_rule_009;
    std::vector<int> v = {1,2,3,4,5};
    _demo(v);
    return 0;
}
