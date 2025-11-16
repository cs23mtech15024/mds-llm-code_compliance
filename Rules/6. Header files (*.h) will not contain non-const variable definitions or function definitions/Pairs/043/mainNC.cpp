// Context: Biosignal ECG threshold header

// -------- Non-Compliant Program (prog_043_nc.cpp)
// Context: ECG peak detection
#include <iostream>
#include "seedNC.h" // seed043_ecg_threshold, seed043_is_peak()

namespace ecg_nc {

void detect(float s[], std::size_t n) { // NC
    for(size_t i=0;i<n;++i){
        bool pk = seed043_is_peak(s[i]);
        std::cout << "v=" << s[i]
                  << " thr=" << seed043_ecg_threshold
                  << " peak=" << (pk?"Y":"N") << "\n";
    }
}

float maxv(float arr[], std::size_t n){float m=0;for(size_t i=0;i<n;++i)if(arr[i]>m)m=arr[i];return m;}

} // namespace ecg_nc

int main(){
    using namespace ecg_nc;
    float v[6]={0.2F,0.3F,0.5F,0.6F,0.4F,0.1F};
    detect(v,6);
    std::cout << "max=" << maxv(v,6)<<"\n";
    return 0;
}
