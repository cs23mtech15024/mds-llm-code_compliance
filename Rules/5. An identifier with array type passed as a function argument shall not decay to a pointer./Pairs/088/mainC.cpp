// Context: Tachometer pulse intervals

// ------ Compliant Program (088_c.cpp)
// Context: Tachometer pulse intervals (10 pulses)
// Status: Array passed by reference (COMPLIANT)
// Benefit: Type ensures correct size for average computation
#include <iostream>
#include <iomanip>

namespace tach_088_c {

static long calc_avg(const long (&p)[10]){ long s=0; for(int i=0;i<10;i++){ s+=p[i]; } return s/10; }

void compute_rpm(long (&intervals)[10]) { // C API
    long avg = calc_avg(intervals);
    long rpm = 60000000L / avg;
    std::cout << "avg_us=" << avg << ", rpm=" << rpm << "\n";
}

} // namespace tach_088_c

int main(){
    using namespace tach_088_c;
    long pulses[10] = {10000,10100,9900,9800,10200,10000,9900,10100,9950,10000};
    compute_rpm(pulses);
    return 0;
}
