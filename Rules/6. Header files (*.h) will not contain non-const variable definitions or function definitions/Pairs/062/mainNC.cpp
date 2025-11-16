// Context: Smart thermostat humidity correction parameters

// -------- Non-Compliant Program (prog_062_nc.cpp)
#include <iostream>
#include "seedNC.h"

namespace hum_nc {

void adjust(float h[], std::size_t n) { // NC
    for (size_t i=0;i<n;++i) {
        float out = seed062_correct(h[i]);
        std::cout << "h=" << h[i]
                  << " off=" << seed062_humidity_offset
                  << " out=" << out << "\n";
    }
}

float maxv(float arr[], std::size_t n){ float m=arr[0]; for(size_t i=1;i<n;++i) if(arr[i]>m)m=arr[i]; return m; }

} // namespace hum_nc

int main(){
    using namespace hum_nc;
    float h[5]={40.0F,42.5F,43.0F,39.0F,41.0F};
    adjust(h,5);
    std::cout << "max=" << maxv(h,5)<<"\n";
    return 0;
}
