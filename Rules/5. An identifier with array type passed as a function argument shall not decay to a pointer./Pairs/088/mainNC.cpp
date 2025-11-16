// Context: Tachometer pulse intervals

// ------ Non-Compliant Program (088_nc.cpp)
// Context: Tachometer pulse intervals (10 pulses)
// Rule: Array parameter decays to pointer (VIOLATION)
// Impact: Callee cannot validate buffer length
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace tach_088_nc {

static long calc_avg(const long *p, std::size_t n){ long s=0; for(std::size_t i=0;i<n;i++){ s+=p[i]; } return s/static_cast<long>(n); }

void compute_rpm(long intervals[]) { // NC API
    const std::size_t N = 10U; (void)N;
    long avg = calc_avg(intervals, 10U);
    long rpm = 60000000L / avg;
    std::cout << "avg_us=" << avg << ", rpm=" << rpm << "\n";
}

} // namespace tach_088_nc

int main(){
    using namespace tach_088_nc;
    long pulses[10] = {10000,10100,9900,9800,10200,10000,9900,10100,9950,10000};
    compute_rpm(pulses);
    return 0;
}
