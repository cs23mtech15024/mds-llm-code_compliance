// Context: Smart lock retry timeout header

// -------- Compliant Program (prog_056_c.cpp)
// Context: Smart lock timeout — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed056_retry_timeout_ms = 3000;
bool seed056_timeout_expired(int elapsed){ return elapsed > seed056_retry_timeout_ms; }

namespace lock_c {

template <std::size_t N>
void test(const int (&arr)[N]){
    for(auto e:arr){
        bool ex = seed056_timeout_expired(e);
        std::cout << "elapsed=" << e
                  << " limit=" << seed056_retry_timeout_ms
                  << " expired=" << (ex?"Y":"N") << "\n";
    }
}

template <std::size_t N>
int maxv(const int (&arr)[N]){int m=0;for(auto v:arr)if(v>m)m=v;return m;}

} // namespace lock_c

int main(){
    using namespace lock_c;
    const int e[5]={500,2000,3500,1000,3000};
    test(e);
    std::cout << "max=" << maxv(e)<<"\n";
    return 0;
}
