// Context: Industrial sensor hysteresis header

// -------- Compliant Program (prog_053_c.cpp)
// Context: Hysteresis logic — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
float seed053_hysteresis = 0.5F;
bool seed053_should_switch(float oldv, float newv){ return (newv - oldv) > seed053_hysteresis; }

namespace hyst_c {

template <std::size_t N>
void detect(const float (&vals)[N]){
    for(size_t i=1;i<N;++i){
        bool sw = seed053_should_switch(vals[i-1], vals[i]);
        std::cout << "old=" << vals[i-1]
                  << " new=" << vals[i]
                  << " hyst=" << seed053_hysteresis
                  << " sw=" << (sw?"Y":"N") << "\n";
    }
}

template <std::size_t N>
float maxv(const float (&arr)[N]){float m=0;for(auto v:arr)if(v>m)m=v;return m;}

} // namespace hyst_c

int main(){
    using namespace hyst_c;
    const float v[5]={1.0F,1.3F,1.9F,2.0F,2.2F};
    detect(v);
    std::cout << "max=" << maxv(v)<<"\n";
    return 0;
}
