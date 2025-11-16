// Context: Autopilot yaw control gain header

// -------- Non-Compliant Program (prog_058_nc.cpp)
// Context: Yaw control gain computation
#include <iostream>
#include "seedNC.h" // seed058_yaw_gain, seed058_compute()

namespace yaw_nc {

void apply(double e[], std::size_t n){ // NC decay
    for(size_t i=0;i<n;++i){
        double out = seed058_compute(e[i]);
        std::cout << "err=" << e[i]
                  << " gain=" << seed058_yaw_gain
                  << " out=" << out <<"\n";
    }
}

double maxd(double arr[], std::size_t n){double m=0;for(size_t i=0;i<n;++i)if(arr[i]>m)m=arr[i];return m;}

} // namespace yaw_nc

int main(){
    using namespace yaw_nc;
    double e[5]={0.1,0.2,0.4,0.3,0.5};
    apply(e,5);
    std::cout << "max=" << maxd(e,5)<<"\n";
    return 0;
}
