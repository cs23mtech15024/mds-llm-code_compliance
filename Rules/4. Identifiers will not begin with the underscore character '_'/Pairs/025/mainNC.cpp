// Context: Acceleration vector normalizer — Expanded program

// ------ Non-Compliant Program (025_nc.cpp)
// Context: 3D magnitude squared calculator
// MISRA: Identifiers must not begin with '_'
// NC: parameters begin with '_'
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

namespace _vec_rule_025 {

static float _sq(float v) { return v * v; }

static float _magsq(float _x, float _y, float _z) { // NC
    return _sq(_x) + _sq(_y) + _sq(_z);
}

static void _show(const std::vector<std::tuple<float,float,float>> &_v) {
    for (const auto &t : _v) {
        float _x = std::get<0>(t);
        float _y = std::get<1>(t);
        float _z = std::get<2>(t);
        std::cout << std::fixed << std::setprecision(3)
                  << _magsq(_x, _y, _z) << std::endl;
    }
}

} // namespace _vec_rule_025

int main() {
    using namespace _vec_rule_025;
    std::vector<std::tuple<float,float,float>> pts;
    pts.emplace_back(1.0F, 2.0F, 3.0F);
    pts.emplace_back(0.0F, 0.0F, 1.0F);
    pts.emplace_back(-1.0F, -2.0F, -3.0F);
    _show(pts);
    return 0;
}
