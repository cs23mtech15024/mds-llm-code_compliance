// Context: Autopilot yaw control gain header

// -------- Compliant Program (prog_058_c.cpp)
// Context: Yaw control — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
double seed058_yaw_gain = 0.75;
double seed058_compute(double err){ return err * seed058_yaw_gain; }

namespace yaw_c {

template <std::size_t N>
void apply(const double (&e)[N]){
    for(auto v:e){
        double out = seed058_compute(v);
        std::cout << "err=" << v
                  << " gain=" << seed058_yaw_gain
                  << " out=" << out <<"\n";
    }
}

template <std::size_t N>
double maxd(const double (&arr)[N]){double m=0;for(auto v:arr)if(v>m)m=v;return m;}

} // namespace yaw_c

int main(){
    using namespace yaw_c;
    const double e[5]={0.1,0.2,0.4,0.3,0.5};
    apply(e);
    std::cout << "max=" << maxd(e)<<"\n";
    return 0;
}
