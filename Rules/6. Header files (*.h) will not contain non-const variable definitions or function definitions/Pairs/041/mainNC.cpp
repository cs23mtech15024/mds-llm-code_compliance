// Context: Wind turbine blade angle configuration

// -------- Non-Compliant Program (prog_041_nc.cpp)
// Context: Wind turbine blade angle logic
#include <iostream>
#include "seedNC.h" // seed041_blade_angle, seed041_is_safe()

namespace wind_nc {

float clamp(float a) { return (a < 0)?0:a; }

void assess(float angles[], std::size_t n) { // NC: decayed array
    for (std::size_t i = 0; i < n; ++i) {
        float c = clamp(angles[i]);
        bool safe = seed041_is_safe(c);
        std::cout << "blade=" << c
                  << " lim=" << seed041_blade_angle
                  << " safe=" << (safe?"Y":"N") << "\n";
    }
}

float maxv(float arr[], std::size_t n) { // NC
    float m=0; for(size_t i=0;i<n;++i) if(arr[i]>m) m=arr[i]; return m;
}

} // namespace wind_nc

int main(){
    using namespace wind_nc;
    float a[5] = {5.0F,10.0F,12.0F,14.0F,8.0F};
    assess(a,5);
    std::cout << "max=" << maxv(a,5) << "\n";
    return 0;
}
