// Context: HVAC fan speed parameters header

// -------- Compliant Program (prog_069_c.cpp)
#include <iostream>
#include "seedC.h"

int seed069_max_fan_speed = 5;
int seed069_limit(int s){ return (s > seed069_max_fan_speed) ? seed069_max_fan_speed : s; }

namespace fan_c {

template <std::size_t N>
void check(const int (&s)[N]){
    for(auto v:s){
        int out = seed069_limit(v);
        std::cout << "in=" << v
                  << " max=" << seed069_max_fan_speed
                  << " out=" << out << "\n";
    }
}

template <std::size_t N>
int maxv(const int (&arr)[N]){ int m=arr[0]; for(auto v:arr) if(v>m)m=v; return m; }

} // namespace fan_c

int main(){
    using namespace fan_c;
    const int s[5]={1,4,5,7,2};
    check(s);
    std::cout << "maxv=" << maxv(s)<<"\n";
    return 0;
}
