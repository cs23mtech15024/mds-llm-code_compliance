// Context: Ultrasonic sensor echo times

// ------ Non-Compliant Program (020_nc.cpp)
// Context: Return and preview first echo time (microseconds)
// Rule: Array shall not decay — VIOLATED (echo_times[] decays)
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace ultra_020_nc {

static void show_head(const long *v, std::size_t n) { // NC helper
    std::cout << "head:";
    for (std::size_t i = 0; i < n && i < 5U; ++i) std::cout << ' ' << v[i];
    std::cout << "\n";
}

long get_echo_time(long echo_times[]) { // NC API
    show_head(echo_times, 8U);
    return echo_times[0];
}

} // namespace ultra_020_nc

int main() {
    using namespace ultra_020_nc;
    long ultrasonic_echos[8] = {1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200};
    std::cout << "echo=" << get_echo_time(ultrasonic_echos) << "\n";
    return 0;
}
