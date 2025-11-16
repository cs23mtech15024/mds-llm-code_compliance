// Context: Sonar ping response times

// ------ Compliant Program (067_c.cpp)
// Context: Convert ping time to distance in cm
// Rule: Preserve array via reference (COMPLIANT)
#include <iostream>
#include <cstddef>
#include <iomanip>

namespace sonar_067_c {

constexpr std::size_t kN = 16U;

template <std::size_t N>
static long to_cm(const long (&t)[N]) { return (t[0] / 58L); }

template <std::size_t N>
static long to_mm(const long (&t)[N]) { return ((t[0] * 10L) / 58L); }

long calculate_distance(long (&ping_times)[kN]) { // C API
    long cm = to_cm(ping_times);
    long mm = to_mm(ping_times);
    std::cout << "cm=" << cm << " mm=" << mm << "\n";
    return cm;
}

} // namespace sonar_067_c

int main() {
    using namespace sonar_067_c;
    long p[kN] = {2900L};
    std::cout << "dist_cm=" << calculate_distance(p) << "\n";
    return 0;
}
