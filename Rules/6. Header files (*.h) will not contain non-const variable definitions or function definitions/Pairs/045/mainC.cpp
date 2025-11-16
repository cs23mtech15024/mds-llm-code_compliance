// Context: Smartwatch heart rate smoothing window

// -------- Compliant Program (prog_045_c.cpp)
// Context: HR smoothing window — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed045_smooth_window = 6;
float seed045_smooth_hr(float* vals){ return vals[0]; }

namespace hr_c {

template <std::size_t N>
void smooth(const float (&v)[N]) {
    for(size_t i=0;i<N;++i){
        float tmp=v[i];
        float out = seed045_smooth_hr(&tmp);
        std::cout << "hr=" << v[i]
                  << " win=" << seed045_smooth_window
                  << " out=" << out <<"\n";
    }
}

template <std::size_t N>
float avg(const float (&arr)[N]){float s=0;for(auto v:arr)s+=v;return N?s/N:0;}

} // namespace hr_c

int main(){
    using namespace hr_c;
    const float h[5]={70,72,78,80,75};
    smooth(h);
    std::cout << "avg=" << avg(h)<<"\n";
    return 0;
}
