// Context: Industrial sensor hysteresis header

// -------- Non-Compliant Program (prog_053_nc.cpp)
// Context: Hysteresis switching logic
#include <iostream>
#include "seedNC.h" // seed053_hysteresis, seed053_should_switch()

namespace hyst_nc {

void detect(float vals[], std::size_t n) { // NC
    for (size_t i=1;i<n;++i) {
        bool sw = seed053_should_switch(vals[i-1], vals[i]);
        std::cout << "old=" << vals[i-1]
                  << " new=" << vals[i]
                  << " hyst=" << seed053_hysteresis
                  << " sw=" << (sw?"Y":"N") << "\n";
    }
}

float maxv(float arr[], std::size_t n){float m=0;for(size_t i=0;i<n;++i)if(arr[i]>m)m=arr[i];return m;}

} // namespace hyst_nc

int main(){
    using namespace hyst_nc;
    float v[5]={1.0F,1.3F,1.9F,2.0F,2.2F};
    detect(v,5);
    std::cout << "max=" << maxv(v,5)<<"\n";
    return 0;
}
