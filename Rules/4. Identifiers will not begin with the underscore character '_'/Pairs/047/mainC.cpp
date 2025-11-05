// Context: Color space RGB to HSV — Expanded program

// ------ Compliant Program (047_c.cpp)
// Context: RGB max component (toy HSV step)
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace rgb_rule_047 {

static int max3(int a, int b, int c) {
    int m = (a > b) ? a : b;
    return (m > c) ? m : c;
}

static void rgb_to_hsv(int r, int g, int b) {
    int max_val = max3(r, g, b);
    std::cout << "max=" << max_val << std::endl;
}

static void samples(const std::vector<std::tuple<int,int,int>> &v) {
    for (const auto &t : v) {
        rgb_to_hsv(std::get<0>(t), std::get<1>(t), std::get<2>(t));
    }
}

} // namespace rgb_rule_047

int main() {
    using namespace rgb_rule_047;
    std::vector<std::tuple<int,int,int>> v;
    v.emplace_back(255, 128, 64);
    v.emplace_back(0, 200, 200);
    samples(v);
    return 0;
}
