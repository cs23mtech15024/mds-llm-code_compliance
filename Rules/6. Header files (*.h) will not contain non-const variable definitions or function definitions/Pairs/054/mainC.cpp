// Context: Smart grid load shedding threshold header

// -------- Compliant Program (prog_054_c.cpp)
// Context: Load shedding — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
double seed054_shed_threshold_kw = 500.0;
double seed054_margin(double load){ return seed054_shed_threshold_kw - load; }

namespace grid_c {

template <std::size_t N>
void margin_test(const double (&loads)[N]){
    for(auto v:loads){
        double m = seed054_margin(v);
        std::cout << "load=" << v
                  << " thr=" << seed054_shed_threshold_kw
                  << " margin=" << m << "\n";
    }
}

template <std::size_t N>
double maxd(const double (&arr)[N]){double m=0;for(auto v:arr)if(v>m)m=v;return m;}

} // namespace grid_c

int main(){
    using namespace grid_c;
    const double l[5]={100,200,350,450,500};
    margin_test(l);
    std::cout << "max=" << maxd(l)<<"\n";
    return 0;
}
