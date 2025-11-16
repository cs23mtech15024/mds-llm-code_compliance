// Context: IMU orientation quaternions

// ------ Compliant Program (069_c.cpp)
// Context: Simple quaternion tweak (toy, not full normalize)
// Rule: Preserve array via reference (COMPLIANT)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace quat_069_c {

constexpr std::size_t kQ = 4U;

template <std::size_t N>
static void halve_w(float (&q)[N]) {
    static_assert(N == 4U, "expect quaternion size 4");
    q[0] = q[0] * 0.5F;
}

template <std::size_t N>
static void print_q(const float (&q)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << (i?", ":"") << std::fixed << std::setprecision(2) << q[i];
    }
    std::cout << "\n";
}

void normalize_quaternion(float (&quat)[kQ]) { // C API (toy)
    halve_w(quat);
    print_q(quat);
}

} // namespace quat_069_c

int main() {
    using namespace quat_069_c;
    float q[kQ] = {1.0F, 0.0F, 0.0F, 0.0F};
    normalize_quaternion(q);
    return 0;
}
