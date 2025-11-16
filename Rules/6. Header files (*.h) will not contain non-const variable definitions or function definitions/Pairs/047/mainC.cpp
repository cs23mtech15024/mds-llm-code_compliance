// Context: Audio synthesizer detune factor table

// -------- Compliant Program (prog_047_c.cpp)
// Context: Audio synthesizer detune logic — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
float seed047_detune = 0.03F;
float seed047_apply(float f){ return f + (f * seed047_detune); }

namespace synth_c {

template <std::size_t N>
void apply_all(const float (&freqs)[N]) {
    for (auto f : freqs) {
        float out = seed047_apply(f);
        std::cout << "f=" << f
                  << " detune=" << seed047_detune
                  << " out=" << out << "\n";
    }
}

template <std::size_t N>
float maxf(const float (&arr)[N]){
    float m=0; for(auto v:arr) if(v>m)m=v; return m;
}

} // namespace synth_c

int main(){
    using namespace synth_c;
    const float f[4]={440,880,220,110};
    apply_all(f);
    std::cout << "max=" << maxf(f) << "\n";
    return 0;
}
