// Context: Weather station rainfall calibration header

// -------- Compliant Program (prog_063_c.cpp)
#include <iostream>
#include "seedC.h"

double seed063_rain_factor = 0.87;
double seed063_calibrate(double mm){ return mm * seed063_rain_factor; }

namespace rain_c {

template <std::size_t N>
void read(const double (&mm)[N]){
    for(auto v:mm){
        double out = seed063_calibrate(v);
        std::cout << "raw=" << v
                  << " fac=" << seed063_rain_factor
                  << " cal=" << out << "\n";
    }
}

template <std::size_t N>
double maxd(const double (&arr)[N]){ double m=arr[0]; for(auto v:arr) if(v>m)m=v; return m; }

} // namespace rain_c

int main(){
    using namespace rain_c;
    const double d[5]={1.2,2.0,5.5,3.3,4.1};
    read(d);
    std::cout << "max=" << maxd(d)<<"\n";
    return 0;
}
