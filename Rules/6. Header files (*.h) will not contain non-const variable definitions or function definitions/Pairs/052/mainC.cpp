// Context: Satellite telemetry beacon interval header

// -------- Compliant Program (prog_052_c.cpp)
// Context: Satellite beacon interval — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed052_beacon_interval_s = 60;
int seed052_next_interval(){ return seed052_beacon_interval_s; }

namespace sat_c {

template <std::size_t N>
void schedule(const int (&times)[N]){
    for(auto t:times){
        int nxt = seed052_next_interval();
        std::cout << "t=" << t
                  << " int=" << seed052_beacon_interval_s
                  << " next=" << nxt << "\n";
    }
}

template <std::size_t N>
int sum(const int (&arr)[N]){int s=0;for(auto v:arr)s+=v;return s;}

} // namespace sat_c

int main(){
    using namespace sat_c;
    const int t[4]={0,60,120,180};
    schedule(t);
    std::cout << "sum=" << sum(t)<<"\n";
    return 0;
}
