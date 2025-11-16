// Context: Machine tool spindle RPM limiter header

// -------- Compliant Program (prog_048_c.cpp)
// Context: Spindle RPM limiter — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed048_rpm_limit = 12000;
bool seed048_is_allowed(int rpm){ return rpm <= seed048_rpm_limit; }

namespace rpm_c {

template <std::size_t N>
void test(const int (&vals)[N]) {
    for (auto v : vals) {
        bool ok = seed048_is_allowed(v);
        std::cout << "rpm=" << v
                  << " lim=" << seed048_rpm_limit
                  << " ok=" << (ok?"Y":"N") << "\n";
    }
}

template <std::size_t N>
int maxv(const int (&arr)[N]){int m=0; for(auto v:arr) if(v>m)m=v; return m;}

} // namespace rpm_c

int main(){
    using namespace rpm_c;
    const int r[5]={8000,9000,12000,15000,7000};
    test(r);
    std::cout << "max=" << maxv(r) << "\n";
    return 0;
}
