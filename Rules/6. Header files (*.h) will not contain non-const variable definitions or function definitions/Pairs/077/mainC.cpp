// Context: Medical heart rate smoothing factor

// -------- Compliant Program (prog_077_c.cpp)
#include <iostream>
#include "seedC.h"

float seed077_smooth_factor = 0.85F;
float seed077_smooth(float hr) { return hr * seed077_smooth_factor; }

namespace hr_c {

template <std::size_t N>
void smooth(const float (&data)[N]){
    for(auto v:data){
        float out = seed077_smooth(v);
        std::cout << "raw=" << v
                  << " fact=" << seed077_smooth_factor
                  << " sm=" << out << "\n";
    }
}

template <std::size_t N>
float avg(const float (&a)[N]){ float s=0; for(auto v:a) s+=v; return N? s/N : 0; }

} // namespace hr_c

int main(){
    using namespace hr_c;
    const float beats[6] = {72.0F, 75.0F, 80.0F, 77.0F, 74.0F, 76.0F};
    smooth(beats);
    std::cout << "avg=" << avg(beats) << "\n";
    return 0;
}
