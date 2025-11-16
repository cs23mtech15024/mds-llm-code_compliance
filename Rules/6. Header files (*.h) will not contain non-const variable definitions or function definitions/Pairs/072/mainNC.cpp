// Context: Marine sonar gain compensation header

// -------- Non-Compliant Program (prog_072_nc.cpp)
#include <iostream>
#include "seedNC.h" // seed072_gain, seed072_apply_gain()

namespace sonar_nc {

void process(float samples[], std::size_t n) { // NC decay
    for (std::size_t i=0;i<n;++i) {
        float out = seed072_apply_gain(samples[i]);
        std::cout << "in=" << samples[i]
                  << " gain=" << seed072_gain
                  << " out=" << out << "\n";
    }
}

float maxv(float a[], std::size_t n){ float m=a[0]; for(size_t i=1;i<n;++i) if(a[i]>m) m=a[i]; return m; }

} // namespace sonar_nc

int main(){
    using namespace sonar_nc;
    float s[5] = {0.5F, 1.2F, 0.8F, 1.5F, 0.9F};
    process(s,5);
    std::cout << "peak=" << maxv(s,5) << "\n";
    return 0;
}
