// Context: Factory conveyor belt speed configuration

// -------- Compliant Program (prog_070_c.cpp)
#include <iostream>
#include "seedC.h"

float seed070_belt_speed = 1.25F;
bool seed070_within_limit(float s){ return s <= seed070_belt_speed; }

namespace belt_c {

template <std::size_t N>
void check(const float (&s)[N]){
    for(auto v:s){
        bool ok = seed070_within_limit(v);
        std::cout << "spd=" << v
                  << " lim=" << seed070_belt_speed
                  << " ok=" << (ok?"Y":"N") << "\n";
    }
}

template <std::size_t N>
float maxf(const float (&arr)[N]){ float m=arr[0]; for(auto v:arr) if(v>m)m=v; return m; }

} // namespace belt_c

int main(){
    using namespace belt_c;
    const float s[5]={1.0F,1.2F,1.3F,1.0F,0.9F};
    check(s);
    std::cout << "maxf=" << maxf(s)<<"\n";
    return 0;
}
