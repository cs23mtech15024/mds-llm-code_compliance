// Context: Factory conveyor belt speed configuration

// -------- Non-Compliant Program (prog_070_nc.cpp)
#include <iostream>
#include "seedNC.h"

namespace belt_nc {

void check(float s[], std::size_t n){ // NC decay
    for(size_t i=0;i<n;++i){
        bool ok = seed070_within_limit(s[i]);
        std::cout << "spd=" << s[i]
                  << " lim=" << seed070_belt_speed
                  << " ok=" << (ok?"Y":"N") << "\n";
    }
}

float maxf(float a[], std::size_t n){ float m=a[0]; for(size_t i=1;i<n;++i) if(a[i]>m)m=a[i]; return m; }

} // namespace belt_nc

int main(){
    using namespace belt_nc;
    float s[5]={1.0F,1.2F,1.3F,1.0F,0.9F};
    check(s,5);
    std::cout << "maxf=" << maxf(s,5)<<"\n";
    return 0;
}
