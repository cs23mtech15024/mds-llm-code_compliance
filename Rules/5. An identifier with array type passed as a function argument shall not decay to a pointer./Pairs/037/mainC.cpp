// Context: Wheel encoder pulse counts

// ------ Compliant Program (037_c.cpp)
// Context: Add pulses from first two wheels, show both and total
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace enc_037_c {

static long sum2(const long (&p)[4]) { return p[0] + p[1]; }

long get_total_pulses(long (&pulse_counts)[4]) { // C API
    std::cout << "w0=" << pulse_counts[0] << ", w1=" << pulse_counts[1] << "\n";
    return sum2(pulse_counts);
}

} // namespace enc_037_c

int main() {
    using namespace enc_037_c;
    long encoder_pulses[4] = {1000, 1050, 0, 0};
    std::cout << "total=" << get_total_pulses(encoder_pulses) << "\n";
    return 0;
}
