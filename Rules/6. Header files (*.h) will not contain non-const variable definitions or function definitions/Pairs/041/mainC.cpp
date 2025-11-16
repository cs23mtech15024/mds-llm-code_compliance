// Context: Wind turbine blade angle configuration

// -------- Compliant Program (prog_041_c.cpp)
// Context: Wind turbine blade angle logic — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
float seed041_blade_angle = 12.5F;
bool seed041_is_safe(float a) { return a < seed041_blade_angle; }

namespace wind_c {

float clamp(float a) { return (a < 0)?0:a; }

template <std::size_t N>
void assess(const float (&angles)[N]) {
    for (auto a : angles) {
        float c = clamp(a);
        bool safe = seed041_is_safe(c);
        std::cout << "blade=" << c
                  << " lim=" << seed041_blade_angle
                  << " safe=" << (safe?"Y":"N") << "\n";
    }
}

template <std::size_t N>
float maxv(const float (&arr)[N]) {
    float m=0; for(auto v:arr) if(v>m) m=v; return m;
}

} // namespace wind_c

int main(){
    using namespace wind_c;
    const float a[5]={5,10,12,14,8};
    assess(a);
    std::cout << "max=" << maxv(a) << "\n";
    return 0;
}
