// Context: 3D printer extrusion multiplier header

// -------- Compliant Program (prog_055_c.cpp)
// Context: Extrusion multiplier — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
float seed055_extrude_mult = 1.0F;
float seed055_scaled(float v){ return v * seed055_extrude_mult; }

namespace extr_c {

template <std::size_t N>
void adjust(const float (&vals)[N]) {
    for(auto v:vals){
        float out = seed055_scaled(v);
        std::cout << "in=" << v
                  << " mult=" << seed055_extrude_mult
                  << " out=" << out << "\n";
    }
}

template <std::size_t N>
float avg(const float (&arr)[N]){float s=0;for(auto v:arr)s+=v;return N?s/N:0;}

} // namespace extr_c

int main(){
    using namespace extr_c;
    const float vals[4]={1.0F,1.2F,0.9F,1.1F};
    adjust(vals);
    std::cout << "avg=" << avg(vals)<<"\n";
    return 0;
}
