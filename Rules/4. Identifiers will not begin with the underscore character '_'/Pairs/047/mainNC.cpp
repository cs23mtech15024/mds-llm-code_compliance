// Context: Color space RGB to HSV — Expanded program

// ------ Non-Compliant Program (047_nc.cpp)
// Context: RGB max component (toy HSV step)
// MISRA: Identifiers must not begin with '_'
// NC: parameters begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _rgb_rule_047 {

static int _max3(int a, int b, int c) {
    int m = (a > b) ? a : b;
    return (m > c) ? m : c;
}

static void _rgb_to_hsv(int _r, int _g, int _b) { // NC
    int max_val = _max3(_r, _g, _b);
    std::cout << "max=" << max_val << std::endl;
}

static void _samples(const std::vector<std::tuple<int,int,int>> &_v) {
    for (const auto &t : _v) {
        _rgb_to_hsv(std::get<0>(t), std::get<1>(t), std::get<2>(t));
    }
}

} // namespace _rgb_rule_047

int main() {
    using namespace _rgb_rule_047;
    std::vector<std::tuple<int,int,int>> v;
    v.emplace_back(255, 128, 64);
    v.emplace_back(0, 200, 200);
    _samples(v);
    return 0;
}
