// Context: Display refresh compensation factor

// -------- Compliant Program (prog_066_c.cpp)
#include <iostream>
#include "seedC.h"

float seed066_refresh_factor = 1.05F;
float seed066_apply(float hz){ return hz * seed066_refresh_factor; }

namespace disp_c {

template <std::size_t N>
void calc(const float (&hz)[N]){
    for(auto v:hz){
        float out = seed066_apply(v);
        std::cout << "hz=" << v
                  << " fac=" << seed066_refresh_factor
                  << " out=" << out << "\n";
    }
}

template <std::size_t N>
float maxf(const float (&arr)[N]){ float m=arr[0]; for(auto v:arr) if(v>m)m=v; return m; }

} // namespace disp_c

int main(){
    using namespace disp_c;
    const float f[5]={60,75,90,120,144};
    calc(f);
    std::cout << "max=" << maxf(f)<<"\n";
    return 0;
}
