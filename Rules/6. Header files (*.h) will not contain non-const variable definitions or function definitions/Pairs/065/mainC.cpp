// Context: Warehouse robot battery reserve threshold

// -------- Compliant Program (prog_065_c.cpp)
#include <iostream>
#include "seedC.h"

int seed065_reserve_pct = 15;
bool seed065_low_battery(int pct){ return pct < seed065_reserve_pct; }

namespace batt_c {

template <std::size_t N>
void scan(const int (&pct)[N]){
    for(auto v:pct){
        bool low = seed065_low_battery(v);
        std::cout << "pct=" << v
                  << " lim=" << seed065_reserve_pct
                  << " low=" << (low?"Y":"N") << "\n";
    }
}

template <std::size_t N>
int minv(const int (&arr)[N]){ int m=arr[0]; for(auto v:arr) if(v<m)m=v; return m; }

} // namespace batt_c

int main(){
    using namespace batt_c;
    const int b[5]={10,20,15,30,5};
    scan(b);
    std::cout << "min=" << minv(b)<<"\n";
    return 0;
}
