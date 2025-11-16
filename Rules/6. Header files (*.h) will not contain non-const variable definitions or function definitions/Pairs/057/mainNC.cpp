// Context: Environmental sensor sampling interval header

// -------- Non-Compliant Program (prog_057_nc.cpp)
// Context: Sensor sampling interval
#include <iostream>
#include "seedNC.h" // seed057_sample_interval_ms, seed057_half_interval()

namespace env_nc {

void show(unsigned long v[], std::size_t n){ // NC
    for(size_t i=0;i<n;++i){
        auto half = seed057_half_interval();
        std::cout << "val=" << v[i]
                  << " interval=" << seed057_sample_interval_ms
                  << " half=" << half << "\n";
    }
}

unsigned long maxv(unsigned long a[], std::size_t n){unsigned long m=0;for(size_t i=0;i<n;++i)if(a[i]>m)m=a[i];return m;}

} // namespace env_nc

int main(){
    using namespace env_nc;
    unsigned long v[4]={1000,1500,2000,500};
    show(v,4);
    std::cout << "max=" << maxv(v,4)<<"\n";
    return 0;
}
