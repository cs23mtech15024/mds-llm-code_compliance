// Context: Marine sonar gain compensation header

// -------- Compliant Program (prog_072_c.cpp)
#include <iostream>
#include "seedC.h"

float seed072_gain = 2.4F;
float seed072_apply_gain(float v) { return v * seed072_gain; }

namespace sonar_c {

template <std::size_t N>
void process(const float (&samples)[N]) {
    for (auto v : samples) {
        float out = seed072_apply_gain(v);
        std::cout << "in=" << v
                  << " gain=" << seed072_gain
                  << " out=" << out << "\n";
    }
}

template <std::size_t N>
float maxv(const float (&a)[N]){ float m=a[0]; for(auto v:a) if(v>m) m=v; return m; }

} // namespace sonar_c

int main(){
    using namespace sonar_c;
    const float s[5] = {0.5F, 1.2F, 0.8F, 1.5F, 0.9F};
    process(s);
    std::cout << "peak=" << maxv(s) << "\n";
    return 0;
}
