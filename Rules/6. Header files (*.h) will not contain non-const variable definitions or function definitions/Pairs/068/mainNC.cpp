// Context: Smart irrigation moisture threshold header

// -------- Non-Compliant Program (prog_068_nc.cpp)
#include <iostream>
#include "seedNC.h"

namespace irr_nc {

void eval(int v[], std::size_t n){ // NC
    for(size_t i=0;i<n;++i){
        bool w = seed068_needs_water(v[i]);
        std::cout << "m=" << v[i]
                  << " thr=" << seed068_moisture_threshold
                  << " need=" << (w?"Y":"N") << "\n";
    }
}

int minv(int a[], std::size_t n){ int m=a[0]; for(size_t i=1;i<n;++i) if(a[i]<m)m=a[i]; return m; }

} // namespace irr_nc

int main(){
    using namespace irr_nc;
    int m[5]={30,40,55,60,20};
    eval(m,5);
    std::cout << "min=" << minv(m,5)<<"\n";
    return 0;
}
