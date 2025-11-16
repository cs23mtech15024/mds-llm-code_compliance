// Context: Weather station rainfall calibration header

// -------- Non-Compliant Program (prog_063_nc.cpp)
#include <iostream>
#include "seedNC.h"

namespace rain_nc {

void read(double mm[], std::size_t n){ // NC
    for(size_t i=0;i<n;++i){
        double out = seed063_calibrate(mm[i]);
        std::cout << "raw=" << mm[i]
                  << " fac=" << seed063_rain_factor
                  << " cal=" << out << "\n";
    }
}

double maxd(double arr[], std::size_t n){ double m=arr[0]; for(size_t i=1;i<n;++i) if(arr[i]>m) m=arr[i]; return m; }

} // namespace rain_nc

int main(){
    using namespace rain_nc;
    double d[5]={1.2,2.0,5.5,3.3,4.1};
    read(d,5);
    std::cout << "max=" << maxd(d,5)<<"\n";
    return 0;
}
