// Context: Display refresh compensation factor

// -------- Non-Compliant Program (prog_066_nc.cpp)
#include <iostream>
#include "seedNC.h"

namespace disp_nc {

void calc(float hz[], std::size_t n){ // NC
    for(size_t i=0;i<n;++i){
        float out = seed066_apply(hz[i]);
        std::cout << "hz=" << hz[i]
                  << " fac=" << seed066_refresh_factor
                  << " out=" << out << "\n";
    }
}

float maxf(float a[], std::size_t n){ float m=a[0]; for(size_t i=1;i<n;++i) if(a[i]>m)m=a[i]; return m; }

} // namespace disp_nc

int main(){
    using namespace disp_nc;
    float f[5]={60,75,90,120,144};
    calc(f,5);
    std::cout << "max=" << maxf(f,5)<<"\n";
    return 0;
}
