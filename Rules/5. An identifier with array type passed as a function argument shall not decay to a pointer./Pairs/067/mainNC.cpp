// Context: Sonar ping response times

// ------ Non-Compliant Program (067_nc.cpp)
// Context: Convert ping time to distance in cm
// Rule: Array parameter decays to pointer (VIOLATED)
#include <iostream>
#include <cstddef>
#include <iomanip>

namespace sonar_067_nc {

constexpr std::size_t kN = 16U;

static long to_cm(const long *t, std::size_t n) { // NC helper
    return (n? (t[0] / 58L) : 0L);
}

static long to_mm(const long *t, std::size_t n) { // NC helper
    return (n? (t[0] * 10L) / 58L : 0L);
}

long calculate_distance(long ping_times[]) { // NC API
    long cm = to_cm(ping_times, kN);
    long mm = to_mm(ping_times, kN);
    std::cout << "cm=" << cm << " mm=" << mm << "\n";
    return cm;
}

} // namespace sonar_067_nc

int main() {
    using namespace sonar_067_nc;
    long p[kN] = {2900L};
    std::cout << "dist_cm=" << calculate_distance(p) << "\n";
    return 0;
}
