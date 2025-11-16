// Context: Ultrasonic sensor echo times

// ------ Compliant Program (020_c.cpp)
// Context: Return and preview first echo time (microseconds)
// Rule: COMPLIANT (array by reference preserves extent)
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace ultra_020_c {

static void show_head(const long (&v)[8]) { // C helper
    std::cout << "head:";
    for (std::size_t i = 0; i < 5U; ++i) std::cout << ' ' << v[i];
    std::cout << "\n";
}

long get_echo_time(long (&echo_times)[8]) { // C API
    show_head(echo_times);
    return echo_times[0];
}

} // namespace ultra_020_c

int main() {
    using namespace ultra_020_c;
    long ultrasonic_echos[8] = {1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200};
    std::cout << "echo=" << get_echo_time(ultrasonic_echos) << "\n";
    return 0;
}
