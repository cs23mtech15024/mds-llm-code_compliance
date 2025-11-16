// Context: Biosignal ECG threshold header

// -------- Compliant Program (prog_043_c.cpp)
// Context: ECG peak detection — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
float seed043_ecg_threshold = 0.45F;
bool seed043_is_peak(float v){ return v > seed043_ecg_threshold; }

namespace ecg_c {

template <std::size_t N>
void detect(const float (&s)[N]) {
    for (auto v : s) {
        bool pk = seed043_is_peak(v);
        std::cout << "v=" << v
                  << " thr=" << seed043_ecg_threshold
                  << " peak=" << (pk?"Y":"N") << "\n";
    }
}

template <std::size_t N>
float maxv(const float (&arr)[N]) {
    float m=0; for(auto v:arr) if(v>m)m=v; return m;
}

} // namespace ecg_c

int main(){
    using namespace ecg_c;
    const float v[6]={0.2F,0.3F,0.5F,0.6F,0.4F,0.1F};
    detect(v);
    std::cout << "max=" << maxv(v)<<"\n";
    return 0;
}
