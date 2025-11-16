// Context: Automated gate motor torque settings

// -------- Compliant Program (prog_064_c.cpp)
#include <iostream>
#include "seedC.h"

int seed064_torque_limit = 120;
bool seed064_overloaded(int t){ return t > seed064_torque_limit; }

namespace gate_c {

template <std::size_t N>
void check(const int (&vals)[N]){
    for(auto v:vals){
        bool o = seed064_overloaded(v);
        std::cout << "t=" << v
                  << " lim=" << seed064_torque_limit
                  << " ov=" << (o?"Y":"N") << "\n";
    }
}

template <std::size_t N>
int maxv(const int (&arr)[N]){ int m=arr[0]; for(auto v:arr) if(v>m)m=v; return m; }

} // namespace gate_c

int main(){
    using namespace gate_c;
    const int t[5]={80,100,120,130,90};
    check(t);
    std::cout << "max=" << maxv(t)<<"\n";
    return 0;
}
