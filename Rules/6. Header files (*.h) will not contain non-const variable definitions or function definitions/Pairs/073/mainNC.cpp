// Context: Wind turbine blade pitch calibration

// -------- Non-Compliant Program (prog_073_nc.cpp)
#include <iostream>
#include "seedNC.h" // seed073_pitch_offset, seed073_calibrate()

namespace wind_nc {

void calibrate(double angles[], std::size_t n) { // NC
    for (std::size_t i=0;i<n;++i) {
        double out = seed073_calibrate(angles[i]);
        std::cout << "angle=" << angles[i]
                  << " off=" << seed073_pitch_offset
                  << " cal=" << out << "\n";
    }
}

double maxd(double a[], std::size_t n){ double m=a[0]; for(size_t i=1;i<n;++i) if(a[i]>m) m=a[i]; return m; }

} // namespace wind_nc

int main(){
    using namespace wind_nc;
    double ang[4] = {2.0, 3.5, 1.2, 4.0};
    calibrate(ang,4);
    std::cout << "peak=" << maxd(ang,4) << "\n";
    return 0;
}
