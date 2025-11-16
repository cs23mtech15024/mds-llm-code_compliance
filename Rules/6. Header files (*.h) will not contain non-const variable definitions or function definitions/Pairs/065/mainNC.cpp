// Context: Warehouse robot battery reserve threshold

// -------- Non-Compliant Program (prog_065_nc.cpp)
#include <iostream>
#include "seedNC.h"

namespace batt_nc {

void scan(int pct[], std::size_t n){ // NC
    for(size_t i=0;i<n;++i){
        bool low = seed065_low_battery(pct[i]);
        std::cout << "pct=" << pct[i]
                  << " lim=" << seed065_reserve_pct
                  << " low=" << (low?"Y":"N") << "\n";
    }
}

int minv(int a[], std::size_t n){ int m=a[0]; for(size_t i=1;i<n;++i) if(a[i]<m)m=a[i]; return m; }

} // namespace batt_nc

int main(){
    using namespace batt_nc;
    int b[5]={10,20,15,30,5};
    scan(b,5);
    std::cout << "min=" << minv(b,5)<<"\n";
    return 0;
}
