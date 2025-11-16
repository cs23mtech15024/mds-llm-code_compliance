// Context: Satellite telemetry beacon interval header

// -------- Non-Compliant Program (prog_052_nc.cpp)
// Context: Satellite beacon interval logic
#include <iostream>
#include "seedNC.h" // seed052_beacon_interval_s, seed052_next_interval()

namespace sat_nc {

void schedule(int times[], std::size_t n) { // NC
    for(size_t i=0;i<n;++i){
        int nxt = seed052_next_interval();
        std::cout << "t=" << times[i]
                  << " int=" << seed052_beacon_interval_s
                  << " next=" << nxt << "\n";
    }
}

int sum(int arr[], std::size_t n){int s=0;for(size_t i=0;i<n;++i)s+=arr[i];return s;}

} // namespace sat_nc

int main(){
    using namespace sat_nc;
    int t[4]={0,60,120,180};
    schedule(t,4);
    std::cout << "sum=" << sum(t,4)<<"\n";
    return 0;
}
