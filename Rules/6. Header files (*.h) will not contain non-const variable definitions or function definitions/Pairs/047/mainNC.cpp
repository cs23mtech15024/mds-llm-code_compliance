// Context: Audio synthesizer detune factor table

// -------- Non-Compliant Program (prog_047_nc.cpp)
// Context: Audio synthesizer detune logic
#include <iostream>
#include "seedNC.h" // seed047_detune, seed047_apply()

namespace synth_nc {

void apply_all(float freqs[], std::size_t n) { // NC
    for (std::size_t i=0;i<n;++i) {
        float out = seed047_apply(freqs[i]);
        std::cout << "f=" << freqs[i]
                  << " detune=" << seed047_detune
                  << " out=" << out << "\n";
    }
}

float maxf(float arr[], std::size_t n){ float m=0; for(size_t i=0;i<n;++i) if(arr[i]>m)m=arr[i]; return m; }

} // namespace synth_nc

int main(){
    using namespace synth_nc;
    float f[4]={440,880,220,110};
    apply_all(f,4);
    std::cout << "max=" << maxf(f,4) << "\n";
    return 0;
}
