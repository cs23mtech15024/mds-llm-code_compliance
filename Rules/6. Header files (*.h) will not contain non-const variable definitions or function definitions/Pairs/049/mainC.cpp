// Context: Network routing retry limit header

// -------- Compliant Program (prog_049_c.cpp)
// Context: Routing retry control — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed049_retry_limit = 5;
bool seed049_should_retry(int n){ return n < seed049_retry_limit; }

namespace route_c {

template <std::size_t N>
void simulate(const int (&hops)[N]) {
    for (auto h : hops) {
        bool retry = seed049_should_retry(h);
        std::cout << "hop=" << h
                  << " lim=" << seed049_retry_limit
                  << " retry=" << (retry?"Y":"N") << "\n";
    }
}

template <std::size_t N>
int sum(const int (&arr)[N]){int s=0; for(auto v:arr)s+=v; return s;}

} // namespace route_c

int main(){
    using namespace route_c;
    const int h[5]={0,1,2,5,7};
    simulate(h);
    std::cout << "sum=" << sum(h)<<"\n";
    return 0;
}
