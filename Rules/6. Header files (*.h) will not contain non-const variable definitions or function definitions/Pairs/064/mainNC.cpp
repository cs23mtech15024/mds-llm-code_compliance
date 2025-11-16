// Context: Automated gate motor torque settings

// -------- Non-Compliant Program (prog_064_nc.cpp)
#include <iostream>
#include "seedNC.h"

namespace gate_nc {

void check(int vals[], std::size_t n){ // NC
    for(size_t i=0;i<n;++i){
        bool o = seed064_overloaded(vals[i]);
        std::cout << "t=" << vals[i]
                  << " lim=" << seed064_torque_limit
                  << " ov=" << (o?"Y":"N") << "\n";
    }
}

int maxv(int a[], std::size_t n){ int m=a[0]; for(size_t i=1;i<n;++i) if(a[i]>m)m=a[i]; return m; }

} // namespace gate_nc

int main(){
    using namespace gate_nc;
    int t[5]={80,100,120,130,90};
    check(t,5);
    std::cout << "max=" << maxv(t,5)<<"\n";
    return 0;
}
