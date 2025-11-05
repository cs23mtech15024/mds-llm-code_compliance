// Context: Velocity limit checker — Expanded program

// ------ Compliant Program (023_c.cpp)
// Context: Velocity <= limit check
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace vel_rule_023 {

static float clip(float v, float lo, float hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static bool check_velocity_limit(float vel, float limit) {
    float v = clip(vel, -1000.0F, 1000.0F);
    float L = clip(limit, 0.0F, 1000.0F);
    return v <= L;
}

static void scan(const std::vector<float> &v, float limit) {
    for (float x : v) {
        std::cout << std::fixed << std::setprecision(2)
                  << "v=" << x << " ok=" << check_velocity_limit(x, limit) << std::endl;
    }
}

} // namespace vel_rule_023

int main() {
    using namespace vel_rule_023;
    std::vector<float> vel = {10.0F, 45.0F, 55.0F};
    scan(vel, 50.0F);
    return 0;
}
