// Context: Smart grid load shedding threshold header

// -------- Non-Compliant Program (prog_054_nc.cpp)
// Context: Load shedding margin logic
#include <iostream>
#include "seedNC.h" // seed054_shed_threshold_kw, seed054_margin()

namespace grid_nc {

void margin_test(double loads[], std::size_t n) { // NC
    for (size_t i=0;i<n;++i) {
        double m = seed054_margin(loads[i]);
        std::cout << "load=" << loads[i]
                  << " thr=" << seed054_shed_threshold_kw
                  << " margin=" << m << "\n";
    }
}

double maxd(double arr[], std::size_t n){double m=0;for(size_t i=0;i<n;++i)if(arr[i]>m)m=arr[i];return m;}

} // namespace grid_nc

int main(){
    using namespace grid_nc;
    double l[5]={100,200,350,450,500};
    margin_test(l,5);
    std::cout << "max=" << maxd(l,5)<<"\n";
    return 0;
}
