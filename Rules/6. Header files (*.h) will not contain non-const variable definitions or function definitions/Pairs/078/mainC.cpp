// Context: Warehouse barcode scanner retry config

// -------- Compliant Program (prog_078_c.cpp)
#include <iostream>
#include "seedC.h"

int seed078_max_retries = 4;
bool seed078_allow_retry(int c) { return c < seed078_max_retries; }

namespace scan_c {

template <std::size_t N>
void attempt(const int (&counts)[N]){
    for(auto v:counts){
        bool ok = seed078_allow_retry(v);
        std::cout << "attempts=" << v
                  << " max=" << seed078_max_retries
                  << " allow_retry=" << (ok?"Y":"N") << "\n";
    }
}

template <std::size_t N>
int maxv(const int (&a)[N]){ int m=a[0]; for(auto v:a) if(v>m)m=v; return m; }

} // namespace scan_c

int main(){
    using namespace scan_c;
    const int tries[5] = {0,1,2,3,4};
    attempt(tries);
    std::cout << "max=" << maxv(tries) << "\n";
    return 0;
}
