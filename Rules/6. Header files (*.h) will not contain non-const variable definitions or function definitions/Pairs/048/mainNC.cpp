// Context: Machine tool spindle RPM limiter header

// -------- Non-Compliant Program (prog_048_nc.cpp)
// Context: Spindle RPM limiter
#include <iostream>
#include "seedNC.h" // seed048_rpm_limit, seed048_is_allowed()

namespace rpm_nc {

void test(int vals[], std::size_t n) { // NC
    for(std::size_t i=0;i<n;++i){
        bool ok = seed048_is_allowed(vals[i]);
        std::cout << "rpm=" << vals[i]
                  << " lim=" << seed048_rpm_limit
                  << " ok=" << (ok?"Y":"N") << "\n";
    }
}

int maxv(int arr[], std::size_t n){int m=0; for(size_t i=0;i<n;++i) if(arr[i]>m)m=arr[i]; return m;}

} // namespace rpm_nc

int main(){
    using namespace rpm_nc;
    int r[5]={8000,9000,12000,15000,7000};
    test(r,5);
    std::cout << "max=" << maxv(r,5) << "\n";
    return 0;
}
