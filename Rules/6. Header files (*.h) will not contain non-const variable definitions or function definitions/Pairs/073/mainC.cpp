// Context: Wind turbine blade pitch calibration

// -------- Compliant Program (prog_073_c.cpp)
#include <iostream>
#include "seedC.h"

double seed073_pitch_offset = 1.8;
double seed073_calibrate(double p) { return p + seed073_pitch_offset; }

namespace wind_c {

template <std::size_t N>
void calibrate(const double (&angles)[N]){
    for(auto v:angles){
        double out = seed073_calibrate(v);
        std::cout << "angle=" << v
                  << " off=" << seed073_pitch_offset
                  << " cal=" << out << "\n";
    }
}

template <std::size_t N>
double maxd(const double (&a)[N]){ double m=a[0]; for(auto v:a) if(v>m)m=v; return m; }

} // namespace wind_c

int main(){
    using namespace wind_c;
    const double ang[4] = {2.0, 3.5, 1.2, 4.0};
    calibrate(ang);
    std::cout << "peak=" << maxd(ang) << "\n";
    return 0;
}
