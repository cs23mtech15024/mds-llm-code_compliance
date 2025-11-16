// Context: Smart thermostat humidity correction parameters

// -------- Compliant Program (prog_062_c.cpp)
#include <iostream>
#include "seedC.h"

float seed062_humidity_offset = 3.5F;
float seed062_correct(float h){ return h + seed062_humidity_offset; }

namespace hum_c {

template <std::size_t N>
void adjust(const float (&h)[N]){
    for(auto v:h){
        float out = seed062_correct(v);
        std::cout << "h=" << v
                  << " off=" << seed062_humidity_offset
                  << " out=" << out << "\n";
    }
}

template <std::size_t N>
float maxv(const float (&arr)[N]){ float m=arr[0]; for(auto v:arr) if(v>m)m=v; return m; }

} // namespace hum_c

int main(){
    using namespace hum_c;
    const float h[5]={40.0F,42.5F,43.0F,39.0F,41.0F};
    adjust(h);
    std::cout << "max=" << maxv(h)<<"\n";
    return 0;
}
