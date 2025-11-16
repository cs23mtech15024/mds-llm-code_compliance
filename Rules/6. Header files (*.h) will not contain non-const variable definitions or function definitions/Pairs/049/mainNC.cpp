// Context: Network routing retry limit header

// -------- Non-Compliant Program (prog_049_nc.cpp)
// Context: Routing retry control
#include <iostream>
#include "seedNC.h" // seed049_retry_limit, seed049_should_retry()

namespace route_nc {

void simulate(int hops[], std::size_t n) { // NC
    for(size_t i=0;i<n;++i){
        bool retry = seed049_should_retry(hops[i]);
        std::cout << "hop=" << hops[i]
                  << " lim=" << seed049_retry_limit
                  << " retry=" << (retry?"Y":"N") << "\n";
    }
}

int sum(int a[], std::size_t n){int s=0;for(size_t i=0;i<n;++i)s+=a[i];return s;}

} // namespace route_nc

int main(){
    using namespace route_nc;
    int h[5]={0,1,2,5,7};
    simulate(h,5);
    std::cout << "sum=" << sum(h,5)<<"\n";
    return 0;
}
