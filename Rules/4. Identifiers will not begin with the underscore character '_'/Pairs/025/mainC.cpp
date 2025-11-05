// Context: Acceleration vector normalizer — Expanded program

// ------ Compliant Program (025_c.cpp)
// Context: 3D magnitude squared calculator
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

namespace vec_rule_025 {

static float sq(float v) { return v * v; }

static float magsq(float x, float y, float z) {
    return sq(x) + sq(y) + sq(z);
}

static void show(const std::vector<std::tuple<float,float,float>> &v) {
    for (const auto &t : v) {
        float x = std::get<0>(t);
        float y = std::get<1>(t);
        float z = std::get<2>(t);
        std::cout << std::fixed << std::setprecision(3)
                  << magsq(x, y, z) << std::endl;
    }
}

} // namespace vec_rule_025

int main() {
    using namespace vec_rule_025;
    std::vector<std::tuple<float,float,float>> pts;
    pts.emplace_back(1.0F, 2.0F, 3.0F);
    pts.emplace_back(0.0F, 0.0F, 1.0F);
    pts.emplace_back(-1.0F, -2.0F, -3.0F);
    show(pts);
    return 0;
}
