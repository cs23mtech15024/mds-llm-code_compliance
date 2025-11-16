// Context: HVAC fan speed parameters header

// -------- Non-Compliant Program (prog_069_nc.cpp)
#include <iostream>
#include "seedNC.h"

namespace fan_nc {

void check(int s[], std::size_t n){ // NC
    for(size_t i=0;i<n;++i){
        int out = seed069_limit(s[i]);
        std::cout << "in=" << s[i]
                  << " max=" << seed069_max_fan_speed
                  << " out=" << out << "\n";
    }
}

int maxv(int a[], std::size_t n){ int m=a[0]; for(size_t i=1;i<n;++i) if(a[i]>m)m=a[i]; return m; }

} // namespace fan_nc

int main(){
    using namespace fan_nc;
    int s[5]={1,4,5,7,2};
    check(s,5);
    std::cout << "maxv=" << maxv(s,5)<<"\n";
    return 0;
}
