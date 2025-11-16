// Context: 3D printer extrusion multiplier header

// -------- Non-Compliant Program (prog_055_nc.cpp)
// Context: Extrusion multiplier logic
#include <iostream>
#include "seedNC.h" // seed055_extrude_mult, seed055_scaled()

namespace extr_nc {

void adjust(float v[], std::size_t n) { // NC
    for(size_t i=0;i<n;++i){
        float out = seed055_scaled(v[i]);
        std::cout << "in=" << v[i]
                  << " mult=" << seed055_extrude_mult
                  << " out=" << out << "\n";
    }
}

float avg(float arr[], std::size_t n){float s=0;for(size_t i=0;i<n;++i)s+=arr[i];return n?s/n:0;}

} // namespace extr_nc

int main(){
    using namespace extr_nc;
    float vals[4]={1.0F,1.2F,0.9F,1.1F};
    adjust(vals,4);
    std::cout << "avg=" << avg(vals,4)<<"\n";
    return 0;
}
