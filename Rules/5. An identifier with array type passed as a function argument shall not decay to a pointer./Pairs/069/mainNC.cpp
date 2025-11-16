// Context: IMU orientation quaternions

// ------ Non-Compliant Program (069_nc.cpp)
// Context: Simple quaternion tweak (toy, not full normalize)
// Rule: Array parameter decays to pointer (VIOLATED)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace quat_069_nc {

constexpr std::size_t kQ = 4U;

static void halve_w(float *q, std::size_t n) { // NC helper
    if (n) q[0] = q[0] * 0.5F;
}

static void print_q(const float *q, std::size_t n) {
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << (i?", ":"") << std::fixed << std::setprecision(2) << q[i];
    }
    std::cout << "\n";
}

void normalize_quaternion(float quat[]) { // NC API (toy)
    halve_w(quat, kQ);
    print_q(quat, kQ);
}

} // namespace quat_069_nc

int main() {
    using namespace quat_069_nc;
    float q[kQ] = {1.0F, 0.0F, 0.0F, 0.0F};
    normalize_quaternion(q);
    return 0;
}
