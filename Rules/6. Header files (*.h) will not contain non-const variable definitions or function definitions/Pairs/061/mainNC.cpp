// Context: Car infotainment audio buffer size header

// -------- Non-Compliant Program (prog_061_nc.cpp)
#include <iostream>
#include "seedNC.h" // seed061_audio_buffer, seed061_half_buffer()

namespace audio_nc {

void process(int samples[], std::size_t n) { // NC decay
    for (size_t i=0;i<n;++i) {
        int half = seed061_half_buffer();
        std::cout << "sample=" << samples[i]
                  << " buf=" << seed061_audio_buffer
                  << " half=" << half << "\n";
    }
}

int peak(int arr[], std::size_t n) {
    int m = arr[0];
    for(size_t i=1;i<n;++i) if(arr[i] > m) m = arr[i];
    return m;
}

} // namespace audio_nc

int main(){
    using namespace audio_nc;
    int s[5]={12,18,22,30,25};
    process(s,5);
    std::cout << "peak=" << peak(s,5) << "\n";
    return 0;
}
