// Context: Satellite power budget margin header

// -------- Non-Compliant Program (prog_079_nc.cpp)
#include <iostream>
#include "seedNC.h" // seed079_margin, seed079_within_margin()

namespace sat_nc {

void check(double usages[], std::size_t n) { // NC
    for (std::size_t i=0;i<n;++i) {
        bool ok = seed079_within_margin(usages[i]);
        std::cout << "usage=" << usages[i]
                  << " margin=" << seed079_margin
                  << " within=" << (ok?"YES":"NO") << "\n";
    }
}

double sumd(double a[], std::size_t n){ double s=0; for(size_t i=0;i<n;++i) s+=a[i]; return s; }

} // namespace sat_nc

int main(){
    using namespace sat_nc;
    double u[4] = {10.0, 11.5, 12.0, 13.0};
    check(u,4);
    std::cout << "total=" << sumd(u,4) << "\n";
    return 0;
}
