// Context: Satellite power budget margin header

// -------- Compliant Program (prog_079_c.cpp)
#include <iostream>
#include "seedC.h"

double seed079_margin = 12.5;
bool seed079_within_margin(double usage) { return usage < seed079_margin; }

namespace sat_c {

template <std::size_t N>
void check(const double (&usages)[N]){
    for(auto v:usages){
        bool ok = seed079_within_margin(v);
        std::cout << "usage=" << v
                  << " margin=" << seed079_margin
                  << " within=" << (ok?"YES":"NO") << "\n";
    }
}

template <std::size_t N>
double sumd(const double (&a)[N]){ double s=0; for(auto v:a) s+=v; return s; }

} // namespace sat_c

int main(){
    using namespace sat_c;
    const double u[4] = {10.0, 11.5, 12.0, 13.0};
    check(u);
    std::cout << "total=" << sumd(u) << "\n";
    return 0;
}
