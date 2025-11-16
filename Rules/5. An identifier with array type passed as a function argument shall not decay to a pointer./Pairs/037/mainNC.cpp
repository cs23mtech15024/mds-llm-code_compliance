// Context: Wheel encoder pulse counts

// ------ Non-Compliant Program (037_nc.cpp)
// Context: Add pulses from first two wheels, show both and total
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace enc_037_nc {

static long sum2(const long *p, std::size_t n) { return (n > 1U) ? (p[0] + p[1]) : (n ? p[0] : 0L); }

long get_total_pulses(long pulse_counts[]) { // NC API
    const std::size_t N = 4U; (void)N;
    std::cout << "w0=" << pulse_counts[0] << ", w1=" << pulse_counts[1] << "\n";
    return sum2(pulse_counts, 4U);
}

} // namespace enc_037_nc

int main() {
    using namespace enc_037_nc;
    long encoder_pulses[4] = {1000, 1050, 0, 0};
    std::cout << "total=" << get_total_pulses(encoder_pulses) << "\n";
    return 0;
}
