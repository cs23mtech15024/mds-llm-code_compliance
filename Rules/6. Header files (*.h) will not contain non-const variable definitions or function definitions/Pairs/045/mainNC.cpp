// Context: Smartwatch heart rate smoothing window

// -------- Non-Compliant Program (prog_045_nc.cpp)
// Context: HR smoothing window
#include <iostream>
#include "seedNC.h" // seed045_smooth_window, seed045_smooth_hr()

namespace hr_nc {

void smooth(float* v, std::size_t n) { // NC pointer
    for(size_t i=0;i<n;++i){
        float out = seed045_smooth_hr(&v[i]);
        std::cout << "hr=" << v[i]
                  << " win=" << seed045_smooth_window
                  << " out=" << out <<"\n";
    }
}

float avg(float arr[], std::size_t n){float s=0;for(size_t i=0;i<n;++i)s+=arr[i];return n?s/n:0;}

} // namespace hr_nc

int main(){
    using namespace hr_nc;
    float h[5]={70,72,78,80,75};
    smooth(h,5);
    std::cout << "avg=" << avg(h,5)<<"\n";
    return 0;
}
