// Context: Smart irrigation moisture threshold header

// -------- Compliant Program (prog_068_c.cpp)
#include <iostream>
#include "seedC.h"

int seed068_moisture_threshold = 45;
bool seed068_needs_water(int v){ return v < seed068_moisture_threshold; }

namespace irr_c {

template <std::size_t N>
void eval(const int (&v)[N]){
    for(auto x:v){
        bool w = seed068_needs_water(x);
        std::cout << "m=" << x
                  << " thr=" << seed068_moisture_threshold
                  << " need=" << (w?"Y":"N") << "\n";
    }
}

template <std::size_t N>
int minv(const int (&arr)[N]){ int m=arr[0]; for(auto v:arr) if(v<m)m=v; return m; }

} // namespace irr_c

int main(){
    using namespace irr_c;
    const int m[5]={30,40,55,60,20};
    eval(m);
    std::cout << "min=" << minv(m)<<"\n";
    return 0;
}
