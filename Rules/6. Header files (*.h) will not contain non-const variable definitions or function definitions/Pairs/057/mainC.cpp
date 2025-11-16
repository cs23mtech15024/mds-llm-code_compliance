// Context: Environmental sensor sampling interval header

// -------- Compliant Program (prog_057_c.cpp)
// Context: Sensor sampling — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
unsigned long seed057_sample_interval_ms = 1000UL;
unsigned long seed057_half_interval(){ return seed057_sample_interval_ms/2UL; }

namespace env_c {

template <std::size_t N>
void show(const unsigned long (&v)[N]){
    for(auto x:v){
        auto half = seed057_half_interval();
        std::cout << "val=" << x
                  << " interval=" << seed057_sample_interval_ms
                  << " half=" << half << "\n";
    }
}

template <std::size_t N>
unsigned long maxv(const unsigned long (&arr)[N]){unsigned long m=0;for(auto v:arr)if(v>m)m=v;return m;}

} // namespace env_c

int main(){
    using namespace env_c;
    const unsigned long v[4]={1000,1500,2000,500};
    show(v);
    std::cout << "max=" << maxv(v)<<"\n";
    return 0;
}
